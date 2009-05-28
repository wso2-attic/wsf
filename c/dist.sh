set -e
cp dist.sh dist_hook.sh /tmp
grep -rl WSFC_HOME *| xargs sed -i "s/WSFC_HOME/WSFC_HOME/g"
export WSFC_HOME=`pwd`/deploy
find . -name "*configure.ac" | xargs sed -i "s/-Werror//g"
make distclean
./configure --prefix=`pwd`/deploy --enable-openssl=yes --with-xmpp=yes --enable-tests=yes --with-apache2=/usr/local/apache2/include --with-axis2=`pwd`/axis2c/include --with-esbpub=$ESB_HOME/include --with-xpath=/usr/include/libxml2 --enable-sandesha=yes --enable-rampart=yes --enable-wsclient=yes --enable-savan=yes --enable-tcp=yes --with-archive --with-registry=$REGISTRY_HOME/include --enable-service
make 
make install
make samples
make dist
tar xf wso2-wsf-c-src-2.0.0.tar.gz
cd wso2-wsf-c-src-2.0.0

./configure
make maintainer-clean

cd axis2c/samples
./configure
make maintainer-clean
cd ../../sandesha2c/samples
./configure
make maintainer-clean
cd ../../rampartc/samples
./configure
make maintainer-clean
cd ../../savanc/samples
./configure
make maintainer-clean

cd ../../

cd ..

cp /tmp/dist.sh /tmp/dist_hook.sh .

rm -rf wso2-wsf-c-src-2.0.0.tar.gz
cd wso2-wsf-c-src-2.0.0
rm -rf `find . -type d -name .svn`
rm -rf `find . -type f -name *.la`
rm -rf `find . -type f -name *.o`
rm -rf `find . -type f -name *.lo`
rm -rf `find . -type f -name *.loT`
rm -rf `find . -type d -name .deps`
rm -rf `find . -type d -name .libs`
rm -rf `find . -type f -name Makefile`
rm -rf `find . -type d -name autom4te.cache`
cd ..
tar -pczf wso2-wsf-c-src-2.0.0.tar.gz wso2-wsf-c-src-2.0.0
rm -rf wso2-wsf-c-src-2.0.0/examples/config.log
zip -r wso2-wsf-c-src-2.0.0.zip wso2-wsf-c-src-2.0.0
rm -rf wso2-wsf-c-src-2.0.0
