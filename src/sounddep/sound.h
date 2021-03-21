#if defined(SOUND_ALSA)
#include "sd-alsa/sound.h"
#elif defined(SOUND_BEOS)
#include "sd-beos/sound.h"
#elif defined(SOUND_PEPPER)
#include "sd-pepper/sound.h"
#elif defined(SOUND_SOLARIS)
#include "sd-solaris/sound.h"
#elif defined(SOUND_AMIGAOS)
#include "sd-amigaos/sound.h"
#elif defined(SOUND_USS)
#include "sd-uss/sound.h"
#elif defined(SOUND_SDL)
#include "sd-sdl/sound.h"
#else
#include "sd-none/sound.h"
#endif
