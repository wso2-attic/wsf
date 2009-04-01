TESTS =

prglibdir=$(prefix)/lib

prglib_LTLIBRARIES = librampart.la

librampart_la_SOURCES = rampart_crypto_util.c \
							rampart_util.c rampart_handler_util.c rampart_username_token.c rampart_timestamp_token.c \
							rampart_encryption.c rampart_sec_header_processor.c rampart_sec_processed_result.c \
							rampart_sec_header_builder.c rampart_context.c rampart_token_processor.c rampart_signature.c \
							rampart_token_builder.c rampart_replay_detector.c rampart_engine.c \
							rampart_policy_validator.c rampart_error.c rampart_config.c rampart_saml.c rampart_saml_token.c \
							rampart_issued.c rampart_issued_token.c

librampart_la_LDFLAGS = -version-info $(VERSION_NO)

librampart_la_LIBADD  = ../omxmlsec/libomxmlsec.la \
                     ../secconv/libsecconv.la \
                     ../trust/libtrust.la \
                     @OPENSSLLIB@ \
                     -lcrypto 

INCLUDES = -I$(top_builddir)/include \
			-I ../../include \
			@OPENSSLINC@ \
			@AXIOMINC@ \
			@UTILINC@ \
			@NEETHIINC@ \
			@AXIS2INC@
