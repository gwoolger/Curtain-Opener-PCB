# Curtain Opener (PCB)

This is a project to create a simple PCB to link a microcontroller to various peripherals to automatically open and close a curtain.

The housing and CAD files can be found on [gwoolger/Curtain-Opener-3D](gitHub.com/gwoolger/Curtain-Opener-3D)

## Repo Info
Contains the PCB design files and documentation for the creation of a PCB to control a stepper motor which is designed to open curtains with a pull cord.

## Use Case
The PCB will be for an attachment to replace the curtain cord tensioner to automatically open and close the curtain.

![Image showing a Curtain Cord with a Curtain](images//Curtain%20Cord.png)

This is primarily designed to work with curtains that have a pull cord, but the PCB could easily be adapted to work with curtains on a rail - just by using it as a sled.

## PCB
Is a fairly simple PCB, with battery input from a 2S Li Ion pack, which powers a stepper motor and an ESP32. From my rough estimates, it should last easily for 4 months without a charge, and with better optimisation likely much longer.

![Schematic](images/Schematic_final.png)
---


Again, a relatively simple PCB, without that many connections.
| | |
| --- | --- |
| ![PSB Front](images/PCB_Front.png) | ![PCB Back](images/PCB_Pack.png) |

## Code

Already is a skeleton code definition, but will finish code later in the build week, as can't code without the microcontroller and parts - at least without going massively wrong.

## BOM
Actually surprisingly cheap, due to AliExpress being clutch.

| Item | Qty | Supplier | Cost/item | Total Cost | link |
|---|---|---|---|---|---|
| Nema 17 Pancake Stepper | 1 | Aliexpress | $6.55 | $6.55 | [Aliexpress](https://www.aliexpress.com/item/1005003874936862.html?spm=a2g0o.productlist.main.1.345a523aoLDYQH&algo_pvid=0a3d7d18-cb98-493e-bae6-49b1989a0b29&algo_exp_id=0a3d7d18-cb98-493e-bae6-49b1989a0b29-12&pdp_ext_f=%7B%22order%22%3A%228807%22%2C%22spu_best_type%22%3A%22price%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21GBP%215.24%211.58%21%21%216.74%212.03%21%4021613be817915628806768532e0e61%2112000036219123370%21sea%21UK%210%21ABX%211%210%21n_tag%3A-29910%3Bd%3A98ea16a6%3Bm03_new_user%3A-29895%3BpisId%3A5000000218642852&curPageLogUid=RjxpKRYOV0Tl&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005003874936862%7C_p_origin_prod%3A) |
| Xiao Seeed ESP32C6 | 1 | Aliexpress | $9.12 | $9.12 | [Aliexpress](https://www.aliexpress.com/item/1005007427033011.html?spm=a2g0o.cart.0.0.6cb538dalip601&mp=1&pdp_npi=6%40dis%21USD%21USD+9.12%21USD+9.12%21%21USD+9.12%21%21%21%400b88486a17915708470302400e0cf1%2112000040716079484%21ct%21GB%21-1%21%211%210%21&pdp_ext_f=%7B%22cart2PdpParams%22%3A%7B%22pdpBusinessMode%22%3A%22retail%22%7D%7D) |
| Misc | 1 | Aliexpress | $32.79 | $32.79 | [Aliexpress](https://aliexpress.com) |
| PCB | 1 | JLCPCB | $4.00 | $4.00 | [JLCPCB](https://jlcpcb.com) |
| Estimated total shipping | 1 |  |  | $4.77 |  |

Oh and, the Misc AliExpress parts, are like resistors, switches, pin headers, the ina219 module, the stepper driver etc. Just didn't want to spend time writing them all out, as AliExpress changes the exact prices constantly. But the price is calculated from the AliExpress cart total of $48.46 minus the other parts listed separately.

Though will list briefly here with rough prices without links as quicker - and if parts are looked up on AliExpress, you're unlikely to find better prices:
- seeed esp32c6 $9
- 200pcs capacitor kit 7$
- 230pcs jst connector kit $3
- kapton tape $2.50
- 20pcs switch $1.50
- push button $2
- NEMA 17 pancake $6 
- 10x40 pin headers kit $2
- 10pcs bmp280 temp sensor $4
- 820pcs resistor kit $8
- tmc2209 clone $5
- 5pcs buck to 5v $3
- INA219 module $2
- 2s battery holder $2.50

They add up to more here, but will be less due do AliExpress coupons etc.
