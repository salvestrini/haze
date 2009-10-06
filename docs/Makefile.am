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

EXTRA_DIST =					\
	Doxyfile.in

CLEANFILES =					\
	Doxyfile

Doxyfile: $(srcdir)/Doxyfile.in Makefile
	( rm -f $@ $@.tmp && \
	  $(do_subst) < $(srcdir)/Doxyfile.in > $@.tmp && \
	  chmod a-w $@.tmp && \
	  mv -f $@.tmp $@ ) || { \
		rm -f $@ $@.tmp ; \
		exit 1 ; \
	}

.PHONY: doxygen
doxygen: Doxyfile
	rm -r -f doxygen && \
	mkdir doxygen && \
	$(DOXYGEN) Doxyfile || { \
		rm -r -f doxygen \
		exit 1 ; \
	}

clean-local:
	rm -r -f doxygen

##
## Maintainer related targets
##
update-local: Makefile

maintainer-check-local: Makefile
