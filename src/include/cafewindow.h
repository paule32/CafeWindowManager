#ifndef __CAFEWINDOW_H__
#define __CAFEWINDOW_H__

#include <cafewm.h>
#include <caferect.h>
#include <cafedisplay.h>

// ---------------------------------------
// window structure for client desktop ... 
// ---------------------------------------
namespace kallup {
typedef int hwnd;   // window handle number: HWND

class CafeWindow {
public:
    explicit CafeWindow();
    ~CafeWindow();
    
    // getter ...
    CafeRect pos() const;
    Window window() const;
    GC windowGC() const;
    hwnd HWND() const;
    
    CafeDisplay * display() const;
    std::string title() const;
    
    XSizeHints hintsFlags();
    
    int minWidth();
    int maxWidth();
    
    int minHeight();
    int maxHeight();

    
    // setter ...
    void setWindow(Window);
    void setWindowGC(GC);

    void setDisplay(CafeDisplay*);
    void setTitle(std::string);
    void setPos(CafeRect);
    
    void setFlags(int);
   
    void setMinWidth(int);
    void setMaxWidth(int);
    
    void setMinHeight(int);
    void setMaxHeight(int);
    
    int showModal();
    void drawGraphics();

    static int    win_id;
    
private:
    Window        win;
    hwnd          win_hwnd;
    GC            win_gc;
    std::string   win_title;
    CafeRect      win_pos;
    XSizeHints    size_hints;
    CafeDisplay * display_object;
};
}  // namespace: kallup
#endif  // __CAFEWINDOW_H__
