#ifndef __CAFEDESKTOP_H__
#define __CAFEDESKTOP_H__

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
