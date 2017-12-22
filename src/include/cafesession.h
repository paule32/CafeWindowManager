#ifndef __CAFESESSION_H__
#define __CAFESESSION_H__

#include <cafewm.h>
#include <cafedisplay.h>
#include <cafedesktop.h>

namespace kallup {
class CafeSession {
public:
    explicit CafeSession();
    ~CafeSession();
private:
    CafeDisplay * display;
    CafeDesktop * desktop;
};
}  // namespace: kallup
#endif  // __CAFESESSION_H__

