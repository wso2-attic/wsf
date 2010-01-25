#!/bin/bash

./autogen.sh

./configure --prefix=${AXIS2C_HOME} --with-axis2=${AXIS2C_HOME}/include/axis2-1.5.0 --with-savan=${AXIS2C_HOME}/include/savan-0.90
make -j10
make install
