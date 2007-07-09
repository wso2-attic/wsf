#!/bin/bash

if [ -z "$1" ] ; then
    AXIS2C_DEPLOY="/usr/local/axis2c"
else
    AXIS2C_DEPLOY=$1
fi

if [ `uname -s` = Darwin ]
then
    export DYLD_LIBRARY_PATH=${AXIS2C_DEPLOY}/lib
else
    export LD_LIBRARY_PATH=${AXIS2C_DEPLOY}/lib
fi

./configure --prefix=${AXIS2C_DEPLOY}
make 
make install

cd samples
./configure --prefix=${AXIS2C_DEPLOY} --with-axis2==${AXIS2C_DEPLOY}/include/axis2-1.1
make 
make install


