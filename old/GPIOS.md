# For the Xiao Seeed ESP32C6

| XIAO ESP32-C6 Pin | ESP32-C6 Native GPIO | Your PCB Custom Assignment |
| :--- | :--- | :--- |
| D0/A0 | GPIO 0 | Battery Voltage Monitor |
| D1/A1 | GPIO 1 | TMC2209 DIAG |
| D2/A2 | GPIO 2 | TMC2209 STEP Pulse |
| D3 | GPIO 21 | TMC2209 DIR Direction |
| D4 | GPIO 22 | TMC2209 Single-Wire UART |
| D5 | GPIO 23 | Motor EN Pin |
| D6 | GPIO 16 | Sensor I2C SDA |
| D7 | GPIO 17 | Sensor I2C SCL |
| D8 | GPIO 19 |  |
| D9 | GPIO 20 | Physical Toggle Button |
| D10 | GPIO 18 |  |


---
## Notes
- D0 (Bat Mon): Add a resistor divider network to drop battery voltage safely down under 3.3V for ADC1.
- D1 (DIAG): Direct trace to the TMC2209 DIAG pin for sensorless homing. No extras needed.
- D4 & D5 (Stepper Serial / EN): Kept here to completely isolate the driver from native TX bootloader noise. Add an external 10kΩ pull-up to 3.3V on D5 to ensure the motor stays locked off at power-up.
- D6 & D7 (I2C Sensors): Board has no native onboard I2C pull-ups. Add physical 4.7kΩ resistors to 3.3V for both lines on the schematic.
- D9 (Toggle): Wired to GPIO 20. Supports native hardware interrupts for immediate wake/trigger. Wire straight to GND and rely on software internal pull-up.