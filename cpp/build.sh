#!/bin/bash
set -e
cp build/wsf_c/rampartc/configure.ac build/wsf_c/rampartc/configure.ac
cp build/wsf_c/rampartc/src/Makefile.am  build/wsf_c/rampartc/src/Makefile.am
cp build/wsf_c/rampartc/src/core/Makefile.am  build/wsf_c/rampartc/src/core/Makefile.am

sh autogen.sh

./configure --prefix=`pwd`/deploy --with-axis2=${AXIS2C_HOME}/include/axis2-1.1
make -j 10 
