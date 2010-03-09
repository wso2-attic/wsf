#!/usr/bin/sh
set -e
export LD_LIBRARY_PATH=$1/lib; 

rm -rf $1/samples/src/*

cd examples
./configure --prefix=$1
make
make install
cd ..

if ! test -d $1/samples/src; then
    mkdir $1/samples/src;
fi

if ! test -d $1/samples/src/c; then
    mkdir $1/samples/src/c;
fi


if ! test -d $1/samples/src/cpp; then
    mkdir $1/samples/src/cpp;
    cp -rf examples/* $1/samples/src/cpp;
fi


if ! test -d $1/samples/src/c/axis2c; then
    mkdir $1/samples/src/c/axis2c;
    cp -rf wsf_c/axis2c/samples/* $1/samples/src/c/axis2c;
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
cd wsf_c/rampartc/samples; ./configure --prefix=$1  --with-axis2=$1/include/wsfc-2.0.0; make; make install;
cd ../../../
fi

if test -d $1/samples/src/rampartc; then
cp -rf  $1/samples/src/rampartc/data/keys  $1/samples/src/c/rampartc/data;
rm -rf $1/samples/src/rampartc;
fi

if test -d $1/samples/bin/rampartc; then
rm -rf $1/samples/bin/rampartc;
fi

if test -d $1/samples/lib/rampartc; then
rm -rf $1/samples/lib/rampartc;
fi

if ! test -d $1/samples/bin/security; then
mkdir $1/samples/bin/security;
fi

cp -rf examples/secscripts/*.sh $1/samples/bin/security;
mv $1/samples/bin/security/update_n_run.sh $1/samples/bin;
