#include <cafewm.h>
#include <cafedisplay.h>

using namespace std;
namespace kallup {

CafeDisplay::CafeDisplay()
{
    display_name = std::string(":0");
    is_open = false;
    
    if (!(display_device = ::XOpenDisplay(display_name.c_str()))) {
        std::cout
        << "Error: can't open Display: "
        << XDisplayName(display_name.c_str())
        <<
        std::endl;
        is_open = false;
        return;
    }
    display_screen = XDefaultScreen(display_device);
    is_open = true;
}

CafeDisplay::~CafeDisplay()
{
    XCloseDisplay(display_device);
}

}  // namespace: kallup
