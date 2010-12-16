//
// Copyright (C) 2010 Francesco Salvestrini
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//

#ifndef HAZE_CORE_LOG
#define HAZE_CORE_LOG

#include <cstdio>

#include "settings.hxx"

extern const char * prefix_;

#define LOG_SETPREFIX(X) { prefix_ = X; }

#if DEBUG
#define DBG(FMT, ARGS...) fprintf(stdout, "%s: " FMT "\n", prefix_, ##ARGS)
#else
#define DBG(FMT, ARGS...)
#endif

#define WRN(FMT, ARGS...) fprintf(stderr, "%s: " FMT "\n", prefix_, ##ARGS)
#define ERR(FMT, ARGS...) fprintf(stderr, "%s: " FMT "\n", prefix_, ##ARGS)

#endif