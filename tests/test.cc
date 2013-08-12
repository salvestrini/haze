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

#include <string>

#include "haze/haze.hh"

#include "data.hh"

void test(const std::string & datadir)
{
        using namespace haze;

        //
        // Setup
        //

        haze::video  video;

        haze::camera camera;

        image        glyphs(path(datadir + "font.png"));

        DBG("Glyphs image is " << glyphs.width() << " x " << glyphs.height());

        // Font image is 16x16 chars
        haze::rectangle<size_t, size_t> rectangle(0,
                                                  0,
                                                  glyphs.width()  / 16,
                                                  glyphs.height() / 16);

        haze::font font;

        {
                char c = 0;
                for (int y = 0; y < 16; y++) {
                        for (int x = 0; x < 16; x++) {
                                rectangle.move(x * rectangle.width(),
                                               y * rectangle.height(),
                                               0.0f);
                                font.add(c, glyphs.clip(rectangle));

                                c++;
                        }
                }
        }

#if 1
        text text_message("this is a test", font);
#endif
#if 1
        text * text_chars[256];
        for (int i = 0; i < 256; i++) {
                text_chars[i] = new text(std::string(1, static_cast<char>(i)),
                                         font);
        }
#endif
        image star_image(path(datadir + "star.bmp"));
#if 1
        GL::texture star1_texture(star_image);
        GL::texture star2_texture(star_image);
        GL::texture star3_texture(star_image);
#endif

        haze::time t;

        GL::pen pen_white (GL::color(1.0f, 1.0f, 1.0f, 0.5f), 10.0);
        GL::pen pen_red   (GL::color(1.0f, 0.0f, 0.0f, 0.5f),  1.0);
        GL::pen pen_green (GL::color(0.0f, 1.0f, 0.0f, 0.5f),  1.0);
        GL::pen pen_blue  (GL::color(0.0f, 0.0f, 1.0f, 0.5f),  1.0);

        GL::point     point(pen_white);
        GL::segment   segment(pen_blue,
                              math::point<GLfloat>(0.0f, 0.0f),
                              math::point<GLfloat>(1.0f, 1.0f));
        GL::rectangle rectangle_filled(pen_green,
                                       math::point<GLfloat>(60, 60),
                                       math::point<GLfloat>(80, 80),
                                       true);
        GL::rectangle rectangle_empty(pen_green,
                                      math::point<GLfloat>(10, 10),
                                      math::point<GLfloat>(30, 30),
                                      false);
        GL::circle    circle_filled(pen_green,
                                    math::point<GLfloat>(70, 15),
                                    180,
                                    8,
                                    true);
        GL::circle    circle_empty(pen_blue,
                                   math::point<GLfloat>(10, 75),
                                   220,
                                   8,
                                   false);

        haze::fps fps(30);

        //
        // Main loop
        //

        GLfloat x     = 0.0f;
        GLfloat y     = 0.0f;
        GLfloat angle = 0.0f;

        io::event_manager io;

        view::orthogonal view(video.width(), video.height());

        for (;;) {
                video.clear();

                //camera.direction(angle, angle, angle);
                //camera.position(x, y, +25.0f);

#if 0
                for (int k = -1000;
                     k < 1000;
                     k += 5) {
                        point.move(math::point<GLfloat>(k % 100, k));
                        point.draw();
                }
#endif

#if 1
                segment.draw();
#endif
#if 1
                rectangle_filled.draw();
#endif
#if 1
                rectangle_empty.draw();
#endif
#if 1
                circle_filled.draw();
#endif
#if 1
                circle_empty.draw();
#endif
#if 0
                for (int k = 0; k < 256; k++) {
                        text_chars[k]->
                                move(math::point<GLfloat>(100 + k % 16 * 32,
                                                          100 + k / 16 * 32));
                        text_chars[k]->draw();
                }
#endif
#if 1
                star1_texture.move(math::point<GLfloat>(x * 4, y * 4));
                star1_texture.rotate(angle * 1);

                star2_texture.move(math::point<GLfloat>(x * 8, y * 8));
                star2_texture.rotate(angle * 4);

                star3_texture.move(math::point<GLfloat>(video.width()  / 2,
                                                        video.height() / 2));
                star3_texture.rotate(angle * 8);

                star1_texture.draw();
                star2_texture.draw();
                star3_texture.draw();
#endif
#if 1
                text_message.move(math::point<GLfloat>(video.width() / 2,
                                                       video.height() / 2));
                text_message.draw();
#endif

                video.update();

                t.delay(10);

                x++;
                y++;
                angle++;

                (void) fps.rate();

                io::event * e = io.poll();
                if (e) {
                        DBG("Got event!");
                        switch (e->type()) {
                                case io::event::application_quit:
                                        delete e;
                                        return;

                                case io::event::video_resize: {
                                        io::video_resize * p =
                                                dynamic_cast<io::video_resize *>(e);

                                        video.resize(p->width(), p->height());
                                        break;
                                }
                                case io::event::key_down:
                                case io::event::key_up:
                                        break;
                                default:
                                        break;
                        }

                        delete e;
                } else {
                        //DBG("No event in queue");
                }
        }

}

int main(int argc, char * argv[])
{
        LOGS_PREFIX_SET("test");

        std::string datadir(std::string(DATAPATH) + "/");
        if (argc > 1) {
                datadir = std::string(argv[1]);
        }

        int retval = EXIT_FAILURE;

        try {
                test(datadir);
                retval = EXIT_SUCCESS;
        } catch (std::exception & e) {
                ERR("Got exception: " << e.what());
        } catch (...) {
                BUG();
        }

        DBG("Completed with" <<  (retval ? "" : "out") << " errors");

        return retval;
}
