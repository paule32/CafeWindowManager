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

    CafeDisplay * display;
    CafeWindow  * root_window;
    CafeWindow  * root_desktop;
    
private:
    void init();
};
}  // namespace: kallup
#endif  // __CAFEDESKTOP_H__
