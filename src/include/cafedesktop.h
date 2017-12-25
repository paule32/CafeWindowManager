#ifndef __CAFEDESKTOP_H__
#define __CAFEDESKTOP_H__

#if 0
#include <cafewm.h>
#include <cafedisplay.h>
#include <cafewindow.h>
#include <cafewindowlist.h>

// ---------------------------
// the desktop of a client ...
// ---------------------------
namespace kallup {
class CafeDisplay;
class CafeWindow;
class CafeWindowList;
class CafeDesktop {
public:
    explicit CafeDesktop();
    explicit CafeDesktop(CafeDisplay*);
    explicit CafeDesktop(CafeWindow *);
            ~CafeDesktop();
    
    std::list<CafeWindowList> windows;

    CafeDisplay * display() const;
    CafeWindow  * rootwin() const;
    CafeWindow  * desktop() const;
    CafeWindow  * taskbar() const;
    
    void setDisplay(CafeDisplay*);
    
    void setDesktop   (CafeWindow *);
    void setTaskbar   (CafeWindow *);
    void setRootWindow(CafeWindow *);
    
private:
    CafeDisplay * display_class;
    CafeWindow  * root_window;
    CafeWindow  * root_desktop;
    CafeWindow  * root_taskbar;
    
private:
    void init();
};
}  // namespace: kallup
#endif
#endif  // __CAFEDESKTOP_H__
