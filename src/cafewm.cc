#include <cafewm.h>
#include <cafeerrorhandler.h>

kallup::CafeErrorHandler object_ExceptionHandler;
int main(int argc, char **argv) {
    object_ExceptionHandler.start(argc, argv);
    return 0;
}

