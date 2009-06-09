#!/usr/bin/sh
set -e
export LD_LIBRARY_PATH=$1/lib; 

cd examples
./configure --prefix=$1
make
make install
cd ..

cd wsf_c/axis2c/samples; ./configure --prefix=$1 --with-axis2=$1/include/axis2-1.6.0; make; make install ;
if test -e ../../sandesha2c/Makefile; then
cd ../../sandesha2c/samples; ./configure --prefix=$1 --with-axis2=$1/include/axis2-1.6.0; make; make install; 
fi
if test -e ../../rampartc/Makefile; then
cd ../../rampartc/samples; ./configure --prefix=$1  --with-axis2=$1/include/axis2-1.6.0; make; make install;
#cd client/sec_echo; cd ../../secpolicy; sh deploy.sh scenario5; cd ../
fi
if test -e ../../savanc/Makefile; then
cd ../../savanc/samples; ./configure --prefix=$1  --with-axis2=$1/include/axis2-1.6.0 --with-savan=$1/include/savan-1.0; make; make install;
fi
cd ../../examples; ./configure --prefix=$1  --with-wsfc=$1/include; make; make install
cd ..

