#include "stdio.h"
#include "font.h"
#include "framebuffer.h"

using namespace std;

int main()
{

    Framebuffer fb;
    fb.drawChar('j', 0, 0);
    return 0;
}