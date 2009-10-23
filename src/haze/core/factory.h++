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

#ifndef HAZE_FACTORY_H
#define HAZE_FACTORY_H

#include <map>
#include <string>
#include <boost/shared_ptr.hpp>

namespace HAZE {

        template<class Key, class Type> class Factory {
        public:
                typedef boost::shared_ptr<Type> Data;

                Data get(const Key & key);

        protected:

        private:
                std::map<Key, Data> objects_;
        };

        template<class Key, class Type>
        typename Factory<Key, Type>::Data
        Factory<Key, Type>::get(const Key & key)
        {
                typename std::map<Key, Data>::iterator i;

                i = objects_.find(key);

                if (i == objects_.end()) {
                        Data tmp(new Type(key));
                        objects_.insert(std::make_pair(key, tmp));
                }

                return (*i).second;
        }

}

#endif // HAZE_FACTORY_H
