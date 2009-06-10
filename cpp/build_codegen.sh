#!/usr/bin/sh
set -e

export DIL=`pwd`/deploy

cd wsf_c/build/codegen
mvn clean install -Drelease
cd modules/distribution/target/ 
unzip wsf-cpp-1.0-bin.zip
cd wsf-cpp-1.0
if [ -a $DIL/bin/codegen ] ; then
	cp -rf lib $DIL/bin/codegen
else
	mkdir  $DIL/bin/codegen
	cp -rf lib $DIL/bin/codegen
fi

