prglibdir=$(prefix)/bin/samples/rampart/credential_provider
prglib_LTLIBRARIES = libcredential.la
libcredential_la_SOURCES = cred_provider.c
libcredential_la_LIBADD  = ../../src/util/librampart_util.la \
					  ../../src/omxmlsec/openssl/libomopenssl.la
INCLUDES = -I ../../include\
			-I$(prefix)/include/axis2-1.1
