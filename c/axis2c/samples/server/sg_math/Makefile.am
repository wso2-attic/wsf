prglibdir=$(prefix)/services/sg_math
prglib_LTLIBRARIES = libadd.la libsub.la libmul.la libdiv.la
prglib_DATA=services.xml
EXTRA_DIST = services.xml sg_math.mk add.h div.h mul.h sub.h

noinst_HEADERS = add.h sub.h mul.h div.h
libadd_la_SOURCES = add.c add_skeleton.c
libsub_la_SOURCES = sub.c sub_skeleton.c
libmul_la_SOURCES = mul.c mul_skeleton.c
libdiv_la_SOURCES = div.c div_skeleton.c
INCLUDES = @AXIS2INC@
