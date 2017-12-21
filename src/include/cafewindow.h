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
    CafeRect pos() const;
private:
    Window          win;
    std::string     win_title;
    CafeRect  win_pos;
};
}  // namespace: kallup
#endif  // __CAFEWINDOW_H__
