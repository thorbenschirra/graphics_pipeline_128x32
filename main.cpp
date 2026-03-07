#include <stdio.h>
#include "ssd1305.h"
#include "string.h"
#include "framebuffer.h"

int main()
{
    stdio_init_all();
    ssd1305_init();

    Framebuffer fb;
    fb.drawLine(0, 0, 12, 10);
    ssd1305_send_data(fb.getBuffer(), 512);

    while (true)
    {
    }
}