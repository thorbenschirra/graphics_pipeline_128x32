#include <stdio.h>
#include "ssd1305.h"

void ssd1305_send_command(uint8_t command)
{
    gpio_put(SPI_CS, 0);
    gpio_put(DC_PIN, 0);

    spi_write_blocking(spi0, &command, 1);

    gpio_put(SPI_CS, 1);
}

void ssd1305_send_data(uint8_t *data, size_t length)
{
    gpio_put(SPI_CS, 0);
    gpio_put(DC_PIN, 1);

    spi_write_blocking(spi0, data, length);

    gpio_put(SPI_CS, 1);
}

void ssd1305_init()
{

    // set SPI pin functions
    gpio_set_function(SPI_TX, GPIO_FUNC_SPI);
    gpio_set_function(SPI_SCK, GPIO_FUNC_SPI);
    gpio_set_function(SPI_CS, GPIO_FUNC_SPI);

    // initialize control pins as GPIO outputs
    gpio_init(DC_PIN);
    gpio_set_dir(DC_PIN, GPIO_OUT);

    gpio_init(RST_PIN);
    gpio_set_dir(RST_PIN, GPIO_OUT);

    // hardware reset
    gpio_put(RST_PIN, 1);
    sleep_ms(10);
    gpio_put(RST_PIN, 0);
    sleep_ms(10);
    gpio_put(RST_PIN, 1);
    sleep_ms(10);

    // display off
    ssd1305_send_command(0xAE);

    // clock frequency/ oscillator
    ssd1305_send_command(0xD5);
    ssd1305_send_command(0x70);

    // multiplex ratio
    ssd1305_send_command(0xA8);
    ssd1305_send_command(0x1F);

    // display offset
    ssd1305_send_command(0xD3);
    ssd1305_send_command(0x00);

    // display start line
    ssd1305_send_command(0x40);

    // lower column start address
    ssd1305_send_command(0x02);
    // higher column start address
    ssd1305_send_command(0x10);

    // contrast setting
    ssd1305_send_command(0x81);
    ssd1305_send_command(0xFF);

    // segment remap
    ssd1305_send_command(0xA0);

    // COM scan direction
    ssd1305_send_command(0xC0);

    // entire display on
    ssd1305_send_command(0xA4);
    ssd1305_send_command(0xA6);

    // turn display on
    ssd1305_send_command(0xAF);
}

int main()
{
    stdio_init_all();
    ssd1305_init();
}