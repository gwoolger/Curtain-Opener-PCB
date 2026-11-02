// This code should now work at build week, but will likely still iterate further
// I'm thinking Open meteo for pulling sunrise and sunset data

// Havent implemented the tmc2209 UART thing yet, or I2C for the INA219 or BME280.
// But the curtain should open and close automatically anyway

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
    Serial.println("Done.");
}

struct tm getTime() {
    // Connect to Wi-Fi
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }


    struct tm timeinfo;

    // Sync Time. For UK currently With daylight savings
    configTime(0, 0, "pool.ntp.org");
    setenv("TZ", "GMT0BST,M3.5.0/1,M10.5.0/2", 1);
    tzset();

    while (!getLocalTime(&timeinfo)) {
        Serial.println("Failed to obtain time");
        yield();        // might spam serial, but, it worked on an older project with no problems.
    }

    Serial.printf("\nGot Time at %02d:%02d\n", timeinfo.tm_hour, timeinfo.tm_min);

    WiFi.disconnect();

    return timeinfo;
}



uint32_t getSleepTime(struct tm &timeinfo) {
    int hour = timeinfo.tm_hour;
    int min  = timeinfo.tm_min;
    int secleeway = 10;
    uint32_t secs = ((hour * 60) + min) * 60;
    uint32_t waitsecs;

    open_sec_time = OPEN_HOUR * 3600;
    close_sec_time = CLOSE_HOUR * 3600;

    // checking for morning wake up
    if (secs < open_sec_time) {
        waitsecs = open_sec_time - secs - secleeway;
    }
    else if (secs < close_sec_time) {
        waitsecs = close_sec_time - secs - secleeway;
    }
    else {
        waitsecs = 86400 - secs + open_sec_time - secleeway;
    }

    return waitsecs;
}

void setup() {
    Serial.begin(115200);
    
    pinMode(PIN_STEP, OUTPUT);
    pinMode(PIN_DIR, OUTPUT);
    pinMode(PIN_EN, OUTPUT);
    digitalWrite(PIN_EN, HIGH); // Default to disabled (pulled low high anyway)

    struct tm timeinfo = getTime();




    getSleepTime(*timeinfo)
    uint32_t secsToSleep = 0;

    
    if (currentHour >= OPEN_HOUR && currentHour < CLOSE_HOUR) {

        if (currentHour == OPEN_HOUR && currentMin < 5) {
            runStepper(true);
        }
        hoursToSleep = CLOSE_HOUR - currentHour;

    } 


    else {
        if (currentHour == CLOSE_HOUR && currentMin < 5) {
            runStepper(false);
        }
        hoursToSleep = (currentHour < OPEN_HOUR) ? (OPEN_HOUR - currentHour) : (24 - currentHour + OPEN_HOUR);
    }

    Serial.printf("Going to deep sleep for %llu hours...\n", hoursToSleep);     // Deep sleep.
    
    WiFi.disconnect(true);
    
    
    esp_sleep_enable_timer_wakeup(hoursToSleep * 3600ULL * 1000000ULL); // meant to take microsecconds. ULL
    esp_deep_sleep_start();
}

void loop() {
    // Deep sleep means code wont reach here
}
