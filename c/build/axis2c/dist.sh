#!/bin/bash

rm -rf xdocs/api/html
maven site
cd xdocs/api
doxygen doxygenconf
cd ../..

for i in `find . -name "*.la"`
do
	rm $i
done

for i in `find . -name "*.a"`
do
	rm $i
done

