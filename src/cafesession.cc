#include <cafewm.h>
#include <cafedisplay.h>
#include <cafesession.h>

using namespace std;
namespace kallup {

CafeSession::CafeSession()
{
    auto * display = new CafeDisplay;
    if (!display->is_ok())
    throw display;
}

CafeSession::~CafeSession()
{
    delete display;
    
    std::cout << "Thank You, for using cafewm!" << std::endl
              << "Have a nice day."
              << std::endl;
    exit(0);
}
}  // namespace: kallup
