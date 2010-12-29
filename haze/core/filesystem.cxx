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

#include "haze/core/filesystem.hxx"

namespace HAZE {

        Path::Path(const std::string & p) :
                path_(p)
        { }

        Path::~Path()
        { }

        Path Path::basename(const std::string & suffix)
        { return Path(path_); }
 
        Path Path::dirname()
        { return Path(path_); }

        bool Path::isFile()
        { return false; }

        bool Path::isDirectory()
        { return false; }

        bool Path::exists()
        { return false; }

        void Path::remove()
        { }

        const char * Path::c_str() const
        { return path_.c_str(); }

}
