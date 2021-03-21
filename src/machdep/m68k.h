#if defined(MACHINE_68K)
#include "md-68k/m68k.h"
#elif defined(MACHINE_I386_GCC)
#include "md-i386-gcc/m68k.h"
#elif defined(MACHINE_PPC)
#include "md-ppc/m68k.h"
#elif defined(MACHINE_AMD64_GCC)
#include "md-amd64-gcc/m68k.h"
#elif defined(MACHINE_PPC_GCC)
#include "md-ppc-gcc/m68k.h"
#elif defined(MACHINE_X86_GCC)
#include "md-x86-gcc/m68k.h"
#else
#include "md-generic/m68k.h"
#endif
