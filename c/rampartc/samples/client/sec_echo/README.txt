This sample works with sec_echo service.

1. HOW TO CONFIGURE SERVER?
-----------------------
Go to rampart/samples/server/sec_echo and 
Run  %make install
This will deploy a sec_echo service and copy security enabled services.xml
file.

2. HOW TO START SERVER
---------------------
Start server in port 8080 
     ./axis2_http_server -p8080

3. HOW TO CONFIGURE TCP MONITOR (To view messages)
------------------------------
    Listen port: 9090 [specified as in the client argument]
    Target port: 8080 [server port]

NOTE: This step is OPTIONAL and can be avoided by starting the server without -p8080
option.

HOW TO RUN CLIENT?
-----------------
Using scripts
-------------------------
1. Run %deploy_client_repo.sh/bat 
2. Run %update_n_run.sh/bat

Using the actual binary
--------------------------------------
Run %echo <address> <client_repository>


If everything is configured properly You should be able to see the security token(s) is/are  attached to the header of
    the SOAP message in the TCP Monitor.

NOTE:
You need to change the passwordCallbackClass/authnModule and the en/decryptionPropFile
in rampart/samples/client/enc_echo/data/client.axis2.xml and
rampart/samples/server/sec_echo/services.xml to suit your environment.

