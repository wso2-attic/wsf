noinst_LTLIBRARIES = libsandesha2_permanent.la

libsandesha2_permanent_la_SOURCES = \
								permanent_create_seq_mgr.c \
								permanent_invoker_mgr.c \
								permanent_sender_mgr.c \
								permanent_next_msg_mgr.c \
								permanent_seq_property_mgr.c \
								permanent_transaction.c \
								permanent_storage_mgr.c \
								permanent_bean_mgr.c \
								msg_store_bean.c

INCLUDES = -I$(top_builddir)/include \
			-I$(top_builddir)/include/sandesha2 \
			-I. \
			-I ../../../../axis2c/include \
			-I ../../../../axis2c/util/include \
			-I ../../../../axis2c/axiom/include \
			@AXIS2INC@ \
			@MYSQLINC@

