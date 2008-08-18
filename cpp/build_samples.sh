#!/usr/bin/sh
set -e
export LD_LIBRARY_PATH=$1/lib; 


cd examples
./configure
make
cd ..
