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

#ifndef HAZE_CORE_FILESYSTEM
#define HAZE_CORE_FILESYSTEM

#include <string>

namespace HAZE {

        class Path {
        public:
                Path(const std::string & p) : path_(p) { }
                virtual ~Path() { }

                virtual bool isFile()
                { return false; }

                virtual bool isDirectory()
                { return false; }

                virtual bool exists()
                { return false; }

                virtual const char * c_str() const
                { return path_.c_str(); }

        private:
                std::string path_;
        };

        class File : public Path {
        public:
                File(const std::string & p) : Path(p) { }
                virtual ~File() { }

                virtual bool isFile()
                { return true; }

                virtual bool isDirectory()
                { return false; }

        private:
        };

        class Directory : public Path {
        public:
                Directory(const std::string & p) : Path(p) { }
                virtual ~Directory() { }

                virtual bool isFile()
                { return false;}

                virtual bool isDirectory()
                { return true; }

        private:
        };

}

#endif
