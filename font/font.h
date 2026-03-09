#pragma once
#include "stdio.h"
#include <iostream>
#include <cstdint>

const uint8_t letter[][8] = {
    {
        0b00111100,
        0b01100110,
        0b01100110,
        0b01100110,
        0b01111110,
        0b01100110,
        0b01100110,
        0b01100110,
    },
    {
        0b01111000,
        0b01101110,
        0b01100110,
        0b01101100,
        0b01111000,
        0b01101100,
        0b01100110,
        0b01111100,
    },
    {
        0b01111110,
        0b01111110,
        0b01100000,
        0b01100000,
        0b01100000,
        0b01100110,
        0b00111100,
    }};
int getCharacter(char letter);