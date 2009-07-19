#!/usr/bin/sh
set -e
export LD_LIBRARY_PATH=$1/lib; 

cd examples
./configure --prefix=$1
make
make install
cd ..


if ! test -d $1/samples/src/c/savanc; then 
    mkdir $1/samples/src/c/savanc;
    cp -r wsf_c/savanc/samples/* $1/samples/src/c/savanc;
fi    

if ! test -d $1/samples/src/c/sandesha2c; then 
    mkdir $1/samples/src/c/sandesha2c;
    cp -r wsf_c/sandesha2c/samples/* $1/samples/src/c/sandesha2c;
fi    
if ! test -d $1/samples/src/c/rampartc; then 
    mkdir $1/samples/src/c/rampartc;
    cp -r wsf_c/rampartc/samples/* $1/samples/src/c/rampartc;
fi    
if ! test -d $1/samples/src/c/wsclient; then 
    mkdir $1/samples/src/c/wsclient;
    cp -r wsf_c/wsclient/samples/* $1/samples/src/c/wsclient;
fi




cd wsf_c/axis2c/samples
if test -e ../../rampartc/Makefile; then
cd ../../rampartc/samples; ./configure --prefix=$1  --with-axis2=$1/include/axis2-1.6.0; make; make install;
cd client/sec_echo; cd ../../secpolicy; sh deploy.sh scenario5; cd ../
fi
cd ../../examples; ./configure --prefix=$1  --with-wsfc=$1/include; make; make install
cd ..

