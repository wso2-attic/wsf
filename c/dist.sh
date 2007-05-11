#!/bin/sh
cd sandesha2c/samples
find . -name "*.c" | xargs sed -i "s/8888/9090/g"
find . -name "*.c" | xargs sed -i "s/7777/6060/g"
cd ../../
