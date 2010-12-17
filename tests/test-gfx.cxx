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

#include "gfx/video.hxx"
#include "gfx/image.hxx"
#include "gfx/font.hxx"
#include "gfx/text.hxx"
#include "gfx/object.hxx"

void test(const std::string & datadir)
{
        using namespace HAZE;

        Video video;
        Image image(Path(datadir + "font.png"));

        // Font image is 16x16 chars
        Rectangle rectangle(0, 0, image.width() / 16, image.height() / 16);

        Font font;
        for (int i = 0; i < 16; i++) {
                for (int j = 0; j < 16; j++) {
                        rectangle.move(i * 16, j * 16);
                        font.add(i + j, image.clip(rectangle));
                }
        }

        Text    text("this is a test", font);
        Texture texture(image);

        Object o;

        o.draw();
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
