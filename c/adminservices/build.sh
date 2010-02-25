#!/bin/bash
export WSFC_HOME=./../deploy
sh autogen.sh
./configure --prefix=${WSFC_HOME} --with-wsfc=${WSFC_HOME}/include/wsfc-2.0.0 --enable-static=no --enable-openssl=no --enable-rampart=yes
make 
#make install

