#!/bin/bash
DIST="wsf_php_store_demo"

rm -rf $DIST

mkdir $DIST
mkdir $DIST/keys

cp design.jpg $DIST/  
cp manuf_service.php $DIST/
cp store_client.php $DIST/
cp policy.xml $DIST/
cp README $DIST/
cp store_daemon.sh $DIST/
cp keys/*.cert $DIST/keys
cp keys/*.pem $DIST/keys

echo "Make the tar"
tar -czvf $DIST.tar.gz $DIST

echo "Make the zip"
zip -r $DIST.zip $DIST
