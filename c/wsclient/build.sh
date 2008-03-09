#!/bin/bash
./autogen.sh

./configure --prefix=${WSFC_HOME} --with-axis2=${WSFC_HOME}/include/ --enable-tests=no --enable-trace=yes --enable-static=no --enable-openssl=no --enable-rampart=yes

make 
make install

