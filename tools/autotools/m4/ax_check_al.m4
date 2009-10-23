# ===========================================================================
#      http://www.nongnu.org/autoconf-archive/ax_cxxcpp_check_flag.html
# ===========================================================================
#
# SYNOPSIS
#
#   AX_CHECK_AL([ACTION-IF-SUCCESS],[ACTION-IF-FAILURE])
#
# DESCRIPTION
#
#   This macro checks for OpenAL support. If successfull execute
#   ACTION-IF-SUCCESS otherwise ACTION-IF-FAILURE.
#
# LICENSE
#
#   Copyright (c) 2009 Francesco Salvestrini <salvestrini@users.sourceforge.net>
#
#   This program is free software; you can redistribute it and/or modify it
#   under the terms of the GNU General Public License as published by the
#   Free Software Foundation; either version 2 of the License, or (at your
#   option) any later version.
#
#   This program is distributed in the hope that it will be useful, but
#   WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
#   Public License for more details.
#
#   You should have received a copy of the GNU General Public License along
#   with this program. If not, see <http://www.gnu.org/licenses/>.
#
#   As a special exception, the respective Autoconf Macro's copyright owner
#   gives unlimited permission to copy, distribute and modify the configure
#   scripts that are the output of Autoconf when processing the Macro. You
#   need not follow the terms of the GNU General Public License when using
#   or distributing such scripts, even though portions of the text of the
#   Macro appear in them. The GNU General Public License (GPL) does govern
#   all other use of the material that constitutes the Autoconf Macro.
#
#   This special exception to the GPL applies to versions of the Autoconf
#   Macro released by the Autoconf Archive. When you make and distribute a
#   modified version of the Autoconf Macro, you may extend this special
#   exception to the GPL to apply to your modified version as well.

AC_DEFUN([AX_CHECK_AL],[
    AC_ARG_ENABLE([openal], AC_HELP_STRING([--disable-openal], [disable OpenAL dependent parts]),
        [enableopenal=$enableval],
        [enableopenal=yes])

    OPENAL_LIBS=""

    AS_IF([ test x"$enableopenal" = x"yes" ],[
        save_LIBS="$LIBS"
        LIBS="$save_LIBS -pthread"

        AC_CHECK_LIB(openal, alEnable,[
            AC_CHECK_HEADER([AL/al.h],[
                ac_have_openal="yes"
                OPENAL_LIBS="-lopenal"
                 AC_DEFINE(HAVE_OPENAL,1,[Define if you have OpenAL runtime support])
            ],[
                AC_MSG_ERROR([OpenAL runtime is available without development headers ...])
            ])
        ],[
            AC_MSG_WARN([OpenAL runtime is not available. All OpenAL dependent parts will be disabled])
        ])

        AS_IF([ test x$ac_have_openal = "xyes" ],[
            ac_use_openal=yes
            OPENAL_LIBS="-lopenal -pthread"
        ])
    ])

    AC_SUBST(OPENAL_LIBS)
    AM_CONDITIONAL(HAVE_OPENAL, [test x"$ac_use_openal" = x"yes"])
    AS_IF([ test x"$ac_use_openal" = x"yes" ],[
        $1
    ],[
        $2
    ])
])
