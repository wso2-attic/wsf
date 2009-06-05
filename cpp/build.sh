#!/bin/bash
set -e

cp wsf_c/build/rampartc/configure.ac wsf_c/rampartc/configure.ac
cp wsf_c/build/rampartc/src/Makefile.am  wsf_c/rampartc/src/Makefile.am
cp wsf_c/build/rampartc/src/omxmlsec/Makefile.am  wsf_c/rampartc/src/omxmlsec
cp wsf_c/build/rampartc/src/omxmlsec/tokens/Makefile.am  wsf_c/rampartc/src/omxmlsec/tokens/
cp wsf_c/build/rampartc/src/omxmlsec/openssl/Makefile.am  wsf_c/rampartc/src/omxmlsec/openssl
cp wsf_c/build/rampartc/src/core/Makefile.am  wsf_c/rampartc/src/core/Makefile.am
cp wsf_c/build/rampartc/src/trust/Makefile.am  wsf_c/rampartc/src/trust
cp wsf_c/build/rampartc/src/secconv/Makefile.am  wsf_c/rampartc/src/secconv
cp wsf_c/build/rampartc/src/rahas/Makefile.am  wsf_c/rampartc/src/rahas/
cp wsf_c/build/rampartc/src/util/Makefile.am wsf_c/rampartc/src/util/
cp build/wsf_c/axis2c/neethi/configure.ac wsf_c/axis2c/neethi/configure.ac
cp build/wsf_c/axis2c/neethi/src/Makefile.am wsf_c/axis2c/neethi/src/Makefile.am
cp build/wsf_c/rampartc/Makefile.am wsf_c/rampartc/Makefile.am

sh autogen.sh

./configure --prefix=`pwd`/deploy 
make -j 10 
make install
make examples
