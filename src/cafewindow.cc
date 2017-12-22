#include <cafewm.h>
#include <caferect.h>
#include <cafewindow.h>

namespace kallup {
CafeWindow::CafeWindow() { }

Window CafeWindow::window() const { return win; }
void CafeWindow::setWindow(Window v) { win = v; }

CafeWindow::~CafeWindow() { }

int CafeWindow::showModal()
{
    XMapWindow(
    display->display_device,
    window());
    
    return 0;
}

}  // namespace: kallup
