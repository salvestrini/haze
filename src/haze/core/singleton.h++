// -*- c++ -*-

//
// Copyright (C) 2009 Francesco Salvestrini
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

#ifndef HAZE_LOG_H
#define HAZE_LOG_H

#include <string>

namespace HAZE {

        template <typename T> class Singleton {
        public:
                Singleton() { }
                ~Singleton() {
                        if (instance_) {
                                delete instance_;
                        }
                }

                Singleton * operator->() {
                        if (instance_ == 0) {
                                instance_ = new T();
                        }
                        return instance_;
                }

        private:
                Singleton(const Singleton &);
                Singleton & operator=(const Singleton &);

                static T * instance_;
        };

        template <typename T> T * Singleton<T>::instance_ = 0;

}

#endif
