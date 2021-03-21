#if defined(MACHINE_68K)
#include "md-68k/m68kops.h"
#elif defined(MACHINE_I386_GCC)
#include "md-i386-gcc/m68kops.h"
#elif defined(MACHINE_PPC)
#include "md-ppc/m68kops.h"
#elif defined(MACHINE_AMD64_GCC)
#include "md-amd64-gcc/m68kops.h"
#elif defined(MACHINE_PPC_GCC)
#include "md-ppc-gcc/m68kops.h"
#elif defined(MACHINE_X86_GCC)
#include "md-x86-gcc/m68kops.h"
#else
#include "md-generic/m68kops.h"
#endif
