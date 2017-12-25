#include <cafewindow.h>

namespace kallup {
hwnd win_id = 0;

CafeWindow::CafeWindow() { }
CafeWindow::CafeWindow(CafeDisplay *disp)
{
    setDisplay(disp);
    setWindow(        
        XCreateSimpleWindow(
        display()->display(),
        XRootWindow(
        display()->display(),
        display()->screen()),
        0, 0,
        display()->width (),
        display()->height(), 2,
    BlackPixel(
        display()->display(),
        display()->screen ()),
    WhitePixel(
        display()->display(),
        display()->screen ()) ));
        
   setHints();
   show();
}

CafeWindow::CafeWindow(CafeWindow *par_ent)
{
    setParent (par_ent);
    setDisplay(parent()->display());
    
    setWindow(
        XCreateSimpleWindow(
        display()->display(),
        parent ()->window (), 0, 0,
        parent ()->width  ()-2,
        parent ()->height ()-2, 1,
    BlackPixel(
        display()->display(),
        display()->screen ()),
    WhitePixel(
        display()->display(),
        display()->screen ()) ));
        
    setHints();
    show();
}

Window        CafeWindow::window  () const { return win;            }
GC            CafeWindow::windowGC() const { return win_gc;         }

CafeDisplay * CafeWindow::display () const { return display_object; }
CafeWindow  * CafeWindow::parent  () const { return win_parent;     }

std::string   CafeWindow::title   () const { return win_title;      }
hwnd          CafeWindow::HWND    () const { return win_hwnd;       }
CafeRect      CafeWindow::pos     () const { return win_pos;        }

void CafeWindow::setWindow(Window v) { win = v; }
void CafeWindow::setDisplay(CafeDisplay *v) { display_object = v; }

void CafeWindow::setTitle(std::string v) { win_title = v; }
void CafeWindow::setPos(CafeRect v) { win_pos = v; }
void CafeWindow::setWindowGC(GC v) { win_gc = v; }
void CafeWindow::setParent(CafeWindow *v) { win_parent = v; }

void CafeWindow::setWidth(int v)
{
    CafeRect rect;
    rect.setWidth(v);
}

void CafeWindow::setHeight(int v)
{
    CafeRect rect;
    rect.setHeight(v);
}

void CafeWindow::setFlags(int v) { size_hints.flags = v; }
void CafeWindow::setHints()
{
    setFlags(PSize | PMinSize | PMaxSize);
    
    setMinWidth(display()->width());
    setMaxWidth(display()->width());
    
    setMinHeight(display()->height());
    setMaxHeight(display()->height());
    
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

int CafeWindow::width () const { return pos().width (); }
int CafeWindow::height() const { return pos().height(); }

XSizeHints CafeWindow::hintsFlags() { return size_hints; }

CafeWindow::~CafeWindow() { }
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
//    if (!windowGC())
    win_gc = XCreateGC(
        display()->display(),
        window (),
        0,0);

    XWindowAttributes attrs;
    XGetWindowAttributes(
        display()->display(),
        window (),
        &attrs);

    // -----------------------
    // 0=root, 1=desktop, ...
    // -----------------------
//    if (HWND() == 0)
    {
        CafeColor col(this,0,100,150);
        XFillRectangle(
            display()->display(),
            window(),
            windowGC(),
            0, 0,
            attrs.width,
            attrs.height);
    
   
        CafeColor col2(this,120,120,150);
        XFillRectangle(
            display()->display(),
            window(),
            windowGC(),
            20, 20,
            200,200);
    }
    
    
    // --------------------------
    // clear, and free buffer ...
    // --------------------------
    XFlush (display()->display());
    XFreeGC(display()->display(), windowGC());
}

}  // namespace: kallup
