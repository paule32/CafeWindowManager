#include <sys/time.h>

#include <cafewm.h>
#include <cafeprocessevent.h>
#include <cafewindow.h>
#include <cafedisplay.h>

namespace kallup {

#define FRAME_LEN    50000

#define MOUSE_LEFT   1
#define MOUSE_RIGHT  3
#define MOUSE_MIDDLE 2

#define MOUSE_SCROLL_UP   4
#define MOUSE_SCROLL_DOWN 5

static struct timeval st, rt;
static int delay(int i)
{
    struct timeval timeout;
    if (i>0) {
        timeout.tv_usec = i % (unsigned long) 1000000;
        timeout.tv_sec = i / (unsigned long) 1000000;
        select(0, nullptr, nullptr, nullptr, &timeout);
    }   return (i > 0 ? i : 0);
}

// -----------------------------------------
// these two functions for relax the cpu ...
// -----------------------------------------
static int time_diff(void)
{
    int diff;
    gettimeofday(&rt, nullptr);
    diff = (1000000*(rt.tv_sec-st.tv_sec))+(rt.tv_usec-st.tv_usec);
    st = rt;
    return diff;
}

CafeProcessEvent::CafeProcessEvent() { }
CafeProcessEvent::CafeProcessEvent(CafeWindow *win)
{
    int quit = 0;
    int pause = 0;
    int td;
    setWindow(win);
    gettimeofday(&st, nullptr);
    while (!quit) {
        // +++ timer start +++ //
        gettimeofday(&rt, nullptr);
        td = time_diff();
        pause = delay(FRAME_LEN - td + pause);
        st = rt;
        // +++ timer end +++ //
        eventLoop();
    }
}

CafeWindow * CafeProcessEvent::window() const { return w; }
void CafeProcessEvent::setWindow(CafeWindow *v) { w = v; }

int CafeProcessEvent::eventLoop()
{
    XEvent xev;
    int num_events;
    
    XFlush(
        window ()->
        display()->display_device);
    num_events =
    XPending(
        window ()->
        display()->display_device);
    
    while (num_events != 0) {
        num_events--;
        XNextEvent(
            window ()->
            display()->display_device, &xev);
        processEvent(xev);
    }
    
    return 0;
}

int CafeProcessEvent::processEvent(XEvent xev)
{
    KeySym key;
    char buffer[128] = {0};
    int  buffer_size = 128;
    
    char position[50] = {0};
    
    switch (xev.type) {
    case KeyPress:
        key = XLookupKeysym (&xev.xkey, 0);
        XLookupString (&xev.xkey,
            buffer,
            buffer_size, &key, nullptr);
        if (strlen(buffer) != 0
        && buffer[0] != '\n'
        && buffer[0] != '\r')
            std::cout
            <<  "Key-Event pressed: "
            <<  buffer
            <<  " (keycode: "
            <<  XKeysymToKeycode(
                window ()->
                display()->display_device, key)
            <<  ")"
            <<  std::endl;
        else
            std::cout
            <<  "Key-Event pressed: "
            <<  XKeysymToString(key)
            <<  " (keycode: "
            <<  XKeysymToKeycode(
                window ()->
                display()->display_device, key)
            <<  ")"
            <<  std::endl;
        break;
        
    case KeyRelease:
        std::cout << "key released" << std::endl;
        break;
        
    case ButtonPress:
        switch (xev.xbutton.button) {
            case MOUSE_LEFT:
                sprintf(position, "(X,Y) = (%d,%d).",
                    xev.xmotion.x,
                    xev.xmotion.y);
                std::cout
                << "left mouse pressed at: "
                << position
                << std::endl;
                break;
                
            case MOUSE_RIGHT:
                sprintf(position, "(X,Y) = (%d,%d).",
                    xev.xmotion.x,
                    xev.xmotion.y);
                std::cout
                << "right mouse pressed at: "
                << position
                << std::endl;
                break;
                
            case MOUSE_MIDDLE:
                sprintf(position, "(X,Y) = (%d,%d).",
                    xev.xmotion.x,
                    xev.xmotion.y);
                std::cout
                << "middle mouse pressed at: "
                << position
                << std::endl;
                break;

            case MOUSE_SCROLL_UP:
                sprintf(position, "(X,Y) = (%d,%d).",
                    xev.xmotion.x,
                    xev.xmotion.y);
                std::cout
                << "middle mouse pressed/scroll-up at: "
                << position
                << std::endl;
                break;
                
            case MOUSE_SCROLL_DOWN:
                sprintf(position, "(X,Y) = (%d,%d).",
                    xev.xmotion.x,
                    xev.xmotion.y);
                std::cout
                << "middle mouse pressed/scroll-down at: "
                << position
                << std::endl;
                break;
                                
            default:
                break;
        }
        std::cout << "mouse event pressed" << std::endl;
        break;
    case ButtonRelease:
        switch (xev.xbutton.button) {
            case MOUSE_LEFT:
                sprintf(position, "(X,Y) = (%d,%d).",
                    xev.xmotion.x,
                    xev.xmotion.y);
                std::cout
                << "left mouse release at: "
                << position
                << std::endl;
                break;
                
            case MOUSE_RIGHT:
                sprintf(position, "(X,Y) = (%d,%d).",
                    xev.xmotion.x,
                    xev.xmotion.y);
                std::cout
                << "right mouse release at: "
                << position
                << std::endl;
                break;
                
            case MOUSE_MIDDLE:
                sprintf(position, "(X,Y) = (%d,%d).",
                    xev.xmotion.x,
                    xev.xmotion.y);
                std::cout
                << "middle mouse release at: "
                << position
                << std::endl;
                break;

            default:
                break;
        }
        std::cout << "mouse event release" << std::endl;
        break;
    
    case EnterNotify:
        XSetInputFocus(
            window ()->
            display()->display_device,
            window ()->window(),
            RevertToParent,
            CurrentTime);
        std::cout
        << "mouse pointer 'enter' window"
        << std::endl;
        break;
        
    case LeaveNotify:
        XSetInputFocus(
            window ()->
            display()->display_device,
            window ()->window(),
            RevertToParent,
            CurrentTime);
        std::cout
        << "mouse pointer 'leave' window"
        << std::endl;
        break;
    
    case Expose:
        std::cout
        << "screen should new paint"
        << std::endl;
        window()->drawGraphics();
        break;
        
    default:
        break;
    }
    
    return 0;
}

CafeProcessEvent::~CafeProcessEvent()
{
}

}  // namespace: kallup