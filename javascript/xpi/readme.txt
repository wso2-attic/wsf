Folder Structure for the XPI extension
======================================
base/soap/public - IDL for main components - nsIWSRequest
base/soap/src - Implementation for WSRequest
base/util/src - Implementation for utilitiy functions -Exception Mechanism
build/skel/src - Code for registering the component
build/stub/src - Load external libraries and load the component
tests - Test files for the extension - .html pages
xpi -Genreated .xpi file and required files to pack 


Compilation info
================
-linux
1.Build the firefox from source(pls refer:http://developer.mozilla.org/en/docs/Build_and_Install) 
2.Install Axis2c(pls refer: http://ws.apache.org/axis2/c/docs/installationguide.html ) 
3.Place the xpi folder inside ./mozilla/extensions/ in the mozilla code base.
4.Run "sh pack.sh" to compile the source and pack the extension.

-windows
1.Build the firefox from source(pls refer:http://developer.mozilla.org/en/docs/Windows_Build_Prerequisites)
2.Install Axis2c(pls refer: http://ws.apache.org/axis2/c/docs/installationguide.html)
2.Place the xpi folder inside ./mozilla/extensions/ in the mozilla code base.
3.Run "sh winpack.sh" to compile the source and pack the extension
