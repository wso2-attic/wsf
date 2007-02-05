Rino version of WSRequest
--------------------------

WSRequest.js (src/WSRequest.js) is a JavaScript implementation of the WSRequest API (http://www.wso2.org/wiki/display/wsfajax/wsrequest_specification) using Axis2's client API. 

Samples
-------
GoogleSpellCheck.js - This will invoke Google's spell check service to get suggestions for a given word. The Google's service, however, may come across 
                      limitations with some words thus WSRequest would throw an error.

ConversionRate.js - This will invoke http://www.webservicex.net/CurrencyConvertor.asmx Web service to get conversion rate for two given currency codes. 

CurrencyConverter.js - This will invoke http://www.webservicex.net/country.asmx twice to get currency codes for the given countries. It will then 
		       invoke http://www.webservicex.net/CurrencyConvertor.asmx Web service to get the conversion rate for those countries. The latter
		       service, however, may not work with some of the currency codes provided by the first service. Thus an error would occur on such 
		       incidents.

Converter.js - This is the same as CurrencyConverter.js except that this provides a user interface to the client. The issue associated with the 
	       CurrencyConverter.js is there with this as well.

Running the Samples
--------------------

Samples using WSRequest.js can be found under src/samples/. To run samples use the following command.

on Linux environment:
	java -classpath <classpath> org.mozilla.javascript.tools.shell.Main -f src/samples/<samplename>.js

on Windows environment:
	java -classpath <classpath> org.mozilla.javascript.tools.shell.Main -f src\samples\<samplename>.js

A Note on Classpath
--------------------

The following should be included in the classpath.
 
 1. Rhino's (http://www.mozilla.org/rhino) js.jar
 2. Jar files in <Axis2_Home>/lib (Axis2 is available at http://ws.apache.org/axis2/)
 3. Addressing module (this can be found under <Axis2_Home>/repository/modules)
 4. Path to src folder (Make sure to compile StdInReader.java and place the StdInReader.class inside src/samples)




