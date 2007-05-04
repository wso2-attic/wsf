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

cd ../samples
./configure --prefix=${AXIS2C_DEPLOY} --with-axis2_util=${AXIS2C_DEPLOY}/include --with-axiom=${AXIS2C_DEPLOY}/include
make 
make install


