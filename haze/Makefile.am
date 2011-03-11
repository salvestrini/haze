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

core_SRCS =					\
	core/debug.cxx				\
	core/exception.cxx			\
	core/filesystem.cxx			\
	core/log.cxx				\
	core/pattern.cxx			\
	core/synchronization.cxx		\
	core/thread.cxx				\
	core/time.cxx

core_HDRS =					\
	core/debug.hxx				\
	core/exception.hxx			\
	core/filesystem.hxx			\
	core/log.hxx				\
	core/pattern.hxx			\
	core/synchronization.hxx		\
	core/thread.hxx				\
	core/time.hxx				\
						\
	core/core.hxx

io_SRCS =					\
	io/io.cxx

io_HDRS =					\
	io/io.hxx

math_SRCS =					\
	math/math.cxx

math_HDRS =					\
	math/math.hxx


gfx_SRCS =					\
	gfx/gl.cxx				\
	gfx/video.cxx				\
	gfx/fps.cxx				\
	gfx/image.cxx				\
	gfx/geometry.cxx			\
	gfx/primitive.cxx			\
	gfx/camera.cxx				\
	gfx/font.cxx				\
	gfx/text.cxx

gfx_HDRS =					\
	gfx/gl.hxx				\
	gfx/video.hxx				\
	gfx/fps.hxx				\
	gfx/image.hxx				\
	gfx/geometry.hxx			\
	gfx/primitive.hxx			\
	gfx/camera.hxx				\
	gfx/font.hxx				\
	gfx/text.hxx				\
						\
	gfx/gfx.hxx

sfx_SRCS =					\
	sfx/audio.cxx

sfx_HDRS =					\
	sfx/audio.hxx				\
						\
	sfx/sfx.hxx

all_SRCS =								\
	haze.cxx							\
	$(core_SRCS) $(io_SRCS) $(gfx_SRCS) $(sfx_SRCS) $(math_SRCS)

all_HDRS =								\
	haze.hxx settings.hxx						\
	$(core_HDRS) $(io_HDRS) $(gfx_HDRS) $(sfx_HDRS) $(math_HDRS)

nobase_pkginclude_HEADERS = $(all_HDRS)
lib_LTLIBRARIES = libhaze.la

libhaze_la_SOURCES  = $(all_SRCS) $(all_HDRS)
libhaze_la_CPPFLAGS =				\
	-I$(top_srcdir) -I$(top_builddir)	\
	-Wall -Werror				\
	$(SDL_CFLAGS)				\
	$(SDL_IMAGE_CFLAGS)			\
	$(SDL_MIXER_CFLAGS)			\
	$(GL_CFLAGS)
