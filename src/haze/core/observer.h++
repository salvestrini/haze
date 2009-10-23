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

#ifndef HAZE_OBSERVER_H
#define HAZE_OBSERVER_H

#include <cassert>
#include <list>
#include <functional>
#include <algorithm>

namespace HAZE {

        template<typename T> class Observer {
        public:
                virtual void update(const T & parameters) = 0;
        };

        template<class T> class Subject {
        public:
                void attach(Observer<T> * observer) {
                        assert(observer);

                        observers_.push_back(observer);
                }

                void detach(Observer<T> * observer) {
                        assert(observer);

                        observers_.remove(observer);
                }

                void update() const {
                        std::for_each(observers_,
                                      std::mem_fun(&Observer<T>::update));
                }

        private:
                std::list<Observer<T> *> observers_;
        };

}

#endif
