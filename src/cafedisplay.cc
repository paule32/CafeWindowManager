#include <cafewm.h>

namespace kallup {
CafeDisplay::CafeDisplay(void)
{
    dsp_name  = std::string("localhost:0.0");
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

bool CafeDisplay::is_ok() { return is_open; }

}  // namespace: kallup
