#include <stdio.h>
#include "ssd1305.h"
#include "string.h"
#include "framebuffer.h"
#include "font.h"
#include <cstdlib>

using namespace std;

int main()
{
    stdio_init_all();
    ssd1305_init();
    Framebuffer fb;

    ssd1305_flush(fb.getBuffer());
}