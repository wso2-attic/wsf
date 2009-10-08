prgbindir=$(prefix)/samples/bin/
prgbin_PROGRAMS = TraderClient
TraderClient_SOURCES = traderclient.cpp TraderClientStub.cpp


TraderClient_LDADD   = $(LDFLAGS) \
                     -L$(WSFC_HOME)/lib \
   	             -l./../../../../wsf_c/axis2c/util/src/libaxutil.la \
                     -l./../../../../wsf_c/axis2c/axiom/src/om/libaxis2_axiom.la \
                     -l./../../../../wsf_c/axis2c/src/core/engine/libaxis2_engine.la \
                     -l./../../../../wsf_c/axis2c/axis2_parser \
		     ../util/libtrader_util.la \
                     $(GUTHTHILA_LIBS) \
                     $(LIBXML2_LIBS)

INCLUDES = -I ../include 
           -I ../../../include \
           -I ../../../wsf_c/axis2c/include \
           -I ../../../wsf_c/axis2c/neethi/include \
           -I ../../../wsf_c/axis2c/axiom/include \
           -I ../../../wsf_c/axis2c/util/include \
           -I ../../../wsf_c/axis2c/util/include/platforms


