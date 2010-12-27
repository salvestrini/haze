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

#include "core/log.hxx"
#include "core/debug.hxx"
#include "core/timer.hxx"

#include "gfx/video.hxx"
#include "gfx/image.hxx"
#include "gfx/font.hxx"
#include "gfx/text.hxx"
#include "gfx/primitive.hxx"

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
        Rectangle rectangle(0, 0, glyphs.width() / 16, glyphs.height() / 16);

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

#if 0
        Text text_message("this is a test", font);

        Text * text_chars[256];
        for (int i = 0; i < 256; i++) {
                text_chars[i] = new Text(std::string(1, static_cast<char>(i)),
                                         font);
        }
#endif
        Image       star_image(Path(datadir + "star.bmp"));
#if 0
        GL::Texture star1_texture(star_image);
        GL::Texture star2_texture(star_image);
        GL::Texture star3_texture(star_image);
#endif

        Delay d(10);

        GL::Pen pen_white (GL::Color(1.0f, 1.0f, 1.0f, 0.5f), 10.0);
        GL::Pen pen_red   (GL::Color(1.0f, 0.0f, 0.0f, 0.5f),  1.0);
        GL::Pen pen_green (GL::Color(0.0f, 1.0f, 0.0f, 0.5f),  1.0);
        GL::Pen pen_blue  (GL::Color(0.0f, 0.0f, 1.0f, 0.5f),  1.0);

        GL::Point     point(pen_white);
        GL::Line      line(pen_blue);
        GL::Rectangle rectangle_filled(pen_green, true);
        GL::Rectangle rectangle_empty(pen_green,  false);
        GL::Circle    circle_filled(pen_green, 5, 8,  true);
        GL::Circle    circle_empty(pen_blue,   5, 16, false);

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
                        point.draw(Point<GLfloat>(k % 100, k));
                }
#endif

#if 1
                line.draw(Point<GLfloat>(-1, -1), Point<GLfloat>(  1,   1));
                line.draw(Point<GLfloat>( 0,  0), Point<GLfloat>(100, 100));
                line.draw(Point<GLfloat>(50, 50), Point<GLfloat>(150,  50));
                line.draw(Point<GLfloat>(10, 10), Point<GLfloat>(200, 200));
#endif
#if 1
                rectangle_filled.draw(Point<GLfloat>(60, 60),
                                      Point<GLfloat>(80, 80));
#endif
#if 1
                rectangle_empty.draw(Point<GLfloat>(10, 10),
                                     Point<GLfloat>(30, 30));
#endif
#if 1
                circle_filled.draw(Point<GLfloat>(y + 10 , x + 10));
#endif
#if 1
                circle_empty.draw(Point<GLfloat>(x, y));
#endif
#if 0
                for (int k = 0; k < 256; k++) {
                        text_chars[k]->draw(Point<GLfloat>(k % 31));
                }
#endif
#if 0
                star1_texture.draw(Point<GLfloat>(x * 4, y * 4), 1, angle * 1);
                star2_texture.draw(Point<GLfloat>(x * 8, y * 8), 1, angle * 4);
                star3_texture.draw(Point<GLfloat>(video.width()  / 2,
                                                  video.height() / 2),
                                   1, angle * 8);
#endif
#if 0
                text_message.draw(video.width() / 2, video.height() / 2);
#endif

                video.update();

                d.wait();

                x++; y++; angle++;
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
