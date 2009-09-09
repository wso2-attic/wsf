#!/bin/bash
set -e

cp wsf_c/build/rampartc/configure.ac wsf_c/rampartc/configure.ac
cp build/wsf_c/axis2c/neethi/configure.ac wsf_c/axis2c/neethi/configure.ac
cp build/wsf_c/axis2c/neethi/src/Makefile.am wsf_c/axis2c/neethi/src/Makefile.am

sh autogen.sh

./configure --prefix=`pwd`/deploy --enable-openssl=yes --enable-tests=yes --with-apache2=/usr/local/apache2/include --with-axis2=`pwd`/axis2c/include --enable-sandesha=yes --enable-rampart=yes --enable-wsclient=yes --enable-savan=yes --with-xmpp --with-xpath=/usr/include/libxml2/libxml
make -j 10 
make install
make examples


