//
// Copyright (C) 2010 Francesco Salvestrini
//                    Alessandro Massignan
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

#ifndef HAZE_SFX_AUDIO
#define HAZE_SFX_AUDIO

#include "haze/core/exception.hxx"

namespace HAZE {
        namespace SFX {

                class Audio {
                public:
                        class CannotInitialize : public Exception {
                        public:
                            CannotInitialize(const std::string & what) :
                                Exception(what) { }
                        };

                        class WrongArgument : public Exception {
                        public:
                            WrongArgument(const std::string & which) :
                                Exception("Wrong argument(s) calling " +
                                          which                        +
                                          " method") { }
                        };

                        Audio()
                                throw(CannotInitialize);
                        virtual ~Audio();

                        virtual size_t channels();
                        virtual size_t frequency();
                        virtual size_t buffer();

                        virtual void open(size_t frequency,
                                          size_t format,
                                          size_t channels,
                                          size_t chunksize)
                                throw(CannotInitialize, WrongArgument);
                        virtual void close();
                private:
                        size_t channels_;
                        size_t frequency_;
                        size_t buffer_;
                };

        }

}

#endif
