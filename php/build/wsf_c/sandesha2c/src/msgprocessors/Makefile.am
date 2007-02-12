TESTS =
noinst_LTLIBRARIES = libsandesha2_msgprocessors.la

libsandesha2_msgprocessors_la_SOURCES = app_msg_processor.c\
                                        create_seq_msg_processor.c\
                                        ack_msg_processor.c\
                                        ack_req_msg_processor.c\
                                        close_seq_msg_processor.c\
                                        create_seq_res_msg_processor.c\
                                        terminate_seq_msg_processor.c\
                                        terminate_seq_res_msg_processor.c \
										msg_processor_creator.c \
										make_connection_msg_processor.c

INCLUDES = -I$(top_builddir)/include \
			-I$(top_builddir)/include/sandesha2 \
           -I ../../../axis2c/util/include \
            -I ../../../axis2c/include \
            -I ../../../axis2c/axiom/include \
            -I ../../../axis2c/xml_schema/include \
            -I ../../../axis2c/woden/include

