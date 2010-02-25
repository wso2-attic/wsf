#!/usr/bin/sh
set -e
export LD_LIBRARY_PATH=$1/lib; 

# copy samples
if ! test -d $1/samples/src/savanc; then 
    mkdir $1/samples/src/savanc;
    cp -r savanc/samples/* $1/samples/src/savanc;
fi    

if ! test -d $1/samples/src/sandesha2c; then 
    mkdir $1/samples/src/sandesha2c;
    cp -r sandesha2c/samples/* $1/samples/src/sandesha2c;
fi    
if ! test -d $1/samples/src/rampartc; then 
    mkdir $1/samples/src/rampartc;
    cp -r rampartc/samples/* $1/samples/src/rampartc;
fi    
if ! test -d $1/samples/src/wsclient; then 
    mkdir $1/samples/src/wsclient;
    cp -r wsclient/samples/* $1/samples/src/wsclient;
fi    

find $1/samples -name "*.o"| xargs rm -rf

cd axis2c/samples; ./configure --prefix=$1 --with-axis2=$1/include/wsfc-2.0.0; make; make install ;
if test -e ../../sandesha2c/Makefile; then
cd ../../sandesha2c/samples; ./configure --prefix=$1 --with-axis2=$1/include/wsfc-2.0.0; make; make install; 
fi
if test -e ../../rampartc/Makefile; then
cd ../../rampartc/samples; ./configure --prefix=$1  --with-axis2=$1/include/wsfc-2.0.0; make; make install;
cd client/sec_echo; cd ../../secpolicy; sh deploy.sh scenario5; cd ../
fi
if test -e ../../savanc/Makefile; then
cd ../../savanc/samples; ./configure --prefix=$1  --with-axis2=$1/include/wsfc-2.0.0 --with-savan=$1/include/wsfc-2.0.0; make; make install;
fi
cd ../../examples; ./configure --prefix=$1  --with-wsfc=$1/include/wsfc-2.0.0; make; make install


