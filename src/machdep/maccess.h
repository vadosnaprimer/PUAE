#if defined(MACHINE_68K)
#include "md-68k/maccess.h"
#elif defined(MACHINE_I386_GCC)
#include "md-i386-gcc/maccess.h"
#elif defined(MACHINE_PPC)
#include "md-ppc/maccess.h"
#elif defined(MACHINE_AMD64_GCC)
#include "md-amd64-gcc/maccess.h"
#elif defined(MACHINE_PPC_GCC)
#include "md-ppc-gcc/maccess.h"
#elif defined(MACHINE_X86_GCC)
#include "md-x86-gcc/maccess.h"
#else
#include "md-generic/maccess.h"
#endif
