#!/usr/bin/sh
set -e

if ! test -d $1/samples; then 
    mkdir $1/samples;
    cp -r rampartc/samples/* $1/samples;
fi    

find $1/samples -name "*.o"| xargs rm -rf

#if test -e rampartc/samples/Makefile; then
cd rampartc/samples; ./configure --prefix=$1 --with-axis2=$1/include/axis2-1.6.0; make; make install;

