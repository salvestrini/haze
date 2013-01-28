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

        regex::regex(const std::string & expression)
        { compile(expression.c_str()); }

        regex::regex(const char * expression)
        { compile(expression); }

        regex::~regex()
        { regfree(&buffer_); }

        void regex::compile(const char * expression)
        {
                ASSERT(expression != 0);

                DBG("Compiling regex " << quote(expression));

                int rc = regcomp(&buffer_,
                                 expression,
                                 REG_ICASE | REG_EXTENDED | REG_NEWLINE);
                ASSERT(rc == 0);
        }

        std::vector<std::string> regex::matches(const std::string & input,
                                                size_t              mcount)
        {
                DBG("Matching " << quote(input) << " against regex buffer");

                ASSERT(mcount >= 1);

                regmatch_t               matches[mcount];
                std::vector<std::string> tmp;

                if (regexec(&buffer_,
                            input.c_str(),
                            mcount,
                            matches,
                            0) == 0) {
                        DBG("Got matches:");
                        for (size_t i = 0; i < mcount; i++) {
                                std::string s(input.c_str() +
                                              matches[i].rm_so,
                                              (matches[i].rm_eo -
                                               matches[i].rm_so));
                                if (matches[i].rm_so != -1) {
                                        tmp.push_back(s);
                                }
                        }
                } else {
                        DBG("No match!");
                }

                return tmp;
        }

}
