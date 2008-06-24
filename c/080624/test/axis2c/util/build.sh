gcc -o test_util -g -I./ -I../../framework/include -I$WSFC_HOME/include/axis2-1.3.0/ -L$WSFC_HOME/lib -laxutil -lwso2_wsfc_unit -lpthread *.c -ldl -Wl,--rpath -Wl,$WSFC_HOME/lib
