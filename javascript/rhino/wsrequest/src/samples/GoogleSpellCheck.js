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
load(["src/WSRequest.js"])

// Create a new WSRequest object
var wsrequest = new WSRequest();

// Assign onreadystatechange event listener
wsrequest.onreadystatechange = onreadystatechange;


var options = new Array();
options["useSOAP"] = 1.1; // Set SOAP version to 1.1
options["HTTPMethod"] = "POST"; // Set POST as the HTTP transport method
options["useWSA"] = "1.0"; // Use WS-Addressing 1.0
options["action"] = "urn:GoogleSearch"; // Set SOAP action

print("\n**Requests Spell Check for a Given Word**\n");
java.lang.System.out.print("Word: ");
var phrase = StdInReader.readLine();

var payload =  "<ns1:doSpellingSuggestion xmlns:ns1=\"urn:GoogleSearch\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\">" +
"<KEY a0:type=\"xsd:string\" xmlns:a0=\"http://www.w3.org/2001/XMLSchema-instance\">9mcQj79QFHK40EAwAnlpuOyY/K7B8XSJ</KEY>" +
"<PHRASE a1:type=\"xsd:string\" xmlns:a1=\"http://www.w3.org/2001/XMLSchema-instance\">" + phrase + "</PHRASE>" +
"</ns1:doSpellingSuggestion>"

print("\n**Payload**\n" + payload + "\n");
try{
    wsrequest.open(options, "http://api.google.com/search/beta2", true); // Asynchronous request
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
function onreadystatechange(){
    if(this.readyState == 4){  // Data transfer has completed
        print("WSRequest is in state 4");
        print("\n**Response Text**\n" + wsrequest.responseText);
        print("\n**Text Content of 'return' Element in ResponseXML**" +
              wsrequest.responseXML.getFirstChild().getTextContent());
        complete = true; // Set complete = true since data transfer has completed
    } else if(this.readyState == 2){ // WSRequest has successfully acknowledged the request
        print("WSRequest is in state 2");
    } else if(this.readyState == 1) { // The call to Open() has successfully completed
        print("WSRequest is in state 1");
    }
}