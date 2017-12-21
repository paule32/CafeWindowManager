#include <cafewm.h>
#include <cafedisplay.h>

namespace kallup {
CafeDisplay::CafeDisplay()
{
    dsp_name  = std::string("localhost:0.0");
    is_open   = false;
    if (!(dpy = ::XOpenDisplay(dsp_name.c_str()))) {
        std::cout
        << "Error: can't open Display: "
        << ::XDisplayName(dsp_name.c_str())
        <<
        std::endl;
        is_open = false;
        return;
    }
    is_open = true;
}

}  // namespace: kallup
