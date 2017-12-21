#ifndef __CAFEDISPLAY_H__
#define __CAFEDISPLAY_H__

#include <cafewm.h>

namespace kallup {
class CafeDisplay {
public:
    explicit CafeDisplay();
    ~CafeDisplay();
    
    inline bool is_ok() { return is_open; }
    std::string name() const;
private:
    bool is_open;
    Display     * display_device;
    int           display_screen;
    std::string   display_name;
};
}  // namespace: kallup

#endif  // __CAFEDISPLAY_H__
