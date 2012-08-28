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

#include <string.h>
#include <errno.h>

#include <sys/types.h>

// For opendir()/readdir()/closedir()
#include <dirent.h>

// For stat()
#include <sys/stat.h>
#include <unistd.h>

#include "haze/core/log.hh"
#include "haze/core/utils.hh"
#include "haze/core/filesystem.hh"

namespace HAZE {

        bool Path::isFile() const
        {
                struct stat buf;

                if (stat(path_.c_str(), &buf) != 0)
                        throw CannotStat("Cannot stat path "        +
                                         quote(path_)               +
                                         "(" + strerror(errno) + ")");

                if (S_ISREG(buf.st_mode)) return true;
                return false;
        }

        bool Path::isDirectory() const
        {
                struct stat buf;

                if (stat(path_.c_str(), &buf) != 0)
                        throw CannotStat("Cannot stat path "        +
                                         quote(path_)               +
                                         "(" + strerror(errno) + ")");
                
                if (S_ISDIR(buf.st_mode)) return true;
                return false;
        }

        std::set<Path *> Directory::entries() const
        {
                DIR * dir = opendir(name().c_str());
                if (dir == 0)
                        throw CannotWalk(strerror(errno));

                std::set<Path *> tmp;

                // Ugly use of dirent follows ...
                struct dirent * d;
                while ((d = readdir(dir)) != 0) {
                        std::string name(d->d_name);

                        if (d->d_type == DT_DIR) {
                                if ((name == ".") || (name == ".."))
                                        continue;
                                tmp.insert(new Directory(name));
                        } else if (d->d_type == DT_REG) {
                                tmp.insert(new File(name));
                        } else {
                                closedir(dir);
                                throw CannotWalk("Unhandled type for path " +
                                                 quote(name));
                        }
                }

                closedir(dir);
                return tmp;
        }

}
