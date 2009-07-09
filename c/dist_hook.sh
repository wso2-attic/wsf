#!/bin/sh
cd sandesha2c/samples
find . -name "*.c" | xargs sed -i "s/8888/9090/g"
find . -name "*.c" | xargs sed -i "s/7777/6060/g"
cd ../../

cd axis2c/samples
make dist
tar -xf wso2-wsf-c-src-2.0.0.tar.gz
mv wso2-wsf-c-src-2.0.0   ../../wso2-wsf-c-src-2.0.0/axis2c/samples

cd ../../sandesha2c/samples
make dist
tar -xf wso2-wsf-c-src-2.0.0.tar.gz
mv wso2-wsf-c-src-2.0.0   ../../wso2-wsf-c-src-2.0.0/sandesha2c/samples

cd ../../rampartc/samples
make dist
tar -xf wso2-wsf-c-src-2.0.0.tar.gz
mv wso2-wsf-c-src-2.0.0   ../../wso2-wsf-c-src-2.0.0/rampartc/samples

cd ../../savanc/samples
make dist
tar -xf wso2-wsf-c-src-2.0.0.tar.gz
mv wso2-wsf-c-src-2.0.0   ../../wso2-wsf-c-src-2.0.0/savanc/samples

cd ../../
cd axis2c/xdocs/api
doxygen doxygenconf
cd ../../../
cd rampartc/xdocs/api
doxygen doxygenconf
cd ../../../
cd sandesha2c/xdocs/api
doxygen doxygenconf
cd ../../../
cd savanc/xdocs/api
doxygen doxygenconf
cd ../../../

cd wso2-wsf-c-src-2.0.0
cp -r ../axis2c/xdocs docs/axis2c
cp -r ../axis2c/xdocs/api/html docs/axis2c/api
cp -r ../savanc/xdocs/docs docs/savanc
cp -r ../savanc/xdocs/api/html docs/savanc/api
cp -r ../sandesha2c/xdocs docs/sandesha2c
cp -r ../sandesha2c/xdocs/api/html docs/sandesha2c/api
cp -r ../rampartc/xdocs docs/rampartc
cp -r ../rampartc/xdocs/api/html docs/rampartc/api
cp -r wsclient/docs docs/wsclient

grep -rl WSFC_HOME *| xargs sed -i "s/WSFC_HOME/WSFC_HOME/g"
cd ..
