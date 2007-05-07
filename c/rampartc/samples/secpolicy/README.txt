The scenarios available here can be deployed using deploy.sh

Simply give the scenario name as an argument to the script
e.g. %sh deploy.sh scenario1 

Make sure you have run the deploy_client_repo.sh.

These scenarios will only copy the security policy xml files. To run the
client use the script samples/client/sec_echo/update_n_run.sh or
samples/client/sec_echo/update_n_run.bat

Following is a summary of scenarios available.

Scenario    Summary
-------------------
1.          Timestamp
2.          UsernameToken
3.          Client Encrypt(DirectReference)        
4.          Client Encrypt(IssuerSerial/RefKeyIdentifier/Embedded)           
5.          Client Sign(DirectReference)        
6.          Client Sign(IssuerSerial/RefKeyIdentifier/Embedded)           
7.          Timestamp, UsernameToken, Encrypt, Sign (Encrypt before sign/ Sign
before encrypt)
8.          A complete scenario, where both client and server encrypt/sign,
add Timestamps, Usernametokens.

FAQ:
---
* I am in a HURRY and I need to try a scenario
--------------------------------------------
If you are in a real hurry and need to try a scenario please use the
test_scen.sh
Usage : %sh test_scen.sh scenarioX server-port
e.g. %s test_scen.sh scenario3 8080

* I need to try all the scenarios
-------------------------------
In this case please use the script run_all.sh.
Usage: %sh run_all.sh server-port
e.g. %sh run_all.sh 8080

* I need to see the messages exchanged
--------------------------------------
For that you may use the TCP Monitor utility.
http://ws.apache.org/commons/tcpmon/
Make sure that you give the correct port that you configured in TCPMon
while running the scripts

* I cannot run samples and the log says "[rampart][rampart_Engine] Cannot get policy"
----------------------------------------------------------
Check your descriptor file where you engaged rampart(i.e. services.xml or
axis2.xml)
Make sure that you have correct values for 
    <parameter name="OutflowSecurityPolicy"></parameter>
    and
    <parameter name="InflowSecurityPolicy"></parameter>

* I cannot run samples and log says keys cannot be loaded
--------------------------------------------------------
Check you rpolicy files. Make sure that you have correct paths specified for
key/certificate files

