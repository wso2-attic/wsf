#!/bin/bash
./autogen.sh
export WSFC_HOME=/axis2c/deploywsfc
./configure --prefix=${WSFC_HOME} --with-axis2=${WSFC_HOME}/include/axis2-1.6.0 --enable-static=no --enable-openssl=no --enable-rampart=yes
make 
#make install

