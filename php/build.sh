#!/bin/bash
#./autogen.sh

if [ -d  "wsf_c" ];then
    cd wsf_c
    svn up
    cd ..
else
    svn co https://wso2.org/repos/wso2/wsf/c
    mv c wsf_c
fi

cd wsf_c

if [ -d  "axis2" ];then
    cd axis2;
    svn up;
    cd ..
else
    svn co https://svn.apache.org/repos/asf/webservices/axis2/trunk/c
    mv c axis2;
    cp build/axis2/Makefile.am axis2
fi


#if [ -d  "sandesha2" ];then
#    cd sandesha2;
#    svn up;
#    cd ..
#else
#    svn co https://svn.apache.org/repos/asf/webservices/sandesha/trunk/c;
#    mv c sandesha2;
#    cp build/sandesha2/Makefile.am sandesha2
#    cp build/sandesha2/src/core/Makefile.am sandesha2/src/core
#    cp build/sandesha2/src/util/Makefile.am sandesha2/src/util
#    cp build/sandesha2/src/wsrm/Makefile.am sandesha2/src/wsrm
#    cp build/sandesha2/src/transport/Makefile.am sandesha2/src/transport
#    cp build/sandesha2/src/handlers/Makefile.am sandesha2/src/handlers
#    cp build/sandesha2/src/storage/Makefile.am sandesha2/src/storage
#    cp build/sandesha2/src/storage/permanent/Makefile.am sandesha2/src/storage/permanent
#    cp build/sandesha2/src/storage/beans/Makefile.am sandesha2/src/storage/beans
#    cp build/sandesha2/src/storage/inmemory/Makefile.am sandesha2/src/storage/inmemory
#    cp build/sandesha2/src/client/Makefile.am sandesha2/src/client
#    cp build/sandesha2/src/msgprocessors/Makefile.am sandesha2/src/msgprocessors
#    cp build/sandesha2/src/polling/Makefile.am sandesha2/src/polling
#    cp build/sandesha2/src/workers/Makefile.am sandesha2/src/workers
#    cp build/sandesha2/autogen.sh sandesha2
#fi

cd ..

cp build/wsf_c/axis2/configure.ac wsf_c/axis2
cp build/wsf_c/axis2/rampart/samples/Makefile.am wsf_c/axis2/rampart/samples
cp build/wsf_c/axis2/rampart/samples/callback/Makefile.am wsf_c/axis2/rampart/samples/callback
cp build/wsf_c/axis2/rampart/samples/callback/htpasswd_callback/Makefile.am wsf_c/axis2/rampart/samples/callback/htpasswd_callback
cp build/wsf_c/axis2/rampart/configure.ac wsf_c/axis2/rampart
cp build/wsf_c/axis2/rampart/Makefile.am wsf_c/axis2/rampart
cp build/wsf_c/axis2/rampart/autogen.sh wsf_c/axis2/rampart
#cp build/wsf_c/sandesha2/src/core/Makefile.am wsf_c/sandesha2/src/core
#cp build/wsf_c/sandesha2/Makefile.am wsf_c/sandesha2/
cp build/wsf_c/axis2/Makefile.am wsf_c/axis2/
cp wsf_c/axis2/samples/server/axis2.xml .

./autogen.sh && ./configure --with-wsf && make

