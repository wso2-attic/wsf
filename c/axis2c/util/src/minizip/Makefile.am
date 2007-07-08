lib_LTLIBRARIES = libaxis2_minizip.la

libaxis2_minizip_la_SOURCES =	ioapi.c \
							unzip.c \
							archive_extract.c \
							crypt.c

libaxis2_minizip_la_LDFLAGS = -version-info $(VERSION_NO)

INCLUDES = 	-I$(top_builddir)/include \
            -I$(top_builddir)/platforms

EXTRA_DIST=	axis2_archive_extract.h \
			axis2_crypt.h  \
			axis2_ioapi.h \
			axis2_iowin32.h \
			axis2_unzip.h \
			iowin32.c
