//
// Copyright (C) 2012, 2013, 2014 Francesco Salvestrini
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

bool core(const haze::fs::directory & datadir)
{
        using namespace haze;

        std::set<fs::path *>  entries = datadir.entries();
        std::set<std::string> pictures;

        DBG("Got the following entries:");
        for (std::set<fs::path *>::iterator iter = entries.begin();
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

        haze::gfx::video video;
        haze::camera     camera;

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
Image       star_image(haze::fs::path(datadir + "star.bmp"));
#if 1
gl::texture star1_texture(star_image);
gl::texture star2_texture(star_image);
gl::texture star3_texture(star_image);
#endif

//time t;

gl::Pen pen_white (gl::color(1.0f, 1.0f, 1.0f, 0.5f), 10.0);
gl::Pen pen_red   (gl::color(1.0f, 0.0f, 0.0f, 0.5f),  1.0);
gl::Pen pen_green (gl::color(0.0f, 1.0f, 0.0f, 0.5f),  1.0);
gl::Pen pen_blue  (gl::color(0.0f, 0.0f, 1.0f, 0.5f),  1.0);

gl::point     point(pen_white);
gl::segment   segment(pen_blue,
                      math::point<GLfloat>(0.0f, 0.0f),
                      math::point<GLfloat>(1.0f, 1.0f));
gl::Rectangle rectangle_filled(pen_green,
                               math::point<GLfloat>(60, 60),
                               math::point<GLfloat>(80, 80),
                               true);
gl::Rectangle rectangle_empty(pen_green,
                              math::point<GLfloat>(10, 10),
                              math::point<GLfloat>(30, 30),
                              false);
gl::circle    circle_filled(pen_green,
                            math::point<GLfloat>(70, 15),
                            180,
                            8,
                            true);
gl::circle    circle_empty(pen_blue,
                           math::point<GLfloat>(10, 75),
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

io::event_manager io;

view::Orthogonal view(video.width(), video.height());

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

                haze::fs::path datadir(argv[1]);
                if (!datadir.is_directory()) {
                        ERR("path " << datadir.str() << " "
                            "is not a directory");
                        return EXIT_FAILURE;
                }

                haze::fs::directory * dir =
                        new haze::fs::directory(datadir.str());
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
