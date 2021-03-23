 /*
  * E-UAE - The portable Amiga Emulator
  *
  * Read timestamp counter on an AMD64
  *
  * Copyright 2005 Richard Drummond
  *
  * Derived from the i386 version:
  * Copyright 1997, 1998 Bernd Schmidt
  * Copyright 2003-2005  Richard Drummond
  */

#ifndef EUAE_MACHDEP_RPT_H
#define EUAE_MACHDEP_RPT_H

STATIC_INLINE uae_s64 read_processor_time (void)
{
#ifndef __x86_64__
	uae_u32 foo1, foo2;
#else
	uae_s64 foo1, foo2;
#endif
	uae_s64 tsc;

	/* Don't assume the assembler knows rdtsc */
	__asm__ __volatile__ (".byte 0x0f,0x31" : "=a" (foo1), "=d" (foo2) :);
	tsc = (((uae_u64) foo2) << 32ULL) | (uae_u64) foo1;

	return tsc;
}

STATIC_INLINE frame_time_t machdep_gethrtime (void)
{
	return read_processor_time ();
}

frame_time_t machdep_gethrtimebase (void);
int          machdep_inithrtimer   (void);

#endif /* EUAE_MACHDEP_RPT_H */
