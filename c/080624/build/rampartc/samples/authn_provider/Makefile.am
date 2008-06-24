prglibdir=$(prefix)/bin/samples/rampart/authn_provider
prglib_LTLIBRARIES = libauthn.la
libauthn_la_SOURCES = authn_provider.c
libauthn_la_LIBADD  = ../../src/util/librampart_util.la \
					  ../../src/omxmlsec/openssl/libomopenssl.la
INCLUDES = -I ../../include\
			-I$(prefix)/include/axis2-1.1
