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

#include "core/log.hxx"
#include "core/debug.hxx"
#include "core/thread.hxx"

class T : public HAZE::Thread {
public:
        T(const std::string & n) : Thread(n) { }
        
        virtual void loop() {
#if 0
                static int i = 0;
                
                DBG("loop %d", i++);
#endif
        }
};

int main(int argc, char * argv[])
{
        LOG_SETPREFIX("test");

        int retval = EXIT_FAILURE;

        try {
                T x("test");

                x.start();

                sleep(500);
                
                //x.stop();

                retval = EXIT_SUCCESS;

        } catch (std::exception & e) {
                BUG("Uncaught exception");
        } catch (...) {
                BUG("Unknown exception");
        }

        DBG("Completed with%s errors", (retval ? "" : "out"));

        return retval;
}
