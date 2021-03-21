#if defined(GFX_AMIGAOS)
#include "gfx-amigaos/gfx.h"
#elif defined(GFX_COCOA)
#include "gfx-cocoa/gfx.h"
#elif defined(GFX_PEPPER)
#include "gfx-pepper/gfx.h"
#elif defined(GFX_X11)
#include "gfx-x11/gfx.h"
#elif defined(GFX_BEOS)
#include "gfx-beos/gfx.h"
#elif defined(GFX_CURSES)
#include "gfx-curses/gfx.h"
#elif defined(GFX_RETRO)
#include "gfx-retro/gfx.h"
#elif defined(GFX_SVGA)
#include "gfx-svga/gfx.h"
#else
#include "gfx-sdl/gfx.h"
#endif
