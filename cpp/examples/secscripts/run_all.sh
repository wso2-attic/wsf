#!/bin/bash
_SCEN=$WSFCPP_HOME/samples/src/c/rampartc/secpolicy/"scenario"
_SMPL_DIR="$PWD"
_PORT=9090
_SLEEP=2
#You may change these to scenarios u need to run
_LST="1 2 3 4 5 6 7 8 9 10 11 12 13 15 16 17 18 19 21 22 23 25 26 27 28"

if [ $# -eq 1 ]
then
    _PORT=$1
    echo "Using port $1 to start the server"
fi


for i in $_LST 
do
    S_i=$_SCEN$i
	sh test_scen.sh $S_i $_PORT
done

#SAML Sample
#sh saml.sh
  
killall axis2_http_server
echo "DONE"

