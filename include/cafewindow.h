#ifndef __CAFEWINDOW_H__
#define __CAFEWINDOW_H__

#include <cafewm.h>
#include <caferect.h>

// ---------------------------------------
// window structure for client desktop ... 
// ---------------------------------------
namespace kallup {
class CafeWindow {
public:
    explicit CafeWindow();
    class CafeRect pos() const;
private:
    Window          win;
    std::string     win_title;
    class CafeRect  win_pos;
};

class CafeWindowList {
public:
    explicit CafeWindowList();
    class CafeWindow * win_title;
    class CafeWindow * win_icon;
    class CafeWindow * win_frame;
    class CafeWindow * win_child;
    class CafeWindow * win_parent;
};
}  // namespace: kallup
#endif  // __CAFEWINDOW_H__
