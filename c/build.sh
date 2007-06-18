#!/bin/bash

set -e 

rm -rf axis2c/samples/server/listener
cp -r build/xmpp/samples/listener axis2c/samples/server
cp build/rampartc/configure.ac rampartc
cp build/savanc/configure.ac savanc
cp build/axis2c/configure.ac axis2c
cp build/axis2c/Makefile.am axis2c
cp build/rampartc/Makefile.am rampartc
cp build/sandesha2c/configure.ac sandesha2c
cp build/axis2c/src/core/engine/Makefile.am axis2c/src/core/engine/
cp build/axis2c/src/core/transport/Makefile.am axis2c/src/core/transport/Makefile.am
cp build/neethi/configure.ac axis2c/neethi
cp build/neethi/Makefile.am axis2c/neethi

./autogen.sh
./configure --prefix=`pwd`/deploy --enable-openssl=yes --enable-xmpp=no --with-axis2=`pwd`/axis2c/include --enable-sandesha=yes --enable-rampart=yes --enable-wsclient=yes
make
make install
make samples
