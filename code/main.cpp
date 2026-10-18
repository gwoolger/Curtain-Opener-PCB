// Will completely clear and update in build week, as plan to reflash with PlatformIO
// Is just some rough code so the repo has code in

#include <Arduino.h>
// Will need Wire for I2C etc, but will add later when can test things

// Stepper driver (TMC2209)
const uint8_t PIN_STEP = D2;
const uint8_t PIN_DIR  = D3;
const uint8_t PIN_EN   = D5;
const uint8_t PIN_UART = D4;
const uint8_t PIN_DIAG = D1;

// I2C
const uint8_t PIN_SDA = D6;
const uint8_t PIN_SCL = D7;

// Power / input
const uint8_t PIN_VBAT   = D0;
const uint8_t PIN_BUTTON = D9;
