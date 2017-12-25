#include <cafedisplay.h>

using namespace std;
namespace kallup {

CafeDisplay::CafeDisplay() { }
CafeDisplay::CafeDisplay(CafeSession *sess)
{
    XVisualInfo vinfo;
    
    setName(std::string(""));
    setOK(false);
    
    setDisplay(XOpenDisplay(nameASCII()));
    if (!display()) {
        std::cout
        << "Error: can't open Display" <<
        std::endl;
        return;
    }
    
    if (!XMatchVisualInfo(display(), 0, 32, TrueColor, &vinfo))
    if (!XMatchVisualInfo(display(), 0, 24, TrueColor, &vinfo))
    if (!XMatchVisualInfo(display(), 0, 16, TrueColor, &vinfo))
    {
        std::cout
        << "Cannot get TrueColor Visual!"
        << std::endl;
        exit(EXIT_FAILURE);
    }
    
    setVisual(vinfo.visual);
    setDepth (vinfo.depth );
    setScreen(vinfo.screen);
    
    setWidth (800);
    setHeight(600);

    setSession(sess);
    setOK(true);
}

void CafeDisplay::setDisplay(Display     *v) { display_device  = v; }
void CafeDisplay::setSession(CafeSession *v) { display_session = v; }

void CafeDisplay::setVisual(Visual *v)   { display_visual = v; }
void CafeDisplay::setScreen(int v)       { display_screen = v; }
void CafeDisplay::setName(std::string v) { display_name   = v; }

void CafeDisplay::setWidth (int v) { display_width  = v; }
void CafeDisplay::setHeight(int v) { display_height = v; }

void CafeDisplay::setDepth(int v)        { display_depth  = v; }
void CafeDisplay::setOK(bool v)          { display_open   = v; }

char*CafeDisplay::nameASCII() const { return (char*)display_name.c_str(); }
int  CafeDisplay::screen   () const { return display_screen; }
bool CafeDisplay::isOK     () const { return display_open  ; }

int  CafeDisplay::width () const { return display_width ; }
int  CafeDisplay::height() const { return display_height; }

Visual  * CafeDisplay::visual () const { return display_visual; }
Display * CafeDisplay::display() const { return display_device; }
int       CafeDisplay::depth  () const { return display_depth ; }

CafeSession *
CafeDisplay::session() const { return display_session; }

void CafeDisplay::close() {
    XCloseDisplay(display());
}

CafeDisplay::~CafeDisplay() {
    close();
}

}  // namespace: kallup
