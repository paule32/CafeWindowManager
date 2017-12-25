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
    CafeProcessEvent * event   = nullptr;
    
    CafeDisplay      * display = nullptr;
    CafeWindow       * desktop = nullptr;
    CafeWindow       * rootwin = nullptr;
    
    display = new CafeDisplay(this);
    rootwin = new CafeWindow(display);
    desktop = new CafeWindow(rootwin);
    printf("jopster\n");
    event   = new CafeProcessEvent(desktop);
    delete event;
}

CafeSession::~CafeSession()
{   
    std::cout << "Thank You, for using cafewm!" << std::endl
              << "Have a nice day."
              << std::endl;
    exit(0);
}
}  // namespace: kallup
