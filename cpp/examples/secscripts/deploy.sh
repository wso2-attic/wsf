#!/bin/bash
if [ $# -ne 1 ]
then
    echo "Usage : $0 scenarioX"
    exit
fi

INST_DIR=$WSFCPP_HOME
CLIENT_REPO="$INST_DIR/client_repo/"
SERVICE_HOME="$INST_DIR/services/sec_echo"

echo "Copying server's axis2.xml to " $WSFCPP_HOME
cp $WSFCPP_HOME/samples/src/c/rampartc/data/server_axis2.xml $WSFCPP_HOME/axis2.xml

#COPYING THE RELEVENT POLICY FILES TO CLIENT AND SERVER


echo "Replacing settings in policy files."
if [ `uname -s` = Darwin ]
then
    sed -e 's,AXIS2C_HOME/samples/src/rampartc,'$INST_DIR'/samples/src/c/rampartc,g' -e 's,\.so,\.dylib,g' $1/client-policy.xml > $CLIENT_REPO/policy1.xml
else
    sed 's,AXIS2C_HOME/samples/src/rampartc,'$INST_DIR'/samples/src/c/rampartc,g' $1/client-policy.xml > $CLIENT_REPO/policy1.xml
fi


if [ `uname -s` = Darwin ]
then
    sed -e 's,AXIS2C_HOME/samples/lib/rampartc,'$INST_DIR'/samples/lib,g' -e 's,\.so,\.dylib,g' $CLIENT_REPO/policy1.xml  > $CLIENT_REPO/policy.xml
else
    sed 's,AXIS2C_HOME/samples/lib/rampartc,'$INST_DIR'/samples/lib,g' $CLIENT_REPO/policy1.xml > $CLIENT_REPO/policy.xml
fi



echo "Replacing settings in Configuration files."
if [ `uname -s` = Darwin ]
then
    sed -e 's,AXIS2C_HOME/samples/lib/rampartc,'$INST_DIR'/samples/lib,g' -e 's,\.so,\.dylib,g' $1/services.xml > $SERVICE_HOME/services1.xml
else
    sed 's,AXIS2C_HOME/samples/lib/rampartc,'$INST_DIR'/samples/lib,g' $1/services.xml > $SERVICE_HOME/services1.xml
fi


if [ `uname -s` = Darwin ]
then
    sed -e 's,AXIS2C_HOME/samples/src/rampartc,'$INST_DIR'/samples/src/c/rampartc,g' -e 's,\.so,\.dylib,g' $SERVICE_HOME/services1.xml > $SERVICE_HOME/services.xml
else
    sed 's,AXIS2C_HOME/samples/src/rampartc,'$INST_DIR'/samples/src/c/rampartc,g' $SERVICE_HOME/services1.xml > $SERVICE_HOME/services.xml
fi



if [ -e $1/sts.xml ]
then
	if [ `uname -s` = Darwin ]
	then
		    sed -e 's,AXIS2C_HOME/samples/src/rampartc,'$INST_DIR'/samples/src/c/rampartc,g' -e 's,\.so,\.dylib,g' $1/sts.xml > $SERVICE_HOME/../secconv_echo/services.xml
	else
			sed 's,AXIS2C_HOME/samples/src/rampartc,'$INST_DIR'/samples/src/c/rampartc,g' $1/sts.xml > $SERVICE_HOME/../secconv_echo/services.xml
	fi
fi

if [ -e $1/rahas_module.xml ]
then
	if [ `uname -s` = Darwin ]
	then
		    sed -e 's,AXIS2C_HOME/samples/src/rampartc,'$INST_DIR'/samples/src/c/rampartc,g' -e 's,\.so,\.dylib,g' $1/rahas_module.xml > $SERVICE_HOME/../../modules/rahas/module.xml
	else
			sed 's,AXIS2C_HOME/samples/src/rampartc,'$INST_DIR'/samples/src/c/rampartc,g' $1/rahas_module.xml > $SERVICE_HOME/../../modules/rahas/module.xml
	fi
fi


