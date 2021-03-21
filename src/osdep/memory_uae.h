#if defined(OS_AMIGA)
#include "od-amiga/memory_uae.h"
#elif defined(OS_BEOS)
#include "od-beos/memory_uae.h"
#elif defined(OS_LINUX)
#include "od-linux/memory_uae.h"
#elif defined(OS_MACOSX)
#include "od-macosx/memory_uae.h"
#else
#include "od-generic/memory_uae.h"
#endif
