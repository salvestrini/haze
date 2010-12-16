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

int main(int argc, char * argv[])
{
        LOG_SETPREFIX("test");

        std::string datadir("./");
        if (argc > 1) {
                datadir = std::string(argv[1]);
        }

        int retval = EXIT_SUCCESS;

        try {
                HAZE::Video v;
                HAZE::Path p(datadir + "font.png");
                HAZE::Image i(p);
                HAZE::Font f;
                HAZE::Text t("this is a test", f);
                
        } catch (std::exception & e) {
                ERR("%s", e.what());
        } catch (...) {
                BUG();
        }

        DBG("Completed with%s errors", (retval ? "" : "out"));

        return retval;
}
