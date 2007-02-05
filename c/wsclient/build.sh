#!/bin/bash
./autogen.sh

./configure --prefix=${TUNGSTENC_HOME} --enable-tests=no --enable-trace=yes --enable-static=no --enable-openssl=no  

make 
make install

