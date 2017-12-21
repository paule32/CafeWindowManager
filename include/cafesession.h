#ifndef __CAFERECT_H__
#define __CAFERECT_H__

#include <cafewm.h>

namespace kallup {
class CafeSession {
public:
    explicit CafeSession();
    ~CafeSession();
private:
    CafeDisplay *display;
};
}  // namespace: kallup
#endif  // __CAFERECT_H__

