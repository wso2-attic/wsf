#!/bin/sh
rm wso2_wsf_for_ajax_0.1.xpi
mkdir deploy
mkdir deploy/lib
mkdir deploy/modules
mkdir deploy/modules/addressing
mkdir deploy/logs


REQ_LIBS="$AXIS2C_HOME/lib/libaxis2_minizip.so $AXIS2C_HOME/lib/libaxutil.so $AXIS2C_HOME/lib/libaxis2_parser.so $AXIS2C_HOME/lib/libaxis2_axiom.so $AXIS2C_HOME/lib/libaxis2_engine.so  $AXIS2C_HOME/lib/libaxis2_http_sender.so  $AXIS2C_HOME/lib/libaxis2_http_receiver.so"
#echo $REQ_LIBS
cp $REQ_LIBS deploy/lib -f
cp $AXIS2C_HOME/modules/addressing/*.so deploy/modules/addressing -f
cp $AXIS2C_HOME/modules/addressing/module.xml deploy/modules/addressing -f
cp $AXIS2C_HOME/axis2.xml deploy -f

#stripting
strip deploy/lib/*.so
strip deploy/modules/addressing/*.so
#zip -r tungsten.xpi components install.rdf skel deploy chrome/tungsten.jar chrome.manifest

zip wso2_wsf_for_ajax_0.1.xpi components/*.so components/*.xpt install.rdf skel/*.so deploy/lib/*.so deploy/modules/addressing/*.so deploy/modules/addressing/module.xml  deploy/axis2.xml chrome/tungsten.jar chrome.manifest

rm deploy -rf
