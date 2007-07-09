TESTS = test_sha test_util
bin_PROGRAMS = test_sha test_util
SUBDIRS =
AM_CFLAGS = -g -O2 -pthread
test_sha_SOURCES = test_sha.c
test_util_SOURCES = test_util.c


test_sha_LDADD   = $(top_builddir)/src/util/librampart_util.la\
		   -laxis2_util

test_util_LDADD   = $(top_builddir)/src/util/librampart_util.la\
		   -laxis2_util
		   

INCLUDES = -I$(top_builddir)/include \
			@UTILINC@ 

