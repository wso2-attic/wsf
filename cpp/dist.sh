cp -r . ../dist_temp
mv ../dist_temp .
cd dist_temp
cp dist.sh /tmp/dist_cpp.sh
grep -rl AXIS2C_HOME *| xargs sed -i "s/AXIS2C_HOME/WSFCPP_HOME/g"
grep -rl WSFC_HOME *| xargs sed -i "s/WSFC_HOME/WSFCPP_HOME/g"
find . -name "*configure.ac" | xargs sed -i "s/-Werror//g"
cp dist/link.sh dist/link_samples.sh wsf_c
./build.sh
cd wsf_c
sh dist.sh
cd ..
cp Makefile.am Makefile.in /tmp
cp dist/Makefile.am .
rm Makefile.in
automake --no-force
make dist
cp *tar.gz dist
cd wsf_c
cp *tar.gz ../dist
cd ..
mv /tmp/dist_cpp.sh dist.sh
cd dist
tar xf wso2-wsf-cpp-src-1.0.0.tar.gz
rm wso2-wsf-cpp-src-1.0.0.tar.gz
tar xf wso2-wsf-c-src-1.2.0.tar.gz
rm wso2-wsf-c-src-1.2.0.tar.gz
mv wso2-wsf-c-src-1.2.0 wso2-wsf-cpp-src-1.0.0/wsf_c
cd wso2-wsf-cpp-src-1.0.0
cp -r ../../include ../../build_samples.sh .
mv /tmp/Makefile.am /tmp/Makefile.in .
./configure
make maintainer-clean
rm -rf `find . -type d -name .svn`
rm -rf `find . -type f -name *.la`
rm -rf `find . -type f -name *.o`
rm -rf `find . -type f -name *.lo`
rm -rf `find . -type f -name *.loT`
rm -rf `find . -type d -name .deps`
rm -rf `find . -type d -name .libs`
rm -rf `find . -type f -name Makefile`
rm -rf `find . -type d -name autom4te.cache`
cd ..
tar -pczf wso2-wsf-cpp-src-1.0.0.tar.gz wso2-wsf-cpp-src-1.0.0
zip -r wso2-wsf-cpp-src-1.0.0.zip wso2-wsf-cpp-src-1.0.0
rm -rf wso2-wsf-cpp-src-1.0.0
mv *tar.gz ../../
mv *zip ../../
cd ../../
rm -rf dist_temp
