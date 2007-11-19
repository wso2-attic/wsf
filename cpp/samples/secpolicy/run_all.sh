#!/bin/bash
_SCEN="scenario"
_SMPL_DIR="$PWD"
_PORT=9090
_SLEEP=3
#You may change these to scenarios u need to run
_LST="1 2 3 4 5 6 7"

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
    #echo "Jump back to samples dir : $_SMPL_DIR"
    cd $_SMPL_DIR
    sh update_n_run.sh
    echo ">Run the sample"
    #!/bin/bash
    #If your client repository is different, change the value.
    CLIENT_REPO="$AXIS2C_HOME/client_repo"

    #INSTALL MODULE to make sure that both server and client have the same module.
    echo "Copying latest module to client_repo"
    cp -r $AXIS2C_HOME/modules/rampart $CLIENT_REPO/modules

    #RUN

    echo ">Jump back to samples dir :$_SMPL_DIR"
    cd $_SMPL_DIR
done
    
killall axis2_http_server
echo "DONE"

