#include <cafedisplay.h>
#include <cafesession.h>

namespace kallup {
CafeSession::CafeSession()
{
    display = new CafeDisplay;
    if (!display->is_ok()) {
        delete display;
        exit(1);
    }
}

CafeSession::~CafeSession()
{
}
}  // namespace: kallup
