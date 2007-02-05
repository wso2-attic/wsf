JavaScript Message Receiver
---------------------------

This message receiver allows JavaScript services to be deployed in Axis2. It has built-in support for Rhino's load and print functions.

The service should return an E4X XML object in order to use this message receiver.

Building the Message Receiver
-----------------------------

Use the command maven to build the message receiver using the given build file. This will generate a jar file containing the classes of the message receiver.

Note: You can skip the build process by using the javascript-SNAPSHOT.jar inside samples/ConverterService/lib.

Usage
-----

Drop the jar file containing the message receiver to WEB-INF/lib or inside lib folder of the service archive. You'll also need to drop js-axiom-SNAPSHOT.jar
and js-core-SNAPSHOT.jar to either of the aforementioned places.

Write the service as a JavaScript function and archive it as an Axis2 service archive (creating the appropriate folder structure is sufficient).

Note: Temporarily you can get js-axiom-SNAPSHOT.jar and js-core-SNAPSHOT.jar from http://www-lk.wso2.com/~thilina/repository/org.mozilla.javascript/jars/. 

Samples
-------
A currency converter sample is provided to demonstrate the use of the message receiver with the WSRequest.js.

The complete folder structure for the required service including necessary jar files is present under samples/ConverterService.
Copy the ConverterService folder into WEB-INF/services of Axis2 and start the server.

1. converterIE.html

	Note: You need to install WSRequest ActiveX for IE in order to use the sample.

  	Use IE to open samples/converterIE.html. Fill/Change the three fields and click submit. You'll need to wait a little to get the response.

2. converterNative.html
	
	This sample uses the native Javascript implementation of WSRequest to invoke the service. Open samples/converterNative.html using a Web browser
	and fill/change the three fields and click submit. You'll need to wait a little to get the response.

	Note: This sample is tested only with Microsoft IE and Firefox Web browsers.


Example values for the country fields.
	Japan, United States, Sri Lanka, India, United Kingdom, Australia
