#!/bin/bash
set -e
sh autogen.sh

./configure --prefix=`pwd`/deploy --with-axis2=${AXIS2C_HOME}/include/axis2-1.1
make -j 10 
