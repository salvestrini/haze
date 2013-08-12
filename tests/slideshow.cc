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

bool core(const haze::directory & datadir)
{
        using namespace haze;

        std::set<path *>      entries = datadir.entries();
        std::set<std::string> pictures;

        DBG("Got the following entries:");
        for (std::set<path *>::iterator iter = entries.begin();
             iter != entries.end();
             iter++) {
                DBG("  " << (*iter)->str() << " " <<
                    "(" << ((*iter)->is_file() ? "file" : "directory") << ")");
                if ((*iter)->is_file())
                        pictures.insert((*iter)->str());
                delete *iter;
        }

        DBG("Pictures to show:");
        for (std::set<std::string>::iterator iter = pictures.begin();
             iter != pictures.end();
             iter++)
                DBG("  " << *iter);

        video  video;
        haze::camera camera;

#if 0
        Image image(datadir + "font.png"));

DBG("Glyphs image is " << glyphs.width() << " x " << glyphs.height());

// Font image is 16x16 chars
Rectangle<size_t, size_t> rectangle(0,
                                    0,
                                    glyphs.width()  / 16,
                                    glyphs.height() / 16);

font font;

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
Image       star_image(path(datadir + "star.bmp"));
#if 1
GL::texture star1_texture(star_image);
GL::texture star2_texture(star_image);
GL::texture star3_texture(star_image);
#endif

time t;

GL::Pen pen_white (GL::color(1.0f, 1.0f, 1.0f, 0.5f), 10.0);
GL::Pen pen_red   (GL::color(1.0f, 0.0f, 0.0f, 0.5f),  1.0);
GL::Pen pen_green (GL::color(0.0f, 1.0f, 0.0f, 0.5f),  1.0);
GL::Pen pen_blue  (GL::color(0.0f, 0.0f, 1.0f, 0.5f),  1.0);

GL::point     point(pen_white);
GL::segment   segment(pen_blue,
                      MATH::point<GLfloat>(0.0f, 0.0f),
                      MATH::point<GLfloat>(1.0f, 1.0f));
GL::Rectangle rectangle_filled(pen_green,
                               MATH::point<GLfloat>(60, 60),
                               MATH::point<GLfloat>(80, 80),
                               true);
GL::Rectangle rectangle_empty(pen_green,
                              MATH::point<GLfloat>(10, 10),
                              MATH::point<GLfloat>(30, 30),
                              false);
GL::circle    circle_filled(pen_green,
                            MATH::point<GLfloat>(70, 15),
                            180,
                            8,
                            true);
GL::circle    circle_empty(pen_blue,
                           MATH::point<GLfloat>(10, 75),
                           220,
                           8,
                           false);

fps fps(30);

//
// Main loop
//

GLfloat x     = 0.0f;
GLfloat y     = 0.0f;
GLfloat angle = 0.0f;

IO::event_manager io;

VIEW::Orthogonal view(video.width(), video.height());

for (;;) {
        video.clear();

        //camera.direction(angle, angle, angle);
        //camera.position(x, y, +25.0f);

#if 0
        for (int k = -1000;
             k < 1000;
             k += 5) {
                point.move(MATH::point<GLfloat>(k % 100, k));
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
                        move(MATH::point<GLfloat>(100 + k % 16 * 32,
                                                  100 + k / 16 * 32));
                text_chars[k]->draw();
        }
#endif
#if 1
        star1_texture.move(MATH::point<GLfloat>(x * 4, y * 4));
        star1_texture.rotate(angle * 1);

        star2_texture.move(MATH::point<GLfloat>(x * 8, y * 8));
        star2_texture.rotate(angle * 4);

        star3_texture.move(MATH::point<GLfloat>(video.width()  / 2,
                                                video.height() / 2));
        star3_texture.rotate(angle * 8);

        star1_texture.draw();
        star2_texture.draw();
        star3_texture.draw();
#endif
#if 1
        text_message.move(MATH::point<GLfloat>(video.width() / 2,
                                               video.height() / 2));
        text_message.draw();
#endif

        video.update();

        t.delay(10);

        x++;
        y++;
        angle++;

        (void) fps.rate();

        IO::event * e = io.poll();
        if (e) {
                DBG("Got event!");
                switch (e->type()) {
                        case IO::event::application_quit:
                                delete e;
                                return;

                        case IO::event::video_resize: {
                                IO::video_resize * p =
                                        dynamic_cast<IO::video_resize *>(e);

                                video.resize(p->width(), p->height());
                                break;
                        }
                        case IO::event::key_down:
                        case IO::event::key_up:
                                break;
                        default:
                                break;
                }

                delete e;
        } else {
                //DBG("No event in queue");
        }
 }
#endif

return true;
}

int main(int argc, char * argv[])
{
        LOGS_PREFIX_SET("slideshow");

        int retval = EXIT_FAILURE;

        try {
                if (argc <= 1) {
                        ERR("Missing data directory");
                        return EXIT_FAILURE;
                }

                haze::path datadir(argv[1]);
                if (!datadir.is_directory()) {
                        ERR("path " << datadir.str() << " "
                            "is not a directory");
                        return EXIT_FAILURE;
                }

                haze::directory * dir = new haze::directory(datadir.str());
                retval = core(*dir) ? EXIT_SUCCESS : EXIT_FAILURE;
                delete dir;

        } catch (std::exception & e) {
                ERR("Got exception: " << e.what());
        } catch (...) {
                BUG();
        }

        DBG("Completed with" <<  (retval ? "" : "out") << " errors");

        return retval;
}
