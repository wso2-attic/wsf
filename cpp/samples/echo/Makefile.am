prgbindir=$(prefix)/bin/samples/echo
prgbin_PROGRAMS = echo echo_rest echo_blocking echo_blocking_addr echo_blocking_soap11 echo_blocking_dual echo_non_blocking echo_non_blocking_dual echo_security
echo_SOURCES = echo.cpp
echo_rest_SOURCES = echo_rest.cpp
echo_blocking_SOURCES = echo_blocking.cpp
echo_blocking_addr_SOURCES = echo_blocking_addr.cpp
echo_blocking_soap11_SOURCES = echo_blocking_soap11.cpp
echo_blocking_dual_SOURCES = echo_blocking_dual.cpp
echo_non_blocking_SOURCES = echo_non_blocking.cpp
echo_non_blocking_dual_SOURCES = echo_non_blocking_dual.cpp
echo_security_SOURCES = echo_security.cpp

echo_LDADD   = $(LDFLAGS) \
                -L$(AXIS2C_HOME)/lib \
					-laxutil \
                    -laxis2_axiom \
                    -laxis2_engine \
                    -laxis2_parser \
                    -lpthread \
                    -laxis2_http_sender \
                    -laxis2_http_receiver \
			../../src/libwso2_wsf.la \
                    $(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)

echo_rest_LDADD   = $(LDFLAGS) \
                -L$(AXIS2C_HOME)/lib \
					-laxutil \
                    -laxis2_axiom \
                    -laxis2_engine \
                    -laxis2_parser \
                    -lpthread \
                    -laxis2_http_sender \
                    -laxis2_http_receiver \
			../../src/libwso2_wsf.la \
                    $(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)

echo_blocking_LDADD   = $(LDFLAGS) \
                -L$(AXIS2C_HOME)/lib \
					-laxutil \
                    -laxis2_axiom \
                    -laxis2_engine \
                    -laxis2_parser \
                    -lpthread \
                    -laxis2_http_sender \
                    -laxis2_http_receiver \
			../../src/libwso2_wsf.la \
                    $(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)

echo_blocking_addr_LDADD   = $(LDFLAGS) \
                -L$(AXIS2C_HOME)/lib \
					-laxutil \
                    -laxis2_axiom \
                    -laxis2_engine \
                    -laxis2_parser \
                    -lpthread \
                    -laxis2_http_sender \
                    -laxis2_http_receiver \
			../../src/libwso2_wsf.la \
                    $(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)

echo_blocking_soap11_LDADD   = $(LDFLAGS) \
                -L$(AXIS2C_HOME)/lib \
					-laxutil \
                    -laxis2_axiom \
                    -laxis2_engine \
                    -laxis2_parser \
                    -lpthread \
                    -laxis2_http_sender \
                    -laxis2_http_receiver \
			../../src/libwso2_wsf.la \
                    $(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)

echo_blocking_dual_LDADD   = $(LDFLAGS) \
                -L$(AXIS2C_HOME)/lib \
					-laxutil \
                    -laxis2_axiom \
                    -laxis2_engine \
                    -laxis2_parser \
                    -lpthread \
                    -laxis2_http_sender \
                    -laxis2_http_receiver \
			../../src/libwso2_wsf.la \
                    $(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)

echo_non_blocking_LDADD   = $(LDFLAGS) \
                -L$(AXIS2C_HOME)/lib \
					-laxutil \
                    -laxis2_axiom \
                    -laxis2_engine \
                    -laxis2_parser \
                    -lpthread \
                    -laxis2_http_sender \
                    -laxis2_http_receiver \
			../../src/libwso2_wsf.la \
                    $(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)

echo_non_blocking_dual_LDADD   = $(LDFLAGS) \
                -L$(AXIS2C_HOME)/lib \
					-laxutil \
                    -laxis2_axiom \
                    -laxis2_engine \
                    -laxis2_parser \
                    -lpthread \
                    -laxis2_http_sender \
                    -laxis2_http_receiver \
			../../src/libwso2_wsf.la \
                    $(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)

echo_security_LDADD   = $(LDFLAGS) \
                -L$(AXIS2C_HOME)/lib \
                                        -laxutil \
                    -laxis2_axiom \
                    -laxis2_engine \
                    -laxis2_parser \
                    -lpthread \
                    -laxis2_http_sender \
                    -laxis2_http_receiver \
                        ../../src/libwso2_wsf.la \
                    $(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)


INCLUDES =	-I ../../include \
                -I ../../wsf_c/axis2c/include \
                -I ../../wsf_c/axis2c/neethi/include \
                -I ../../wsf_c/axis2c/axiom/include \
                -I ../../wsf_c/axis2c/util/include \
                -I ../../wsf_c/rampartc/include \
                -I ../../wsf_c/sandesha2c/include \
                -I ../../wsf_c/savanc/include

		@AXIS2INC@

