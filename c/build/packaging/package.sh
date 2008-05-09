#!/bin/bash

set -e 

export AXIS2C_HOME=`pwd`/deploy
export WSFC_HOME=`pwd`/deploy

./build/copy_build_files.sh

./autogen.sh
./configure --prefix=`pwd`/deploy --enable-openssl=yes --enable-tests=yes --with-apache2=/usr/local/apache2/include --with-axis2=`pwd`/axis2c/include --enable-sandesha=yes --enable-rampart=yes --enable-wsclient=yes --enable-savan=yes --with-xmpp --with-openssl
make -j 10
make install
make samples -j 10

make dist
tar xf wso2-wsf-c-src-1.2.0.tar.gz
cd wso2-wsf-c-src-1.2.0
./configure
make maintainer-clean

cd axis2c/samples
./configure
make maintainer-clean
cd ../../sandesha2c/samples
./configure
make maintainer-clean
cd ../../rampartc/samples
./configure
make maintainer-clean
cd ../../../
rm -rf wso2-wsf-c-src-1.2.0.tar.gz
tar -pczf wso2-wsf-c-src-1.2.0.tar.gz wso2-wsf-c-src-1.2.0
zip -r wso2-wsf-c-src-1.2.0.zip wso2-wsf-c-src-1.2.0
rm -rf wso2-wsf-c-src-1.2.0
