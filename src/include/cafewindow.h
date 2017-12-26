#ifndef __CAFEWINDOW_H__
#define __CAFEWINDOW_H__

#include <cafewm.h>
#include <caferect.h>
#include <cafedisplay.h>
#include <cafecolor.h>

// ---------------------------------------
// window structure for client desktop ... 
// ---------------------------------------
namespace kallup {
typedef int  hwnd;   // window handle number: HWND
extern  hwnd win_id;

class CafeColor;
class CafeDisplay;
class CafeWindow {
public:
    explicit CafeWindow();
    explicit CafeWindow(CafeDisplay*);
             CafeWindow(CafeWindow *);
            ~CafeWindow();
    
    // getter ...
    CafeRect  * pos() const;
    Window window() const;
    GC windowGC() const;
    hwnd HWND() const;
    
    CafeDisplay * display() const;
    CafeWindow  * parent () const;
    CafeColor   * backgroundColor() const;
    
    std::string title() const;
    
    int width () const;
    int height() const;
    
    XSizeHints hintsFlags();
    
    int minWidth();
    int maxWidth();
    
    int minHeight();
    int maxHeight();

    
    // setter ...
    void setWindow(Window);
    void setWindowGC(GC);
    void setParent(CafeWindow*);
    void setBackgroundColor(CafeColor*);
    void setBackgroundColor(int,int,int);

    void setDisplay(CafeDisplay*);
    void setTitle(std::string);
    void setHints();
    void setPos(CafeRect*);
    
    void setFlags(int);
    
    void setWidth (int);
    void setHeight(int);
   
    void setMinWidth(int);
    void setMaxWidth(int);
    
    void setMinHeight(int);
    void setMaxHeight(int);
    
    int  show();
    void drawGraphics();
    
private:
    Window        win;
    hwnd          win_hwnd;
    CafeWindow  * win_parent;
    GC            win_gc;
    CafeColor   * win_backgroundColor;
    std::string   win_title;
    CafeRect    * win_pos;
    XSizeHints    size_hints;
    CafeDisplay * display_object;
};
}  // namespace: kallup
#endif  // __CAFEWINDOW_H__
