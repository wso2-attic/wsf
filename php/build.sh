#!/bin/bash

set -e


for i in `find . -name configure.ac`
do
    sed  's/-Werror//' $i > configure.ac.back;
    mv configure.ac.back $i;
done
./autogen.sh && ./configure --with-wsf --with-apache2=/usr/local/apache2/include --with-axis2=`pwd`/wsf_c/axis2c/include --enable-tests=yes --enable-savan=no --with-mysql=no --prefix=`php-config --extension-dir`/wsf_c && make -j 100 

