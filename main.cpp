#include <stdio.h>
#include "ssd1305.h"
#include "string.h"

int main()
{
    stdio_init_all();

    // blink the onboard LED to confirm code is running
    gpio_init(25); // onboard LED on Pico
    gpio_set_dir(25, GPIO_OUT);

    for (int i = 0; i < 5; i++)
    {
        gpio_put(25, 1);
        sleep_ms(500);
        gpio_put(25, 0);
        sleep_ms(500);
    }

    ssd1305_init();

    uint8_t framebuffer[512];
    memset(framebuffer, 0xFF, 512);
    ssd1305_send_data(framebuffer, 512);

    while (true)
    {
    }
}