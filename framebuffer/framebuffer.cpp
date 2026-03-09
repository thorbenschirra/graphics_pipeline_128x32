#include "framebuffer.h"
#include "string.h"
#include "font.h"

using namespace std;

Framebuffer::Framebuffer()
{
    memset(framebuffer, 0, sizeof(framebuffer));
}

void Framebuffer::clear()
{
    memset(framebuffer[back], 0, 512);
}

int Framebuffer::calcPage(int y)
{
    if (y < 0 || y > 32)
    {
        return -1;
    }
    return y / 8;
}

void Framebuffer::setPixel(int x, int y, bool state)
{
    if (x < 0 || x >= 128 || y < 0 || y >= 32)
    {
        return;
    }

    int byteIndex = x + (y / 8) * 128;
    int bitIndex = y % 8;

    uint8_t mask = 1 << bitIndex;

    if (state)
    {
        framebuffer[back][byteIndex] |= mask;
    }
    else
    {
        framebuffer[back][byteIndex] &= ~mask;
    }
}

void Framebuffer::drawLine(int x1, int y1, int x2, int y2)
{
    /* bresenhams line drawing algorithm */
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    /* step direction of x and y */
    int sx = (x2 > x1) ? 1 : -1;
    int sy = (y2 > y1) ? 1 : -1;
    cout << "SY: " << sy << " || ";

    /* angle - steep or shallow */
    bool steep = dy > dx;

    if (steep)
    {
        std::swap(x1, y1);
        std::swap(x2, y2);
        std::swap(dx, dy);
        std::swap(sx, sy);
    }

    int x = x1;
    int y = y1;
    int error = 2 * dy - dx;

    for (int i = 0; i <= dx; i++)
    {
        if (steep)
        {
            setPixel(y, x, true);
            cout << " | X: " << y << ", Y: " << x;
        }
        else
        {
            setPixel(x, y, true);
            cout << " | X: " << x << ", Y: " << y;
        }

        x += sx;
        if (error > 0)
        {
            y += sy;
            error += 2 * (dy - dx);
        }
        else
        {
            error += 2 * dy;
        }
    }
}

void Framebuffer::drawRectangle(int x, int y, int length, int width)
{
    int a = x + length;
    int b = y + width;
    drawLine(x, y, x + length, y);
    drawLine(x, y, x, y + width);
    drawLine(x, y + width, x + length, y + width);
    drawLine(x + length, y, x + length, y + width);
}

void Framebuffer::drawSymPixels(int xc, int yc, int x, int y)
{
    setPixel(xc + x, yc + y, true);
    setPixel(xc - x, yc + y, true);
    setPixel(xc + x, yc - y, true);
    setPixel(xc - x, yc - y, true);
    setPixel(xc + y, yc + x, true);
    setPixel(xc - y, yc + x, true);
    setPixel(xc + y, yc - x, true);
    setPixel(xc - y, yc - x, true);
}

void Framebuffer::drawCircle(int xc, int yc, int r)
{

    int x = 0;
    int y = r;
    int d = 3 - (2 * r);
    drawSymPixels(xc, yc, x, y);

    while (y >= x)
    {
        drawSymPixels(xc, yc, x, y);

        if (d < 0)
        {
            d = d + (4 * x) + 6;
            x++;
        }
        else
        {
            d = d + 4 * (x - y) + 10;
            y--;
            x++;
        }
    }
}

int Framebuffer::getCharacter(char letter)
{
    const char alphabet[25] = {
        'a',
        'b',
        'j'};

    for (int i = 0; i < 26; i++)
    {
        if (letter == alphabet[i])
        {
            cout << i;
            return i;
        }
    }

    return -1;
}

void Framebuffer::drawChar(char character, int x, int y)
{
    int intOfLetter = getCharacter(character);
    cout << " intOfLetter: " << intOfLetter << " Character: " << character << endl;
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            if (letter[intOfLetter][col] & (1 << (8 - 1 - col)))
            {
                setPixel(x + col, y + row, 1);
                cout << " X: " << col << " Y: " << row << " Value: " << 1 << endl;
            }
            else
            {
                setPixel(x + col, y + row, 0);
                cout << " X: " << col << " Y: " << row << " Value: " << 0 << endl;
            }
        }
    }
}