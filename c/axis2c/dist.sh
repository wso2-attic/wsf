#!/bin/bash

rm -rf xdocs/api/html
maven site
cd xdocs/api
doxygen doxygenconf
cd ../..
cp -r xdocs/api/html target/docs/api/
cp xdocs/docs/mod_log/module.xml target/docs/docs/mod_log
cp -r target/docs axis2c-src-1.0.0
cd samples
make dist
tar -xf axis2c-src-1.0.0.tar.gz
mv  axis2c-src-1.0.0 ../axis2c-src-1.0.0
cd ../axis2c-src-1.0.0
mv axis2c-src-1.0.0 samples

for i in `find . -name "*.la"`
do
	rm $i
done

for i in `find . -name "*.a"`
do
	rm $i
done

