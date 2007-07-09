#!/bin/bash
echo 'Running autogen.sh in Util'
cd util
sh autogen.sh

echo 'Running autogen.sh in Axiom'
cd ../axiom
sh autogen.sh

echo 'Running autogen.sh in Guththila'
cd ../guththila
sh autogen.sh

echo 'Running autogen.sh in Neethi'
cd ../neethi
sh autogen.sh

echo 'Running autogen.sh in Axis2/C'
cd ..

echo -n 'Running libtoolize...'
if [ `uname -s` = Darwin ]
then
    LIBTOOLIZE=glibtoolize
else
    LIBTOOLIZE=libtoolize
fi

if $LIBTOOLIZE --force > /dev/null 2>&1; then

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
