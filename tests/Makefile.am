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

PASS_TESTS =					\
	test-core				\
	test-gfx				\
	test-sfx				\
	test-io					\
	test-all

FAIL_TESTS =

#TESTS       = $(PASS_TESTS) $(FAIL_TESTS)
#XFAIL_TESTS = $(FAIL_TESTS)
#
#check_PROGRAMS = $(TESTS)

noinst_PROGRAMS = $(PASS_TESTS)

COMMONCPPFLAGS = -I$(top_srcdir) -I$(top_builddir)

noinst_LIBRARIES     = libcommon.a

libcommon_a_SOURCES  = common.cxx
libcommon_a_CPPFLAGS = $(COMMONCPPFLAGS) -DDATAPATH='"$(abs_srcdir)"'

TESTSCPPFLAGS =					\
	$(SDL_CFLAGS)				\
	$(SDL_IMAGE_CFLAGS)			\
	$(SDL_MIXER_CFLAGS)			\
	$(GL_CFLAGS)				\
	$(COMMONCPPFLAGS)
TESTSLDADD    =					\
	$(SDL_LIBS)				\
	$(SDL_IMAGE_LIBS)			\
	$(SDL_MIXER_LIBS)			\
	$(GL_LIBS)				\
	libcommon.a				\
	$(top_builddir)/haze/libhaze.la

test_core_SOURCES  = test-core.cxx
test_core_CPPFLAGS = $(TESTSCPPFLAGS)
test_core_LDADD    = $(TESTSLDADD)
test_core_LDFLAGS  = 

test_gfx_SOURCES   = test-gfx.cxx
test_gfx_CPPFLAGS  = $(TESTSCPPFLAGS)
test_gfx_LDADD     = $(TESTSLDADD)
test_gfx_LDFLAGS   =

test_sfx_SOURCES   = test-sfx.cxx
test_sfx_CPPFLAGS  = $(TESTSCPPFLAGS)
test_sfx_LDADD     = $(TESTSLDADD)
test_sfx_LDFLAGS   =

test_io_SOURCES    = test-io.cxx
test_io_CPPFLAGS   = $(TESTSCPPFLAGS)
test_io_LDADD      = $(TESTSLDADD)
test_io_LDFLAGS    =

test_all_SOURCES   = test-all.cxx
test_all_CPPFLAGS  = $(TESTSCPPFLAGS)
test_all_LDADD     = $(TESTSLDADD)
test_all_LDFLAGS   =
