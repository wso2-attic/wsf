#!/bin/bash
_SCEN="scenario"
_SMPL_DIR="$PWD"
_PORT=9090
_SLEEP=2
#You may change these to scenarios u need to run
_LST="1 2 3 4 5 6 7 8 9 10 11 12 13 15 16 17 18 19 21 22 23 25 26"

if [ $# -eq 1 ]
then
    _PORT=$1
    echo "Using port $1 to start the server"
fi


for i in $_LST 
do
    S_i=$_SCEN$i
    echo "-------------------------------------------------------------------------"
    echo ">Deploying $S_i"
    echo "-------------------------------------------------------------------------"
    sh deploy.sh $S_i
    echo ">Killing server"
    killall axis2_http_server
    echo "Sleeping for $_SLEEP seconds"
    sleep $_SLEEP
    echo ">Go to $AXIS2C_HOME"
    cd $AXIS2C_HOME/bin
    echo ">Start server @ $_PORT"
    ./axis2_http_server -p$_PORT &
    sleep $_SLEEP
    #echo "Jump back to samples dir : $_SMPL_DIR"
    #cd $_SMPL_DIR
    echo ">Go to client directory"
    cd $_SMPL_DIR/../client/sec_echo
    echo ">Run the sample"
    sh update_n_run.sh
    echo ">Jump back to samples dir :$_SMPL_DIR"
    cd $_SMPL_DIR
done

#SAML Sample
#sh saml.sh
  
killall axis2_http_server
echo "DONE"

