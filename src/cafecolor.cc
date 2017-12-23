#include <cafewm.h>
#include <cafecolor.h>
#include <cafewindow.h>

#include <sstream>
#include <iomanip>

namespace kallup {
extern XVisualInfo  current_vinfo  ;
extern Visual     * current_visual ;
extern Screen       current_screen ;
extern CafeWindow * current_window ;
extern Display    * current_display;

CafeColor::CafeColor()
{
    // default: white ...
    //setColor(255,255,255);
}

CafeColor::CafeColor(
    int r,
    int g,
    int b)
{
    setColor(r,g,b);
}

XColor CafeColor::color() const { return color_intern; }

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
        current_window->display()->display_device,
        current_window->window(),
        current_visual,
        0);

    setRed  (v1);
    setGreen(v2);
    setBlue (v3);

    sprintf(buffer,
    "0x00%02x%02x%02x",
    red(),green(),blue());
    
    std::stringstream ss;
    ss << std::setfill('0')
       << std::setw(10)
       << std::hex
       << buffer;
    ss >> c;

    XSetForeground(
        current_window->display()->display_device,
        current_window->windowGC(),c);
}

}  // namespace: kallup
