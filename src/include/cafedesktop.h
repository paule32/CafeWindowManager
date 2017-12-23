#ifndef __CAFEDESKTOP_H__
#define __CAFEDESKTOP_H__

#include <cafewm.h>
#include <cafedisplay.h>
#include <cafewindowlist.h>

// ---------------------------
// the desktop of a client ...
// ---------------------------
namespace kallup {
class CafeDesktop {
public:
    explicit CafeDesktop();
    explicit CafeDesktop(CafeDisplay*);
            ~CafeDesktop();
    
    std::list<CafeWindowList> windows;

    CafeDisplay * display() const;
    void setDisplay(CafeDisplay*);
    
private:
    CafeDisplay * display_class;
    CafeWindow  * root_window;
    CafeWindow  * root_desktop;
    CafeWindow  * root_taskbar;
    
private:
    void init();
};
}  // namespace: kallup
#endif  // __CAFEDESKTOP_H__
