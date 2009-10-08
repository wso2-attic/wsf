#!/bin/bash
set -e

cd wsf_c
./build/copy_build_files.sh
cd ..
cp wsf_c/build/rampartc/configure.ac wsf_c/rampartc/configure.ac
cp build/wsf_c/axis2c/neethi/configure.ac wsf_c/axis2c/neethi/configure.ac
cp build/wsf_c/axis2c/neethi/src/Makefile.am wsf_c/axis2c/neethi/src/Makefile.am
sh autogen.sh

./configure --prefix=`pwd`/deploy 
make -j 10 
make install
make examples


