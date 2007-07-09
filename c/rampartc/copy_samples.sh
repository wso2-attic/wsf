cd $1
find -name "*.svn" |xargs rm -rf
find -name "*.libs" |xargs rm -rf
find -name "*.deps" |xargs rm -rf
find -name "Makefile" |xargs rm -rf
find -name "autom4te.cache" |xargs rm -rf
