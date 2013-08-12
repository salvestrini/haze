//
// Copyright (C) 2012, 2013 Francesco Salvestrini
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

#ifndef HAZE_CORE_REGEX
#define HAZE_CORE_REGEX

#include "haze/config.hh"

#if HAVE_REGEX_H
#include <sys/types.h>
#include <regex.h>
#endif

#include <vector>
#include <string>

namespace haze {

        class regex {
        public:
                regex(const char *);
                regex(const std::string & expression);
                virtual ~regex();

                std::vector<std::string> matches(const std::string & input,
                                                 size_t              mcount);

        private:
                void compile(const char * expression);

#if HAVE_REGEX_H
                regex_t buffer_;
#endif
        };

}

#endif
