#!/bin/bash

set -e

echo ${AXIS2C_HOME}

# specify a folder to install WSF/Perl to a non standard
# folder on your system
LIB=""

# specify the folder where your WSF/C libraries are installed
LIBS=""

# specify the folder where your WSF/C include files are installed
INC=""

if [ -z "$LIB" ]; then
	echo "ERROR: LIB is not set."
	exit 1
fi

if [ -z "$LIBS" ]; then
	echo "ERROR: LIBS is not set."
	exit 1
fi

if [ -z "$INC" ]; then
	echo "ERROR: INC is not set."
fi

echo "Running SWIG..."
swig -Wall -perl -o WSFC_wrap.c swig/WSFC.i

echo "Generating Makefile..."
perl Makefile.PL PREFIX="$LIB" LIB="$LIB" verbose

echo "Running Make..."
make
make install
