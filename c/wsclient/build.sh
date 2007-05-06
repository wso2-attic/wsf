#!/bin/bash
./autogen.sh

./configure --prefix=${WSFC_HOME} --enable-tests=no --enable-trace=yes --enable-static=no --enable-openssl=no  

make 
make install

