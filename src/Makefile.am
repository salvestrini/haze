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

SUBDIRS = gnulib

EXTRA_DIST =

## Programs

lib_LTLIBRARIES =				\
	libhaze.la

libhaze_la_SOURCES =				\
	haze.h					\
	haze.c++				\
	point.h					\
	rectangle.h				\
	screen.h				\
	screen.c++				\
	object.h				\
	window.h				\
	window.c++				\
	button.h

libhaze_la_CPPFLAGS =
libhaze_la_CFLAGS   =
libhaze_la_CXXFLAGS =
libhaze_la_LDFLAGS  = -version-info @LIBTOOL_VERSION_INFO@

##
## Maintainer related targets
##
update-local: Makefile

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

maintainer-check-whitespaces: Makefile $(mexife_SOURCES)
	$(WHITESPACE_DETECT) $(mexife_SOURCES)

maintainer-check-local: Makefile maintainer-check-whitespaces maintainer-check-parameters
