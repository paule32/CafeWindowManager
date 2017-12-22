#include <cafewm.h>
#include <cafedesktop.h>

namespace kallup {
CafeDesktop::CafeDesktop(CafeDisplay * displ)
{
    root_window = new CafeWindow;
    display = displ;

    init();
}

CafeDesktop::CafeDesktop()
{
}

void CafeDesktop::init()
{
    root_window->setWindow(
    RootWindow(
        display->display_device,
        display->display_screen));
    
    root_desktop = new CafeWindow;
    root_desktop->display = display;
    root_desktop->setWindow(
    XCreateSimpleWindow(
        display->display_device,
        root_window->window(), 0, 0, 800,600, 5,
        BlackPixel(
            display->display_device,
            display->display_screen),
        WhitePixel(
            display->display_device,
            display->display_screen) ));
            
    root_desktop->size_hints.flags = PSize | PMinSize | PMaxSize;
    root_desktop->size_hints.min_width  = 800;
    root_desktop->size_hints.max_width  = 800;
    root_desktop->size_hints.min_height = 600;
    root_desktop->size_hints.max_height = 600;
    
    XSetStandardProperties(
        display->display_device,
        root_desktop->window(),
        "TestWindow",
        "",
        None, 0,0, &root_desktop->size_hints);

    // set needed events ...
    XSelectInput(
        display->display_device,
        root_desktop->window(),
        ButtonPressMask | ButtonReleaseMask |
        KeyPressMask    | KeyReleaseMask    |
        EnterWindowMask | LeaveWindowMask   | ExposureMask);
        
    root_desktop->showModal();
}

CafeDesktop::~CafeDesktop()
{
    if (root_desktop->display != nullptr)
    delete root_desktop->display;
    delete root_desktop;
    
    if (root_window->display != nullptr)
    delete root_window->display;
    delete root_window;
}

}  // namespace: kallup
