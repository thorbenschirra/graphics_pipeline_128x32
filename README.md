# graphics_pipeline_128x32

_Note that this is a very early project of mine -> basic functionalities and no proper font design_

### Description

This project is a simple and lightweight graphics pipeline for the **Raspberry Pi Pico 2 W**. <br>
It is implemented for the SSD1305 and I specifically used the Waveshare 2.23 inch OLED display (128x32 pixels).

### Highlights

- easy to use
- lightweight

### Features

- write any sentence to the display using **english alphabet-only characters**
-

### Usage

- buy the **Raspberry Pi Pico 2 W** and the **Waveshare 2.23 inch** OLED display (links can be found at the bottom)
- the Pico plugs directly onto the display (make sure to plug it in the correct way)
- in the main.cpp file create your own program and display text using **_fb.writeSentence()_**, **_fb.drawChar()_**, **_fb.drawCircle()_** or **_fb.drawLine()_** functions.

### Future features

- support of all characters
- font redesign
- connection to WiFi using lwIP
- segmentation of the display for better UI/UX

### Links

- Waveshare 2.23 inch OLED display - https://www.waveshare.com/pico-oled-2.23.htm?srsltid=AfmBOorOy3FZRBvzfxgl5yqcQEWZ6FVBKS5q1xV23o8UFARRk-dEuEVg
- Raspberry Pi Pico 2 W (select shop based on your country) - https://www.raspberrypi.com/products/raspberry-pi-pico-2/?variant=pico-2-w
