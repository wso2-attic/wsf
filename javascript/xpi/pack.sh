#!/bin/sh
# package the component
make clean
make

#cp build/skel/src/libtungsten_skel.so xpi/components
cp build/skel/src/libtungsten_skel.so xpi/skel
cp build/stub/src/libtungsten_stub.so xpi/components
cp base/soap/public/_xpidlgen/tungsten.xpt xpi/components
cd xpi
sh zip.sh

