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

EXTRA_DIST =

TESTS =						\
	test

check_PROGRAMS =				\
	test

test_SOURCES  = test.c++

test_CPPFLAGS = -I$(top_srcdir)/src -I$(top_builddir)/src
test_CFLAGS   =
test_CXXFLAGS =
test_LDADD    = $(top_srcdir)/src/libhaze.la

ALL_TESTS_SRCS =				\
	$(test_SOURCES)

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

maintainer-check-whitespaces: Makefile $(ALL_TESTS_SRCS)
	$(WHITESPACE_DETECT) $(ALL_TESTS_SRCS)

maintainer-check-local: Makefile maintainer-check-whitespaces maintainer-check-parameters
