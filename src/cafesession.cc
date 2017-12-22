#include <cafewm.h>
#include <cafedisplay.h>
#include <cafesession.h>
#include <cafedesktop.h>
#include <cafeprocessevent.h>

using namespace std;
namespace kallup {

CafeSession::CafeSession()
{
    auto * display = new CafeDisplay;
    if (!display->is_ok())
    throw display;
    
    desktop = new CafeDesktop(display);
    
    auto * event = new CafeProcessEvent(desktop->root_desktop);
    delete event;
}

CafeSession::~CafeSession()
{
std::cout << "session delete" << std::endl;

    delete desktop;
    delete display;
    
    std::cout << "Thank You, for using cafewm!" << std::endl
              << "Have a nice day."
              << std::endl;
    exit(0);
}
}  // namespace: kallup
