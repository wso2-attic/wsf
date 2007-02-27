#!/bin/bash
#./autogen.sh

if [ -d  "axis2" ];then
    cd axis2;
    svn up;
    cd ..
else
#    svn co https://svn.apache.org/repos/asf/webservices/axis2/trunk/c
#    mv c axis2;
    cp build/axis2/Makefile.am axis2
    cp build/axis2/configure.ac axis2
fi

if [ -d  "sandesha2" ];then
    cd sandesha2;
    svn up;
    cd ..
else
#    svn co https://svn.apache.org/repos/asf/webservices/sandesha/trunk/c;
#    mv c sandesha2;
    cp build/sandesha2/Makefile.am sandesha2
    cp build/sandesha2/src/core/Makefile.am sandesha2/src/core
    cp build/sandesha2/src/util/Makefile.am sandesha2/src/util
    cp build/sandesha2/src/wsrm/Makefile.am sandesha2/src/wsrm
    cp build/sandesha2/src/transport/Makefile.am sandesha2/src/transport
    cp build/sandesha2/src/handlers/Makefile.am sandesha2/src/handlers
    cp build/sandesha2/src/storage/Makefile.am sandesha2/src/storage
    cp build/sandesha2/src/storage/permenant/Makefile.am sandesha2/src/storage/permenant
    cp build/sandesha2/src/storage/beans/Makefile.am sandesha2/src/storage/beans
    cp build/sandesha2/src/storage/inmemory/Makefile.am sandesha2/src/storage/inmemory
    cp build/sandesha2/src/client/Makefile.am sandesha2/src/client
    cp build/sandesha2/src/msgprocessors/Makefile.am sandesha2/src/msgprocessors
    cp build/sandesha2/src/polling/Makefile.am sandesha2/src/polling
    cp build/sandesha2/src/workers/Makefile.am sandesha2/src/workers
   cp build/sandesha2/autogen.sh sandesha2
fi

cp -r build/xmpp/xmpp axis2/modules/core/transport
cp -r build/xmpp/include/*.h axis2/include
cp build/axis2/modules/core/transport/http/server/simple_axis2_server/Makefile.am axis2/modules/core/transport/http/server/simple_axis2_server/
cp build/axis2/modules/core/transport/http/sender/Makefile.am axis2/modules/core/transport/http/sender
cp build/axis2/modules/core/transport/http/sender/ssl/Makefile.am axis2/modules/core/transport/http/sender/ssl/
cp build/axis2/modules/core/transport/Makefile.am axis2/modules/core/transport
cp build/axis2/modules/core/Makefile.am axis2/modules/core

./autogen.sh
./configure --prefix=`pwd`/deploy --enable-openssl=yes --enable-rampart=yes
make


