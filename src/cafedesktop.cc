#include <cafewm.h>
#include <cafedesktop.h>
#include <cafewindow.h>

namespace kallup  {
XVisualInfo  current_vinfo  ;
Visual     * current_visual ;
int          current_screen ;
int          current_depth  ;
CafeWindow * current_window ;
Display    * current_display;
CafeDesktop::CafeDesktop(CafeDisplay * displ)
{
    root_window = new CafeWindow;
    display = displ;

    if (!XMatchVisualInfo (display->display_device, 0, 32, TrueColor, &current_vinfo))
    if (!XMatchVisualInfo (display->display_device, 0, 24, TrueColor, &current_vinfo))
    if (!XMatchVisualInfo (display->display_device, 0, 16, TrueColor, &current_vinfo)) {
        std::cout
        << "Cannot get TrueColor Visual!"
        << std::endl;
        exit(EXIT_FAILURE);
    }
    current_visual = current_vinfo.visual;
    current_depth  = current_vinfo.depth;
    current_screen = current_vinfo.screen;
 
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
    root_desktop->setDisplay(display);
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
    current_window  = root_desktop;
    current_display = root_desktop->display()->display_device;
    
    //
    root_window->win_id++;
    root_desktop->setFlags(PSize | PMinSize | PMaxSize);
    
    root_desktop->setMinWidth(800);
    root_desktop->setMaxWidth(800);
    
    root_desktop->setMinHeight(600);
    root_desktop->setMaxHeight(600);
    
    XSizeHints hints_flags = root_desktop->hintsFlags();
    XSetStandardProperties(
        display->display_device,
        root_desktop->window(),
        "TestWindow",
        "",
        None, 0,0, &hints_flags);

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
    if (root_desktop->display() != nullptr)
    delete root_desktop->display();
    delete root_desktop;
    
    if (root_window->display() != nullptr)
    delete root_window->display();
    delete root_window;
}

}  // namespace: kallup
