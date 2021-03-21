#if defined(THREAD_AMIGAOS)
#include "td-amigaos/thread.h"
#elif defined(THREAD_BEOS)
#include "td-beos/thread.h"
#elif defined(THREAD_NONE)
#include "td-none/thread.h"
#elif defined(THREAD_SDL)
#include "td-sdl/thread.h"
#else
#include "td-posix/thread.h"
#endif
