#!/bin/bash

./autogen.sh

./configure --prefix=/axis2c/deploy --with-axis2=${AXIS2C_HOME}/include/axis2-1.5.0 --with-savan=${AXIS2C_HOME}/include/savan-0.90
make -j30
make install

