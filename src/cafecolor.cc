#include <cafecolor.h>

#include <sstream>
#include <iomanip>

namespace kallup {
CafeColor::CafeColor()
{
    // default: white ...
    //setColor(255,255,255);
}

CafeColor::CafeColor(
    CafeWindow *win,
    int r,
    int g,
    int b)
{
    setWindow(win);
    setColor(r,g,b);
    printf("5555\n");
}

XColor       CafeColor::color () const { return color_intern; }
CafeWindow * CafeColor::window() const { return color_window; }

void CafeColor::setWindow(CafeWindow *v) { color_window = v; }

void CafeColor::setColor(XColor v) { color_intern       = v; color_intern.flags = DoRed | DoBlue | DoGreen; }
void CafeColor::setRed  (int    v) { color_intern.red   = v; color_intern.flags = DoRed | DoBlue | DoGreen; }
void CafeColor::setBlue (int    v) { color_intern.blue  = v; color_intern.flags = DoRed | DoBlue | DoGreen; }
void CafeColor::setGreen(int    v) { color_intern.green = v; color_intern.flags = DoRed | DoBlue | DoGreen; }

int CafeColor::red  () const { return color_intern.red;   }
int CafeColor::blue () const { return color_intern.blue;  }
int CafeColor::green() const { return color_intern.green; }

void CafeColor::setColor(
    int v1,
    int v2,
    int v3)
{
    char buffer[20] = {0};
    unsigned long int c = 0;
    
    color_map = XCreateColormap(
        window()->display()->display(),
        window()->window (),
        window()->display()->visual(),
        0);

    setRed  (v1);
    setGreen(v2);
    setBlue (v3);

    sprintf(buffer,"0x00%02x%02x%02x",
    red(),green(),blue());
    
    std::stringstream ss;
    ss << std::setfill('0')
       << std::setw(10)
       << std::hex
       << buffer;
    ss >> c;
printf("88888\n");
    XSetForeground(
        window()->display()->display(),
        window()->windowGC(),c);
printf("98887\n");
}

}  // namespace: kallup
