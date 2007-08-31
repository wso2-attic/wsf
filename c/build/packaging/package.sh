set -e
make dist
tar xf wso2-wsf-c-src-1.1.0.tar.gz
cd wso2-wsf-c-src-1.1.0
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
rm -rf wso2-wsf-c-src-1.1.0.tar.gz
tar -pczf wso2-wsf-c-src-1.1.0.tar.gz wso2-wsf-c-src-1.1.0
zip -r wso2-wsf-c-src-1.1.0.zip wso2-wsf-c-src-1.1.0
rm -rf wso2-wsf-c-src-1.1.0
