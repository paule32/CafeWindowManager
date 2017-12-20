#include <iostream>
#include <cafewm.h>

using namespace std;
namespace kallup {
CafeWindow::CafeWindow()
{
    // inital values ...
    win_pos.pos_x = 0;
    win_pos.pos_y = 0;
    win_pos.pos_width = 0;
    win_pos.pos_height = 0;
}

CafeDisplay::CafeDisplay()
{
    if (!(dpy = ::XOpenDisplay(name))) {
        std::cout
        << "Error: can't open Display: "
        << ::XDisplayName(name)
        <<
        std::endl;
        is_open = false;
        return;
    }
    is_open = true;
}

CafeSession::CafeSession()
{
    display = new CafeDisplay;
    if (!display->is_ok()) {
        delete display;
        exit(1);
    }
}

CafeSession::~CafeSession()
{
}
}  // namespace: kallup

int main(int argc, char **argv)
{
    using namespace kallup;
    CafeSession *session = new CafeSession;
    delete session;
}

