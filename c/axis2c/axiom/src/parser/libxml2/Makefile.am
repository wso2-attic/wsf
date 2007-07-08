lib_LTLIBRARIES = libaxis2_libxml2.la libaxis2_parser.la
libaxis2_libxml2_la_SOURCES = ../xml_reader.c ../xml_writer.c libxml2_reader_wrapper.c \
                              libxml2_writer_wrapper.c

libaxis2_libxml2_la_LIBADD = -lxml2

libaxis2_parser_la_SOURCES = ../xml_reader.c ../xml_writer.c libxml2_reader_wrapper.c \
                              libxml2_writer_wrapper.c

libaxis2_parser_la_LIBADD = -lxml2

libaxis2_parser_la_LDFLAGS = -version-info $(VERSION_NO)
libaxis2_libxml2_la_LDFLAGS = -version-info $(VERSION_NO)


INCLUDES = -I$(top_builddir)/include \
            -I$(top_builddir)/src/parser \
            -I ../../../../util/include 
			
