#!/usr/bin/sh
echo $1
cd axis2c/samples
./autogen.sh
./configure --prefix=$1
make
make install
cd ../../sandesha2c/samples
./autogen.sh
./configure --prefix=$1
make
make install
cd ../../rampartc/samples
./autogen.sh
./configure --prefix=$1
#make
make install
