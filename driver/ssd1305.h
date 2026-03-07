#pragma once
#include "pico/stdlib.h"
#include "hardware/spi.h"

constexpr uint SPI_SCK = 10;
constexpr uint SPI_TX = 11;
constexpr uint DC_PIN = 8;
constexpr uint SPI_CS = 9;
constexpr uint RST_PIN = 12;

void ssd1305_init();
void ssd1305_send_data(uint8_t *data, size_t length);

void ssd1305_send_command(uint8_t command);