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

        Text text_message("this is a test", font);

        Text * text_chars[256];
        for (int i = 0; i < 256; i++) {
                text_chars[i] = new Text(std::string(1, static_cast<char>(i)),
                                         font);
        }

        Image       star_image(Path(datadir + "star.bmp"));
        GL::Texture star1_texture(star_image);
        GL::Texture star2_texture(star_image);

        Delay d(10);

        GLfloat x = 0.0f;
        GLfloat y = 0.0f;

        GL::Color     color_white (1.0, 1.0, 1.0, 1.0);
        GL::Color     color_red   (1.0, 0.0, 0.0, 1.0);
        GL::Color     color_green (0.0, 1.0, 0.0, 1.0);
        GL::Color     color_blue  (0.0, 0.0, 0.0, 1.0);

        GL::Point     point(color_green);
        GL::Line      line(color_blue);
        GL::Rectangle rectangle_filled(color_white, true);
        GL::Rectangle rectangle_empty(color_blue,   false);
        GL::Circle    circle_filled(color_green, 0.5, 8,  true);
        GL::Circle    circle_empty(color_blue,   0.5, 16, false);

        //
        // Draw
        //

        GLfloat angle = 0.0;
        
        for (int iteration = 0;
             iteration < 50;
             iteration++) {
                DBG("Iteration %d", iteration);

                video.clear();

#if 0
                point.draw(Point<GLfloat>(0.5f, 0.5f));
#endif
#if 0
                line.draw(Point<GLfloat>(50, 50), Point<GLfloat>(100, 100));
#endif
#if 0
                rectangle_filled.draw(Point<GLfloat>(10),
                                 Point<GLfloat>(0.5, 0.5));
#endif
#if 0
                rectangle_empty.draw(Point<GLfloat>(10, 10),
                                Point<GLfloat>(30, 30));
#endif
#if 0
                circle_filled.draw(Point<GLfloat>(y, x));
#endif
#if 0
                circle_empty.draw(Point<GLfloat>(x, y));
#endif

#if 1
                Point<GLfloat> p(x, y);
                for (int k = 0; k < 256; k++) {
                        text_chars[k]->draw(p);
                }
#endif

#if 1
                text_message.draw(x, y);
#endif

#if 1
                star1_texture.draw(Point<GLfloat>(x * 4, y * 4));
                star2_texture.draw(Point<GLfloat>(x * 8, y * 8), 4, angle);
#endif
                video.update();

                d.wait();

                x++; y++; angle += 1;
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
