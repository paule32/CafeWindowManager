#ifndef __CAFECOLOR_H__
#define __CAFECOLOR_H__

#include <cafewm.h>
#include <cafewindow.h>

namespace kallup {
class CafeWindow;
class CafeColor {
public:
    explicit CafeColor();
    explicit CafeColor(
             CafeWindow*,
             int r,
             int g,
             int b);
    
    // getter ...
    XColor color() const;
    CafeWindow * window() const;
    
    int red  () const;
    int green() const;
    int blue () const;
    
    // setter ...
    void setWindow(CafeWindow*);
    void setColor(XColor);
    void setColor(
            int r,
            int g,
            int b);
    
    void setRed  (int);
    void setGreen(int);
    void setBlue (int);
    
private:
    XColor        color_intern;
    Colormap      color_map;
    CafeWindow  * color_window;
    CafeColor   * color_object;
};
}  // namespace: kallup
#endif  // __CAFECOLOR_H__
