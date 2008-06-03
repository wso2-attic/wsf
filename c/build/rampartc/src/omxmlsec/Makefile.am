SUBDIRS = tokens openssl c14n 
lib_LTLIBRARIES = libomxmlsec.la

libomxmlsec_la_SOURCES = ctx.c  buffer.c key.c cipher.c error.c axis2_utils.c axiom.c \
                         iv.c xml_encryption.c encryption.c\
						utility.c asym_ctx.c x509_cert.c key_mgr.c sign_part.c sign_ctx.c \
						xml_signature.c signature.c transform.c transforms_factory.c xml_key_processor.c \
						xml_key_info_builder.c derivation.c saml/assertion.c saml/auth_des_stmt.c \
						saml/condition.c saml/query.c saml/response.c saml/subject.c saml/attr_stmt.c \
						saml/auth_smt.c saml/id_type.c saml/request.c saml/stmt.c saml/sutil.c

						

libomxmlsec_la_LIBADD  = @OPENSSLLIB@ \
			-lssl \
			tokens/liboxstokens.la \
			openssl/libomopenssl.la \
			c14n/liboxsc14n.la \
			-lcrypto 

INCLUDES = -I$(top_builddir)/include \
			-I ../../include \
			@OPENSSLINC@ \
			@UTILINC@ \
			@AXIOMINC@ \
			@NEETHIINC@ \
			@AXIS2INC@
