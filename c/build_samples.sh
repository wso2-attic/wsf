#!/usr/bin/sh
set -e
export LD_LIBRARY_PATH=$1/lib; 

# copy samples
if ! test -d $1/samples/savanc; then 
    mkdir $1/samples/savanc;
    cp -r savanc/samples/* $1/samples/savanc;
fi    

if ! test -d $1/samples/sandesha2c; then 
    mkdir $1/samples/sandesha2c;
    cp -r sandesha2c/samples/* $1/samples/sandesha2c;
fi    
if ! test -d $1/samples/rampartc; then 
    mkdir $1/samples/rampartc;
    cp -r rampartc/samples/* $1/samples/rampartc;
fi    
if ! test -d $1/samples/wsclient; then 
    mkdir $1/samples/wsclient;
    cp -r wsclient/samples/* $1/samples/wsclient;
fi    

find $1/samples -name "*.o"| xargs rm -rf

cd axis2c/samples; ./configure --prefix=$1 --with-axis2=$1/include/axis2-1.3.1; make; make install ;
if test -e ../../sandesha2c/Makefile; then
cd ../../sandesha2c/samples; ./configure --prefix=$1 --with-axis2=$1/include/axis2-1.3.1; make; make install; 
fi
if test -e ../../rampartc/Makefile; then
cd ../../rampartc/samples; ./configure --prefix=$1  --with-axis2=$1/include/axis2-1.3.1; make; make install;
cd client/sec_echo; sh deploy_client_repo.sh; cd ../../secpolicy; sh deploy.sh scenario5; cd ../
fi
if test -e ../../savanc/Makefile; then
cd ../../savanc/samples; ./configure --prefix=$1  --with-axis2=$1/include/axis2-1.3.1 --with-savan=$1/include/savan-0.90; make; make install;
fi
cd ../../examples; ./configure --prefix=$1  --with-wsfc=$1/include; make; make install


