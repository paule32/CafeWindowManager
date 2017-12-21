#ifndef __CAFEDISPLAY_H__
#define __CAFEDISPLAY_H__

#include <cafewm.h>

namespace kallup {
class CafeDisplay {
public:
    explicit CafeDisplay(void);
    bool is_ok();
    std::string name() const;
private:
    bool is_open;
    Display *dpy;
    std::string dsp_name;
};
}  // namespace: kallup

#endif  // __CAFEDISPLAY_H__
