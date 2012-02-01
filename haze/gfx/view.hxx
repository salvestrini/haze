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

#ifndef HAZE_GFX_VIEW
#define HAZE_GFX_VIEW

#include "haze/core/log.hxx"
#include "haze/gfx/gl.hxx"

namespace HAZE {

        namespace VIEW {

                class Perspective {
                public:
                        Perspective() {
                                glMatrixMode(GL_PROJECTION);
                                glPushMatrix();

                                glMatrixMode(GL_MODELVIEW);
                                glPushMatrix();

                                DBG("Perspective enabled");

                                glEnable(GL_DEPTH_TEST);
                        }

                        virtual ~Perspective() {
                                glPopMatrix();
                                glPopMatrix();

                                DBG("Perspective disabled");

                                glDisable(GL_DEPTH_TEST);
                        }
                };

                class Orthogonal {
                public:
                        Orthogonal(GLdouble width,
                                   GLdouble height) {
                                glMatrixMode(GL_PROJECTION);
                                glPushMatrix();

                                glLoadIdentity();

                                glOrtho(0,       // Left
                                        width,   // Right
                                        height,  // Bottom
                                        0,       // Top
                                        -1,      // near
                                        1);      // far

                                glMatrixMode(GL_MODELVIEW);
                                glPushMatrix();

                                glLoadIdentity();

                                DBG("Orthogonal enabled");
                        }

                        virtual ~Orthogonal() {
                                glPopMatrix();
                                glPopMatrix();

                                DBG("Orthogonal disabled");
                        }
                };

        }
}

#endif