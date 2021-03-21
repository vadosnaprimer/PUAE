#if defined(OS_AMIGA)
#include "od-amiga/hrtimer.h"
#elif defined(OS_BEOS)
#include "od-beos/hrtimer.h"
#elif defined(OS_LINUX)
#include "od-linux/hrtimer.h"
#elif defined(OS_MACOSX)
#include "od-macosx/hrtimer.h"
#else
#include "od-generic/hrtimer.h"
#endif
