#!/bin/bash
#./autogen.sh

set -e 

#if [ -d  "axis2c" ];then
#    cd axis2c;
#    svn up;
#    cd ..
#else
#    svn co https://svn.apache.org/repos/asf/webservices/axis2/trunk/c
#    mv c axis2;
#    cp build/axis2c/Makefile.am axis2c
#    cp build/axis2c/samples/server/Makefile.am axis2c/samples/server
#    cp build/axis2c/configure.ac axis2c
#fi

    cp build/axis2c/Makefile.am axis2c
    cp build/axis2c/samples/server/Makefile.am axis2c/samples/server
    cp build/axis2c/configure.ac axis2c

rm -rf axis2c/src/core/transport/xmpp
rm -rf axis2c/samples/server/listener
cp -r build/xmpp/xmpp axis2c/src/core/transport
cp -r build/xmpp/include/*.h axis2c/include
cp -r build/xmpp/samples/listener axis2c/samples/server
cp build/axis2c/src/core/transport/http/server/simple_axis2_server/Makefile.am axis2c/src/core/transport/http/server/simple_axis2_server/
cp build/axis2c/src/core/transport/http/sender/Makefile.am axis2c/src/core/transport/http/sender
cp build/axis2c/src/core/transport/http/sender/ssl/Makefile.am axis2c/src/core/transport/http/sender/ssl/
cp build/axis2c/src/core/transport/http/Makefile.am axis2c/src/core/transport/http
cp build/axis2c/src/core/transport/Makefile.am axis2c/src/core/transport
cp build/axis2c/src/core/Makefile.am axis2c/src/core

cp build/savanc/src/Makefile.am savanc/src/
cp build/savanc/samples/client/subscriber/Makefile.am savanc/samples/client/subscriber/

./autogen.sh
./configure --prefix=`pwd`/deploy --enable-openssl=yes --enable-rampart=yes --enable-xmpp=no 
make


