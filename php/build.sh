#!/bin/bash

set -e
cd wsf_c
build/copy_build_files.sh
cd ..

for i in `find . -name configure.ac`
do
    sed  's/-Werror//' $i > configure.ac.back;
    mv configure.ac.back $i;
done
./autogen.sh && ./configure --with-wsf --enable-openssl --with-apache2=/usr/local/apache2/include --with-axis2=`pwd`/wsf_c/axis2c/include --enable-tests=no --enable-wsclient=no --with-mysql  --enable-savan=no --prefix=`php-config --extension-dir`/wsf_c && make -j 100 

