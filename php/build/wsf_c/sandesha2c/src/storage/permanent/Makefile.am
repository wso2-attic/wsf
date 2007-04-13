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
            -I ../../../../axis2c/util/include \
            -I ../../../../axis2c/include \
            -I ../../../../axis2c/axiom/include \
            -I ../../../../axis2c/xml_schema/include \
            -I ../../../../axis2c/woden/include \
			-I/usr/include/mysql

EXTRA_DIST=sandesha2_sqls.h
