prglibdir=$(prefix)/modules/sandesha2
prglib_LTLIBRARIES = libsandesha2.la

libsandesha2_la_SOURCES = sandesha2_msg_ctx.c\
                          mod_sandesha2.c\
                          msg_validator.c

INCLUDES = -I$(top_builddir)/include \
            -I ../../../axis2c/util/include \
            -I ../../../axis2c/include \
            -I ../../../axis2c/axiom/include \
            -I ../../../axis2c/xml_schema/include \
            -I ../../../axis2c/woden/include

libsandesha2_la_LIBADD = ../client/libsandesha2_client.la\
                        ../handlers/libsandesha_handlers.la\
                        ../msgprocessors/libsandesha2_msgprocessors.la\
                        ../storage/beans/libsandesha2_storage_beans.la\
						../storage/libsandesha2_storage.la\
                        ../storage/inmemory/libsandesha2_inmemory.la\
                        ../storage/permanent/libsandesha2_permanent.la\
                        ../transport/libsandesha2_transport.la\
                        ../util/libsandesha_util.la\
                        ../workers/libsandesha2_workers.la\
                        ../wsrm/libsandesha2_wsrm.la \
                        ../polling/libsandesha2_polling.la \
						-lmysqlclient -lnsl -lm -lz

