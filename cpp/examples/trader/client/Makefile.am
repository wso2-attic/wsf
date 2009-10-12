        
prgbindir=$(prefix)/samples/bin/
prgbin_PROGRAMS = TraderClient
noinst_HEADERS=ITraderClientCallback.h  TraderClientStub.h

TraderClient_SOURCES = traderclient.cpp TraderClientStub.cpp
TraderClient_LDADD   = $(LDFLAGS) \
                -L$(WSFC_HOME)/lib \
                -laxutil \
                -laxis2_axiom \
                -laxis2_engine \
                ../util/libtrader_util.la \
		-lwso2_wsf
        
INCLUDES = -I ../include \
        -I ../../../include \
        -I ../../../wsf_c/axis2c/include \
        -I ../../../wsf_c/axis2c/neethi/include \
        -I ../../../wsf_c/axis2c/axiom/include \
        -I ../../../wsf_c/axis2c/util/include \
        -I ../../../wsf_c/axis2c/util/include/platforms
