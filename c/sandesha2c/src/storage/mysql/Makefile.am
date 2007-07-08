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
		   	@AXIS2INC@ \
		   	@AXIOMINC@ \
		   	@UTILINC@ \
			-I. \
			@MYSQLINC@

EXTRA_DIST=sandesha2_permanent_bean_mgr.h \
		sandesha2_permanent_next_msg_mgr.h \
		sandesha2_permanent_transaction.h \
		sandesha2_permanent_create_seq_mgr.h \
		sandesha2_permanent_sender_mgr.h \
		sandesha2_sqls.h \
		sandesha2_permanent_invoker_mgr.h \
		sandesha2_permanent_seq_property_mgr.h

