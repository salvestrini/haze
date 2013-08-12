//
// Copyright (C) 2012, 2013 Francesco Salvestrini
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

#ifndef HAZE_GFX_CAMERA
#define HAZE_GFX_CAMERA

#include "haze/core/pattern.hh"
#include "haze/gfx/math.hh"
#include "haze/gfx/backends/backend.hh"

namespace haze {

        class camera : public MATH::point<GLfloat> {
        public:
                camera(GLfloat x = 0.0f,
                       GLfloat y = 0.0f,
                       GLfloat z = 0.0f,
                       GLfloat p = 0.0f,
                       GLfloat h = 0.0f,
                       GLfloat r = 0.0f) :
                        MATH::point<GLfloat>(x, y, z)
                {
                        heading_ = h;
                        pitch_   = p;
                        roll_    = r;
                }

                virtual ~camera()
                { }

                void position(GLfloat x = 0.0f,
                              GLfloat y = 0.0f,
                              GLfloat z = 0.0f)
                {
                        move(x, y, z);

                        update();
                }

                void direction(GLfloat pitch,
                               GLfloat heading,
                               GLfloat roll)
                {
                        pitch_   = pitch;
                        heading_ = heading;
                        roll_    = roll;

                        update();
                }

                void set(GLfloat x,
                         GLfloat y,
                         GLfloat z,
                         GLfloat pitch,
                         GLfloat heading,
                         GLfloat roll)
                {
                        move(x, y, z);

                        pitch_   = pitch;
                        heading_ = heading;
                        roll_    = roll;

                        update();
                }

        private:
                GLfloat heading_;
                GLfloat pitch_;
                GLfloat roll_;

                void update()
                {
                        //glPushMatrix();

                        glMatrixMode(GL_PROJECTION);
                        glLoadIdentity();

                        // glFrustum( fovy, aspect, znear, zfar );

                        glMatrixMode(GL_MODELVIEW);
                        glLoadIdentity();

                        glRotatef(-pitch_,   1, 0, 0); // pitch   -> X
                        glRotatef(-roll_,    0, 1 ,0); // roll    -> Y
                        glRotatef(-heading_, 0, 0, 1); // heading -> Z

                        glTranslatef(-x(), -y(), -z());

                        //glPopMatrix();
                }
        };

}

#endif
