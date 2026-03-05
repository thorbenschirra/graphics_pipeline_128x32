#pragma once
#include "pico/stdlib.h"
#include "hardware/spi.h"

constexpr uint SPI_PIN = 1;
constexpr uint SPI_SCK = 19;
constexpr uint SPI_TX = 20;
constexpr uint DC_PIN = 16;
constexpr uint SPI_CS = 17;
constexpr uint RST_PIN = 15;

void ssd_1305_init() {}
void ssd1305_send_command(uint8_t command) {}