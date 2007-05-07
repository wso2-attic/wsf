noinst_LTLIBRARIES = libomopenssl.la
libomopenssl_la_SOURCES = cipher_ctx.c crypt.c rsa.c pkey.c util.c cipher_property.c digest.c x509.c pkcs12.c pem.c sign.c

libomopenssl_la_LIBADD  = -lssl\
    		-lcrypto

INCLUDES = -I$(top_builddir)/include \
			-I ../../../../axis2c/util/include \
			-I ../../../../axis2c/include \
			-I ../../../../axis2c/axiom/include \
			@AXIS2INC@
