# ===========================================================================
#         http://www.nongnu.org/autoconf-archive/ac_path_generic.html
# ===========================================================================
#
# SYNOPSIS
#
#   AC_PATH_GENERIC(LIBRARY [, MINIMUM-VERSION [, ACTION-IF-FOUND [, ACTION-IF-NOT-FOUND [, CONFIG-SCRIPTS [, CFLAGS-ARG [, LIBS-ARG]]]]]])
#
# DESCRIPTION
#
#   Runs a LIBRARY-config script and defines LIBRARY_CFLAGS and LIBRARY_LIBS
#
#   The script must support `--cflags' and `--libs' args. If MINIMUM-VERSION
#   is specified, the script must also support the `--version' arg. If the
#   `--with-library-[exec-]prefix' arguments to ./configure are given, it
#   must also support `--prefix' and `--exec-prefix'. (In other words, it
#   must be like gtk-config.) Prefereable use CONFIG-SCRIPTS as config script,
#   CFLAGS-ARG instead of `--cflags` and LIBS-ARG instead of `--libs`, if given.
#
#   For example:
#
#      AC_PATH_GENERIC(Foo, 1.0.0)
#
#   would run `foo-config --version' and check that it is at least 1.0.0
#
#   If so, the following would then be defined:
#
#      FOO_CFLAGS to `foo-config --cflags`
#      FOO_LIBS   to `foo-config --libs`
#
#   At present there is no support for additional "MODULES" (see
#   AM_PATH_GTK) (shamelessly stolen from gtk.m4 and then hacked around a
#   fair amount)
#
# LICENSE
#
#   Copyright (c) 2008 Angus Lees
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

AC_DEFUN([AC_PATH_GENERIC],
[dnl
dnl we're going to need uppercase, lowercase and user-friendly versions of the
dnl string `LIBRARY'
pushdef([UP], translit([$1], [a-z], [A-Z]))dnl
pushdef([DOWN], translit([$1], [A-Z], [a-z]))dnl

dnl
dnl Get the cflags and libraries from the LIBRARY-config script
dnl
AC_ARG_WITH(DOWN-prefix,[AS_HELP_STRING([--with-]DOWN[-prefix=PREFIX], [Prefix where $1 is installed (optional)])],
        DOWN[]_config_prefix="$withval", DOWN[]_config_prefix="")
AC_ARG_WITH(DOWN-exec-prefix,[AS_HELP_STRING([--with-]DOWN[-exec-prefix=PREFIX], [Exec prefix where $1 is installed (optional)])],
        DOWN[]_config_exec_prefix="$withval", DOWN[]_config_exec_prefix="")
AC_ARG_VAR(UP[]_CONFIG, [config script used for $1])
AC_ARG_VAR(UP[]_CFLAGS, [CFLAGS used for the $1])
AC_ARG_VAR(UP[]_LIBS,   [LIBS used for the $1])

  if test x$DOWN[]_config_exec_prefix != x ; then
     DOWN[]_config_args="$DOWN[]_config_args --exec-prefix=$DOWN[]_config_exec_prefix"
     if test x${UP[]_CONFIG+set} != xset ; then
       UP[]_CONFIG=$DOWN[]_config_exec_prefix/bin/DOWN-config
     fi
  fi
  if test x$DOWN[]_config_prefix != x ; then
     DOWN[]_config_args="$DOWN[]_config_args --prefix=$DOWN[]_config_prefix"
     if test x${UP[]_CONFIG+set} != xset ; then
       UP[]_CONFIG=$DOWN[]_config_prefix/bin/DOWN-config
     fi
  fi

  AC_PATH_PROGS(UP[]_CONFIG, $5 DOWN-config, no)
  ifelse([$2], ,
     AC_MSG_CHECKING(for $1),
     AC_MSG_CHECKING(for $1 - version >= $2)
  )
  no_[]DOWN=""
  if test "$UP[]_CONFIG" = "no" ; then
     no_[]DOWN=yes
  else
     ifelse([$6], , [
        UP[]_CFLAGS="`$UP[]_CONFIG $DOWN[]_config_args --cflags`"
     ], [
        UP[]_CFLAGS="`$UP[]_CONFIG $DOWN[]_config_args $6`"
     ])
     ifelse([$7], , [
        UP[]_LIBS="`$UP[]_CONFIG $DOWN[]_config_args --libs`"
     ], [
        UP[]_LIBS="`$UP[]_CONFIG $DOWN[]_config_args $7`"
     ])
     ifelse([$2], , ,[
        DOWN[]_config_major_version=`$UP[]_CONFIG $DOWN[]_config_args \
         --version | sed 's/[[^0-9]]*\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\1/'`
        if test "$DOWN[]_config_major_version" = "" ; then
           DOWN[]_config_major_version="0"
        fi

        DOWN[]_config_minor_version=`$UP[]_CONFIG $DOWN[]_config_args \
         --version | sed 's/[[^0-9]]*\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\2/'`
        if test "$DOWN[]_config_minor_version" = "" ; then
           DOWN[]_config_minor_version="0"
        fi

        DOWN[]_config_micro_version=`$UP[]_CONFIG $DOWN[]_config_args \
         --version | sed 's/[[^0-9]]*\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\3/'`
        if test "$DOWN[]_config_micro_version" = "" ; then
           DOWN[]_config_micro_version="0"
        fi

        DOWN[]_wanted_major_version="regexp($2, [\<\([0-9]*\)], [\1])"
        if test "$DOWN[]_wanted_major_version" = "" ; then
           DOWN[]_wanted_major_version="0"
        fi

        DOWN[]_wanted_minor_version="regexp($2, [\<\([0-9]*\)\.\([0-9]*\)], [\2])"
        if test "$DOWN[]_wanted_minor_version" = "" ; then
           DOWN[]_wanted_minor_version="0"
        fi

        DOWN[]_wanted_micro_version="regexp($2, [\<\([0-9]*\).\([0-9]*\).\([0-9]*\)], [\3])"
        if test "$DOWN[]_wanted_micro_version" = "" ; then
           DOWN[]_wanted_micro_version="0"
        fi

        # Compare wanted version to what config script returned.
        # If I knew what library was being run, i'd probably also compile
        # a test program at this point (which also extracted and tested
        # the version in some library-specific way)
        if test "$DOWN[]_config_major_version" -lt \
                        "$DOWN[]_wanted_major_version" \
          -o \( "$DOWN[]_config_major_version" -eq \
                        "$DOWN[]_wanted_major_version" \
            -a "$DOWN[]_config_minor_version" -lt \
                        "$DOWN[]_wanted_minor_version" \) \
          -o \( "$DOWN[]_config_major_version" -eq \
                        "$DOWN[]_wanted_major_version" \
            -a "$DOWN[]_config_minor_version" -eq \
                        "$DOWN[]_wanted_minor_version" \
            -a "$DOWN[]_config_micro_version" -lt \
                        "$DOWN[]_wanted_micro_version" \) ; then
          # older version found
          no_[]DOWN=yes
          echo -n "*** An old version of $1 "
          echo -n "($DOWN[]_config_major_version"
          echo -n ".$DOWN[]_config_minor_version"
          echo    ".$DOWN[]_config_micro_version) was found."
          echo -n "*** You need a version of $1 newer than "
          echo -n "$DOWN[]_wanted_major_version"
          echo -n ".$DOWN[]_wanted_minor_version"
          echo    ".$DOWN[]_wanted_micro_version."
          echo "***"
          echo "*** If you have already installed a sufficiently new version, this error"
          echo "*** probably means that the wrong copy of the DOWN-config shell script is"
          echo "*** being found. The easiest way to fix this is to remove the old version"
          echo "*** of $1, but you can also set the UP[]_CONFIG environment to point to the"
          echo "*** correct copy of DOWN-config. (In this case, you will have to"
          echo "*** modify your LD_LIBRARY_PATH environment variable, or edit /etc/ld.so.conf"
          echo "*** so that the correct libraries are found at run-time)"
        fi
     ])
  fi
  if test "x$no_[]DOWN" = x ; then
     AC_MSG_RESULT(yes)
     ifelse([$3], , :, [$3])
  else
     AC_MSG_RESULT(no)
     if test "$UP[]_CONFIG" = "no" ; then
       echo "*** The DOWN-config script installed by $1 could not be found"
       echo "*** If $1 was installed in PREFIX, make sure PREFIX/bin is in"
       echo "*** your path, or set the UP[]_CONFIG environment variable to the"
       echo "*** full path to DOWN-config."
     fi
     UP[]_CFLAGS=""
     UP[]_LIBS=""
     ifelse([$4], , :, [$4])
  fi
  AC_SUBST(UP[]_CFLAGS)
  AC_SUBST(UP[]_LIBS)

  popdef([UP])
  popdef([DOWN])
])
