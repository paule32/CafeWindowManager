#ifndef __CAFEDISPLAY_H__
#define __CAFEDISPLAY_H__

#include <cafewm.h>

namespace kallup {
class CafeDisplay {
public:
    explicit CafeDisplay();
    inline bool is_ok() { return is_open; }
    std::string name() const;
private:
    bool is_open;
    Display *dpy;
    std::string dsp_name;
};
}  // namespace: kallup

#endif  // __CAFEDISPLAY_H__
