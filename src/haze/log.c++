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

#include <iostream>

#include "haze/log.h++"

namespace HAZE {

        Log log("haze: ");

        Log::Log(const std::string & prefix) :
                prefix_(prefix),
                newline_(true)
        { }

        Log & Log::endl(Log & l)
        { return l; }

        Log & Log::operator<<(const std::string & v)
        {
                if (newline_) {
                        std::cout << prefix_;
                        newline_ = false;
                }
                std::cout << v;

                return (*this);
        }

        Log & Log::operator<<(int v)
        {
                if (newline_) {
                        std::cout << prefix_;
                        newline_ = false;
                }
                std::cout << v;

                return (*this);
        }

        Log & Log::operator<<(unsigned int v)
        {
                if (newline_) {
                        std::cout << prefix_;
                        newline_ = false;
                }
                std::cout << v;

                return (*this);
        }

        Log & Log::operator<<(char v)
        {
                if (newline_) {
                        std::cout << prefix_;
                        newline_ = false;
                }
                std::cout << v;

                return (*this);
        }


        Log & Log::operator<<(Log & (*m)(Log &))
        {
                if (m == Log::endl) {
                        std::cout << std::endl;
                        newline_ = true;
                }

                return (*this);
        }

}
