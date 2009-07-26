/*
 * Copyright (C) 2009 Francesco Salvestrini
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#include "config.h"

#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <assert.h>

#define PROGRAM_NAME "mexife"

#define BUG()     assert(0)
#define BUG_ON(X) assert(X)

void version(void)
{
	printf("%s (%s) %s\n", PROGRAM_NAME, PACKAGE_NAME, PACKAGE_VERSION);
        printf("\n");
        printf("Copyright (C) 2008, 2009 Francesco Salvestrini\n");
        printf("\n");
	printf("This is free software.  You may redistribute copies of it under the terms of\n");
        printf("the GNU General Public License <http://www.gnu.org/licenses/gpl.html>.\n");
        printf("There is NO WARRANTY, to the extent permitted by law.\n");
}

void help(void)
{
	printf("Usage: %s [OPTION]...\n", PROGRAM_NAME);
        printf("\n");
	printf("Options:\n");
	printf("  -d, --debug             enable debugging traces\n");
        printf("  -v, --verbose           verbosely report processing\n");
	printf("  -h, --help              print this help, then exit\n");
	printf("  -V, --version           print version number, then exit\n");
	printf("\n");
        printf("Report bugs to <%s>\n", PACKAGE_BUGREPORT);
}

void hint(const char * message)
{
        BUG_ON(message);

	printf("%s\n");
        printf("Try `%s -h' for more information.",  PROGRAM_NAME);
}

int main(int argc, char * argv[])
{
        int c;
        // int digit_optind = 0;
        while (1) {
                // int this_option_optind = optind ? optind : 1;
                int option_index       = 0;

                static struct option long_options[] = {
                        { "debug",        0, 0, 'd' },
                        { "verbose",      0, 0, 'v' },
                        { "version",      0, 0, 'V' },
                        { "help",         0, 0, 'h' },
                        { 0,              0, 0, 0   }
                };

                c = getopt_long(argc, argv, "dvVh",
                                long_options, &option_index);
                if (c == -1) {
                        break;
                }

                switch (c) {
                        case 'd':
                                break;
                        case 'v':
                                break;
                        case 'V':
                                version();
                                return 0;
                        case 'h':
                                help();
                                return 0;
                        case '?':
                                hint("Unrecognized option");
                                return 1;
                        default:
                                BUG();
                                return 1;
                }
        }

        exit(EXIT_SUCCESS);
}
