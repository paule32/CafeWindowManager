#include <cafewm.h>
#include <cafedesktop.h>
#include <cafewindow.h>
#include <cafedisplay.h>

namespace kallup  {
CafeWindow * current_window ;
CafeDesktop::CafeDesktop(CafeDisplay * displ)
{
    XVisualInfo vinfo;
    setDisplay(displ);
        
    if (!XMatchVisualInfo(display()->display(), 0, 32, TrueColor, &vinfo))
    if (!XMatchVisualInfo(display()->display(), 0, 24, TrueColor, &vinfo))
    if (!XMatchVisualInfo(display()->display(), 0, 16, TrueColor, &vinfo))
    {
        std::cout
        << "Cannot get TrueColor Visual!"
        << std::endl;
        exit(EXIT_FAILURE);
    }
    
    display()->setVisual(vinfo.visual);
    display()->setDepth (vinfo.depth );
    display()->setScreen(vinfo.screen);

    root_window = new CafeWindow;
 
    init();
}

CafeDesktop::CafeDesktop()
{
}

CafeDisplay * CafeDesktop::display() const { return display_class; }

void CafeDesktop::init()
{
    root_window->setWindow(
    XRootWindow(
        display()->display(),
        display()->screen()));
    
    root_desktop = new CafeWindow;
    root_desktop->setDisplay(display());
    
    root_desktop->setWidth (800);
    root_desktop->setHeight(600);
    
    root_desktop->setWindow(
        XCreateSimpleWindow(
            display()->display(),
            root_window ->window(), 0, 0,
            root_desktop->width (),
            root_desktop->height(), 5,
        BlackPixel(
            display()->display(),
            display()->screen ()),
        WhitePixel(
            display()->display(),
            display()->screen ()) ));
//  current_window  = root_desktop;
//  current_display = root_desktop->display()->display_device;
    
    //
    root_window->win_id++;
    root_desktop->setFlags(PSize | PMinSize | PMaxSize);
    
    root_desktop->setMinWidth(800);
    root_desktop->setMaxWidth(800);
    
    root_desktop->setMinHeight(600);
    root_desktop->setMaxHeight(600);
    
    XSizeHints hints_flags = root_desktop->hintsFlags();
    XSetStandardProperties(
        display()->display(),
        root_desktop->window(),
        "TestWindow",
        "",
        None, 0,0, &hints_flags);

    // set needed events ...
    XSelectInput(
        display()->display(),
        root_desktop->window(),
        ButtonPressMask | ButtonReleaseMask |
        KeyPressMask    | KeyReleaseMask    |
        EnterWindowMask | LeaveWindowMask   | ExposureMask);
        
    
    int xpos = 0;
    int ypos = root_desktop->height();
    int wpos = root_desktop->width ();
    int hpos = 40;
    
    root_taskbar = new CafeWindow;
    root_taskbar->setDisplay(display());
    root_taskbar->setWindow(
        XCreateSimpleWindow(
        display()->display(),
        root_desktop->window(),
        xpos, ypos - hpos,
        wpos, hpos,
        5,
        BlackPixel(
            display()->display(),
            display()->screen()),
        WhitePixel(
            display()->display(),
            display()->screen()) ));
    
    
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
