TESTS =

noinst_LTLIBRARIES = librp_builder.la

librp_builder_la_SOURCES = algorithmsuite_builder.c asymmetric_binding_builder.c binding_commons_builder.c \
						   https_token_builder.c layout_builder.c qname_matcher.c rampart_config_builder.c secpolicy_builder.c \
						   security_context_token_builder.c signed_encrypted_elements_builder.c \
						   signed_encrypted_parts_builder.c supporting_tokens_builder.c symmetric_asymmetric_commons_builder.c \
						   symmetric_binding_builder.c token_builder.c transport_binding_builder.c username_token_builder.c \
						   wss10_builder.c wss11_builder.c x509_token_builder.c policy_creator.c


librp_builder_la_LIBADD  = 


INCLUDES = -I$(top_builddir)/include \
			-I ../../../include \
			-I ../../../../include \
			-I ../../../../util/include \
			-I ../../../../axiom/include \
			-I ../../../../xml_schema/include 
