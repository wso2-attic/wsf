#!/bin/sh
cd sandesha2c/samples
find . -name "*.c" | xargs sed -i "s/8888/9090/g"
find . -name "*.c" | xargs sed -i "s/7777/6060/g"
cd ../../

cd axis2c/samples
make dist
tar -xf wso2-wsf-c-src-1.0.tar.gz
mv wso2-wsf-c-src-1.0   ../../wso2-wsf-c-src-1.0.0/axis2c/samples

cd ../../sandesha2c/samples
make dist
tar -xf wso2-wsf-c-src-1.0.tar.gz
mv wso2-wsf-c-src-1.0   ../../wso2-wsf-c-src-1.0.0/sandesha2c/samples

cd ../../rampartc/samples
make dist
tar -xf wso2-wsf-c-src-1.0.tar.gz
mv wso2-wsf-c-src-1.0   ../../wso2-wsf-c-src-1.0.0/rampartc/samples

cd ../../

cd wso2-wsf-c-src-1.0.0
cp -r axis2c/xdocs docs/axis2c
cp -r savanc/xdocs docs/savanc
cp -r sandesha2c/xdocs docs/sandesha2c
cp -r rampartc/xdocs docs/rampartc
cp -r wsclient/docs docs/wsclient

rm -rf `find . -type d -name .svn`
rm -rf `find . -type f -name *.la`
rm -rf `find . -type f -name *.o`
rm -rf `find . -type f -name *.lo`
rm -rf `find . -type f -name *.loT`
rm -rf `find . -type d -name .deps`
rm -rf `find . -type d -name .libs`
rm -rf `find . -type f -name Makefile`
rm -rf `find . -type d -name autom4te.cache`

grep -rl AXIS2C_HOME *| xargs sed -i "s/AXIS2C_HOME/WSFC_HOME/g"
cd ..
