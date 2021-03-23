AC_PREREQ(2.55)
AC_INIT(PUAE, 2.8.1, rofl0r@github, puae)

AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADER([src/sysconfig.h])

AC_PROG_CC
AC_LANG(C)

AC_CANONICAL_TARGET
AC_AIX
AC_ISC_POSIX

dnl commit version
dnl
commit=`tail -1 .git/packed-refs | awk '{print $1}'`
if test -z "$commit"; then
	commit="not git"
fi
AC_DEFINE_UNQUOTED(PACKAGE_COMMIT, "$commit", [cloned git commit version])
AC_SUBST(PACKAGE_COMMIT, $commit)

AC_ARG_WITH(sound,
        AS_HELP_STRING([--with-sound=alsa,none,sdl], [which sound backend to use [sdl]]),
        [sound=$withval],
        [sound=sdl])

AC_ARG_WITH(gfx,
        AS_HELP_STRING([--with-gfx=x11,sdl], [which gfx backend to use [sdl]]),
        [gfx=$withval],
        [gfx=sdl])

AC_ARG_WITH(gui,
        AS_HELP_STRING([--with-gui=gtk,none,sdl], [which gui frontend to use [sdl]]),
        [gui=$withval],
        [gui=sdl])

AC_ARG_WITH(threads,
        AS_HELP_STRING([--with-threads=posix,none,sdl], [which threads implementation use [sdl]]),
        [threads=$withval],
        [threads=sdl])

AC_ARG_WITH(os,
        AS_HELP_STRING([--with-os=linux,macosx,generic], [which OS to compile for [linux]]),
        [os=$withval],
        [os=linux])

AC_ARG_WITH(joystick,
        AS_HELP_STRING([--with-joystick=none,linuxold,sdl], [which joystick implementation to use [sdl]]),
        [joystick=$withval],
        [joystick=sdl])

AC_ARG_WITH(machine,
        AS_HELP_STRING([--with-machine=generic,amd64-gcc,x86-gcc,ppc-gcc], [which machine specific optimizations to use [generic]]),
        [machine=$withval],
        [machine=generic])

AC_ARG_WITH(float,
        AS_HELP_STRING([--with-float=ieee,unknown], [whether target machine uses IEEE 754 compatible floats [ieee]]),
        [float=$withval],
        [float=ieee])

AC_ARG_ENABLE(jit,
	AS_HELP_STRING([--enable-jit], [Enable JIT compiler (currently x86 only)]),
	[WANT_JIT=$enableval],[])

dnl  Checks for header files.
dnl
AC_HEADER_DIRENT
AC_HEADER_STDC
AC_CHECK_HEADERS([fcntl.h sys/ioctl.h sys/time.h utime.h])
AC_CHECK_HEADERS([values.h ncurses.h curses.h sys/termios.h])
AC_CHECK_HEADERS([sys/stat.h sys/ipc.h sys/shm.h sys/mman.h])
AC_CHECK_HEADERS([sys/statfs.h sys/statvfs.h])
AC_CHECK_HEADERS([sys/filio.h])

AC_CHECK_HEADERS([libraries/cybergraphics.h cybergraphx/cybergraphics.h])

AC_CHECK_HEADERS([devices/ahi.h])
AC_CHECK_HEADERS([sys/soundcard.h machine/soundcard.h sun/audioio.h sys/audioio.h])

AC_CHECK_HEADERS([machine/joystick.h])
AC_CHECK_HEADER([amigainput/amigainput.h], HAVE_AMIGAINPUT=yes, HAVE_AMIGAINPUT=no)

AC_CHECK_HEADERS([byteswap.h])

AC_CHECK_HEADERS([pcap.h], HAVE_PCAP=yes, HAVE_PCAP=no)

dnl
dnl  Checks for typedefs, structures, and compiler characteristics.
dnl
AC_HEADER_STDBOOL
AC_C_CONST
AC_C_INLINE
AC_TYPE_MODE_T
AC_TYPE_OFF_T
AC_TYPE_SIZE_T
AC_STRUCT_ST_BLOCKS
AC_HEADER_TIME
AC_STRUCT_TM
AC_C_VOLATILE
AC_C_BIGENDIAN

AC_CHECK_SIZEOF(char, 1)
AC_CHECK_SIZEOF(short, 2)
AC_CHECK_SIZEOF(int, 4)
AC_CHECK_SIZEOF(long, 4)
AC_CHECK_SIZEOF(long long, 8)
AC_CHECK_SIZEOF(void *)

if test "${ac_cv_c_have_long_double}" = "yes" ; then
	AC_CHECK_SIZEOF(long double, 12)
fi

dnl  Checks for library functions.
dnl
AC_FUNC_MEMCMP
AC_TYPE_SIGNAL
AC_FUNC_UTIME_NULL
AC_CHECK_FUNCS(gettimeofday sigaction)
AC_CHECK_FUNCS(select strerror isnan isinf setitimer alarm sync)
AC_CHECK_FUNCS(readdir_r)
AC_CHECK_FUNCS(strdup strstr strcasecmp stricmp strcmpi)
AC_CHECK_FUNCS(nanosleep usleep sleep)
AC_CHECK_FUNCS(vprintf vsprintf vfprintf)

AC_CHECK_FUNCS(localtime_r timegm gmtime_r)
AC_SYS_LARGEFILE

AC_MSG_CHECKING(for bswap_16)
AC_TRY_LINK([
  #if HAVE_BYTESWAP_H
  # include <byteswap.h>
  #endif
],[
  bswap_16 (0x12);
],[
  AC_DEFINE(HAVE_BSWAP_16, 1, [Define to 1 if you have the 'bswap_16' function.])
  AC_MSG_RESULT(yes)
],[
  AC_MSG_RESULT(no)
])
AC_MSG_CHECKING(for bswap_32)
AC_TRY_LINK([
  #if HAVE_BYTESWAP_H
  # include <byteswap.h>
  #endif
],[
  bswap_32 (0x1234);
],[
  AC_DEFINE(HAVE_BSWAP_32, 1, [Define to 1 if you have the 'bswap_32' function.])
  AC_MSG_RESULT(yes)
],[
  AC_MSG_RESULT(no)
])

dnl
dnl  Checks for fsusage
dnl
AC_CHECK_HEADERS(sys/param.h sys/vfs.h sys/fs_types.h)
AC_CHECK_HEADERS(sys/mount.h, [], [],
[#ifdef HAVE_SYS_PARAM_H
# include <sys/param.h>
#endif
])
jm_FILE_SYSTEM_USAGE([gl_cv_fs_space=yes], [gl_cv_fs_space=no])
if test $gl_cv_fs_space = yes; then
  AC_LIBOBJ(fsusage)
  gl_PREREQ_FSUSAGE_EXTRA
fi

AC_CACHE_SAVE

AC_CHECK_LIB(z, inflateEnd, [zlib_cv_libz=yes], [zlib_cv_libz=no])
AC_CHECK_HEADER(zlib.h, [zlib_cv_zlib_h=yes], [zlib_cv_zlib_h=no])
if test "$zlib_cv_libz" = "yes" -a "$zlib_cv_zlib_h" = "yes"
then
    UAE_LIBS="-lz $UAE_LIBS"
else
    AC_MSG_ERROR(Check for libz failed)
fi

dnl
dnl  Check for dlopen
dnl
AC_CHECK_LIB(dl, dlopen, [
    UAE_LIBS="-ldl $UAE_LIBS"
    AC_DEFINE(HAVE_DLOPEN, 1, "Define to 1 if you have 'dlopen' function)
  ],
)

AC_CONFIG_FILES([config.mak])
AC_SUBST(gfx)
AC_SUBST(gui)
AC_SUBST(threads)
AC_SUBST(machine)
AC_SUBST(os)
AC_SUBST(sound)
AC_SUBST(joystick)
AC_SUBST(float)

AC_SUBST(CC)
AC_SUBST(HOSTCC)
AC_SUBST(CFLAGS)
AC_SUBST(CPPFLAGS)
AC_SUBST(LDFLAGS)
AC_SUBST(LIBS)

AC_OUTPUT
