#pragma once
#include <stdio.h>
#include <iostream>
#include <cstdint>

class Framebuffer
{
private:
    uint8_t framebuffer[2][512] = {0};
    int back = 0;
    int front = 1;

public:
    Framebuffer();
    void clear();
    int calcPage(int y);
    uint8_t *getBuffer() { return framebuffer[back]; }
    void setPixel(int x, int y, bool state);
    void drawLine(int x1, int y1, int x2, int y2);
    void drawRectangle(int x, int y, int length, int width);
    void drawSymPixels(int xc, int yc, int x, int y);
    void drawCircle(int xc, int yc, int r);
    int getCharacter(char letter);
    void drawChar(char character, int x, int y);
};