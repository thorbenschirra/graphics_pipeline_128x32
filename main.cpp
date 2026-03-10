#include <stdio.h>
#include <iostream>
#include <string>
#include "ssd1305.h"
#include "string.h"
#include "framebuffer.h"
#include "font.h"

using namespace std;

int main()
{
    stdio_init_all();
    ssd1305_init();

    Framebuffer fb;

    fb.drawChar('d', 4, 4);
    fb.drawChar('e', 12, 4);
    fb.drawChar('e', 20, 4);
    fb.drawChar('z', 28, 4);
    fb.drawChar('n', 44, 4);
    fb.drawChar('u', 52, 4);
    fb.drawChar('t', 60, 4);
    fb.drawChar('s', 68, 4);

    ssd1305_flush(fb.getBuffer());
}