prgbindir=$(prefix)/bin/test/framework/samples
prgbin_PROGRAMS = sample
noinst_HEADERS = sample.h
sample_SOURCES = sample.c test_sample1.c test_sample2.c

sample_LDADD   = $(LDFLAGS) \
                        ../src/libwso2_wsfc_unit.la

INCLUDES = -I ../include

