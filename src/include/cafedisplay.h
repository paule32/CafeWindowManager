#ifndef __CAFEDISPLAY_H__
#define __CAFEDISPLAY_H__

#include <cafewm.h>
#include <cafesession.h>
#include <cafedisplay.h>

namespace kallup {
class CafeSession;
class CafeDisplay {
public:
    explicit CafeDisplay();
    explicit CafeDisplay(CafeSession*);
            ~CafeDisplay();
    
    bool   isOK() const;
    char * nameASCII() const;

    CafeSession * session() const;    
    Display     * display() const;
    int           screen () const;
    int           width  () const;
    int           height () const;
    Visual      * visual () const;
    int           depth  () const;
    
    void setDisplay(Display*);
    void setSession(CafeSession*);
    void setScreen(int);
    void setVisual(Visual*);
    void setWidth(int);
    void setHeight(int);
    void setDepth(int);
    void setName(std::string);
    void setName(char*);
    void setOK(bool);
    
    void close();
    
private:
    bool          display_open;
    CafeSession * display_session;
    Display     * display_device;
    int           display_screen;
    Visual      * display_visual;
    int           display_depth ;
    int           display_width ;
    int           display_height;
    std::string   display_name;
};
}  // namespace: kallup

#endif  // __CAFEDISPLAY_H__
