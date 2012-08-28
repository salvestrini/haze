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
#include <dirent.h>

#include "haze/core/utils.hh"
#include "haze/core/filesystem.hh"

namespace HAZE {

        std::set<Path *> Directory::items()
        {
                DIR * dir = opendir(name().c_str());
                if (dir == 0)
                        throw CannotWalk(strerror(errno));

                std::set<Path *> tmp;

                // Ugly use of dirent follows ...
                struct dirent * d;
                while ((d = readdir(dir)) != 0) {
                        if (d->d_type == DT_DIR) {
                                tmp.insert(new Directory(d->d_name));
                        } else if (d->d_type == DT_REG) {
                                tmp.insert(new File(d->d_name));
                        } else {
                                closedir(dir);
                                throw CannotWalk("Unhandled type for path " +
                                                 quote(d->d_name));
                        }
                }

                closedir(dir);
                return tmp;
        }

}
