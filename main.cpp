#include <stdio.h>
#include <string>
#include "ssd1305.h"
#include "string.h"
#include "framebuffer.h"
#include "letters.cpp"

int main()
{
    stdio_init_all();
    ssd1305_init();

    Framebuffer fb;
    /* void drawLetter(uint8_t *letter)
    {
        for (int i = 0; i < 64; i++)
        {
        }
    } */

    ssd1305_flush(fb.getBuffer());
}