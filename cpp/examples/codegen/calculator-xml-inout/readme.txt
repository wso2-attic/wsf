This sample demonstrate how use the codegeneration tool to generate code without the data binding
support and use the xml-in-out model to implemented clients and services. 

Sample Name : Calculator
========================

This sample contains client\calculator_main.cpp file and service skeleton file CalculatorSkeleton.cpp. The WSDL corresponding
to the code is Calculator.wsdl

Code Generation Options
=======================

Client
------

WSDL2CPP.bat -uri Calculator.wsdl -d none -o client
WSDL2CPP.sh -uri Calculator.wsdl -d -sd none -o client

This command will generate client code to the directory client without the data binding support.

Service
-------

WSDL2CPP.bat -uri Calculator.wsdl -d none -ss -sd -o service
WSDL2CPP.sh -uri Calculator.wsdl -d none -ss -sd -o service

This command will generate service code to the directory service without the data binding support.

How to build and run
====================

Client
------
Copy the calculator_main.cpp file to the client directory ( Where generated client code is located )
Windows : - 
open the visual studio project and add this file to the project. 

Linux : - Run the build.sh which is generated when the -sd option is specified. Note that  you will have to set the Environment variable
WSFCPP_HOME for this to work. 

Eg $ export WSFCPP_HOME=`pwd`
   $ sh build.sh

Service
-------

Copy the CalculatorSkeleton.cpp file to the service directory ( Where generated service code is located ).

Windows : - 
open the visual studio project and add this file to the project. 
Now create a directory named Calculator and copy the complied dll Calculator.dll and the generated services.xml file to it.
Now copy this to the services folder in the WSF/CPP distribution.



Linux : - Run the build.sh which is generated when the -sd option is specified. Note that  you will have to set the Environment variable
WSFCPP_HOME for this to work. 

Eg $ export WSFCPP_HOME=`pwd`
   $ sh build.sh

This will build and package the Calculator service. Copy it to the services folder in the WSF/CPP distrbution. 

Running
=======

Now everything is ready to try out the sample. Start the axis2_http_server.exe and execute the client. :)
