#include <cafewm.h>
#include <cafedisplay.h>

using namespace std;
namespace kallup {

CafeDisplay::CafeDisplay()
{
    setName(std::string(":0"));
    setOK(false);
    
    if (!(display_device = XOpenDisplay(nameASCII()))) {
        std::cout
        << "Error: can't open Display: "
        << XDisplayName(nameASCII())
        <<
        std::endl;
        return;
    }
    setScreen(XDefaultScreen(display()));
    setOK(true);
}

void CafeDisplay::setDisplay(Display *display) { display_device = display; }

void CafeDisplay::setVisual(Visual *v)   { display_visual = v; }
void CafeDisplay::setScreen(int v)       { display_screen = v; }
void CafeDisplay::setName(std::string v) { display_name   = v; }
void CafeDisplay::setDepth(int v)        { display_depth  = v; }
void CafeDisplay::setOK(bool v)          { display_open   = v; }

char*CafeDisplay::nameASCII() const { return (char*)display_name.c_str(); }
int  CafeDisplay::screen   () const { return display_screen; }
bool CafeDisplay::isOK     () const { return display_open  ; }

Visual  * CafeDisplay::visual () const { return display_visual; }
Display * CafeDisplay::display() const { return display_device; }
int       CafeDisplay::depth  () const { return display_depth ; }

void CafeDisplay::close()
{
    XCloseDisplay(display());
}

CafeDisplay::~CafeDisplay()
{
    close();
}

}  // namespace: kallup
