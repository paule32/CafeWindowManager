#ifndef __CAFEWINDOW_H__
#define __CAFEWINDOW_H__

#include <cafewm.h>
#include <caferect.h>
#include <cafedisplay.h>

// ---------------------------------------
// window structure for client desktop ... 
// ---------------------------------------
namespace kallup {
class CafeWindow {
public:
    explicit CafeWindow();
    ~CafeWindow();
    
    CafeRect pos() const;
    Window window() const;
    void setWindow(Window);
    
    int showModal();

    Window        win;
    std::string   win_title;
    CafeRect      win_pos;
    
    XSizeHints    size_hints;
    CafeDisplay * display;
};
}  // namespace: kallup
#endif  // __CAFEWINDOW_H__
