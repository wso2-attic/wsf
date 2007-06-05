#!/bin/bash
#./autogen.sh

set -e 

#if [ -d  "axis2c" ];then
#    cd axis2c;
#    svn up;
#    cd ..
#fi

#    cp build/axis2c/configure.ac axis2c

#rm -rf axis2c/src/core/transport/xmpp
rm -rf axis2c/samples/server/listener
cp -r build/xmpp/samples/listener axis2c/samples/server
cp build/rampartc/configure.ac rampartc
cp build/savanc/configure.ac savanc
cp build/axis2c/configure.ac axis2c
cp build/axis2c/src/core/engine/Makefile.am axis2c/src/core/engine/
cp build/axis2c/src/core/transport/Makefile.am axis2c/src/core/transport/Makefile.am

./autogen.sh
./configure --prefix=`pwd`/deploy --enable-openssl=yes --enable-rampart=yes --enable-wsclient=yes --enable-sandesha=yes --enable-xmpp=no --with-axis2=`pwd`/axis2c/include 
make


