#!/bin/bash
set -e
cd axis2c
echo "Running autogen.sh in Axis2/C"
./autogen.sh
cd samples
echo "Running autogen.sh in Axis2/C samples"
./autogen.sh
cd ../tools/tcpmon
echo "Running autogen.sh in tcpmon"
./autogen.sh

cd ../../../sandesha2c 
echo "Running autogen.sh in Sandesha2/C"
./autogen.sh

cd samples
echo "Running autogen.sh in Sandesha2/C Samples"
./autogen.sh

cd ..
cd ../wsclient
echo "Running autogen.sh in wsclient"
./autogen.sh

cd ../rampartc
echo "Running autogen.sh in Rampart/C"
./autogen.sh
cd samples
echo "Running autogen.sh in Rampart/C samples"
./autogen.sh

cd ../../savanc
echo "Running autogen.sh in Savan/C"
./autogen.sh
cd samples
echo "Running autogen.sh in Savan/C samples"
./autogen.sh

cd ../../

echo "Running autogen.sh in WSF/C"
echo -n 'Running libtoolize...'
if libtoolize --force > /dev/null 2>&1; then
	echo 'done.'
else
	echo 'failed.'
	exit 1
fi

echo -n 'Running aclocal...'
if aclocal > /dev/null 2>&1; then
	echo 'done.'
else
	echo 'failed.'
	exit 1
fi

echo -n 'Running autoheader...'
if autoheader > /dev/null 2>&1; then
	echo 'done.'
else
	echo 'failed.'
	exit 1
fi

echo -n 'Running autoconf...'
if autoconf > /dev/null 2>&1; then
	echo 'done.'
else
	echo 'failed.'
	exit 1
fi

echo -n 'Running automake...'
if automake --add-missing > /dev/null 2>&1; then
	echo 'done.'
else
	echo 'failed.'
	exit 1
fi

echo 'done'

echo "Running autogen.sh in WSF/C samples"
cd examples
./autogen.sh
cd ..

