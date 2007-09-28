/*
 * Copyright 2007 WSO2, Inc. http://www.wso2.org
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

function convert(xmlstring) {
    var req = new XML(xmlstring);

    // Create two instances of WSRequest
    var req1 = new WSRequest();
    var req2 = new WSRequest();

    // Asign eventlisteners for each instance of WSRequest
    req1.onreadystatechange = func1;
    req2.onreadystatechange = func2;

    var options = new Array();
    options["useSOAP"] = 1.1;
    options["HTTPMethod"] = "POST";
    options["useWSA"] = "1.0";
    options["action"] = "http://www.webserviceX.NET/GetCurrencyByCountry"

    // Default amount
    var amount = 1;
    // Default fromCountry
    var fromCountry = "United States";
    // Default toCountry
    var toCountry = "Sri Lanka";
    // Default fromCurrency
    var fromCurrency = "USD";
    // Default toCurrency
    var toCurrency = "LKR";

    fromCountry = req.fromCountry;
    toCountry = req.toCountry;
    amount = req.amount;

    try{
        // Open each request asynchronously
        req1.open(options, "http://www.webservicex.net/country.asmx", true);
        req2.open(options, "http://www.webservicex.net/country.asmx", true);

        // Payload for the first request
        var payload = "<GetCurrencyByCountry xmlns=\"http://www.webserviceX.NET\"><CountryName>" +
                      fromCountry +
                      "</CountryName></GetCurrencyByCountry>";

        print("\nSending Request to get Currency Code for " + fromCountry);
        req1.send(payload);

        // Payload for the second request
        payload = "<GetCurrencyByCountry xmlns=\"http://www.webserviceX.NET\"><CountryName>" +
                  toCountry +
                  "</CountryName></GetCurrencyByCountry>";

        print("Sending Request to get Currency Code for " + toCountry);
        req2.send(payload);
    } catch (ex){
        print(ex);
    }

    // Wait till both requests complete
    var complete = false;
    while (!complete) {
        java.lang.Thread.sleep(1);
    }

    //create new WSRequest object (convReq) for requesting the conversion rate
    var convReq = new WSRequest();
    //assign an eventlistener for convReq
    convReq.onreadystatechange = func3;

    options = new Array();
    options["useSOAP"] = 1.1;
    options["HTTPMethod"] = "POST";
    options["useWSA"] = "1.0";
    //SOAP action of the ConvesionRate Web Service
    options["action"] = "http://www.webserviceX.NET/ConversionRate"
    //create payload for ConversionRate Web Service
    payload =  "<ConversionRate xmlns=\"http://www.webserviceX.NET/\">" +
               "<FromCurrency>" + fromCurrency + "</FromCurrency>" +
               "<ToCurrency>" + toCurrency + "</ToCurrency>" +
               "</ConversionRate>";

    var convRate;
    try{
        //open convReq with synchronous option
        convReq.open(options, "http://www.webservicex.net/CurrencyConvertor.asmx", false);
        print("\nSending Request to get Conversion Rate from " + fromCurrency + " to " + toCurrency + "\n");
        convReq.send(payload);
    } catch(ex){
        print(ex);
    }


    function func1() {
        if (req1.readyState == 4) {
            var str = req1.responseText;
            //replace &lt; with < in the responseText
            str = str.replaceAll("&lt;", "<");
            //get the currency code out of the responseText
            str = str.split("<CurrencyCode>")[1];
            if(str != null){
                str = str.substring(0, 3);
            } else {
                print("\nError - Unsupported Country '" + fromCountry + "'");
                print("Setting Default Currency Code '" + fromCurrency + "'");
                str = fromCurrency;
            }
            fromCurrency = str;
            print("\nCurrency Code for " + fromCountry + " -> " + fromCurrency);
            if(req2.readyState == 4){
                complete = true;
            }
        }
    }

    function func2() {
        if (req2.readyState == 4) {
            var str = req2.responseText;
            //replace &lt; with < in the responseText
            str = str.replaceAll("&lt;", "<");
            //get the currency code out of the responseText
            str = str.split("<CurrencyCode>")[1];
            if(str != null){
                str = str.substring(0, 3);
            } else {
                print("\nError - Unsupported Country '" + toCountry + "'");
                print("Setting Default Currency Code '" + toCurrency + "'");
                str = toCurrency;
            }
            toCurrency = str;
            print("\nCurrency Code for " + toCountry + " -> " + toCurrency);
            if(req1.readyState == 4){
                complete = true;
            }
        }
    }
    var num;
    function func3(){
        if(convReq.readyState == 4){
            convRate = convReq.responseXML.getFirstChild().getFirstChild().getFirstChild().getTextContent();
            print("Rate -> " + convRate)
            var result = amount * convRate;
            num = result;

            print("Result -> " + result);
        }
    }

    return new XML("<conversionResp><amount>" +
           num +
           "</amount><currency>" +
           toCurrency +
           "</currency></conversionResp>");

}
