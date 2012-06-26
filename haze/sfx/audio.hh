//
// Copyright (C) 2012 Francesco Salvestrini
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

#include <map>
#include <string>
#include <vector>

#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

#include "haze/core/exception.hh"
#include "haze/core/filesystem.hh"

namespace HAZE {
        namespace SFX {

                class Audio {
                public:
                        class CannotInitialize : public Exception {
                        public:
                            CannotInitialize(const std::string & what) :
                                Exception(what) { }
                        };

                        Audio(size_t frequency = 44100,
                              size_t channels  = 2)
                                throw(CannotInitialize);
                        ~Audio();

                        size_t frequency();
                        size_t channels();

                private:
                        size_t frequency_;
                        size_t channels_;
                };

                class Music {
                public:
                        class CannotLoad : public Exception {
                        public:
                                CannotLoad(const Path &        path,
                                           const std::string & cause) :
                                        Exception(std::string("Cannot load ") +
                                                  std::string(path.c_str())   +
                                                  (!cause.empty() ?
                                                   ", " + cause   :
                                                   ""))
                                { }
                        };

                        Music();
                        ~Music();

                        typedef size_t milliseconds;

                        void   play(const Path & file,
                                    size_t       loops    = -1,
                                    milliseconds fade_in  = 0);
                        void   pause();
                        void   resume();
                        void   rewind();
                        void   stop();
                        void   fade(milliseconds time = 0);

                        void   volume(size_t value);
                        size_t volume();

                private:
                        Mix_Music * music_;
                };

                class Sample {
                public:
                        class CannotLoad : public Exception {
                        public:
                                CannotLoad(const Path &        path,
                                           const std::string & cause) :
                                        Exception(std::string("Cannot load ") +
                                                  std::string(path.c_str())   +
                                                  (!cause.empty() ?
                                                   ", " + cause   :
                                                   ""))
                                { }
                        };

                        Sample();
                        ~Sample();

                        size_t volume(size_t volume);

                private:
                        Mix_Chunk * sample_;
                        size_t      volume_;
                };

                class Channels {
                public:
                        Channels(size_t amount = 16);
                        ~Channels();

                        typedef size_t milliseconds;

                        size_t allocate(size_t amount);
                        size_t reserve(size_t index);
                        void   play(int          index,
                                    Sample *     sample,
                                    int          loops   = -1,
                                    milliseconds fade_in = 0,
                                    milliseconds delay   = 0);
                        void   stop(int          index,
                                    milliseconds delay = 0);
                        void   fade(int          index,
                                    milliseconds time = 0);
                        void   pause(int index);
                        void   resume(int index);

                private:
                        size_t              amount_;
                        std::vector<size_t> reserved_;
                };

                class Groups {
                public:
                        Groups(size_t amount = 16);
                        ~Groups();

                        typedef size_t milliseconds;

                        size_t assign(size_t channel,
                                      int    index);
                        size_t assign_range(size_t channel_from,
                                            size_t channel_to,
                                            int    index);
                        void   stop(int          index,
                                    milliseconds delay = 0);
                        void   fade(int          index,
                                    milliseconds time = 0);
                        size_t get_count(size_t index);
                        int    get_available(size_t index);
                        int    get_oldest(size_t index);
                        int    get_newer(size_t index);
                private:
                        std::map<size_t, std::vector<size_t> > relations;
                        std::vector<size_t>                    reserved_;
                };
        }
}

#endif
