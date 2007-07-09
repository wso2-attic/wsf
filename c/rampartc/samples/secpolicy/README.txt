The scenarios available here can be deployed using deploy.sh

Simply give the scenario name as an argument to the script
e.g. %sh deploy.sh scenario1 
(Win32 users please use the win_deploy.bat)

Make sure you have run the deploy_client_repo.sh.
These scenarios will only copy the security policy xml files. To run the
client use the script samples/client/sec_echo/update_n_run.sh or
samples/client/sec_echo/update_n_run.bat

Following is a summary of scenarios available.

Scenario    Summary
-------------------
1.          Timestamp
2.          UsernameToken
3.          Encryption        
4.          Signature           
5.          A complete scenario to show :Timestamp, UsernameToken, Encrypt, Sign 

FAQ:
---
* I am NOT in LINUX. Are there any changes to be done in samples.
----------------------------------------------------------------
YES. You have to change file names accordingly. For example your password
callback module might have "*.so" as the extension. This might be different in
WIN32 and Mac OS.

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

* I cannot run samples and log says keys cannot be loaded
--------------------------------------------------------
Check you rpolicy files. Make sure that you have correct paths specified for
key/certificate files

