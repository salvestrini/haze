//
// Copyright (C) 2010 Francesco Salvestrini
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

#include <cstdlib>
#include <string>

#include "haze/core/log.hxx"
#include "haze/core/debug.hxx"
#include "haze/core/time.hxx"
#include "haze/gfx/video.hxx"
#include "haze/gfx/image.hxx"
#include "haze/gfx/font.hxx"
#include "haze/gfx/text.hxx"
#include "haze/gfx/primitive.hxx"

void test(const std::string & datadir)
{
        using namespace HAZE;

        //
        // Setup
        //

        Video video;

        Image glyphs(Path(datadir + "font.png"));

        DBG("Glyphs image is %d x %d", glyphs.width(), glyphs.height());

        // Font image is 16x16 chars
        Rectangle<size_t, size_t> rectangle(0,
                                            0,
                                            glyphs.width()  / 16,
                                            glyphs.height() / 16);

        Font font;

        char c = 0;

        for (int y = 0; y < 16; y++) {
                for (int x = 0; x < 16; x++) {
                        rectangle.move(x * rectangle.width(),
                                       y * rectangle.height());
                        font.add(c, glyphs.clip(rectangle));

                        c++;
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
        GL::Line      line(pen_blue,
                           HAZE::Point<GLfloat>(0.0f, 0.0f),
                           HAZE::Point<GLfloat>(1.0f, 1.0f));
        GL::Rectangle rectangle_filled(pen_green,
                                       Point<GLfloat>(60, 60),
                                       Point<GLfloat>(80, 80),
                                       true);
        GL::Rectangle rectangle_empty(pen_green,
                                      Point<GLfloat>(10, 10),
                                      Point<GLfloat>(30, 30),
                                      false);
        GL::Circle    circle_filled(pen_green,
                                    Point<GLfloat>(70, 15),
                                    180,
                                    8,
                                    true);
        GL::Circle    circle_empty(pen_blue,
                                   Point<GLfloat>(10, 75),
                                   220,
                                   8,
                                   false);

        //
        // Draw
        //

        GLfloat x     = 0.0f;
        GLfloat y     = 0.0f;
        GLfloat angle = 0.0f;
        
        for (int iteration = 0;
             iteration < 100;
             iteration++) {
                DBG("Iteration %d", iteration);

                video.clear();

#if 1
                for (int k = -1000;
                     k < 1000;
                     k += 5) {
                        point.move(Point<GLfloat>(k % 100, k));
                        point.draw();
                }
#endif

#if 1
                line.draw();
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
#if 1
                for (int k = 0; k < 256; k++) {
                        text_chars[k]->move(Point<GLfloat>(100 + k % 16 * 32,
                                                           100 + k / 16 * 32));
                        text_chars[k]->draw();
                }
#endif
#if 1
                star1_texture.draw(Point<GLfloat>(x * 4, y * 4), 1, angle * 1);
                star2_texture.draw(Point<GLfloat>(x * 8, y * 8), 1, angle * 4);
                star3_texture.draw(Point<GLfloat>(video.width()  / 2,
                                                  video.height() / 2),
                                   1, angle * 8);
#endif
#if 1
                text_message.move(Point<GLfloat>(video.width() / 2,
                                                 video.height() / 2));
                text_message.draw();
#endif

                video.update();

                t.delay(10);

                x++;
                y++;
                angle++;
        }

}

int main(int argc, char * argv[])
{
        LOG_SETPREFIX("test");

        std::string datadir("./");
        if (argc > 1) {
                datadir = std::string(argv[1]);
        }

        int retval = EXIT_FAILURE;

        try {
                test(datadir);
                retval = EXIT_SUCCESS;
        } catch (std::exception & e) {
                ERR("%s", e.what());
        } catch (...) {
                BUG();
        }

        DBG("Completed with%s errors", (retval ? "" : "out"));

        return retval;
}
