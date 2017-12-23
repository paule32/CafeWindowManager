#ifndef __CAFEDISPLAY_H__
#define __CAFEDISPLAY_H__

#include <cafewm.h>
#include <cafedisplay.h>

namespace kallup {
class CafeDisplay {
public:
    explicit CafeDisplay();
    ~CafeDisplay();
    
    bool   isOK() const;
    char * nameASCII() const;
    
    Display * display() const;
    int       screen () const;
    Visual  * visual () const;
    int       depth  () const;
    
    void setDisplay(Display*);
    void setScreen(int);
    void setVisual(Visual*);
    void setDepth(int);
    void setName(std::string);
    void setOK(bool);
    
    void close();
    
private:
    bool          display_open;
    Display     * display_device;
    int           display_screen;
    Visual      * display_visual;
    int           display_depth ;
    std::string   display_name;
};
}  // namespace: kallup

#endif  // __CAFEDISPLAY_H__
