#!/bin/bash
sh clean.sh

./autogen.sh
AXIS2C_HOME=`pwd`/deploy
export AXIS2C_HOME 

./configure --prefix=${AXIS2C_HOME} --enable-tests=no --enable-trace=yes  --enable-diclient=no --enable-static=no --enable-openssl=no --with-apache2=/usr/local/apache2/include

make
make install

cd tools/tcpmon
./autogen.sh
./configure --prefix=${AXIS2C_HOME} --enable-tests=no
make
make install

cd ../../samples

./autogen.sh

./configure --prefix=${AXIS2C_HOME} --with-axis2=${AXIS2C_HOME}/include/axis2-1.1
make
make install

make dist
tar xf axis2c-sample-src-1.1.0.tar.gz
mv axis2c-sample-src-1.1.0 samples
rm -rf ${AXIS2C_HOME}/samples
mv samples ${AXIS2C_HOME}

cd ..

rm -rf xdocs/api/html
maven site
cd xdocs/api 
doxygen doxygenconf
cd ../..
cp -r xdocs/api/html target/docs/api/
cp xdocs/docs/mod_log/module.xml target/docs/docs/mod_log
cp -r target/docs ${AXIS2C_HOME}

cd ${AXIS2C_HOME}

# rm -rf config.sub missing config.guess depcomp ltmain.sh
for i in `find . -name "*.la"`
do
   rm $i
done

for i in `find . -name "*.a"`
do
   rm $i
done

cd lib
strip -g *
cd ..
