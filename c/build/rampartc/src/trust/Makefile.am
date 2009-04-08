lib_LTLIBRARIES = libtrust.la

libtrust_la_SOURCES = context.c \
			claims.c \
			entropy.c \
			life_time.c \
			rst.c \
			rstr.c \
			trust_util.c \
			sts_client.c \
			policy_util.c \
			token.c

libtrust_la_LDFLAGS = -version-info $(VERSION_NO)

INCLUDES = -I$(top_builddir)/include \
            -I ../../../../util/include \
            -I ../../../../include \
            -I ../../../../axiom/include \
	    @OPENSSLINC@ \
	    @UTILINC@ \
	    @AXIOMINC@ \
	    @NEETHIINC@ \
	    @AXIS2INC@
