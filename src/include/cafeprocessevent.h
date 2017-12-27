#ifndef __CAFEPROCESSEVENT_H__
#define __CAFEPROCESSEVENT_H__

#include <cafewm.h>
#include <cafewindow.h>

namespace kallup {
class CafeProcessEvent {
public:
    explicit CafeProcessEvent();
    explicit CafeProcessEvent(CafeWindow*);
            ~CafeProcessEvent();
    
    // getter ...        
    CafeWindow * window() const;
    
    // setter ...
    void setWindow(CafeWindow*);
    void startEventLoop();

private:    
    int eventLoop();
    int processEvent(XEvent);

    CafeWindow * win;
};

}

#endif  // __CAFEPROCESSEVENT_H__
