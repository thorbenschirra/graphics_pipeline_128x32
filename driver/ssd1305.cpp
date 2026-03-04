#include <stdio.h>
#include "pico/stdlib.h"
#include "ssd1305.h"

void ssd1305_init()
{
    // Hardware reset first
    gpio_put(RST_PIN, 0);
    sleep_ms(10);
    gpio_put(RST_PIN, 1);
    sleep_ms(10);

    uint8_t cmds[] = {
        0xAE, // 1.  display OFF

        0xD5, 0xA0, // 2.  clock: recommended oscillator freq, no divide
        0xA8, 0x1F, // 3.  multiplex: 32 rows (0x1F = 31)
        0xD3, 0x00, // 4.  display offset: none
        0x40,       // 5.  start line: 0

        0xAD, 0x8B, // 6.  master config: internal DC-DC (SSD1305 specific)

        0xA1,       // 7.  segment remap: mirrored (correct for Waveshare)
        0xC8,       // 8.  COM scan: remapped top-to-bottom (correct for Waveshare)
        0xDA, 0x02, // 9.  COM pin config: sequential (128×32 panel)

        0x81, 0xFF, // 10. contrast: maximum
        0xD9, 0xF1, // 11. pre-charge period
        0xDB, 0x40, // 12. VCOMH level

        0x20, 0x00, // 13. addressing mode: horizontal (needed for flush)

        0xA4, // 14. output follows RAM
        0xA6, // 15. normal display (not inverted)

        0xAF // 16. display ON — always last
    };

    for (int i = 0; i < sizeof(cmds); i++)
    {
        ssd1305_send_command(cmds[i]);
    }
}

int main()
{
}