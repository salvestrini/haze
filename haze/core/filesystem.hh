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

#ifndef HAZE_CORE_FILESYSTEM
#define HAZE_CORE_FILESYSTEM

#include <string>
#include <set>

#include "haze/core/exception.hh"

namespace HAZE {

        class Path {
        public:
                Path(const std::string & p) : path_(p) { }
                virtual ~Path() { }

                class CannotStat : public Exception {
                public:
                        CannotStat(const std::string & what) :
                                Exception(what) { }
                        CannotStat(const char * what) :
                                Exception(what) { }
                };

                virtual bool isFile() const;
                virtual bool isDirectory() const;
                virtual bool exists() const;

                virtual std::string str() const
                { return path_; }

                Path operator+(const Path & rhs);

        private:
                std::string path_;
        };

        class File : public Path {
        public:
                File(const std::string & p) : Path(p) { }
                virtual ~File() { }

                virtual bool isFile() const
                { return true; }

                virtual bool isDirectory() const
                { return false; }

        private:
        };

        class Directory : public Path {
        public:
                Directory(const std::string & p) : Path(p) { }
                virtual ~Directory() { }

                class CannotWalk : public Exception {
                public:
                        CannotWalk(const std::string & what) :
                                Exception(what) { }
                        CannotWalk(const char * what) :
                                Exception(what) { }
                };

                std::set<Path *> entries() const;

                virtual bool isFile() const
                { return false;}

                virtual bool isDirectory() const
                { return true; }

        private:
        };

}

#endif
