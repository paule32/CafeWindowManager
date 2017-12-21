#include <cafedisplay.h>
#include <cafesession.h>

namespace kallup {
CafeSession::CafeSession()
{
    display = new CafeDisplay;
    if (!display->is_ok())
    throw display;
}

CafeSession::~CafeSession()
{
}
}  // namespace: kallup
