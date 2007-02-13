noinst_LTLIBRARIES = libsandesha2_inmemory.la

libsandesha2_inmemory_la_SOURCES = \
								inmemory_create_seq_mgr.c \
								inmemory_invoker_mgr.c \
								inmemory_sender_mgr.c \
								inmemory_next_msg_mgr.c \
								inmemory_seq_property_mgr.c \
								inmemory_transaction.c \
								inmemory_storage_mgr.c \
								inmemory_bean_mgr.c

INCLUDES = -I$(top_builddir)/include \
			-I$(top_builddir)/include/sandesha2 \
           -I ../../../../axis2c/util/include \
            -I ../../../../axis2c/include \
            -I ../../../../axis2c/axiom/include \
            -I ../../../../axis2c/xml_schema/include \
            -I ../../../../axis2c/woden/include

EXTRA_DIST=sandesha2_inmemory_bean_mgr.h

