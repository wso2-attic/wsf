#!/bin/bash
_SMPL_DIR="$PWD"

if [ $# -ne 2 ]
then
    echo "Usage : $0 scenarioX server-port"
    exit
fi
    S_i=$1
    _PORT=$2
    echo "-------------------------------------------------------------------------"
    echo ">Deploying $S_i"
    sh deploy.sh $S_i
    echo ">Killing server"
    killall axis2_http_server
    echo ">Go to $AXIS2C_HOME"
    cd $AXIS2C_HOME/bin
    echo ">Start server @ $_PORT"
    ./axis2_http_server -p$_PORT &
    echo ">Go to client directory"
    cd $_SMPL_DIR/../client/sec_echo
    echo ">Run the sample"
    sh update_n_run.sh
    echo ">Jump back to samples dir :$_SMPL_DIR"
    cd $_SMPL_DIR
    
killall axis2_http_server
echo "DONE"

