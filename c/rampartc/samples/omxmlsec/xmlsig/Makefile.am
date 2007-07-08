prgbindir=$(prefix)/bin/samples/rampart/omxmlsec/xmlsig
prgbin_PROGRAMS = sign

sign_SOURCES =  sign.c

INCLUDES = @AXIS2INC@ \
            -I ../../../include 

sign_LDADD = -laxutil \
                    -laxis2_axiom \
					-lxml2 \
					../../../src/omxmlsec/libomxmlsec.la \
                    ../../../src/omxmlsec/openssl/libomopenssl.la \
                    ../../../src/omxmlsec/tokens/liboxstokens.la 
 


EXTRA_DIST = input.xml		   
