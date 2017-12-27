#ifndef __CAFEWINDOWLIST_H__
#define __CAFEWINDOWLIST_H__

#include <cafewm.h>
#include <cafewindow.h>

// ---------------------------------------
// window structure list ...
// ---------------------------------------
namespace kallup {
class CafeWindow;
class CafeWindowList {
public:
    explicit CafeWindowList();

    CafeWindow * win_title;
    CafeWindow * win_icon;
    CafeWindow * win_frame;
    CafeWindow * win_child;
    CafeWindow * win_parent;
};
}  // namespace: kallup
#endif  // __CAFEWINDOWLIST_H__
