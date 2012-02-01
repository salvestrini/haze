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

#include "haze/gfx/gl.hxx"
#include "haze/gfx/view.hxx"

namespace HAZE {

        namespace VIEW {

                void perspective()
                {
                        glMatrixMode(GL_PROJECTION);
                        glPopMatrix();
                        glMatrixMode(GL_MODELVIEW);
                        glPopMatrix();
                        glEnable(GL_DEPTH_TEST);
                }

                void orthogonal(GLdouble width,
                                GLdouble height)
                {
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
                        glDisable(GL_DEPTH_TEST);
                }

        }
}
