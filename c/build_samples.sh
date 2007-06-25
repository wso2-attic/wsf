#!/usr/bin/sh
set -e
export LD_LIBRARY_PATH=$1/lib; 
cd axis2c/samples; ./configure --prefix=$1 --with-axis2=$1/include/axis2-1.1; make; make install ;
if test -e ../../sandesha2c/Makefile; then
cd ../../sandesha2c/samples; ./configure --prefix=$1 --with-axis2=$1/include/axis2-1.1; make; make install; 
fi
if test -e ../../rampartc/Makefile; then
cd ../../rampartc/samples; ./configure --prefix=$1  --with-axis2=$1/include/axis2-1.1; make; make install
fi
cd ../../examples; ./configure --prefix=$1  --with-wsfc=$1/include; make; make install


