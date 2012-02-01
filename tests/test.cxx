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

#include <string>

#include "haze/haze.hxx"

#include "config.hxx"

void test(const std::string & datadir)
{
        using namespace HAZE;

        //
        // Setup
        //

        Video video;

        Camera camera;

        Image glyphs(Path(datadir + "font.png"));

        DBG("Glyphs image is %lu x %lu", glyphs.width(), glyphs.height());

        // Font image is 16x16 chars
        Rectangle<size_t, size_t> rectangle(0,
                                            0,
                                            glyphs.width()  / 16,
                                            glyphs.height() / 16);

        Font font;

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
        Text text_message("this is a test", font);
#endif
#if 1
        Text * text_chars[256];
        for (int i = 0; i < 256; i++) {
                text_chars[i] = new Text(std::string(1, static_cast<char>(i)),
                                         font);
        }
#endif
        Image       star_image(Path(datadir + "star.bmp"));
#if 1
        GL::Texture star1_texture(star_image);
        GL::Texture star2_texture(star_image);
        GL::Texture star3_texture(star_image);
#endif

        Time t;

        GL::Pen pen_white (GL::Color(1.0f, 1.0f, 1.0f, 0.5f), 10.0);
        GL::Pen pen_red   (GL::Color(1.0f, 0.0f, 0.0f, 0.5f),  1.0);
        GL::Pen pen_green (GL::Color(0.0f, 1.0f, 0.0f, 0.5f),  1.0);
        GL::Pen pen_blue  (GL::Color(0.0f, 0.0f, 1.0f, 0.5f),  1.0);

        GL::Point     point(pen_white);
        GL::Segment   segment(pen_blue,
                              MATH::Point<GLfloat>(0.0f, 0.0f),
                              MATH::Point<GLfloat>(1.0f, 1.0f));
        GL::Rectangle rectangle_filled(pen_green,
                                       MATH::Point<GLfloat>(60, 60),
                                       MATH::Point<GLfloat>(80, 80),
                                       true);
        GL::Rectangle rectangle_empty(pen_green,
                                      MATH::Point<GLfloat>(10, 10),
                                      MATH::Point<GLfloat>(30, 30),
                                      false);
        GL::Circle    circle_filled(pen_green,
                                    MATH::Point<GLfloat>(70, 15),
                                    180,
                                    8,
                                    true);
        GL::Circle    circle_empty(pen_blue,
                                   MATH::Point<GLfloat>(10, 75),
                                   220,
                                   8,
                                   false);

        FPS fps(30);

        //
        // Main loop
        //

        GLfloat x     = 0.0f;
        GLfloat y     = 0.0f;
        GLfloat angle = 0.0f;

        IO::EventManager io;

        for (;;) {
                video.clear();

                //camera.direction(angle, angle, angle);
                //camera.position(x, y, +25.0f);

#if 0
                for (int k = -1000;
                     k < 1000;
                     k += 5) {
                        point.move(MATH::Point<GLfloat>(k % 100, k));
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
                                move(MATH::Point<GLfloat>(100 + k % 16 * 32,
                                                          100 + k / 16 * 32));
                        text_chars[k]->draw();
                }
#endif
#if 1
                star1_texture.move(MATH::Point<GLfloat>(x * 4, y * 4));
                star1_texture.rotate(angle * 1);

                star2_texture.move(MATH::Point<GLfloat>(x * 8, y * 8));
                star2_texture.rotate(angle * 4);

                star3_texture.move(MATH::Point<GLfloat>(video.width()  / 2,
                                                        video.height() / 2));
                star3_texture.rotate(angle * 8);

                star1_texture.draw();
                star2_texture.draw();
                star3_texture.draw();
#endif
#if 1
                text_message.move(MATH::Point<GLfloat>(video.width() / 2,
                                                       video.height() / 2));
                text_message.draw();
#endif

                video.update();

                t.delay(10);

                x++;
                y++;
                angle++;

                (void) fps.rate();

                IO::Event * e = io.poll();
                if (e) {
                        DBG("Got event!");
                        switch (e->type()) {
                                case IO::Event::ApplicationQuit:
                                        delete e;
                                        return;

                                case IO::Event::VideoResize: {
                                        IO::VideoResize * p =
                                                dynamic_cast<IO::VideoResize *>(e);

                                        video.resize(p->width(), p->height());
                                        break;
                                }
                                case IO::Event::KeyDown:
                                case IO::Event::KeyUp:
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
        LOG_SETPREFIX("test");

        std::string datadir(std::string(DATAPATH) + "/");
        if (argc > 1) {
                datadir = std::string(argv[1]);
        }

        int retval = EXIT_FAILURE;

        try {
                test(datadir);
                retval = EXIT_SUCCESS;
        } catch (std::exception & e) {
                ERR("Got exception: %s", e.what());
        } catch (...) {
                BUG();
        }

        DBG("Completed with%s errors", (retval ? "" : "out"));

        return retval;
}
