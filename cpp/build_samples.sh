#!/usr/bin/sh
set -e
export LD_LIBRARY_PATH=$1/lib; 

rm -rf $1/samples/src/*

cd examples
./configure --prefix=$1
make
make install
cd ..

if ! test -d $1/samples/src/c; then
    mkdir $1/samples/src/c;
fi

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

if test -e wsf_c/rampartc/Makefile; then
cd wsf_c/rampartc/samples; ./configure --prefix=$1  --with-axis2=$1/include/axis2-1.6.0; make; make install;
cd ../../../../
fi

if test -d $1/samples/src/rampartc; then
rm -rf $1/samples/src/rampartc;
fi

