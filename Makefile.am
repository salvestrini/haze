#
# Input file for automake
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

ACLOCAL_AMFLAGS = -I m4 --install

EXTRA_DIST     =
DISTCLEANFILES =

.PHONY: AUTHORS
AUTHORS:
	$(GIT) log --format="%aN <%aE>" | $(SORT) | $(UNIQ) > AUTHORS || { \
		rm -f AUTHORS ;						   \
		exit 1 ;						   \
        }

DISTCLEANFILES += AUTHORS

EXTRA_DIST +=					\
	AUTHORS					\
	NEWS					\
	README					\
	bootstrap

SUBDIRS =					\
	haze					\
	tests

pkgconfigdir   = $(libdir)/pkgconfig
pkgconfig_DATA = haze.pc

.PHONY: ChangeLog
ChangeLog:
	rm -f ChangeLog &&                                                   \
	$(GIT) log --decorate --format="%aN <%aE>:%d%n  %s%n" --date-order > \
	        ChangeLog || {                                               \
	        rm -f ChangeLog ;                                            \
	        exit 1 ;                                                     \
	}

EXTRA_DIST += ChangeLog
