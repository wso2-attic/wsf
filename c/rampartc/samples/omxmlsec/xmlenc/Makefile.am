prgbindir=$(prefix)/bin/samples/rampart/omxmlsec/xmlenc
prgbin_PROGRAMS = enc

enc_SOURCES =  enc.c

INCLUDES = -I $(AXIS2C_HOME)/include \
            -I ../../../include \
            -I ../../../util/include \
            -I ../../../axiom/include

enc_LDADD   = ../../../src/util/librampart_util.la \
                    ../../../src/omxmlsec/libomxmlsec.la \
                    ../../../src/omxmlsec/openssl/libomopenssl.la \
                    ../../../src/omxmlsec/tokens/liboxstokens.la \
                    ../../../../util/src/libaxutil.la \
                    ../../../../axiom/src/om/libaxis2_axiom.la \
                    ../../../../axiom/src/parser/libxml2/libaxis2_libxml2.la \
           -lxml2


EXTRA_DIST = input.xml		   
