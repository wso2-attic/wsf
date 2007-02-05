/*
 * Copyright 2005,2006 WSO2, Inc. http://www.wso2.org
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

importClass(Packages.samples.StdInReader);

// Load WSRequest.js
load(["src/WSRequest.js"]);

// Create a new WSRequest object
var wsrequest = new WSRequest();

// Assign onreadystatechange event listener
wsrequest.onreadystatechange = onreadystatechange;

var options = new Array();
options["useSOAP"] = 1.1; // Set SOAP version to 1.1
options["HTTPMethod"] = "POST"; // Set POST as the HTTP transport method
options["useWSA"] = "submission"; // Use WS-Addressing submission version
options["action"] = "http://www.webserviceX.NET/ConversionRate";  // Set SOAP action

print("\n**Requests Conversion Rate for Two Given Currency Codes**\n");
java.lang.System.out.print("From Currency: ");
var fromCurrency = StdInReader.readLine();
java.lang.System.out.print("\nTo Currency: ");
var toCurrency = StdInReader.readLine();

var payload =  "<ConversionRate xmlns=\"http://www.webserviceX.NET/\">" +
"<FromCurrency>" + fromCurrency +"</FromCurrency>" +
"<ToCurrency>" + toCurrency + "</ToCurrency>" +
"</ConversionRate>";

print("\n**Payload**\n" + payload + "\n");

try {
    wsrequest.open(options, "http://localhost:8090/CurrencyConvertor.asmx", true);
    wsrequest.send(payload);
} catch(ex) {
    print(ex);
}

// Wait till data transfer completes
var complete = false
while(!complete) {
    java.lang.Thread.sleep(10);
}

// Event listener - onreadystatechange
function onreadystatechange() {
    if (wsrequest.readyState == 4) { // Data transfer has completed
        print("\n**Response Text**")
        print(wsrequest.responseText);
        print("\n**Content of 'ConversionRateResult' Element in Response XML**")
        print(wsrequest.responseXML.getFirstChild().getFirstChild().getTextContent());
        complete = true; // Set complete = true since data transfer has completed
    }
}