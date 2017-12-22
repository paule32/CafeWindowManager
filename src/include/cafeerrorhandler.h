#ifndef __CAFEERRORHANDLER_H__
#define __CAFEERRORHANDLER_H__

#include <cafewm.h>

namespace kallup {
class CafeErrorHandler {
private:
    class SingletonHandler {
    public:
        SingletonHandler();
        static void Handler();
    };
    
public:
    CafeErrorHandler();
    void start(int,char**);
}; // class: CafeErrorHandler

}  // namespace: kallup
#endif // __CAFEERRORHANDLER_H__
