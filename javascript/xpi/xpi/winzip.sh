#!/bin/sh
rm win_wso2_wsf_for_ajax_0.1.xpi
mkdir deploy
mkdir deploy/lib
mkdir deploy/modules
mkdir deploy/modules/addressing
mkdir deploy/logs

cp $AXIS2C_HOME/lib/*.dll deploy/lib -f
cp $LIBXML_DLL_PATH/*.dll deploy/lib -f
cp $AXIS2C_HOME/modules/addressing/*.dll deploy/modules/addressing -f
cp $AXIS2C_HOME/modules/addressing/module.xml deploy/modules/addressing -f
cp $AXIS2C_HOME/axis2.xml deploy -f
#zip -r tungsten.xpi components install.rdf skel deploy chrome/tungsten.jar chrome.manifest

zip win_wso2_wsf_for_ajax_0.1.xpi components/*.dll components/*.xpt install.rdf skel/*.dll  deploy/lib/*.dll deploy/modules/addressing/*.dll deploy/modules/addressing/module.xml  deploy/axis2.xml chrome/tungsten.jar chrome.manifest

rm deploy -rf
