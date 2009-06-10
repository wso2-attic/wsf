#!/usr/bin/sh
set -e

@set DIL=%CD%/deploy

cd wsf_c/build/codegen
mvn clean install -Drelease
cd modules/distribution/target/ 
unzip wsf-cpp-1.0-bin.zip
cd wsf-cpp-1.0
if exist %DIL%/bin/tools/codegen
	cp -rf lib $DIL/bin/tools/codegen

if not exist %DIL%/bin/tools/codegen
	mkdir  $DIL/bin/tools/codegen
	cp -rf lib $DIL/bin/tools/codegen


