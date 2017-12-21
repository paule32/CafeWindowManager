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
}; // class: CafeErrorHandler

}  // namespace: kallup
