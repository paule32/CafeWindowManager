#include <cafewm.h>
#include <caferect.h>

namespace kallup {
CafeRect::CafeRect()
{
    // initial values ...
    pos_x = 0;
    pos_y = 0;
    pos_w = 0;
    pos_h = 0;
}

CafeRect::CafeRect(
    int x,
    int y,
    int w,
    int h)
{
    setX(x);
    setY(y);
    setWidth (w);
    setHeight(h);
}

// getter ...
int CafeRect::x()      const { return pos_x; }
int CafeRect::y()      const { return pos_y; }
int CafeRect::width()  const { return pos_w; }
int CafeRect::height() const { return pos_h; }

// setter ...
void CafeRect::setX(int v)      { pos_x = v; }
void CafeRect::setY(int v)      { pos_y = v; }
void CafeRect::setWidth(int v)  { pos_w = v; }
void CafeRect::setHeight(int v) { pos_h = v; }

}  // namespace: kallup

