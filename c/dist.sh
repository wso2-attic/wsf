#!/bin/sh
cd sandesha2c/samples
find . -name "*.c" | xargs sed -i "s/8888/9090/g"
find . -name "*.c" | xargs sed -i "s/7777/6060/g"
cd ../../
cd wso2-wsf-c-src-1.0
mv axis2c/xdocs docs/axis2c
mv savanc/xdocs docs/savanc
mv sandesha2c/xdocs docs/sandesha2c
mv rampartc/xdocs docs/rampartc
mv wsclient/docs docs/wsclient

mkdir examples/axis2c
mkdir examples/savanc
mkdir examples/sandesha2c
mkdir examples/rampartc
mkdir examples/wsclient

cp -r axis2c/samples/* examples/axis2c
cp -r savanc/samples/* examples/savanc
cp -r sandesha2c/samples/* examples/sandesha2c
cp -r rampartc/samples/* examples/rampartc
cp -r wsclient/samples/* examples/wsclient

find -name "*.libs"| xargs rm -rf
find -name "*.deps"| xargs rm -rf
find -name "*.svn"| xargs rm -rf
find -name "Makefile"| xargs rm -rf
grep -rl AXIS2C_HOME *| xargs sed -i "s/AXIS2C_HOME/WSFC_HOME/g"
cd ..
