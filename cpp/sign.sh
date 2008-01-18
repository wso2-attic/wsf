#!/bin/bash
if [ $# -ne 1 ]
then
    echo "Usage : $0 version"
    exit
fi

echo "Signing Source (Linux)"
gpg --armor --output wso2-wsf-cpp-src-$1.tar.gz.asc --detach-sig wso2-wsf-cpp-src-$1.tar.gz
openssl md5 < wso2-wsf-cpp-src-$1.tar.gz > wso2-wsf-cpp-src-$1.tar.gz.md5
echo "Signing wso2-wsf-cpp-src-$1.tar.gz completed"

echo "Signing Source (Win32)"
gpg --armor --output wso2-wsf-cpp-src-$1.zip.asc --detach-sig wso2-wsf-cpp-src-$1.zip
openssl md5 < wso2-wsf-cpp-src-$1.zip > wso2-wsf-cpp-src-$1.zip.md5
echo "Signing wso2-wsf-cpp-src-$1.zip completed"
