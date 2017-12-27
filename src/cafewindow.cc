#include <cafewindow.h>

#include <sstream>
#include <iomanip>

using namespace std;

namespace kallup {
hwnd win_id = 0;

CafeWindow::CafeWindow() { }
CafeWindow::CafeWindow(CafeDisplay *disp)
{
    setDisplay(disp);

    setWidth (display()->width ());
    setHeight(display()->height());

    setWindow(        
        XCreateSimpleWindow(
        display()->display(),
        XRootWindow(
        display()->display(),
        display()->screen()),
        0, 0,
        width (),
        height(), 2,
    BlackPixel(
        display()->display(),
        display()->screen ()),
    WhitePixel(
        display()->display(),
        display()->screen ()) ));
        
    win_gc = XCreateGC(
    display()->display(),
    XRootWindow (
    display()->display(),
    display()->screen()), 0,0);

    setBackgroundColor(new CafeColor(this,0,100,150));
    win_hwnd = win_id++;

    setHints();
    show();
}

CafeWindow::CafeWindow(CafeWindow *par_ent)
{
    setParent (par_ent);
    setDisplay(parent()->display());

    setWidth (200); //parent()->width ());
    setHeight(200); //parent()->height());

    setWindow(
        XCreateSimpleWindow(
        display()->display(),
        parent ()->window (), 40, 40,
        width  ()-2,
        height ()-2, 1,
    BlackPixel(
        display()->display(),
        display()->screen ()),
    WhitePixel(
        display()->display(),
        display()->screen ()) ));

    win_gc = XCreateGC(
    display()->display(),
    XRootWindow (
    display()->display(),
    display()->screen()), 0,0);

    setBackgroundColor(new CafeColor(this,220,180,180));
    win_hwnd = win_id++;
            
    setHints();
    show();
}

Window        CafeWindow::window  () const { return win;            }
GC            CafeWindow::windowGC() const { return win_gc;         }

CafeDisplay * CafeWindow::display () const { return display_object; }
CafeWindow  * CafeWindow::parent  () const { return win_parent;     }

std::string   CafeWindow::title   () const { return win_title;      }
hwnd          CafeWindow::HWND    () const { return win_hwnd;       }
CafeRect    * CafeWindow::pos     () const { return win_pos;        }

void CafeWindow::setWindow(Window v) { win = v; }
void CafeWindow::setDisplay(CafeDisplay *v) { display_object = v; }

void CafeWindow::setTitle(std::string v) { win_title = v; }
void CafeWindow::setPos(CafeRect *v) { win_pos = v; }
void CafeWindow::setWindowGC(GC v) { win_gc = v; }
void CafeWindow::setParent(CafeWindow *v) { win_parent = v; }

CafeColor * CafeWindow::backgroundColor() const {
    return win_backgroundColor;
}
void CafeWindow::setBackgroundColor(CafeColor *col)
{
    char buffer[24];
    unsigned long c;

    win_backgroundColor = col;
    win_backgroundColor->setRed  (col->red  ());
    win_backgroundColor->setGreen(col->green());
    win_backgroundColor->setBlue (col->blue ());

    sprintf(buffer,"0x00%02x%02x%02x",
        col->red(),
        col->green(),
        col->blue());
    
    std::stringstream ss;
    ss << std::setfill('0')
       << std::setw(10)
       << std::hex
       << buffer;
    ss >> c;

    XSetWindowBackground(
        display()->display(),
        window (),c);
}

void CafeWindow::setBackgroundColor(int r, int g, int b)
{
    win_gc = XCreateGC(
        display()->display(),
        window (),
        0,0);
    if (win_backgroundColor == nullptr)
        win_backgroundColor = new CafeColor(this,r,g,b); else
        win_backgroundColor->setColor(r,g,b);
}

void CafeWindow::setWidth(int v)
{
    if (win_pos == nullptr)
        win_pos = new CafeRect;

    pos()->setWidth(v);
}

void CafeWindow::setHeight(int v)
{
    if (win_pos == nullptr)
        win_pos = new CafeRect;

    pos()->setHeight(v);
}

void CafeWindow::setFlags(int v) { size_hints.flags = v; }
void CafeWindow::setHints()
{
    setFlags(PSize | PMinSize | PMaxSize);
    
    setMinWidth(width());
    setMaxWidth(width());
    
    setMinHeight(height());
    setMaxHeight(height());
    
    XSetStandardProperties(
    display()->display(),
    window(),
    "TestWindow","",
    None, 0,0, &size_hints);
    
    XSelectInput(
    display()->display(),
    window (),
    ButtonPressMask | ButtonReleaseMask |
    KeyPressMask    | KeyReleaseMask    |
    EnterWindowMask | LeaveWindowMask   | ExposureMask);
}

void CafeWindow::setMinWidth(int v) { size_hints.min_width = v; }
void CafeWindow::setMaxWidth(int v) { size_hints.max_width = v; }

void CafeWindow::setMinHeight(int v) { size_hints.min_height = v; }
void CafeWindow::setMaxHeight(int v) { size_hints.max_height = v; }

int CafeWindow::minWidth() { return size_hints.min_width; }
int CafeWindow::maxWidth() { return size_hints.max_width; }

int CafeWindow::minHeight() { return size_hints.min_height; }
int CafeWindow::maxHeight() { return size_hints.max_height; }

int CafeWindow::width () const { return pos()->width (); }
int CafeWindow::height() const { return pos()->height(); }

XSizeHints CafeWindow::hintsFlags() { return size_hints; }

CafeWindow::~CafeWindow()
{
    // ---------------------------------
    // clear, and free buffer ...
    // --------------------------
    XFlush (display()->display());
    XFreeGC(display()->display(), windowGC());
}

int CafeWindow::show()
{
    XMapWindow(
        display()->display(),
        window());
    drawGraphics();
    return 0;
}

void CafeWindow::drawGraphics()
{
    // -----------------------
    // 0=root, 1=desktop, ...
    // -----------------------
//    if (HWND() == 0)
    {
//        CafeColor col(this,0,100,150);

std::cout
<< "win: " << window  () << std::endl
<< "gc:  " << windowGC() << std::endl;
        XFillRectangle(
            display()->display(),
            window(),
            windowGC(),
            0, 0,
            width (),
            height());
    }
/*
        CafeColor col2(this,220,180,180);
        XFillRectangle(
            display()->display(),
            window(),
            windowGC(),
            12, 20,
            width()-100,
            200);*/

}

}  // namespace: kallup
