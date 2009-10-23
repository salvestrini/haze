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

#ifndef HAZE_LABEL_H
#define HAZE_LABEL_H

#include <string>

#include "haze/gfx/rectangle.h++"
#include "haze/gfx/font.h++"
#include "haze/ui/widget.h++"

namespace HAZE {

        class Label : public RectangularWidget {
        public:
                Label(const std::string & name,
                      const Font &        font,
                      const std::string & text) :
                        RectangularWidget(name,
                                          Size(font.width(text),
                                               font.height(text))),
                        font_(font),
                        text_(text) { }

                const std::string & text() const { return text_; }

                void text(const std::string & t) { text_ = t; }

        protected:
                const Font & font_;
                std::string  text_;

        private:
        };

}

#endif // HAZE_LABEL_H
