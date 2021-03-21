#if defined(TARGET_AMIGA)
#include "targets/t-amiga.h"
#elif defined(TARGET_BEOS)
#include "targets/t-beos.h"
#else
#include "targets/t-unix.h"
#endif
