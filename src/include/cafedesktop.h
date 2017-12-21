#ifndef __CAFEDESKTOP_H__
#define __CAFEDESKTOP_H__

#include <cafewm.h>
#include <cafewindowlist.h>

// ---------------------------
// the desktop of a client ...
// ---------------------------
namespace kallup {
class CafeDesktop {
public:
    explicit CafeDesktop();
    std::list<CafeWindowList> windows;
};
}  // namespace: kallup
#endif  // __CAFEDESKTOP_H__
