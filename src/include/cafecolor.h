#ifndef __CAFECOLOR_H__
#define __CAFECOLOR_H__

#include <cafewm.h>

namespace kallup {
class CafeColor {
public:
    explicit CafeColor();
    explicit CafeColor(
             int r,
             int g,
             int b);
    
    // getter ...
    XColor color() const;
    
    int red  () const;
    int green() const;
    int blue () const;
    
    // setter ...
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
    CafeColor   * color_object;
};
}  // namespace: kallup
#endif  // __CAFECOLOR_H__
