# Curtain Opener PCB Plan

## Parts

- Xiao Seeed ESP32 C6
- 2x 18650 cell holder
- 2x 18650 cells (already have)
- 20a 2s balanced bms
- 2s l-ion battery step up charger (usb5v)
- tmc2209
- temp/barometer sensor - likely BME280
- INA219

- 12mm Panel Mount Metal Momentary Push Button
- THT Slide Switch or Toggle Switch
- 2.54mm Female Header Pins (2x8 for esp, 2x8 for stepper driver)
- 2.54mm Male Pin Headers. Just get a couple sets of 40.
- Electrical tape

- 2.54mm Screw Terminal Blocks or JST connector kit

- Mini Step down 5V buck converter
- 10µF Electrolytic Capacitor (Radial THT, minimum 16V or 25V rating)
- 22µF or 47µF Electrolytic Capacitor (Radial THT, 10V or 16V rating)
- 0.1µF (100nF) Ceramic Disc Capacitor (Pitch 2.54mm)
- 100µF or 220µF Electrolytic Capacitor (Radial THT, Rated 16V or 25V) - for tmc2209 power absorbtion

#### Stepper motor choices
- Using a Nema 17 pancake


## Plan
ESP32, Stepper Driver and most components on one side. Battery holder solderd to other side.
Will only be opening a curtain periodically, so does not need high voltages etc.
All things avaliable as modules will be on pin headers. or attached with wires etc. Will have minimal on pcb components, and all should preferably be tht.

At some point will design and 3D print a case.

## Removed
- Solar panel circuitry as overcomplicated things
- All Mosfets for Charging toggling - too complex
- Nicdec kv4239-t2b013 in favour of Nema 17 pancake
- k7805 1000r3, as not cost effective
- Voltage divider for battery sensing in favour of module that could detect current - eg motor stalls
- ESP32 C3 Supermini, as when looking at it, it was going to be quite a lot less power efficient - eg and entire order of magnitude off what the Seeed board could do in deep sleep
