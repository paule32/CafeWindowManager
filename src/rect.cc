#include <cafewm.h>

namespace kallup {
CafeRect::CafeRect()
{
    // initial values ...
    pos_x = 0;
    pos_y = 0;
    pos_w = 0;
    pos_h = 0;
}

// getter ...
int CafeRect::x()      const { return pos_x; }
int CafeRect::y()      const { return pos_y; }
int CafeRect::width()  const { return pos_width; }
int CafeRect::height() const { return pos_height; }

// setter ...
void CafeRect::setX(int v)      { pos_x = v; }
void CafeRect::setY(int v)      { pos_y = v; }
void CafeRect::setWidth(int v)  { pos_width = v; }
void CafeRect::setHeight(int v) { pos_height = v; }

}  // namespace: kallup

