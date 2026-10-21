# Curtain Opener (PCB)

This is a project to create a simple PCB to link a microcontroller to various peripherals to automatically open and close a curtain.

The housing and CAD files can be found on [gwoolger/Curtain-Opener-3D](gitHub.com/gwoolger/Curtain-Opener-3D)

## For Reviewer

I was looking back at things, and realised I had the wrong shipping location selected. So when I added things up again, the parts got to just under $100. What should I do? as I'm currently stuck on tier 2, and the website won't let me change it?

The half life website says I'm at 24.1 hours, so should have enough for tier 3? it was 24 hours at one point, but can't remember if it changed.

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
|---|---:|---|---:|---:|---|
| NEMA 17 pancake | 1 | AliExpress | $10.12 | $10.12 | [link](https://www.aliexpress.com/item/1005005742670433.html?spm=a2g0n.productlist.0.0.49559mTH9mTHDD&aff_platform=msite&m_page_id=&pdp_ext_f=%7B%22order%22%3A%22440%22%2C%22spu_best_type%22%3A%22price%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21USD%2110.12%2110.11%21%21%2110.12%2110.11%21%400b88a96117926076938061329e0e2c%2112000034182321935%21sea%21GB%218513385029%21ABX%211%210%21n_tag%3A-29910%3Bd%3A98c60280%3Bm03_new_user%3A-29895%3BpisId%3A5000000218644952&algo_pvid=48bdf137-72ed-4d50-b74c-a98029b86bd7&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005005742670433%7C_p_origin_prod%3A) |
| xiao esp32c6 with pins | 1 | AliExpress | $14.46 | $14.46 | [link](https://www.aliexpress.com/item/1005007427033011.html?spm=a2g0n.productlist.0.0.6b751c72OdA9iv&browser_id=c47aa3d29b4c48bc919fdf8c3cb51026&aff_platform=msite&m_page_id=nbxai6x6q3ycabkj1a15fc0ca5d1aada4c88f95950&pdp_ext_f=%7B%22order%22%3A%222831%22%2C%22spu_best_type%22%3A%22price%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21USD%219.12%218.57%21%21%219.12%218.57%21%400b88a95617926078326295025e0e7b%2112000040716079484%21sea%21GB%218513385029%21ABX%211%210%21n_tag%3A-29910%3Bd%3A98c60280%3Bm03_new_user%3A-29895%3BpisId%3A5000000219610136&algo_pvid=84fb1087-e432-4eeb-9788-c68cacfe43f1&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005007427033011%7C_p_origin_prod%3A) |
| 230pcs JST connector | 1 | AliExpress | $3.06 | $3.06 | [link](https://www.aliexpress.com/item/1005006498660940.html?mp=1&pdp_npi=6%40dis%21USD%21USD+3.07%21USD+3.06%21%21USD+3.06%21%21%21%400b88ad2b17926075737317503e0de2%2112000037425305641%21ct%21GB%218513385029%21%211%210%21&pdp_ext_f=%7B%22cart2PdpParams%22%3A%7B%22pdpBusinessMode%22%3A%22retail%22%7D%7D) |
| 200pcs electrolytic capacitor | 1 | AliExpress | $7.12 | $7.12 | [link](https://www.aliexpress.com/item/1005005626707702.html?mp=1&pdp_npi=6%40dis%21USD%21USD+7.12%21USD+7.11%21%21USD+7.11%21%21%21%400b88a96117926076658848685e0e2c%2112000033796706984%21ct%21GB%218513385029%21%211%210%21) |
| 2pcs BigTreeTech TMC2209 | 1 | AliExpress | $8.62 | $8.62 | [link](https://www.aliexpress.com/item/33028050145.html?spm=a2g0n.productlist.0.0.44326378zKzfyn&aff_platform=msite&m_page_id=&pdp_ext_f=%7B%22order%22%3A%224524%22%2C%22spu_best_type%22%3A%22price%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21USD%218.62%217.70%21%21%218.62%217.70%21%400b884b5817926083007897944e0ce2%2112000041238691050%21sea%21GB%218513385029%21ABX%211%210%21n_tag%3A-29910%3Bd%3A98c60280%3Bm03_new_user%3A-29895%3BpisId%3A5000000219610136&algo_pvid=f07ed452-2dfe-4553-8c2e-39c5320b4def&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A33028050145%7C_p_origin_prod%3A) |
| 5pcs INA219 | 1 | AliExpress | $4.88 | $4.88 | [link](https://www.aliexpress.com/item/32469098903.html?spm=a2g0n.productlist.0.0.78192e47lb4pAh&aff_platform=msite&m_page_id=&pdp_ext_f=%7B%22order%22%3A%221421%22%2C%22spu_best_type%22%3A%22price%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21USD%211.38%211.37%21%21%211.38%211.37%21%400b88a96117926084454147762e0d45%2112000057342623698%21sea%21GB%218513385029%21ABX%211%210%21n_tag%3A-29910%3Bd%3A98c60280%3Bm03_new_user%3A-29895%3BpisId%3A5000000218644952&algo_pvid=c1cfe114-a841-4254-837e-c4bc02a532f4&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A32469098903%7C_p_origin_prod%3A) |
| 20mm x 30m kapton tape | 1 | AliExpress | $5.54 | $5.54 | [link](https://www.aliexpress.com/item/1005010653561140.html?spm=a2g0n.productlist.0.0.32d64d984YaSbx&aff_platform=msite&m_page_id=&pdp_ext_f=%7B%22order%22%3A%223914%22%2C%22eval%22%3A%221%22%2C%22orig_sl_item_id%22%3A%221005010653561140%22%2C%22orig_item_id%22%3A%221005012086062231%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21USD%213.22%211.60%21%21%2121.40%2110.63%21%400b884b4717926085375914853e1074%2112000060794550870%21sea%21GB%218513385029%21ABX%211%210%21n_tag%3A-29910%3Bd%3A98c60280%3Bm03_new_user%3A-29895%3BpisId%3A5000000218644952&algo_pvid=f3d59c5b-27a7-4acc-be49-2e5253c88ff3&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005010653561140%7C_p_origin_prod%3A1005012086062231) |
| 20pcs 40 pin pin headers | 1 | AliExpress | $4.88 | $4.88 | [link](https://www.aliexpress.com/item/1005010759653046.html?spm=a2g0n.productlist.0.0.7005665ei1DmI4&browser_id=c47aa3d29b4c48bc919fdf8c3cb51026&aff_platform=msite&m_page_id=nbxai6x6q3ycabkj1a15fce1fbf20d9d2f96283c34&pdp_ext_f=%7B%22order%22%3A%2211299%22%2C%22eval%22%3A%221%22%2C%22orig_sl_item_id%22%3A%221005010759653046%22%2C%22orig_item_id%22%3A%221005007330323661%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21USD%214.88%212.43%21%21%2132.38%2116.12%21%402103842a17926087199692390e0f82%2112000053415962296%21sea%21GB%218513385029%21ABX%211%210%21n_tag%3A-29910%3Bd%3A98c60280%3Bm03_new_user%3A-29895%3BpisId%3A5000000218644952&algo_pvid=d3fde66a-43d7-4980-a4d6-52039030e0bf&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005010759653046%7C_p_origin_prod%3A1005007330323661) |
| 6pcs momentary push button | 1 | AliExpress | $6.78 | $6.78 | [link](https://www.aliexpress.com/item/1005006695980453.html?spm=a2g0n.productlist.0.0.7c69zHexzHexCV&aff_platform=msite&m_page_id=&pdp_ext_f=%7B%22order%22%3A%226579%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21USD%216.78%212.97%21%21%2145.01%2119.73%21%402103956a17926087999327038e1016%2112000038033411774%21sea%21GB%218513385029%21ABX%211%210%21n_tag%3A-29910%3Bd%3A98c60280%3Bm03_new_user%3A-29895%3BpisId%3A5000000218644952&algo_pvid=16f5e7d4-dc96-4769-b291-ecf6f31a9637&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005006695980453%7C_p_origin_prod%3A) |
| 10pcs BMP280 | 1 | AliExpress | $3.66 | $3.66 | [link](https://www.aliexpress.com/item/1005008511564094.html?spm=a2g0n.productlist.0.0.7cfb155cdzV7SG&aff_platform=msite&m_page_id=&pdp_ext_f=%7B%22order%22%3A%226533%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21USD%212.16%212.15%21%21%212.16%212.15%21%40210398e917926089354184288e1043%2112000045490825870%21sea%21GB%218513385029%21ABX%211%210%21n_tag%3A-29910%3Bd%3A98c60280%3Bm03_new_user%3A-29895%3BpisId%3A5000000218644952&algo_pvid=1b21626c-e5ee-4595-880e-d2d2fad266a7&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005008511564094%7C_p_origin_prod%3A) |
| 5pcs mini 360 buck | 1 | AliExpress | $6.63 | $6.63 | [link](https://www.aliexpress.com/item/1005007823534769.html?spm=a2g0n.productlist.0.0.565bH2W1H2W13f&aff_platform=msite&m_page_id=&pdp_ext_f=%7B%22order%22%3A%224992%22%2C%22eval%22%3A%221%22%2C%22orig_sl_item_id%22%3A%221005007823534769%22%2C%22orig_item_id%22%3A%221005008498998352%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21USD%212.66%211.28%21%21%2117.63%218.46%21%400b1585c117926090884431281e0db9%2112000061130607317%21sea%21GB%218513385029%21ABX%211%210%21n_tag%3A-29910%3Bd%3A98c60280%3Bm03_new_user%3A-29895&algo_pvid=922e4651-2784-4d9f-a299-0bc4856d6bf4&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005007823534769%7C_p_origin_prod%3A1005008498998352) |
| 2s 18650 holder | 1 | AliExpress | $4.31 | $4.31 | [link](https://www.aliexpress.com/item/1005013266198026.html?spm=a2g0n.productlist.0.0.318dMJc7MJc744&aff_platform=msite&m_page_id=&pdp_ext_f=%7B%22order%22%3A%2225498%22%2C%22eval%22%3A%221%22%2C%22orig_sl_item_id%22%3A%221005013266198026%22%2C%22orig_item_id%22%3A%221005008803291008%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21USD%214.31%212.15%21%21%2128.62%2114.25%21%4021038a8017926093185597361e1069%2112000061080661671%21sea%21GB%218513385029%21ABX%211%210%21n_tag%3A-29910%3Bd%3A98c60280%3Bm03_new_user%3A-29895%3BpisId%3A5000000218644952&algo_pvid=130109a3-b8cb-4bcc-b6fb-92d0ee055a6d&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005013266198026%7C_p_origin_prod%3A1005008803291008) |
| 820pcs resistor kit with box | 1 | AliExpress | $6.31 | $6.31 | [link](https://www.aliexpress.com/item/1005011772534173.html?mp=1&pdp_npi=6%40dis%21USD%21USD+6.31%21USD+6.31%21%21USD+6.31%21%21%21%40210382de17926091989282068e0ebc%2112000056500803490%21ct%21GB%218513385029%21%211%210%21) |
| 2s 20a balanced BMS | 1 | AliExpress | $1.21 | $1.21 | [link](https://www.aliexpress.com/item/1005010010254856.html?spm=a2g0n.productlist.0.0.70d4aFIDaFID4k&browser_id=c47aa3d29b4c48bc919fdf8c3cb51026&aff_platform=msite&m_page_id=nbxai6x6q3ycabkj1a15fdd4cf121643fa29143867&pdp_ext_f=%7B%22order%22%3A%22239%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21USD%2111.07%2111.07%21%21%2173.50%2173.50%21%40210398e917926097010671192e0d2f%2112000050832742913%21sea%21GB%218513385029%21ABX%211%210%21n_tag%3A-29910%3Bd%3A98c60280%3Bm03_new_user%3A-29895&algo_pvid=e02b6057-bcab-4b8e-b30b-8bba74e4837c&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005010010254856%7C_p_origin_prod%3A&search_p4p_id=2026102112082161076216341280001513554_4) |
| 2mm 1.5m desoldering braid | 1 | AliExpress | $2.30 | $2.30 | [link](https://www.aliexpress.com/item/1005005398523384.html?mp=1&pdp_npi=6%40dis%21USD%21USD+2.30%21USD+0.78%21%21USD+0.78%21%21%21%4021613be817926097905165058e0ef6%2112000032915095979%21ct%21GB%218513385029%21%211%210%21) |
| PCB | 1 | JLCPCB | $4.00 | $4.00 | [link](https://jlcpcb.com) |
| Estimated total shipping | 1 |  |  | $4.77 |  |
| **Total (incl. shipping)** |  |  |  | **$98.65** |  |

Got more than 1 part for a few in case I fry one or something. Also might do something with the temp sensors in build week.


They add up to more here, but will be less due do AliExpress coupons etc.

But still under the $100 cap for tier 3.

Oh, and AliExpress shipping is included in the price, as they are Choice items, so shipping is just for JLCPCB.

### BOM description
Added as in slack seems people are getting returned for:

stepper and tmc2209 driver for physically moving the thing, esp32c6 for controlling. capacitors used to supplement stepper. 2s batt holder and bms used with cells I'm buying seperately - too expensive to fit in budget. buck module for right voltage for MCU, pin headers so I can put things on and off easier. other modules like current and temp etc for monitoring. other stuff just misc to make everything work. nothing else really adds function.
