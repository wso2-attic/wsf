#!/bin/sh

export CODEGEN_HOME=`pwd`/../
for f in $CODEGEN_HOME/lib/*.jar
do
  CODEGEN_CLASSPATH=$CODEGEN_CLASSPATH:$f
done
export CODEGEN_CLASSPATH

echo the classpath $CODEGEN_CLASSPATH
java -classpath $CODEGEN_CLASSPATH org.apache.axis2.wsdl.WSDL2CPP $*
