#!/bin/bash
./autogen.sh

./configure --prefix=${WSFC_HOME} --enable-tests=no   

make 
make install

