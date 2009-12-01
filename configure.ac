# Process this file with autoconf to produce a configure script.

#
# configure.ac for haze
#
# Copyright (C) 2009 Francesco Salvestrini
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

AC_INIT([HAZE],
        m4_esyscmd([tools/maint/git-version-gen .tarball-version]),
        [salvestrini@gmail.com],
        [haze],
        [http://github.com/salvestrini/haze])

# Check for a recent version of autoconf
AC_PREREQ([2.64])

# Place/find all autotools related files in the following directories
AC_CONFIG_AUX_DIR([tools/autotools])
AC_CONFIG_MACRO_DIR([tools/autotools/m4])
AC_CONFIG_SRCDIR([src/haze/haze.h++])

#
# For automake options (AM_INIT_AUTOMAKE options) see Makefile.am
# file, AUTOMAKE_OPTIONS variable
#
AM_INIT_AUTOMAKE([1.10 foreign std-options -Wall color-tests])

#
# Autoheader support
#
AC_CONFIG_HEADERS([src/config.h])

#
# Build related programs
#
AC_PROG_INSTALL
AC_PROG_MAKE_SET
AC_PROG_LN_S
AC_PROG_GREP
AC_PROG_SED

AC_PROG_CPP
AC_PROG_CXX
AC_PROG_CXX_C_O

LT_INIT
LT_PREREQ([2.2.6])

LIBTOOL_VERSION_CURRENT=0
LIBTOOL_VERSION_REVISION=0
LIBTOOL_VERSION_AGE=0
AC_SUBST(LIBTOOL_VERSION_INFO,[$LIBTOOL_VERSION_CURRENT:$LIBTOOL_VERSION_REVISION:$LIBTOOL_VERSION_AGE])

#
# Checks for libraries
#

# Checks for Boost
AX_BOOST_BASE([1.35.0])

## Checks for Clutter
#PKG_CHECK_MODULES([CLUTTER],[clutter-1.0 >= 1.0],,[
#  have_clutter=yes
#],[
#  have_clutter=no
#])
#AM_CONDITIONAL([HAVE_CLUTTER],[ test "$have_clutter" = "yes" ])

# Checks for SDL
AX_PATH_GENERIC([sdl],[1.2.13],,[
  have_sdl=yes
],[
  have_sdl=no
])
AM_CONDITIONAL([HAVE_SDL],[ test "$have_sdl" = "yes" ])

# Checks for OpenGL
#AX_CHECK_GL

# Checks for OpenAL
#AX_CHECK_AL

# Checks for preprocessor flags
TEMP_FLAGS=""
AX_CXXCPP_CHECK_FLAG([-Wall],  [],[],[ TEMP_FLAGS="$TEMP_FLAGS -Wall"  ])
AX_CXXCPP_CHECK_FLAG([-Werror],[],[],[ TEMP_FLAGS="$TEMP_FLAGS -Werror"])
AC_SUBST([EXTRA_CPPFLAGS],$TEMP_FLAGS)


AX_PATH_MISSING([DOXYGEN], [doxygen])
AX_PATH_MISSING([PERL],    [perl])
AX_PATH_MISSING([WGET],    [wget])
AX_PATH_MISSING([DNT],     [dnt])
AX_PATH_MISSING([SORT],    [sort])

#
# Check for execinfo.h, backtrace() and backtrace_symbols(). They may be useful
#
AC_CHECK_HEADERS([execinfo.h])
AC_CHECK_FUNCS([backtrace backtrace_symbols])

AX_SPLIT_VERSION($PACKAGE_VERSION, AX_MAJOR_VERSION, AX_MINOR_VERSION, AX_MICRO_VERSION, AX_EXTRA_VERSION)
AX_PACKAGE_API([${AX_MAJOR_VERSION}"."${AX_MINOR_VERSION}])

AC_CONFIG_FILES([
	Makefile

        haze.pc

	src/Makefile

	docs/Makefile

	tests/Makefile

	tools/Makefile
	tools/maint/Makefile
	tools/autotools/Makefile
	tools/autotools/m4/Makefile
])

AC_CONFIG_FILES([tools/maint/fetch],               [chmod +x tools/maint/fetch])
AC_CONFIG_FILES([tools/maint/wordwrap-detect],     [chmod +x tools/maint/wordwrap-detect])
AC_CONFIG_FILES([tools/maint/whitespace-detect],   [chmod +x tools/maint/whitespace-detect])
AC_CONFIG_FILES([tools/maint/gitlog-to-committers],[chmod +x tools/maint/gitlog-to-committers])
AC_CONFIG_FILES([tools/maint/gittag-to-date],      [chmod +x tools/maint/gittag-to-date])
AC_CONFIG_FILES([tools/maint/releases-to-news],    [chmod +x tools/maint/releases-to-news])
AC_CONFIG_FILES([tools/maint/guards-check],        [chmod +x tools/maint/guards-check])

AC_OUTPUT
