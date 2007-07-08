TESTS =

noinst_LTLIBRARIES = librp_builder.la

librp_builder_la_SOURCES = algorithmsuite_builder.c \
						   layout_builder.c qname_matcher.c \
						   supporting_tokens_builder.c \
						   transport_binding_builder.c username_token_builder.c \
						   wss10_builder.c transport_token_builder.c \
						   token_identifier.c https_token_builder.c rampart_config_builder.c \
						   asymmetric_binding_builder.c x509_token_builder.c initiator_token_builder.c \
						   recipient_token_builder.c signed_encrypted_parts_builder.c secpolicy_builder.c 


librp_builder_la_LIBADD  = ../../../../axiom/src/om/libaxis2_axiom.la \
				../../../../util/src/libaxutil.la

INCLUDES = -I$(top_builddir)/include \
			-I ../../../include \
			-I ../../../../util/include \
            -I ../../../../axiom/include \
            -I ../../../../include
