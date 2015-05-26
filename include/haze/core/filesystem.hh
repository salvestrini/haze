//
// Copyright (C) 2012, 2013, 2014 Francesco Salvestrini
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

#ifndef HAZE_CORE_FILESYSTEM
#define HAZE_CORE_FILESYSTEM

#include <string>
#include <set>

#include "haze/core/exception.hh"

namespace haze {

        class path {
        public:
                path(const std::string & p) : path_(p) { }
                virtual ~path() { }

                class cannot_stat : public exception {
                public:
                        cannot_stat(const std::string & what) :
                                exception(what) { }
                        cannot_stat(const char * what) :
                                exception(what) { }
                };

                virtual bool is_file() const;
                virtual bool is_directory() const;
                virtual bool exists() const;

                virtual std::string str() const
                { return path_; }

                path operator+(const path & rhs);

        private:
                std::string path_;
        };

        class file : public path {
        public:
                file(const std::string & p) : path(p) { }
                virtual ~file() { }

                virtual bool is_file() const
                { return true; }

                virtual bool is_directory() const
                { return false; }

        private:
        };

        class directory : public path {
        public:
                directory(const std::string & p) : path(p) { }
                virtual ~directory() { }

                class cannot_walk : public exception {
                public:
                        cannot_walk(const std::string & what) :
                                exception(what) { }
                        cannot_walk(const char * what) :
                                exception(what) { }
                };

                std::set<path *> entries() const;

                virtual bool is_file() const
                { return false; }

                virtual bool is_directory() const
                { return true; }

        private:
        };

}

#endif
