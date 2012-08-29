//
// Copyright (C) 2012 Francesco Salvestrini
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

#include "haze/core/debug.hh"
#include "haze/core/log.hh"
#include "haze/core/regex.hh"
#include "haze/core/utils.hh"

namespace HAZE {

#if HAVE_REGEX_H
#define ERROR_BUFFER_SIZE 512

        std::string tostring(regex_t * regex, int errcode)
        {
                ASSERT(regex != 0);
                ASSERT(errcode != 0);

                char buffer[ERROR_BUFFER_SIZE];

                size_t s = regerror(errcode,
                                    regex,
                                    buffer,
                                    ERROR_BUFFER_SIZE);
                ASSERT(s <= ERROR_BUFFER_SIZE);

                return std::string(buffer);
        }
#endif

        Regex::Regex(const std::string & expression)
        { compile(expression.c_str()); }

        Regex::Regex(const char * expression)
        { compile(expression); }

        Regex::~Regex()
        { regfree(&buffer_); }

        void Regex::compile(const char * expression)
        {
                ASSERT(expression != 0);

                DBG("Compiling regex " << quote(expression));

                int rc = regcomp(&buffer_,
                                 expression,
                                 REG_ICASE | REG_EXTENDED | REG_NEWLINE);
                ASSERT(rc == 0);
        }

        std::vector<std::string> Regex::matches(const std::string & input)
        {
                DBG("Matching " << quote(input) << " against regex buffer");

                std::vector<std::string> tmp;

                if (regexec(&buffer_,
                            input.c_str(),
                            REGEX_MAX_MATCHES,
                            matches_,
                            0) == 0) {
                        DBG("Got matches:");
                        for (size_t i = 0; i < REGEX_MAX_MATCHES; i++) {
                                std::string s(input.c_str() +
                                              matches_[i].rm_so,
                                              (matches_[i].rm_eo -
                                               matches_[i].rm_so));
                                if (matches_[i].rm_so != -1) {
                                        tmp.push_back(s);
                                }
                        }
                } else {
                        DBG("No match!");
                }

                return tmp;
        }

}
