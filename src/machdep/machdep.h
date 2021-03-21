#if defined(MACHINE_68K)
#include "md-68k/machdep.h"
#elif defined(MACHINE_I386_GCC)
#include "md-i386-gcc/machdep.h"
#elif defined(MACHINE_PPC)
#include "md-ppc/machdep.h"
#elif defined(MACHINE_AMD64_GCC)
#include "md-amd64-gcc/machdep.h"
#elif defined(MACHINE_PPC_GCC)
#include "md-ppc-gcc/machdep.h"
#elif defined(MACHINE_X86_GCC)
#include "md-x86-gcc/machdep.h"
#else
#include "md-generic/machdep.h"
#endif
