#!/usr/bin/sh
set -e
export LD_LIBRARY_PATH=$1/lib; cd axis2c/samples; ./autogen.sh; ./configure --prefix=$1; make; make install ;cd ../../sandesha2c/samples; ./autogen.sh; ./configure --prefix=$1; make; make install; cd ../../rampartc/samples; ./autogen.sh; ./configure --prefix=$1 ; make; make install
