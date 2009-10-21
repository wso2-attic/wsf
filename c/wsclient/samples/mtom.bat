@echo off

"%WSFC_HOME%\bin\wsclient" --soap --xop-in "%WSFC_HOME%\samples\bin\resources\axis2.jpg" http://localhost:9090/axis2/services/mtom < "%WSFC_HOME%\samples\bin\wsclient\data\mtom_test.xml"
