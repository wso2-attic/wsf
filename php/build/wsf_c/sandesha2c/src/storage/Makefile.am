SUBDIRS = beans inmemory permanent
noinst_LTLIBRARIES = libsandesha2_storage.la

libsandesha2_storage_la_SOURCES = \
								storage_mgr.c \
								transaction.c \
								create_seq_mgr.c \
								invoker_mgr.c \
								sender_mgr.c \
								next_msg_mgr.c \
								seq_property_mgr.c

INCLUDES = -I$(top_builddir)/include \
			-I$(top_builddir)/include/sandesha2 \
            -I ../../../axis2/util/include \
            -I ../../../axis2/include \
            -I ../../../axis2/axiom/include \
            -I ../../../axis2/xml_schema/include \
            -I ../../../axis2/woden/include
