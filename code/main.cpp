// This code should now work at build week, but will likely still iterate further
// I'm thinking Open meteo for pulling sunrise and sunset data

// Havent implemented the tmc2209 UART thing yet, or I2C for the INA219 or BME280.
// But the curtain should open and close automatically anyway at the specified times.

// Currently getting curtain to toggle state 5 sec after hour turns - gives some buffer time.
// And can change during the 5 minutes after the hour. Could cause multiple actuations, but
// provbably wont be a problem.

// Also even with clock drifts etc, it wont be a problem, as there is a 5 min leeway,
// and it syncs with ntp so should realign.

#include <Arduino.h>
#include <WiFi.h>
#include <time.h>

const char* WIFI_SSID = "WIFI_SSID";
const char* WIFI_PASS  = "WIFI_PASSWORD";

// Hardcoded schedule - will provably change evening to be sunset later
const int OPEN_HOUR  = 7;  // 07:00 AM
const int CLOSE_HOUR = 19; // 07:00 PM

/* old
const uint8_t PIN_UART = D4;
const uint8_t PIN_DIAG = D1;

// I2C
const uint8_t PIN_SDA = D6;
const uint8_t PIN_SCL = D7;

// Power / input
//const uint8_t PIN_VBAT   = D0; not this one, as would fry esp if connected
const uint8_t PIN_BUTTON = D9;
*/

// stepper on tmc2209
const uint8_t PIN_STEP = D2;
const uint8_t PIN_DIR  = D3;
const uint8_t PIN_EN   = D5;

RTC_DATA_ATTR bool curtainIsOpen = false;   // will persist over deep sleep

void runStepper(bool openCurtain) {
    Serial.println(openCurtain ? "Opening..." : "Closing...");
    digitalWrite(PIN_EN, LOW); // Enable driver (Active LOW) - kept high by 10k resistor
    digitalWrite(PIN_DIR, openCurtain ? HIGH : LOW);
    
    unsigned long startTime = millis();
    while (millis() - startTime < 30000) { // 30 seconds
        digitalWrite(PIN_STEP, HIGH);
        delayMicroseconds(1000); 
        digitalWrite(PIN_STEP, LOW);
        delayMicroseconds(1000);
    }
    digitalWrite(PIN_EN, HIGH); // Disable driver for better battery life
    curtainIsOpen = openCurtain; // Update state in RTC memory after movement finishes
    Serial.println("Done.");
}

struct tm getTime() {
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    int wifiAttempts = 0;
    while (WiFi.status() != WL_CONNECTED && wifiAttempts < 20) {
        delay(500);
        Serial.print(".");
        wifiAttempts++;
    }

    struct tm timeinfo;
    // Default time if sync completely fails - not sure if there is a more elegant solution for this
    timeinfo.tm_hour = 12;
    timeinfo.tm_min = 0;
    timeinfo.tm_sec = 0;

    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("\nWiFi failed to connect. Using fallback time.");
        return timeinfo;
    }

    // Sync Time. For UK currently With daylight savings
    configTime(0, 0, "pool.ntp.org");
    setenv("TZ", "GMT0BST,M3.5.0/1,M10.5.0/2", 1);
    tzset();

    // 5 sec timeout
    int ntpAttempts = 0;
    while (!getLocalTime(&timeinfo) && ntpAttempts < 10) {
        Serial.println("Failed to obtain time, retrying...");
        delay(500);
        ntpAttempts++;
    }

    Serial.printf("\nGot Time at %02d:%02d\n", timeinfo.tm_hour, timeinfo.tm_min);

    WiFi.disconnect(true);

    return timeinfo;
}

uint32_t getSleepTime(struct tm &timeinfo) {
    int hour = timeinfo.tm_hour;
    int min  = timeinfo.tm_min;
    int sec  = timeinfo.tm_sec;
    
    uint32_t secs = ((hour * 60) + min) * 60 + sec;
    uint32_t waitsecs;

    uint32_t open_sec_time = OPEN_HOUR * 3600;
    uint32_t close_sec_time = CLOSE_HOUR * 3600;
    uint32_t safetyBuffer = 2;

    // wake up times
    if (secs < open_sec_time) {
        waitsecs = open_sec_time - secs + safetyBuffer;
    }
    else if (secs < close_sec_time) {
        waitsecs = close_sec_time - secs + safetyBuffer;
    }
    else {
        waitsecs = (86400 - close_sec_time) + open_sec_time + safetyBuffer;
    }

    return waitsecs;
}

void setup() {
    Serial.begin(115200);
    
    pinMode(PIN_STEP, OUTPUT);
    pinMode(PIN_DIR, OUTPUT);
    pinMode(PIN_EN, OUTPUT);
    digitalWrite(PIN_EN, HIGH); // Default to disabled (pulled low high anyway)

    uint32_t start = millis();
    struct tm timeinfo = getTime();
    
    int currentHour = timeinfo.tm_hour; 
    int currentMin = timeinfo.tm_min;   

    // Runs only if time falls in the activation window AND the curtain isn't already in that state
    if (currentHour == OPEN_HOUR && currentMin < 5 && !curtainIsOpen) {       // so cant cycle anymore
        runStepper(true);
    }
    else if (currentHour == CLOSE_HOUR && currentMin < 5 && curtainIsOpen) {
        runStepper(false);
    }


    uint32_t elapsedSeconds = (millis() - start) / 1000;        // dont know why i didnt do this earlier
    uint32_t baseSleepTime = getSleepTime(timeinfo);
    
    uint32_t secsToSleep;
    if (baseSleepTime > elapsedSeconds) {
        secsToSleep = baseSleepTime - elapsedSeconds;
    } 
    else {
        secsToSleep = baseSleepTime;
    }

    uint32_t displayHours = secsToSleep / 3600;
    uint32_t displayMins = (secsToSleep % 3600) / 60;
    uint32_t displaySecs = secsToSleep % 60;        // gotta be a more efficient way of doing this

    Serial.printf("Going to deep sleep for %02u hours, %02u minutes, and %02u seconds (%u total seconds)...\n", 
        displayHours, displayMins, displaySecs, secsToSleep);     // Deep sleep.
        
    esp_sleep_enable_timer_wakeup(secsToSleep * 1000000ULL); // meant to take microsecconds. ULL
    esp_deep_sleep_start();
}

void loop() {
    // Deep sleep means code wont reach here
}
