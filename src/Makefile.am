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

## Base
libhaze_la_SOURCES +=				\
	haze/haze.h++				\
	haze/haze.c++

## Core
libhaze_la_SOURCES +=				\
	haze/core/debug.h++			\
	haze/core/debug.c++			\
	haze/core/utility.h++			\
	haze/core/utility.c++			\
	haze/core/exception.h++			\
	haze/core/exception.c++			\
	haze/core/log.h++			\
	haze/core/log.c++			\
	haze/core/buffer.h++			\
	haze/core/buffer.c++			\
	haze/core/factory.h++			\
	haze/core/factory.c++			\
	haze/core/singleton.h++			\
	haze/core/singleton.c++			\
	haze/core/observer.h++			\
	haze/core/observer.c++

## Graphic
libhaze_la_SOURCES +=				\
	haze/gfx/color.h++			\
	haze/gfx/color.c++			\
	haze/gfx/point.h++			\
	haze/gfx/point.c++			\
	haze/gfx/size.h++			\
	haze/gfx/size.c++			\
	haze/gfx/rectangle.h++			\
	haze/gfx/rectangle.c++			\
	haze/gfx/bitmap.h++			\
	haze/gfx/bitmap.c++			\
	haze/gfx/image.h++			\
	haze/gfx/image.c++			\
	haze/gfx/animation.h++			\
	haze/gfx/animation.c++			\
	haze/gfx/font.h++			\
	haze/gfx/font.c++

## Graphic Backends
libhaze_la_SOURCES +=				\
	haze/gfx/backends/video.h++		\
	haze/gfx/backends/video.c++
if HAVE_SDL
libhaze_la_SOURCES +=				\
	haze/gfx/backends/sdl.h++		\
	haze/gfx/backends/sdl.c++
endif

## Sound
libhaze_la_SOURCES +=				\
	haze/sfx/sample.h++			\
	haze/sfx/sample.c++

## Sound Backends
libhaze_la_SOURCES +=				\
	haze/sfx/backends/audio.h++		\
	haze/sfx/backends/audio.c++
if HAVE_SDL
libhaze_la_SOURCES +=				\
	haze/sfx/backends/sdl.h++		\
	haze/sfx/backends/sdl.c++
endif

## I/O
libhaze_la_SOURCES +=				\
	haze/io/keyboard.h++			\
	haze/io/keyboard.c++			\
	haze/io/mouse.h++			\
	haze/io/mouse.c++

## I/O Backends
libhaze_la_SOURCES +=				\
	haze/io/backends/controller.h++		\
	haze/io/backends/controller.c++
if HAVE_SDL
libhaze_la_SOURCES +=				\
	haze/io/backends/sdl.h++		\
	haze/io/backends/sdl.c++
endif

## User Interface
libhaze_la_SOURCES +=				\
	haze/ui/object.h++			\
	haze/ui/object.c++			\
	haze/ui/pointer.h++			\
	haze/ui/pointer.c++			\
	haze/ui/screen.h++			\
	haze/ui/screen.c++			\
	haze/ui/widget.h++			\
	haze/ui/widget.c++			\
	haze/ui/window.h++			\
	haze/ui/window.c++			\
	haze/ui/label.h++			\
	haze/ui/label.c++

libhaze_la_CPPFLAGS = $(BOOST_CPPFLAGS) $(EXTRA_CPPFLAGS)
libhaze_la_CFLAGS   = $(GL_CFLAGS)
libhaze_la_CXXFLAGS =
libhaze_la_LDFLAGS  = -version-info @LIBTOOL_VERSION_INFO@ $(BOOST_LDFLAGS) $(GL_LIBS) $(OPENAL_LIBS)

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
