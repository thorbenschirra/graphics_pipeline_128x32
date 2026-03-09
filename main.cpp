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

    fb.drawChar('j', 4, 4);

    ssd1305_flush(fb.getBuffer());
}