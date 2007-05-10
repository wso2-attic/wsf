SUBDIRS = beans inmemory $(WRAPPER_DIR)
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
		   	@AXIS2INC@
EXTRA_DIST=mysql
