#!/usr/bin/sh
set -e
export LD_LIBRARY_PATH=$1/lib; 
cd axis2c/samples; ./autogen.sh; ./configure --prefix=$1/bin/samples/axis2 --with-axis2=$1/include/axis2-1.1; make; make install ;
if test -e ../../sandesha2c/Makefile; then
cd ../../sandesha2c/samples; ./autogen.sh; ./configure --prefix=$1 --with-axis2=$1/include/axis2-1.1; make; make install; 
fi
if test -e ../../rampartc/Makefile; then
cd ../../rampartc/samples; ./autogen.sh; ./configure --prefix=$1  --with-axis2=$1/include/axis2-1.1; make; make install
fi
