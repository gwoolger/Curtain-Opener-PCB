# Curtain Opener (PCB)

This is a project to create a simple PCB to link a microcontroller to various peripherals to automatically open and close a curtain.

It also costs narly the same amount to make 3 sets of the electronics as 1 set. See the BOM bit later on. (Thus as 3 sets fit in budget, I'm going to make 3, so I can make a whole room's curtains open automatically)

The housing and CAD files can be found on [gwoolger/Curtain-Opener-3D](https://github.com/gwoolger/Curtain-Opener-3D)

## Repo Info
Contains the PCB design files, documentation and code for the creation of a PCB to control a stepper motor which is designed to open curtains with a pull cord.

## Use Case
The PCB will be for an attachment to replace the curtain cord tensioner to automatically open and close the curtain.

![Image showing a Curtain Cord with a Curtain](images//Curtain%20Cord.png)

This is primarily designed to work with curtains that have a pull cord, but the PCB could easily be adapted to work with curtains on a rail - just by using it as a sled.

## PCB
The ESP32 intentionally has it's usb port in the middle of the board. This is as it won't need much access, and it will be mounted on pin headers anyway, so will be accessible by cable anyway - or just need some unplugging.


Is a fairly simple PCB, with battery input from a 2S Li Ion pack, which powers a stepper motor and an ESP32. From my rough estimates, it should last easily for 4 months without a charge, and with better optimisation likely much longer.

![Schematic](images/Schematic_final.png)
---


Again, a relatively simple PCB, without that many connections.
| | |
| --- | --- |
| ![PSB Front](images/PCB_Front.png) | ![PCB Back](images/PCB_Pack.png) |

Are currently old images, but the current board is similar enough I'm not changing it yet.

## Code

Currently just connects to NTP to get the time, and if it is within the hardcoded open or close times it wil run. then in either case, it will work out the next time it needs to wake up, and will then go to deep sleep until then.

Will update most likely to have some other way of toggling the curtain state.

## BOM
Actually surprisingly cheap, due to AliExpress being clutch.

Has gone through several iterations due to pricings and discounts.

[HalfLife Grant BOM](BOM.csv)

[Full pricing for 1 curtain opener with no discounts - just adds batteries](BOM_full.csv)

[New Latest BOM with discounts (makes 3 curtain openers within the budget](NEW_BOM.csv)

`Aliexpress can be made much cheaper through splitting an order and using multiple discounts (as long as its for Choice items which have shipping included).`
Also means that for others buying thes parts, they will most likely be more expensive, depending on how much time you are willing to put in to find deals.

### With latest BOM and discounts:

|Store|Price|
|---|---|
| Aliexpress Order 1 | $53.96 |
| Aliexpress Order 2 | $40.47 |
| JLCPCB | $2.30 |
| **Total** | **$96.73** |
| | |
|`(Not included in grant money)` Batteries | ~$35|