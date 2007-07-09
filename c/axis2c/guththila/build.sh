./autogen.sh
./configure --prefix=${AXIS2C_HOME} --with-axis2_util=${AXIS2C_HOME}/include
make
make install
