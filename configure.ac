#
# Input file for autoconf
#
# Copyright (C) 2011 Francesco Salvestrini
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
#

AC_INIT([haze],[m4_esyscmd(build-aux/git-version-gen .tarball-version)],[salvestrini@gmail.com],[haze])

AC_PREREQ([2.65])

AC_CONFIG_HEADERS([haze/config.h])
AC_CONFIG_SRCDIR([haze/haze.cxx])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

AC_CANONICAL_BUILD
AC_CANONICAL_HOST
AC_CANONICAL_TARGET

AM_INIT_AUTOMAKE([1.11 foreign no-installman no-installinfo -Wall])

AC_PROG_SED
AC_PROG_GREP

AC_PATH_PROG([SORT], [sort])
AC_PATH_PROG([UNIQ], [uniq])
AC_PATH_PROG([GIT],  [git])

AC_PROG_CPP
AC_PROG_CC
AM_PROG_CC_C_O
AC_PROG_CXXCPP
AC_PROG_CXX
AC_PROG_CXX_C_O

AC_SEARCH_LIBS([SDL_Init], [SDL],[
    AC_SUBST([SDL_LIBS],  [-lSDL])
    AC_SUBST([SDL_CFLAGS],[])
],[
    AC_MSG_ERROR([Your system lacks SDL library])
],[])

AC_SEARCH_LIBS([SDL_initFramerate], [SDL_gfx],[
    AC_SUBST([SDL_GFX_LIBS],  [-lSDL_gfx])
    AC_SUBST([SDL_GFX_CFLAGS],[])
], [
    AC_MSG_ERROR([Your system lacks SDL_image library])
],[-lSDL])

AC_SEARCH_LIBS([IMG_Init], [SDL_image],[
    AC_SUBST([SDL_IMAGE_LIBS],  [-lSDL_image])
    AC_SUBST([SDL_IMAGE_CFLAGS],[])
], [
    AC_MSG_ERROR([Your system lacks SDL_image library])
],[-lSDL])

AC_SEARCH_LIBS([Mix_OpenAudio], [SDL_mixer], [
    AC_SUBST([SDL_MIXER_LIBS],  [-lSDL_mixer])
    AC_SUBST([SDL_MIXER_CFLAGS],[])
],[
    AC_MSG_ERROR([Your system lacks SDL_mixer library])
], [-lSDL])

AX_HAVE_GL
AS_IF([test x"$have_GL" = x"no" ],[
    AC_MSG_ERROR([Cannot find a suitable OpenGL library])
],[
     AC_DEFINE([HAVE_GL], [1], [Define to 1 if GL libraries are available])
])
#AX_CHECK_GL
#AS_IF([test x"$no_gl" = x"yes" ],[
#    AC_MSG_ERROR([Cannot find a suitable OpenGL library])
#])

AX_PREFIX_CONFIG_H([haze/haze-config.h], [HAZE], [haze/config.h])
#AH_TOP([
##ifndef HAZE_CONFIG_H
##define HAZE_CONFIG_H
#])
#AH_BOTTOM([
##endif
#])

# C Preprocessor flags
TEMP_CPPFLAGS=""
AX_CPP_CHECK_FLAG([-W],[],[],[
  TEMP_CPPFLAGS="$TEMP_CPPFLAGS -W"
])
AX_CPP_CHECK_FLAG([-Wall],[],[],[
  TEMP_CPPFLAGS="$TEMP_CPPFLAGS -Wall"
])
AX_CPP_CHECK_FLAG([-Werror],[],[],[
  TEMP_CPPFLAGS="$TEMP_CPPFLAGS -Werror"
])
AX_CPP_CHECK_FLAG([-Wendif-labels],[],[],[
  TEMP_CPPFLAGS="$TEMP_CPPFLAGS -Wendif-labels"
])
AX_CPP_CHECK_FLAG([-Wcast-align],[],[],[
  TEMP_CPPFLAGS="$TEMP_CPPFLAGS -Wcast-align"
])
AX_CPP_CHECK_FLAG([-Wredundant-decls],[],[],[
  TEMP_CPPFLAGS="$TEMP_CPPFLAGS -Wredundant-decls"
])
AX_CPP_CHECK_FLAG([-Wswitch],[],[],[
  TEMP_CPPFLAGS="$TEMP_CPPFLAGS -Wswitch"
])
AX_CPP_CHECK_FLAG([-Wparentheses],[],[],[
  TEMP_CPPFLAGS="$TEMP_CPPFLAGS -Wparentheses"
])
AX_CPP_CHECK_FLAG([-Wunused],[],[],[
  TEMP_CPPFLAGS="$TEMP_CPPFLAGS -Wunused"
])
AX_CPP_CHECK_FLAG([-Wmissing-braces],[],[],[
  TEMP_CPPFLAGS="$TEMP_CPPFLAGS -Wmissing-braces"
])
AX_CPP_CHECK_FLAG([-Wreturn-type],[],[],[
  TEMP_CPPFLAGS="$TEMP_CPPFLAGS -Wreturn-type"
])
AX_CPP_CHECK_FLAG([-Wundef],[],[],[
  TEMP_CPPFLAGS="$TEMP_CPPFLAGS -Wundef"
])
AX_CPP_CHECK_FLAG([-Wswitch-default],[],[],[
  TEMP_CPPFLAGS="$TEMP_CPPFLAGS -Wswitch-default"
])
AX_CPP_CHECK_FLAG([-Wchar-subscripts],[],[],[
  TEMP_CPPFLAGS="$TEMP_CPPFLAGS -Wchar-subscripts"
])
AC_SUBST([TEMP_CPPFLAGS], ["$TEMP_CPPFLAGS"])

LT_PREREQ([2.2.6])
#LT_INIT([disable-shared])
LT_INIT

AC_CONFIG_FILES([
        Makefile

        haze/Makefile
        tests/Makefile

        haze.pc
])

AC_OUTPUT
