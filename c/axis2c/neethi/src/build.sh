gcc -g -I$AXIS2C_HOME/include/axis2-1.0 -I../include -L$AXIS2C_HOME/lib -L. -laxutil -laxis2_axiom -laxis2_parser *.c -o test
