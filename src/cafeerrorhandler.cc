#include <cafewm.h>
#include <cafeerrorhandler.h>
#include <cafedisplay.h>

using namespace std;
namespace kallup {

CafeErrorHandler::CafeErrorHandler()
{
    static SingletonHandler static_objectHandler;
}

CafeErrorHandler::SingletonHandler::SingletonHandler()  {
    set_terminate(Handler);
}

void CafeErrorHandler::SingletonHandler::Handler()
{
    try {
        //float x = 1.2;
        //throw x;
    }
    catch (CafeDisplay x) {
        std::cout << "DisplayException"
                  << std::endl;
    }
    catch (double x) {
        std::cout << "DoubleFloatingPointException"
                  << std::endl;
    }
    catch (float x) {
        std::cout << "FloatingPointException"
                  << std::endl;
    }
    catch (...) {
        std::cout << "Unknown Exception"
                  << std::endl;
    }
    
    abort();
    //pthread_exit();
}

}  // namespace; kallup
