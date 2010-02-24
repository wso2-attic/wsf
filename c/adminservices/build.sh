#!/bin/bash
./autogen.sh
export WSFC_HOME=/axis2c/deploywsfc
./configure --prefix=${WSFC_HOME} --with-wsfc=${WSFC_HOME}/include/wsfc-2.0.0 --enable-static=no --enable-openssl=no --enable-rampart=yes
make 
#make install

