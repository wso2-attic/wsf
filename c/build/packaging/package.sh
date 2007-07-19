set -e
make dist
tar xf wso2-wsf-c-src-1.0.1.tar.gz
cd wso2-wsf-c-src-1.0.1
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
cd ../../../
rm -rf wso2-wsf-c-src-1.0.1.tar.gz
tar -pczf wso2-wsf-c-src-1.0.1.tar.gz wso2-wsf-c-src-1.0.1
zip -r wso2-wsf-c-src-1.0.1.zip wso2-wsf-c-src-1.0.1
rm -rf wso2-wsf-c-src-1.0.1
