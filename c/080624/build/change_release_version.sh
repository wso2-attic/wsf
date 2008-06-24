#!/bin/sh
if [ ! "$2" ]
then
    echo "Usage $0    Current version        Next version"
    exit 1
fi

sed -i "s/$1/$2/g" configure.ac
sed -i "s/$1/$2/g" dist.sh
sed -i "s/$1/$2/g" dist_hook.sh
sed -i "s/$1/$2/g" build.bat
