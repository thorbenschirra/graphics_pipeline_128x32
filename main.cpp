#include <stdio.h>
#include <iostream>
#include "ssd1305.cpp"

using namespace std;

int main()
{
    stdio_init_all();
    ssd1305_init();

    // fill framebuffer with all pixels on
    uint8_t framebuffer[512];
    memset(framebuffer, 0xFF, 512);

    // push to display
    ssd1305_send_data(framebuffer, 512);

    while (true)
    {
    }
}