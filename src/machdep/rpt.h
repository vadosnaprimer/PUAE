#if defined(MACHINE_68K)
#include "md-68k/rpt.h"
#elif defined(MACHINE_I386_GCC)
#include "md-i386-gcc/rpt.h"
#elif defined(MACHINE_PPC)
#include "md-ppc/rpt.h"
#elif defined(MACHINE_AMD64_GCC)
#include "md-amd64-gcc/rpt.h"
#elif defined(MACHINE_PPC_GCC)
#include "md-ppc-gcc/rpt.h"
#elif defined(MACHINE_X86_GCC)
#include "md-x86-gcc/rpt.h"
#else
#include "md-generic/rpt.h"
#endif
