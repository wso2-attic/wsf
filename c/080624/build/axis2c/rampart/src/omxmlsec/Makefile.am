SUBDIRS = tokens openssl c14n
lib_LTLIBRARIES = libomxmlsec.la

libomxmlsec_la_SOURCES = ctx.c  buffer.c key.c cipher.c error.c axis2_utils.c axiom.c \
                         iv.c xml_encryption.c encryption.c\
						utility.c asym_ctx.c x509_cert.c key_mgr.c sign_part.c sign_ctx.c \
						xml_signature.c signature.c transform.c transforms_factory.c xml_key_processor.c \
						xml_key_info_builder.c
						

libomxmlsec_la_LIBADD  = -lssl\
			tokens/liboxstokens.la \
			openssl/libomopenssl.la \
			c14n/liboxsc14n.la \
			-lcrypto 

INCLUDES = -I$(top_builddir)/include \
			-I ../../include \
			-I ../../../include \
			-I ../../../axiom/include \
			-I ../../../util/include \
			@AXIS2INC@
