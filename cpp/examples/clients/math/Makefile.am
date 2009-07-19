prgbindir=$(prefix)/samples/bin
prgbin_PROGRAMS = math 
math_SOURCES = math.cpp

math_LDADD   = $(LDFLAGS) \
                -L$(WSFCPP_HOME)/lib \
                ../../../wsf_c/axis2c/util/src/libaxutil.la \
                ../../../wsf_c/axis2c/axiom/src/om/libaxis2_axiom.la \
                ../../../wsf_c/axis2c/src/core/engine/libaxis2_engine.la \
                ../../../wsf_c/axis2c/axiom/src/parser/guththila/libaxis2_parser.la \
                ../../../wsf_c/axis2c/src/core/transport/http/sender/libaxis2_http_sender.la \
                ../../../wsf_c/axis2c/src/core/transport/http/receiver/libaxis2_http_receiver.la \
                -lpthread \
		../../../src/main/libwso2_wsf.la \
                    $(GUTHTHILA_LIBS) \
                    $(LIBXML2_LIBS)

INCLUDES =	-I ../../../include \
                -I ../../../wsf_c/axis2c/include \
                -I ../../../wsf_c/axis2c/neethi/include \
                -I ../../../wsf_c/axis2c/axiom/include \
                -I ../../../wsf_c/axis2c/util/include \
                -I ../../../wsf_c/axis2c/util/include/platforms \
                -I ../../../wsf_c/rampartc/include \
                -I ../../../wsf_c/sandesha2c/include \
                -I ../../../wsf_c/savanc/include


