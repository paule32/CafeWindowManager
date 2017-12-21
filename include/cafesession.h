#ifndef __CAFERECT_H__
#define __CAFERECT_H__

#include <cafewm.h>
#include <cafedisplay.h>

namespace kallup {
class CafeSession {
public:
    explicit CafeSession();
    ~CafeSession();
private:
    class CafeDisplay *display;
};
}  // namespace: kallup
#endif  // __CAFERECT_H__

