#include <cafewm.h>
#include <cafedisplay.h>
#include <cafesession.h>
#include <cafedesktop.h>
#include <cafewindow.h>
#include <cafeprocessevent.h>

using namespace std;
namespace kallup {

CafeSession::CafeSession()
{  
    CafeDisplay      * display = nullptr;
    CafeWindow       * desktop = nullptr;
    CafeWindow       * rootwin = nullptr;
    
    display = new CafeDisplay(this);
    rootwin = new CafeWindow(display);
    desktop = new CafeWindow(rootwin);

    auto * event1 = new CafeProcessEvent(rootwin);
    auto * event2 = new CafeProcessEvent(desktop);

    event2->startEventLoop();

    delete event2;
    delete event1;
}

CafeSession::~CafeSession()
{   
    std::cout << "Thank You, for using cafewm!" << std::endl
              << "Have a nice day."
              << std::endl;
    exit(0);
}
}  // namespace: kallup
