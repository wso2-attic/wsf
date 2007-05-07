#!/bin/bash
#./autogen.sh

if [ -d  "axis2c" ];then
    cd axis2c;
    svn up;
    cd ..
    cp build/axis2c/Makefile.am axis2c
    cp build/axis2c/samples/server/Makefile.am axis2c/samples/server
    cp build/axis2c/configure.ac axis2c
else
#    svn co https://svn.apache.org/repos/asf/webservices/axis2/trunk/c
#    mv c axis2;
    cp build/axis2c/Makefile.am axis2c
    cp build/axis2c/samples/server/Makefile.am axis2c/samples/server
    cp build/axis2c/configure.ac axis2c
fi

if [ -d  "sandesha2c" ];then
    cd sandesha2c;
    svn up;
    cd ..
else
    svn co https://svn.apache.org/repos/asf/webservices/sandesha/trunk/c;
    mv c sandesha2c;
fi

cp build/sandesha2c/src/client/Makefile.am sandesha2c/src/client/
cp build/sandesha2c/src/core/Makefile.am sandesha2c/src/core/
cp build/sandesha2c/src/handlers/Makefile.am sandesha2c/src/handlers/
cp build/sandesha2c/src/msgprocessors/Makefile.am sandesha2c/src/msgprocessors/
cp build/sandesha2c/src/polling/Makefile.am sandesha2c/src/polling/
cp build/sandesha2c/src/storage/Makefile.am sandesha2c/src/storage/
cp build/sandesha2c/src/transport/Makefile.am sandesha2c/src/transport/
cp build/sandesha2c/src/util/Makefile.am sandesha2c/src/util/
cp build/sandesha2c/src/workers/Makefile.am sandesha2c/src/workers/
cp build/sandesha2c/src/wsrm/Makefile.am sandesha2c/src/wsrm/
cp build/sandesha2c/src/storage/beans/Makefile.am sandesha2c/src/storage/beans
cp build/sandesha2c/src/storage/inmemory/Makefile.am sandesha2c/src/storage/inmemory
cp build/sandesha2c/src/storage/mysql/Makefile.am sandesha2c/src/storage/mysql
cp build/sandesha2c/src/storage/sqlite/Makefile.am sandesha2c/src/storage/sqlite
cp build/sandesha2c/Makefile.am sandesha2c
cp build/sandesha2c/autogen.sh sandesha2c


rm -rf axis2c/src/core/transport/xmpp
rm -rf axis2c/samples/server/listener
cp -r build/xmpp/xmpp axis2c/src/core/transport
cp -r build/xmpp/include/*.h axis2c/include
cp -r build/xmpp/samples/listener axis2c/samples/server
cp build/axis2c/src/core/transport/http/server/simple_axis2_server/Makefile.am axis2c/src/core/transport/http/server/simple_axis2_server/
cp build/axis2c/src/core/transport/http/sender/Makefile.am axis2c/src/core/transport/http/sender
cp build/axis2c/src/core/transport/http/sender/ssl/Makefile.am axis2c/src/core/transport/http/sender/ssl/
cp build/axis2c/src/core/transport/Makefile.am axis2c/src/core/transport
cp build/axis2c/src/core/Makefile.am axis2c/src/core

./autogen.sh
./configure --prefix=`pwd`/deploy --enable-openssl=yes --enable-rampart=yes --enable-xmpp=yes --with-mysql=/usr/include/mysql 
make


