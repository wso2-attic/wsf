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
function convert(fromCountry, toCountry, amount) {
    var result;
    var payload = "<conversionReq>" +
    "<fromCountry>" + fromCountry + "</fromCountry>" +
    "<toCountry>" + toCountry + "</toCountry>" +
    "<amount>" + amount + "</amount>" +
    "</conversionReq>";

    var wsrequest;
    try {
        wsrequest = new ActiveXObject("WSRequest");
    } catch(e) {
        alert("WSRequest is not defined");
    }

    wsrequest.onreadystatechange = listener;
    var options = new Array();
    options["useSOAP"] = 1.1;
    wsrequest.open(options, "http://127.0.0.1:8080/axis2/services/ConverterService/convert", false);
    try {
        wsrequest.send(payload);
    } catch(e) {
        alert(e.description);
    }

    return result;

    function listener() {
        if (wsrequest.readyState == 4) {
            result = wsrequest.responseXML;
        }
    }
}
