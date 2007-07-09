prglibdir=$(prefix)/lib
prgbindir=$(prefix)/bin/tools

prglib_LTLIBRARIES = \
             libaxis2_tcpmon.la

libaxis2_tcpmon_la_SOURCES = \
            entry.c \
            session.c \
            util.c \
            $(NULL)

libaxis2_tcpmon_la_LIBADD = \
			 ../../../util/src/libaxutil.la \
			 ../../../axiom/src/om/libaxis2_axiom.la \
			 ../../../axiom/src/parser/$(WRAPPER_DIR)/libaxis2_parser.la \
            $(NULL)

prgbin_PROGRAMS = tcpmon

tcpmon_SOURCES =  tcpmon.c
tcpmon_LDADD =  \
             $(top_builddir)/src/libaxis2_tcpmon.la \
			 ../../../util/src/libaxutil.la \
			 ../../../axiom/src/om/libaxis2_axiom.la \
			 ../../../axiom/src/parser/$(WRAPPER_DIR)/libaxis2_parser.la \
             $(NULL)


INCLUDES = -I$(top_builddir)/include \
			-I ../../../util/include \
			-I ../../../axiom/include \
		-I ../../../include \
                        $(NULL)

EXTRA_DIST=tcpmon_entry_local.h tcpmon_session_local.h
