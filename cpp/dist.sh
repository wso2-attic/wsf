#!/bin/bash
set -e

if test  -d ../dist_temp; then
rm -rf ../dist_temp
fi

if test -d dist_temp; then
rm -rf dist_temp
fi

cp -r . ../dist_temp
mv ../dist_temp .
cd dist_temp
cp dist.sh /tmp/dist_cpp.sh
grep -rl AXIS2C_HOME *| xargs sed -i "s/AXIS2C_HOME/WSFCPP_HOME/g"
grep -rl WSFC_HOME *| xargs sed -i "s/WSFC_HOME/WSFCPP_HOME/g"
grep -rl 'WSO2 Web Services Framework[/]' * | xargs sed -i "s/WSO2 Web Services Framework\//WSO2 Web Services Framework for /g"
find . -name "*configure.ac" | xargs sed -i "s/-Werror//g"
cp dist/link.sh dist/link_samples.sh wsf_c

cp build/wsf_c/axis2c/neethi/configure.ac wsf_c/axis2c/neethi/configure.ac
cp build/wsf_c/axis2c/neethi/src/Makefile.am wsf_c/axis2c/neethi/src/Makefile.am


cd wsf_c
./build.sh

# build registry dependency

export WSFCPP_BUILD_DIR=`pwd`
export WSFCPP_HOME=`pwd`/deploy
#if test -d $REGISTRY_HOME; then 
#cd $REGISTRY_HOME;
#./autogen.sh
#./configure --with-axis2=${WSFCPP_HOME}/include/axis2-1.6.0 --prefix=${WSFCPP_HOME} --enable-tests=yes --with-libcurl=/usr/include/curl
#make
#make install
#cd $WSFCPP_BUILD_DIR
#fi
# end registry building

cd ..
#build wsfcpp code
sh dist_hook.sh
sh autogen.sh
./configure --prefix=`pwd`/wsf_c/deploy
make -j 10
make install
make samples


cp Makefile.am Makefile.in /tmp
cp dist/Makefile.am .
rm Makefile.in
automake --no-force
make dist

cd examples
make dist
tar xf wsfcpp-samples-src-2.1.0.tar.gz
cd ..
tar xf wso2-wsf-cpp-src-2.1.0.tar.gz
mv examples/wsfcpp-samples-src-2.1.0 wso2-wsf-cpp-src-2.1.0/examples
rm wso2-wsf-cpp-src-2.1.0.tar.gz
tar -pczf wso2-wsf-cpp-src-2.1.0.tar.gz wso2-wsf-cpp-src-2.1.0

cp *tar.gz dist

cd wsf_c
sh dist.sh
cp *tar.gz ../dist
cd ..

mv /tmp/dist_cpp.sh dist.sh

cd dist
tar xf wso2-wsf-cpp-src-2.1.0.tar.gz
rm wso2-wsf-cpp-src-2.1.0.tar.gz
tar xf wso2-wsf-c-src-2.0.0.tar.gz
rm wso2-wsf-c-src-2.0.0.tar.gz
mv wso2-wsf-c-src-2.0.0 wso2-wsf-cpp-src-2.1.0/wsf_c
cd wso2-wsf-cpp-src-2.1.0
cp -r ../../include ../../build_samples.sh .
cp ../../build_codegen.sh .
mv /tmp/Makefile.am /tmp/Makefile.in .
./configure
make maintainer-clean
rm -rf `find . -type d -name .svn`
rm -rf `find . -type f -name *.la`
rm -rf `find . -type f -name *.o`
rm -rf `find . -type f -name *.lo`
rm -rf `find . -type f -name *.loT`
rm -rf `find . -type d -name .deps`
rm -rf `find . -type d -name .libs`
rm -rf `find . -type f -name Makefile`
rm -rf `find . -type d -name autom4te.cache`
rm -rf `find . -type f -name stamp-h1`

if test -d wsf_c/rampartc/samples/wso2-wsf-c-src-2.0.0; then
rm -rf wsf_c/rampartc/samples/wso2-wsf-c-src-2.0.0
fi

if test -d wsf_c/savanc/samples/wso2-wsf-c-src-2.0.0; then
rm -rf wsf_c/savanc/samples/wso2-wsf-c-src-2.0.0
fi

cd ..
tar -pczf wso2-wsf-cpp-src-2.1.0.tar.gz wso2-wsf-cpp-src-2.1.0
rm -rf `find . -type f -name config.log`
zip -r wso2-wsf-cpp-src-2.1.0.zip wso2-wsf-cpp-src-2.1.0
rm -rf wso2-wsf-cpp-src-2.1.0
mv *tar.gz ../../
mv *zip ../../
cd ../../
