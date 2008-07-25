#!/bin/bash
set -e

cp build/wsf_c/rampartc/configure.ac wsf_c/rampartc/configure.ac
cp build/wsf_c/Makefile.am wsf_c/
cp build/wsf_c/rampartc/src/Makefile.am  wsf_c/rampartc/src/Makefile.am
cp build/wsf_c/rampartc/src/omxmlsec/Makefile.am  wsf_c/rampartc/src/omxmlsec
cp build/wsf_c/rampartc/src/omxmlsec/tokens/Makefile.am  wsf_c/rampartc/src/omxmlsec/tokens/
cp build/wsf_c/rampartc/src/omxmlsec/openssl/Makefile.am  wsf_c/rampartc/src/omxmlsec/openssl
cp build/wsf_c/rampartc/src/core/Makefile.am  wsf_c/rampartc/src/core/Makefile.am
cp build/wsf_c/rampartc/src/trust/Makefile.am  wsf_c/rampartc/src/trust
cp build/wsf_c/rampartc/src/secconv/Makefile.am  wsf_c/rampartc/src/secconv
cp build/wsf_c/rampartc/src/rahas/Makefile.am  wsf_c/rampartc/src/rahas
cp build/wsf_c/axis2c/neethi/configure.ac wsf_c/axis2c/neethi/configure.ac
cp build/wsf_c/axis2c/neethi/src/Makefile.am wsf_c/axis2c/neethi/src/Makefile.am


sh autogen.sh

./configure --prefix=`pwd`/deploy 
make -j 10 
make install
make examples
