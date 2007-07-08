lib_LTLIBRARIES = libaxis2_parser.la

libaxis2_parser_la_LIBADD = ../../../../guththila/src/libguththila.la

libaxis2_parser_la_SOURCES = ../xml_reader.c ../xml_writer.c guththila_xml_writer_wrapper.c \
                                guththila_xml_reader_wrapper.c 

libaxis2_parser_la_LDFLAGS = -version-info $(VERSION_NO)

INCLUDES = -I$(top_builddir)/include \
			-I ../../../../util/include \
			-I ../../../../guththila/include
