#!/bin/sh
# package the component
make clean
make

cp build/skel/src/tungsten_skel.dll xpi/skel
cp build/stub/src/tungsten_stub.dll xpi/components
cp base/soap/public/_xpidlgen/tungsten.xpt xpi/components
cd xpi
sh winzip.sh

