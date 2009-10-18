##
## Input file for automake
##
## Copyright (C) 2008, 2009 Francesco Salvestrini
##
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 2 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License along
## with this program; if not, write to the Free Software Foundation, Inc.,
## 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
##

include $(top_srcdir)/Makefile.sub

AUTOMAKE_OPTIONS = subdir-objects

SUBDIRS =

EXTRA_DIST =

## Programs

lib_LTLIBRARIES =				\
	libhaze.la

libhaze_la_SOURCES =

## Backends
libhaze_la_SOURCES +=				\
	haze/backends/backend.h++		\
	haze/backends/backend.c++
if HAVE_SDL
libhaze_la_SOURCES +=				\
	haze/backends/sdl.h++			\
	haze/backends/sdl.c++
endif

## Base
libhaze_la_SOURCES +=				\
	haze/haze.h++				\
	haze/haze.c++

## Utilities
libhaze_la_SOURCES +=				\
	haze/debug.h++				\
	haze/utility.h++			\
	haze/exception.h++			\
	haze/exception.c++			\
	haze/log.h++				\
	haze/log.c++				\
	haze/buffer.h++				\
	haze/buffer.c++				\
	haze/factory.h++			\
	haze/factory.c++

## OS
libhaze_la_SOURCES +=				\
	haze/mutex.h++				\
	haze/mutex.c++				\
	haze/thread.h++				\
	haze/thread.c++

## Graphic
libhaze_la_SOURCES +=				\
	haze/color.h++				\
	haze/color.c++				\
	haze/point.h++				\
	haze/point.c++				\
	haze/size.h++				\
	haze/size.c++				\
	haze/rectangle.h++			\
	haze/rectangle.c++			\
	haze/bitmap.h++				\
	haze/bitmap.c++				\
	haze/image.h++				\
	haze/image.c++				\
	haze/animation.h++			\
	haze/animation.c++			\
	haze/background.h++			\
	haze/background.c++			\
	haze/frame.h++				\
	haze/frame.c++				\
	haze/font.h++				\
	haze/font.c++

## Widgets
libhaze_la_SOURCES +=				\
	haze/object.h++				\
	haze/object.c++				\
	haze/pointer.h++			\
	haze/pointer.c++			\
	haze/screen.h++				\
	haze/screen.c++				\
	haze/widget.h++				\
	haze/widget.c++				\
	haze/window.h++				\
	haze/window.c++				\
	haze/label.h++				\
	haze/label.c++

libhaze_la_CPPFLAGS = $(BOOST_CPPFLAGS) $(EXTRA_CPPFLAGS)
libhaze_la_CFLAGS   =
libhaze_la_CXXFLAGS =
libhaze_la_LDFLAGS  = -version-info @LIBTOOL_VERSION_INFO@ $(BOOST_LDFLAGS)

##
## Maintainer related targets
##
update-local: Makefile

maintainer-check-includes: Makefile $(libhaze_la_SOURCES)
	for i in $(libhaze_la_SOURCES) ; do \
		if $(GREP) "include[ \t]\+\"" $$i | $(GREP) -v "\"haze\/" ; then \
			echo "Wrong include in $$i" ; \
			exit 1; \
		fi ; \
	done

maintainer-check-parameters: Makefile $(bin_PROGRAMS)
	for i in $(bin_PROGRAMS) ; do \
		echo @ECHO_N@ "Checking standard parameters for $$i... " ; \
		if ( ./$$i -h 2>&1 > /dev/null ) ; then \
			echo "@ECHO_T@ok" ; \
		else \
			echo "@ECHO_T@error" ; \
			exit 1 ; \
		fi ; \
	done

maintainer-check-whitespaces: Makefile $(libhaze_la_SOURCES)
	$(WHITESPACE_DETECT) $(libhaze_la_SOURCES)

maintainer-check-guards: Makefile $(libhaze_la_SOURCES)
	$(GUARDS_CHECK) $(libhaze_la_SOURCES)

maintainer-check-local: Makefile maintainer-check-includes maintainer-check-guards maintainer-check-whitespaces maintainer-check-parameters
