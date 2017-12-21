#include <cafewm.h>
#include <cafesession.h>
#include <cafeerrorhandler.h>

using namespace std;
using namespace kallup;

CafeErrorHandler object_ExceptionHandler;
CafeSession *session;

int main(int argc, char **argv)
{
    if (argc == 14) {
        std::cout
        << argv[0]
        << std::endl; 
    }
    
    auto *session = new CafeSession;
    delete session;
}

