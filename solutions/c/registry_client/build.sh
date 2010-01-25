#!/bin/bash
./autogen.sh
./configure --with-axis2=${AXIS2C_HOME}/include/axis2-1.6.0 --prefix=${AXIS2C_HOME} --enable-tests=yes --with-libcurl=${CURL_HOME}/include
