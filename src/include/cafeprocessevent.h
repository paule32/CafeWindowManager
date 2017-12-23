#ifndef __CAFEPROCESSEVENT_H__
#define __CAFEPROCESSEVENT_H__

#include <cafewm.h>
#include <cafewindow.h>

namespace kallup {
class CafeProcessEvent {
public:
    explicit CafeProcessEvent();
    explicit CafeProcessEvent(CafeWindow *);
    ~CafeProcessEvent();
    
    CafeWindow * window() const;
    void setWindow(CafeWindow*);

private:    
    int eventLoop();
    int processEvent(XEvent);
    
    CafeWindow * w;
};

}

#endif  // __CAFEPROCESSEVENT_H__
