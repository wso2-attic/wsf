prglibdir=$(prefix)/services/sg_math
samplesdir=$(prefix)/samples/server/sg_math
prglib_LTLIBRARIES = libadd.la libsub.la libmul.la libdiv.la
samples_DATA=services.xml \
                add.h add.c add_skeleton.c \
                sub.h sub.c sub_skeleton.c \
                mul.h mul.c mul_skeleton.c \
                div.h div.c div_skeleton.c \
                Makefile.am Makefile.in
prglib_DATA=services.xml
EXTRA_DIST = services.xml sg_math.mk
noinst_HEADERS = add.h sub.h mul.h div.h
libadd_la_SOURCES = add.c add_skeleton.c
libsub_la_SOURCES = sub.c sub_skeleton.c
libmul_la_SOURCES = mul.c mul_skeleton.c
libdiv_la_SOURCES = div.c div_skeleton.c
INCLUDES = -I$(AXIS2C_HOME)/include/axis2-1.0 \
			@UTILINC@ \
			@AXIOMINC@
