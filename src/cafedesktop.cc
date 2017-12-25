#include <cafedesktop.h>

#if 0
namespace kallup  {
CafeDesktop::CafeDesktop(CafeWindow *win)
{
    setRootWindow(win);
    setDisplay(win->display());
    root_window  = win;
}

CafeDesktop::CafeDesktop(CafeDisplay * displ)
{
    setDisplay(displ);
        printf("56666jsadkldkjlas6\n");
    root_window  = new CafeWindow(display());
        printf("566666\n");
    
    root_window->setWidth (800);
    root_window->setHeight(600);
    printf("566666\n");
    root_window->setMinWidth(root_window->width());
    root_window->setMaxWidth(root_window->width());
    
    root_window->setMinHeight(root_window->height());
    root_window->setMaxHeight(root_window->height());
    root_window->setHints();
    
        printf("566666\n");
    
    root_desktop = new CafeWindow(root_window );  win_id++;
    root_taskbar = new CafeWindow(root_desktop);  win_id++;
    
    init();
}

CafeDesktop::CafeDesktop()
{
}

CafeDisplay * CafeDesktop::display() const { return display_class; }

CafeWindow  * CafeDesktop::rootwin() const { return root_window ; }
CafeWindow  * CafeDesktop::desktop() const { return root_desktop; }
CafeWindow  * CafeDesktop::taskbar() const { return root_taskbar; }

void CafeDesktop::setDisplay   (CafeDisplay *v) { display_class = v; }
void CafeDesktop::setRootWindow(CafeWindow  *v) { root_window   = v; }
void CafeDesktop::setDesktop   (CafeWindow  *v) { root_desktop  = v; }
void CafeDesktop::setTaskbar   (CafeWindow  *v) { root_taskbar  = v; }

void CafeDesktop::init()
{
    win_id++;
    printf("dsdsd\n");
    /*
    root_taskbar->setMinWidth(200);
    root_taskbar->setMaxWidth(400);
    
    root_taskbar->setMinHeight(20);
    root_taskbar->setMaxHeight(60);
    
    XSizeHints hints_flags2 = root_taskbar->hintsFlags();
    XSetStandardProperties(
        display()->display(),
        root_taskbar->window(),
        "TestWindow2",
        "",
        None, 0,0, &hints_flags2);
            
    // set needed events ...
    XSelectInput(
        display()->display(),
        root_taskbar->window(),
        ButtonPressMask | ButtonReleaseMask |
        KeyPressMask    | KeyReleaseMask    |
        EnterWindowMask | LeaveWindowMask   | ExposureMask);

    XMapWindow(
        display()->display(),
        root_taskbar->window());
        */
}

CafeDesktop::~CafeDesktop()
{
    if (root_desktop->display() != nullptr)
    delete root_desktop->display();
    delete root_desktop;
    
    if (root_window->display() != nullptr)
    delete root_window->display();
    delete root_window;
}

}  // namespace: kallup
#endif
