#ifndef __CAFEWM_H__
#define __CAFEWM_H__

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xcursorfont.h>
#include <X11/XIntrinsic.h>
#include <X11/Xproto.h>
#include <X11/Xatom.h>
#include <X11/Xresource.h>
#include <X11/xpm.h>

#include <iostream>
#include <string>
#include <list>

namespace kallup {
class CafeDisplay {
public:
    explicit CafeDisplay();
    bool is_ok() const;
private:
    bool is_open;
};

class CafeSession {
public:
    explicit CafeSession();
    ~CafeSession();
private:
    CafeDisplay *display;
};

//
// helper classes ...
//
class CafeRect {
public:
    CafeRect() { };
    
    // getter ...
    int x() const;
    int y() const;
    int width() const;
    int height() const;
    
    // setter ...
    void setX(int) const;
    void setY(int) const;
    void setWidth(int) const;
    void setHeight(int) const;
    
private:
    int pos_x;
    int pos_y;
    int pos_w;
    int pos_h;
};

// ---------------------------------------
// window structure for client desktop ... 
// ---------------------------------------
class CafeWindow {
public:
    explictit CafeWindow();
    CafeRect pos() const;
private:
    Window      win;
    std::string win_title;
    CafeRect    win_pos;
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

// ---------------------------
// the desktop of a client ...
// ---------------------------
class CafeDesktop {
public:
    std::list<CafeWindowList> windows;
};
}  // namespace: kallup

#endif  // __CAFEWM_H__
