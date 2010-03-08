#!/bin/bash

set -e 

export WSFC_HOME=`pwd`/deploy
export WSFC_HOME=`pwd`/deploy
export AXIS2C_HOME=`pwd`/deploy

./build/copy_build_files.sh

./autogen.sh
./configure --prefix=`pwd`/deploy --enable-openssl=yes --enable-tests=yes --with-apache2=/usr/local/apache2/include --with-axis2=`pwd`/axis2c/include --with-wsfc=`pwd`/axis2c/include --enable-sandesha=yes --enable-rampart=yes --enable-wsclient=yes --enable-savan=yes --enable-xpath --enable-service --with-xmpp --with-xpath=/usr/include/libxml2/libxml --with-archive
make -j 10
make install
