#ifndef __CAFERECT_H__
#define __CAFERECT_H__

namespace kallup {
class CafeRect {
public:
    explicit CafeRect();
    
    // getter ...
    int x() const;
    int y() const;
    int width() const;
    int height() const;
    
    // setter ...
    void setX(int);
    void setY(int);
    void setWidth(int);
    void setHeight(int);
    
private:
    int pos_x;
    int pos_y;
    int pos_w;
    int pos_h;
};
}  // namespace: kallup
#endif  // __CAFERECT_H__
