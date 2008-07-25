lib_LTLIBRARIES = libsecconv.la

libsecconv_la_SOURCES = sct_provider_utility.c \
			security_context_token.c

libsecconv_la_LIBADD = ../trust/libtrust.la

INCLUDES = -I$(top_builddir)/include \
            -I ../../../../util/include \
            -I ../../../../include \
            -I ../../../../axiom/include \
	    @OPENSSLINC@ \
	    @UTILINC@ \
	    @AXIOMINC@ \
	    @NEETHIINC@ \
	    @AXIS2INC@
