#!/bin/sh
mkdir -p /opt/wso2
cp -r wsf_c /opt/wso2

mkdir ./lib/wso2/wsdlc
mkdir ./lib/wso2/wsdlc/xslt
mkdir ./lib/wso2/wsdlc/conf

cp -r ./wsdlc/xslt/*.* ./lib/wso2/wsdlc/xslt/


cp -r ./conf/*.* ./lib/wso2/wsdlc/conf/

/home/milinda/programs/python/bin/python2.5 setup.py --with-wsfc=/home/milinda/wso2/wsf/c/deploy build
/home/milinda/programs/python/bin/python2.5 setup.py --with-wsfc=/home/milinda/wso2/wsf/c/deploy install

rm -rf ./lib/wso2/wsdlc
