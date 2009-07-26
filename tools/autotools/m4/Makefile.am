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

##
## Maintainer related targets
##
HOST = "http://git.savannah.gnu.org/cgit/autoconf-archive.git/plain"

EXTERNAL =					\
	ax_split_version.m4			\
	ax_missing_prog.m4			\
	ax_path_missing.m4			\
        ax_cxxcpp_check_flag.m4			\
	ax_print_to_file.m4			\
	ax_file_escapes.m4

INTERNAL =					\
	gnulib-cache.m4

MACROS =					\
	$(EXTERNAL)				\
	$(INTERNAL)

update-local: Makefile
	rm -r -f fetch-dir && \
	mkdir fetch-dir && \
	for i in $(EXTERNAL) ; do \
		$(FETCH) $(HOST)/$$i fetch-dir/$$i || { \
			rm -f fetch-dir/$$i ; \
			exit 1 ; \
		} \
	done && \
	for i in $(EXTERNAL) ; do \
		mv fetch-dir/$$i $$i || { \
			exit 1 ; \
		} \
	done && \
	rm -r -f fetch-dir

maintainer-check-local: Makefile
