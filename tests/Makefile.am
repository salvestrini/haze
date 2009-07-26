##
## Input file for automake
##
## Copyright (C) 2008, 2009 Francesco Salvestrini
##
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 2 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License along
## with this program; if not, write to the Free Software Foundation, Inc.,
## 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
##

include $(top_srcdir)/Makefile.sub

CLEANFILES =
EXTRA_DIST =

##
## NOTE:
##     In order to debug the tests during the 'distcheck' target use the
##     following TESTS_ENVIRONMENT:
##
##       TESTS_ENVIRONMENT = testdir=@abs_builddir@ DEBUG=x VERBOSE=x
##
TESTS_ENVIRONMENT = testdir=@abs_builddir@

scripts =					\
	defs

all-local: $(scripts)

##
## NOTE:
##   defs should not be made executable because it should be only included by
##   test-cases
##

# defs
defs: $(srcdir)/defs.in Makefile
	( rm -f $@ $@.tmp && \
	  $(do_subst) < $(srcdir)/defs.in > $@.tmp && \
	  chmod a-w $@.tmp && \
	  mv -f $@.tmp $@ ) || { \
		rm -f $@ $@.tmp ; \
		exit 1 ; \
	}
CLEANFILES += defs
EXTRA_DIST += defs.in

# Tests
FAIL_TESTS    =
SUCCESS_TESTS =

FAIL_TESTS +=					\
	test-fail				\
	test-parse-01				\
	test-transformation-01			\
	test-execution-04			\
	test-execution-05			\
	test-samefile-01			\
	test-multipath-01

SUCCESS_TESTS +=				\
	test-success				\
	test-dump-01				\
	test-debug				\
	test-verbose				\
	test-parse-02				\
	test-parse-03				\
	test-parse-04				\
	test-execution-01			\
	test-execution-02			\
	test-execution-03			\
	test-execution-06			\
	test-multiline-01			\
	test-antiloop-01			\
	test-include-01				\
	test-rules-01				\
	test-rules-02				\
	test-hint-01

XFAIL_TESTS  = $(FAIL_TESTS)
TESTS	     = $(FAIL_TESTS) $(SUCCESS_TESTS)

test-success: $(srcdir)/test-success.in Makefile
	( rm -f $@ $@.tmp && \
	  $(do_subst) < $(srcdir)/test-success.in > $@.tmp && \
	  chmod +x $@.tmp && \
	  chmod a-w $@.tmp && \
	  mv -f $@.tmp $@ ) || { \
		rm -f $@ $@.tmp ; \
		exit 1 ; \
	}
EXTRA_DIST += test-success.in
CLEANFILES += test-success

test-dump-01: $(srcdir)/test-dump-01.in Makefile
	( rm -f $@ $@.tmp && \
	  $(do_subst) < $(srcdir)/test-dump-01.in > $@.tmp && \
	  chmod +x $@.tmp && \
	  chmod a-w $@.tmp && \
	  mv -f $@.tmp $@ ) || { \
		rm -f $@ $@.tmp ; \
		exit 1 ; \
	}
EXTRA_DIST += test-dump-01.in
CLEANFILES += test-dump-01

test-debug: $(srcdir)/test-debug.in Makefile
	( rm -f $@ $@.tmp && \
	  $(do_subst) < $(srcdir)/test-debug.in > $@.tmp && \
	  chmod +x $@.tmp && \
	  chmod a-w $@.tmp && \
	  mv -f $@.tmp $@ ) || { \
		rm -f $@ $@.tmp ; \
		exit 1 ; \
	}
EXTRA_DIST += test-debug.in
CLEANFILES += test-debug

test-verbose: $(srcdir)/test-verbose.in Makefile
	( rm -f $@ $@.tmp && \
	  $(do_subst) < $(srcdir)/test-verbose.in > $@.tmp && \
	  chmod +x $@.tmp && \
	  chmod a-w $@.tmp && \
	  mv -f $@.tmp $@ ) || { \
		rm -f $@ $@.tmp ; \
		exit 1 ; \
	}
EXTRA_DIST += test-verbose.in
CLEANFILES += test-verbose

test-fail: $(srcdir)/test-fail.in Makefile
	( rm -f $@ $@.tmp && \
	  $(do_subst) < $(srcdir)/test-fail.in > $@.tmp && \
	  chmod +x $@.tmp && \
	  chmod a-w $@.tmp && \
	  mv -f $@.tmp $@ ) || { \
		rm -f $@ $@.tmp ; \
		exit 1 ; \
	}
EXTRA_DIST += test-fail.in
CLEANFILES += test-fail

test-samefile-01: $(srcdir)/test-samefile-01.in Makefile
	( rm -f $@ $@.tmp && \
	  $(do_subst) < $(srcdir)/test-samefile-01.in > $@.tmp && \
	  chmod +x $@.tmp && \
	  chmod a-w $@.tmp && \
	  mv -f $@.tmp $@ ) || { \
		rm -f $@ $@.tmp ; \
		exit 1 ; \
	}
EXTRA_DIST += test-samefile-01.in
CLEANFILES += test-samefile-01

test-transformation-01: $(srcdir)/test-transformation-01.in Makefile
	( rm -f $@ $@.tmp && \
	  $(do_subst) < $(srcdir)/test-transformation-01.in > $@.tmp && \
	  chmod +x $@.tmp && \
	  chmod a-w $@.tmp && \
	  mv -f $@.tmp $@ ) || { \
		rm -f $@ $@.tmp ; \
		exit 1 ; \
	}
EXTRA_DIST += test-transformation-01.in
CLEANFILES += test-transformation-01

test-parse-01: $(srcdir)/test-parse-01.in Makefile
	( rm -f $@ $@.tmp && \
	  $(do_subst) < $(srcdir)/test-parse-01.in > $@.tmp && \
	  chmod +x $@.tmp && \
	  chmod a-w $@.tmp && \
	  mv -f $@.tmp $@ ) || { \
		rm -f $@ $@.tmp ; \
		exit 1 ; \
	}
EXTRA_DIST += test-parse-01.in
CLEANFILES += test-parse-01

test-parse-02: $(srcdir)/test-parse-02.in Makefile
	( rm -f $@ $@.tmp && \
	  $(do_subst) < $(srcdir)/test-parse-02.in > $@.tmp && \
	  chmod +x $@.tmp && \
	  chmod a-w $@.tmp && \
	  mv -f $@.tmp $@ ) || { \
		rm -f $@ $@.tmp ; \
		exit 1 ; \
	}
EXTRA_DIST += test-parse-02.in
CLEANFILES += test-parse-02

test-parse-03: $(srcdir)/test-parse-03.in Makefile
	( rm -f $@ $@.tmp && \
	  $(do_subst) < $(srcdir)/test-parse-03.in > $@.tmp && \
	  chmod +x $@.tmp && \
	  chmod a-w $@.tmp && \
	  mv -f $@.tmp $@ ) || { \
		rm -f $@ $@.tmp ; \
		exit 1 ; \
	}
EXTRA_DIST += test-parse-03.in
CLEANFILES += test-parse-03

test-parse-04: $(srcdir)/test-parse-04.in Makefile
	( rm -f $@ $@.tmp && \
	  $(do_subst) < $(srcdir)/test-parse-04.in > $@.tmp && \
	  chmod +x $@.tmp && \
	  chmod a-w $@.tmp && \
	  mv -f $@.tmp $@ ) || { \
		rm -f $@ $@.tmp ; \
		exit 1 ; \
	}
EXTRA_DIST += test-parse-04.in
CLEANFILES += test-parse-04

test-execution-01: $(srcdir)/test-execution-01.in Makefile
	( rm -f $@ $@.tmp && \
	  $(do_subst) < $(srcdir)/test-execution-01.in > $@.tmp && \
	  chmod +x $@.tmp && \
	  chmod a-w $@.tmp && \
	  mv -f $@.tmp $@ ) || { \
		rm -f $@ $@.tmp ; \
		exit 1 ; \
	}
EXTRA_DIST += test-execution-01.in
CLEANFILES += test-execution-01

test-execution-02: $(srcdir)/test-execution-02.in Makefile
	( rm -f $@ $@.tmp && \
	  $(do_subst) < $(srcdir)/test-execution-02.in > $@.tmp && \
	  chmod +x $@.tmp && \
	  chmod a-w $@.tmp && \
	  mv -f $@.tmp $@ ) || { \
		rm -f $@ $@.tmp ; \
		exit 1 ; \
	}
EXTRA_DIST += test-execution-02.in
CLEANFILES += test-execution-02

test-execution-03: $(srcdir)/test-execution-03.in Makefile
	( rm -f $@ $@.tmp && \
	  $(do_subst) < $(srcdir)/test-execution-03.in > $@.tmp && \
	  chmod +x $@.tmp && \
	  chmod a-w $@.tmp && \
	  mv -f $@.tmp $@ ) || { \
		rm -f $@ $@.tmp ; \
		exit 1 ; \
	}
EXTRA_DIST += test-execution-03.in
CLEANFILES += test-execution-03

test-execution-04: $(srcdir)/test-execution-04.in Makefile
	( rm -f $@ $@.tmp && \
	  $(do_subst) < $(srcdir)/test-execution-04.in > $@.tmp && \
	  chmod +x $@.tmp && \
	  chmod a-w $@.tmp && \
	  mv -f $@.tmp $@ ) || { \
		rm -f $@ $@.tmp ; \
		exit 1 ; \
	}
EXTRA_DIST += test-execution-04.in
CLEANFILES += test-execution-04

test-execution-05: $(srcdir)/test-execution-05.in Makefile
	( rm -f $@ $@.tmp && \
	  $(do_subst) < $(srcdir)/test-execution-05.in > $@.tmp && \
	  chmod +x $@.tmp && \
	  chmod a-w $@.tmp && \
	  mv -f $@.tmp $@ ) || { \
		rm -f $@ $@.tmp ; \
		exit 1 ; \
	}
EXTRA_DIST += test-execution-05.in
CLEANFILES += test-execution-05

test-execution-06: $(srcdir)/test-execution-06.in Makefile
	( rm -f $@ $@.tmp && \
	  $(do_subst) < $(srcdir)/test-execution-06.in > $@.tmp && \
	  chmod +x $@.tmp && \
	  chmod a-w $@.tmp && \
	  mv -f $@.tmp $@ ) || { \
		rm -f $@ $@.tmp ; \
		exit 1 ; \
	}
EXTRA_DIST += test-execution-06.in
CLEANFILES += test-execution-06

test-hint-01: $(srcdir)/test-hint-01.in Makefile
	( rm -f $@ $@.tmp && \
	  $(do_subst) < $(srcdir)/test-hint-01.in > $@.tmp && \
	  chmod +x $@.tmp && \
	  chmod a-w $@.tmp && \
	  mv -f $@.tmp $@ ) || { \
		rm -f $@ $@.tmp ; \
		exit 1 ; \
	}
EXTRA_DIST += test-hint-01.in
CLEANFILES += test-hint-01

test-multipath-01: $(srcdir)/test-multipath-01.in Makefile
	( rm -f $@ $@.tmp && \
	  $(do_subst) < $(srcdir)/test-multipath-01.in > $@.tmp && \
	  chmod +x $@.tmp && \
	  chmod a-w $@.tmp && \
	  mv -f $@.tmp $@ ) || { \
		rm -f $@ $@.tmp ; \
		exit 1 ; \
	}
EXTRA_DIST += test-multipath-01.in
CLEANFILES += test-multipath-01

test-multiline-01: $(srcdir)/test-multiline-01.in Makefile
	( rm -f $@ $@.tmp && \
	  $(do_subst) < $(srcdir)/test-multiline-01.in > $@.tmp && \
	  chmod +x $@.tmp && \
	  chmod a-w $@.tmp && \
	  mv -f $@.tmp $@ ) || { \
		rm -f $@ $@.tmp ; \
		exit 1 ; \
	}
EXTRA_DIST += test-multiline-01.in
CLEANFILES += test-multiline-01

test-antiloop-01: $(srcdir)/test-antiloop-01.in Makefile
	( rm -f $@ $@.tmp && \
	  $(do_subst) < $(srcdir)/test-antiloop-01.in > $@.tmp && \
	  chmod +x $@.tmp && \
	  chmod a-w $@.tmp && \
	  mv -f $@.tmp $@ ) || { \
		rm -f $@ $@.tmp ; \
		exit 1 ; \
	}
EXTRA_DIST += test-antiloop-01.in
CLEANFILES += test-antiloop-01

test-include-01: $(srcdir)/test-include-01.in Makefile
	( rm -f $@ $@.tmp && \
	  $(do_subst) < $(srcdir)/test-include-01.in > $@.tmp && \
	  chmod +x $@.tmp && \
	  chmod a-w $@.tmp && \
	  mv -f $@.tmp $@ ) || { \
		rm -f $@ $@.tmp ; \
		exit 1 ; \
	}
EXTRA_DIST += test-include-01.in
CLEANFILES += test-include-01

test-rules-01: $(srcdir)/test-rules-01.in Makefile
	( rm -f $@ $@.tmp && \
	  $(do_subst) < $(srcdir)/test-rules-01.in > $@.tmp && \
	  chmod +x $@.tmp && \
	  chmod a-w $@.tmp && \
	  mv -f $@.tmp $@ ) || { \
		rm -f $@ $@.tmp ; \
		exit 1 ; \
	}
EXTRA_DIST += test-rules-01.in
CLEANFILES += test-rules-01

test-rules-02: $(srcdir)/test-rules-02.in Makefile
	( rm -f $@ $@.tmp && \
	  $(do_subst) < $(srcdir)/test-rules-02.in > $@.tmp && \
	  chmod +x $@.tmp && \
	  chmod a-w $@.tmp && \
	  mv -f $@.tmp $@ ) || { \
		rm -f $@ $@.tmp ; \
		exit 1 ; \
	}
EXTRA_DIST += test-rules-02.in
CLEANFILES += test-rules-02

clean-local:
	rm -rf testSubDir-*

##
## Maintainer related targets
##
update-local: Makefile

maintainer-check-local: Makefile
