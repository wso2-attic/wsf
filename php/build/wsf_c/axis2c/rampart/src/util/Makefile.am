TESTS =

noinst_LTLIBRARIES = librampart_util.la

librampart_util_la_SOURCES = rampart_crypto_util.c \
							rampart_util.c rampart_handler_util.c rampart_username_token.c  rampart_timestamp_token.c \
							rampart_encryption.c rampart_sec_header_processor.c rampart_sec_processed_result.c \
							rampart_sec_header_builder.c rampart_context.c rampart_engine.c rampart_token_processor.c rampart_signature.c \
							rampart_token_builder.c rampart_rd_record.c rampart_replay_detector.c


librampart_util_la_LIBADD  = -lssl \
						-lcrypto 

INCLUDES = -I$(top_builddir)/include \
			-I ../../include \
			-I ../../../include \
			-I ../../../util/include \
			-I ../../../axiom/include \
			-I ../../../xml_schema/include 
