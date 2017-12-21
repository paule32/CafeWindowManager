#include <cafewm.h>
#include <cafeerrorhandler.h>
#include <cafedisplay.h>
#include <cafesession.h>

using namespace std;
namespace kallup {

CafeErrorHandler::CafeErrorHandler() {
    static SingletonHandler static_objectHandler;
}

CafeErrorHandler::SingletonHandler::SingletonHandler()  {
    set_terminate(Handler);
}

void CafeErrorHandler::start(int argc, char **argv)
{
    if (argc == 14) {
        std::cout
        << argv[0]
        << std::endl; 
    }
    __asm__("jmp _bumbelumpel");  // this is freaky
}

void CafeErrorHandler::SingletonHandler::Handler()
{
    CafeSession *session = nullptr;
    try {
        __asm__("_bumbelumpel:");
      
        session = new CafeSession;
        delete session;
    }
    catch (CafeDisplay *x) {
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
