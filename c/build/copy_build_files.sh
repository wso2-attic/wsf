#!/bin/bash

set -e 

rm -rf axis2c/samples/server/listener
cp -r build/xmpp/samples/listener axis2c/samples/server
cp build/axis2c/configure.ac axis2c
cp build/axis2c/axiom/Makefile.am axis2c/axiom
cp build/axis2c/axiom/configure.ac axis2c/axiom
cp build/axis2c/axiom/src/parser/Makefile.am axis2c/axiom/src/parser
cp build/axis2c/Makefile.am axis2c
cp build/axis2c/src/core/engine/Makefile.am axis2c/src/core/engine/
cp build/axis2c/src/core/transport/Makefile.am axis2c/src/core/transport/Makefile.am
cp build/axis2c/neethi/Makefile.am axis2c/neethi
cp build/axis2c/neethi/src/util/Makefile.am axis2c/neethi/src/util
cp build/neethi/configure.ac axis2c/neethi
cp build/neethi/src/Makefile.am axis2c/neethi/src
cp build/axis2c/guththila/Makefile.am axis2c/guththila
cp build/axis2c/tools/tcpmon/Makefile.am axis2c/tools/tcpmon
cp build/axis2c/tools/tcpmon/configure.ac axis2c/tools/tcpmon
cp build/axis2c/xdocs/doxygenconf axis2c/xdocs/api
cp build/axis2c/dist.sh axis2c

#copy files for stomp client
cp build/axis2c/util/Makefile.am axis2c/util
cp build/axis2c/util/include/Makefile.am axis2c/util/include
cp build/axis2c/util/configure.ac axis2c/util
cp build/axis2c/util/src/Makefile.am axis2c/util/src
cp build/axis2c/util/src/stomp/*.h axis2c/util/include
cp -rf build/axis2c/util/src/stomp  axis2c/util/src/ 
#end copying for stomp

cp build/rampartc/Makefile.am rampartc
cp build/rampartc/configure.ac rampartc
cp build/sandesha2c/configure.ac sandesha2c
cp build/sandesha2c/Makefile.am sandesha2c
cp build/savanc/Makefile.am savanc/
cp build/savanc/configure.ac savanc/
