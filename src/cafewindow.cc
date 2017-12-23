#include <cafewm.h>
#include <caferect.h>
#include <cafewindow.h>
#include <cafecolor.h>

namespace kallup {
extern CafeWindow * current_window;

CafeWindow::CafeWindow() { }

int CafeWindow::win_id = 0;

Window        CafeWindow::window  () const { return win;            }
GC            CafeWindow::windowGC() const { return win_gc;         }
CafeDisplay * CafeWindow::display () const { return display_object; }

std::string   CafeWindow::title   () const { return win_title;      }
hwnd          CafeWindow::HWND    () const { return win_hwnd;       }
CafeRect      CafeWindow::pos     () const { return win_pos;        }

void CafeWindow::setWindow(Window v) { win = v; }
void CafeWindow::setDisplay(CafeDisplay *v) { display_object = v; }

void CafeWindow::setTitle(std::string v) { win_title = v; }
void CafeWindow::setPos(CafeRect v) { win_pos = v; }
void CafeWindow::setWindowGC(GC v) { win_gc = v; }

void CafeWindow::setFlags(int v) { size_hints.flags = v; }

void CafeWindow::setMinWidth(int v) { size_hints.min_width = v; }
void CafeWindow::setMaxWidth(int v) { size_hints.max_width = v; }

void CafeWindow::setMinHeight(int v) { size_hints.min_height = v; }
void CafeWindow::setMaxHeight(int v) { size_hints.max_height = v; }

int CafeWindow::minWidth() { return size_hints.min_width; }
int CafeWindow::maxWidth() { return size_hints.max_width; }

int CafeWindow::minHeight() { return size_hints.min_height; }
int CafeWindow::maxHeight() { return size_hints.max_height; }

XSizeHints CafeWindow::hintsFlags() { return size_hints; }


CafeWindow::~CafeWindow() { }

int CafeWindow::showModal()
{
    XMapWindow(
    display()->display_device,
    window());

    return 0;
}

void CafeWindow::drawGraphics()
{
    //if (windowGC() == nullptr)
    win_gc = XCreateGC(
        display()->display_device,
        window (),
        0,0);
    current_window = this;

    // -----------------------
    // 0=root, 1=desktop, ...
    // -----------------------
    if (HWND() == 0) {
        CafeColor col(0,255,100);
        XFillRectangle(
            display()->display_device,
            window(),
            windowGC(),
            0, 0,
            200,200);
    }
    
    // --------------------------
    // clear, and free buffer ...
    // --------------------------
    XFlush (display()->display_device);
    XFreeGC(display()->display_device, windowGC());
}

}  // namespace: kallup
