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

function WSRequest()
{
    // data members
    // readyState
    this.readyState = 0;
    // responseText
    this.responseText = null;
    // responseXML
    this.responseXML = null;
    // onreadystatechange event handler
    this.onreadystatechange = null;

    // async | sync communication
    var asyn = true;
    // a java script assosiative array to hold options
    var optionSet = null;
    var uri = null;
    var username = null;
    var password = null;
    var setAction = false;

    //function decleration
    this._seralizerToString = _seralizerToString;
    this._seralizeOption = _seralizeOption;
    this._getBrowser = _getBrowser;
    this._buildSoapHeader = _buildSoapHeader;
    this._buildSoap = _buildSoap;
    this._getSoapBody = _getSoapBody;

    var xmlhttp = false;
    try {
        // IE
        var aVersions = [ "MSXML2.XMLHttp.5.0",
                "MSXML2.XMLHttp.4.0","MSXML2.XMLHttp.3.0",
                "MSXML2.XMLHttp","Microsoft.XMLHttp"
                ];
        for (var i = 0; i < aVersions.length; i++) {
            try {
                xmlhttp = new ActiveXObject(aVersions[i]);

            } catch (e) {
                //Do nothing
            }
        }
    } catch (e) {
        // Do nothing

    }
    if (!xmlhttp && typeof XMLHttpRequest!='undefined')
    {
        try {
            // firefox,opera and safari
            xmlhttp = new XMLHttpRequest();
        } catch (e) {
            throw new Error("XMLHttp object could not be created.");
        }
    }

    function CallBack(ws) {
        this.callerFun = function caller() {
            if (xmlhttp.readyState == 2)
            {
                ws.readyState = 2;
                ws.onreadystatechange();
            }
            if (xmlhttp.readyState == 3)
            {
                ws.readyState = 3;
                ws.onreadystatechange();
            }
            if (xmlhttp.readyState == 4)
            {
                ws.readyState = 4;
                var tempBroswer = _getBrowser();
                var result = _getSoapBody(xmlhttp.responseText);
                if(tempBroswer == "Firefox" || tempBroswer == "Mozilla" || tempBroswer == "Netscape" )
                {
                    netscape.security.PrivilegeManager.enablePrivilege("UniversalBrowserRead");
                    if(result != -1)
                    {
                        ws.responseText = result;
                        var parser=new DOMParser();
                        ws.responseXML = parser.parseFromString(result,"text/xml");
                    }
                    else
                    {
                        ws.responseText = null;
                        ws.responseXML = null;
                    }
                }
                if(tempBroswer == "Internet Explorer"){
                    if(result != -1)
                    {
                        ws.responseText = result;
                        var doc = new ActiveXObject("Microsoft.XMLDOM");
                        doc.async="false";
                        doc.loadXML(result);
                        ws.responseXML = doc;
                    }
                    else
                    {
                        ws.responseText = null;
                        ws.responseXML = null;
                    }
                }
                ws.onreadystatechange();
            }
        }
    }
    //the open method
    this.open = function(option, URL, asnycFlag,userName,passWord)
    {
        if(arguments.length < 2 || arguments.length > 6)
        {
            throw new Error("Invalid input argument");
        }
        optionSet = option;
        uri = URL;
        asyn = asnycFlag;
        if(userName != null && passWord == null)
            throw new Error("User name should have a password");
        else
        {
            username = userName;
            password = passWord;
        }
        this.readyState = 1;
        this.onreadystatechange();
        this.responseText = null;
        this.responseXML = null;
    }
    // the send method
    this.send = function(payLoad)
    {
        if(arguments.length > 1)
        {
            return new Error("Invalid input argument");
        }
        var soapAction = null; // action header
        var soapVer = null;    // soap version
        var header = null;     // soap headers
        var req = null;        // string to be sent
        var method = null;     // GET | POSt
        var temp = _seralizeOption(optionSet);
        switch(typeof(temp))
                {
            case "string":
                method = temp;
                break;
            case "object":
                method = temp["HTTPMethod"];
                break;
            default:
                throw new Error("Invalid input argument");
                break;
        }
        if(payLoad != null)
        {
            var options = _seralizeOption(optionSet);
            soapVer =  options['useSOAP'];
            soapAction = options['Action'];
            var content = _seralizerToString(payLoad); // seralize the dom to string

            if(content == false){
                throw new Error("Invalid input argument");
            }
            header = _buildSoapHeader(options);
            req = _buildSoap(soapVer,header,content,soapAction);
        }
        if (asyn)
        {
            //asynchronous call
            var cb = new CallBack(this);
            xmlhttp.open(method, uri, true);
            if(soapVer == 1.1)
            {
                xmlhttp.setRequestHeader("SOAPAction",soapAction);
                xmlhttp.setRequestHeader("Content-Type","text/xml; charset=UTF-8");
            }
            else
            {
                xmlhttp.setRequestHeader("Content-Type","application/soap+xml;charset=UTF-8;action="+ soapAction);
            }
            xmlhttp.onreadystatechange = cb.callerFun;
            xmlhttp.send(req);
        }
        else
        {
            // sync call
            xmlhttp.open(method, uri, false);
            if(soapVer == 1.1)
            {
                xmlhttp.setRequestHeader("SOAPAction",soapAction);
                xmlhttp.setRequestHeader("Content-Type","text/xml; charset=UTF-8");
            }
            else
            {
                xmlhttp.setRequestHeader("Content-Type","application/soap+xml;charset=UTF-8;action="+ soapAction);
            }
            this.readyState = 2;
            this.onreadystatechange();
            xmlhttp.send(req);

            var tempBroswer = _getBrowser();
            var result =  _getSoapBody(xmlhttp.responseText);
            if(tempBroswer == "Firefox" || tempBroswer == "Mozilla" || tempBroswer == "Netscape")
            {
                netscape.security.PrivilegeManager.enablePrivilege("UniversalBrowserRead");
                if(result != -1)
                {
                    this.responseText = result;
                    var parser=new DOMParser();
                    this.responseXML = parser.parseFromString(result,"text/xml");
                }
                else
                {
                    this.responseText = null;
                    this.responseXML = null;
                }
            }
            if(tempBroswer == "Internet Explorer")
            {
                if(result != -1)
                {
                    this.responseText = result;
                    var doc = new ActiveXObject("Microsoft.XMLDOM");
                    doc.async="false";
                    doc.loadXML(result);
                    this.responseXML = doc;
                }
                else
                {
                    this.responseText = null;
                    this.responseXML = null;
                }
             }
            this.readyState = 4;
            this.onreadystatechange();

        }
    }
    function _getSoapBody(str)
    {
        var str1 = str.substring(str.toLowerCase().indexOf(":body>") + 6);
        var index = str1.toLowerCase().indexOf(":body>");
        if(str1 != -1 && index != -1){
            var foundSla = false;
            var foundGre = false;
            var temp1;
            var temp2;
            while(true){
                var prevousChar = str1.toLowerCase().charAt(index);
                if(prevousChar == "/"){
                    foundSla = true;
                    temp1 = index;
                }
                if(prevousChar == "<"){

                    foundGre = true;
                    temp2 = index;
                }
                if(temp2 == temp1 - 1){
                    break;
                }
                index--;
            }
            return str1.substring(0,index);
        }
        else{
            return -1;
        }

    }
    // options array will be seralized to options
    function _seralizeOption(option)
    {
        var optType = typeof(option);
        if(optType == "string"){
            // user submit the POST or GET method
            if(option == "POST" ||option == "post" || option == "GET" || option == "get")
                return option;
            //the default method
            if(option != "POST" ||option != "post" || option != "GET" || option != "get"){
                var post = "POST";
                return post;
            }
            else
                throw new Error("Invalid input argument");
        }
        else if(optType == "object")
        {
            // defined varlbes only among soapVer,method
            var opt = new Array();
            if(option['useSOAP'] != null)
                opt['useSOAP'] = option['useSOAP'];
            if(option['HTTPMethod'] != null)
                opt['HTTPMethod'] = option['HTTPMethod'];
            // the default method is POST
            if(option['HTTPMethod'] == null)
                opt['HTTPMethod'] = "POST";
            if(option['From'] != null)
                opt['From'] = option['From'];
            if(option['ReplyTo'] != null)
                opt['ReplyTo'] = option['ReplyTo'];
            if(option['FaultTo'] != null)
                opt['FaultTo'] = option['FaultTo'];
            if(option['Action'] != null)
                opt['Action'] = option['Action'];
            return opt;
        }
        else
            throw new Error("Invalid input argument");
    }
    // seralize the
    function _seralizerToString(payLoad)
    {
        if(typeof(payLoad) == "string")
            return payLoad;
        else if(typeof(payLoad) == "object")
        {
            var browser = _getBrowser();
            switch(browser)
                    {
                case "Firefox":
                    var serializer = new XMLSerializer();
                    return serializer.serializeToString(payLoad);
                    break;
                case "Mozilla":
                    var serializer = new XMLSerializer();
                    return serializer.serializeToString(payLoad);
                    break;
                case "Netscape":
                    var serializer = new XMLSerializer();
                    return serializer.serializeToString(payLoad);
                    break;
                case "Internet Explorer":
                    return payLoad.xml;
                    break;

                case "Opera":
                    var xmlSerializer = document.implementation.createLSSerializer();
                    return xmlSerializer.writeToString(payLoad);
                    break;
                case "Safari":
                // use the safari method
                    throw new Error("Not implemented");
                case "undefined":
                    throw new Error("XMLHttp object could not be created");
            }
        }
        else if(typeof(payLoad) != "string" || typeof(payLoad) != "object" )
            return false;
    }
    function _getBrowser()
    {
        //need to do this ?
        var agt = navigator.userAgent.toLowerCase();
        if (agt.indexOf("opera") != -1) return 'Opera';
        if (agt.indexOf("firefox") != -1) return 'Firefox';
        if (agt.indexOf("safari") != -1) return 'Safari';
        if (agt.indexOf("msie") != -1) return 'Internet Explorer';
        if (agt.indexOf("netscape") != -1) return 'Netscape';
        if (agt.indexOf("mozilla/5.0") != -1) return 'Mozilla';
        if (agt.indexOf('\/') != -1)
        {
            if (agt.substr(0,agt.indexOf('\/')) != 'mozilla')
                return navigator.userAgent.substr(0,agt.indexOf('\/'));
            else return 'Netscape';
        }
        else
            return undefined;

    }
    function _buildSoapHeader(options,to)
    {
        var header = "";
        // WSA ,headers
        if(to != null)
            header =  "<wsa:To>"+to+"</wsa:To>";

        if(options['From'] != null)
            header += "<wsa:From><wsa:Address>"+options['From']+"</wsa:Address></wsa:From>";
        if(options['ReplyTo'] != null)
            header += "<wsa:ReplyTo><wsa:Address>"+options['ReplyTo'] +"</wsa:Address></wsa:ReplyTo>";
        if(options['FaultTo'] != null)
            header += "<wsa:FaultTo><wsa:Address>"+options['FaultTo']+"</wsa:Address></wsa:FaultTo>";
        if(options['Action'] != null)
            header += "<wsa:Action>"+options['Action']+" </wsa:Action>"
        if(options['From'] == null && options['ReplyTo'] != null && options['FaultTo'] != null
                && options['Action'] != null )
            return null;
        else
            return header;
    }
    function _buildSoap(soapVer,header,content,soapAction)
    {
        var request = null;
        var ns = null;
        var adnNs = null;
        if(soapVer == 1.1)
        {
            ns =  "http://schemas.xmlsoap.org/soap/envelope/";
            // the name space for addressing
            addNs = "http://www.w3.org/2005/08/addressing";
        }
        else
        {
            // the defailt soapversion 1.2
            ns = "http://www.w3.org/2003/05/soap-envelope";
            // the addressing name space for soap 1.2
            adnNs = "http://www.w3.org/2005/08/addressing";
        }
        // addressing
        if(header != null)
        {
            return request =  "<?xml version='1.0' encoding='UTF-8'?>"+"\n\n"+
                              "<SOAP-ENV:Envelope"+
                              ' xmlns:SOAP-ENV= \"'+ns+'\"'+
                              ' xmlns:wsa=\"'+adnNs+'\"'+
                              ' xmlns:xsi=\"http://www.w3.org/1999/XMLSchema-instance\"'+
                              ' xmlns:xsd=\"http://www.w3.org/1999/XMLSchema\">'+
                              '<SOAP-ENV:Header>'+header+'</SOAP-ENV:Header>' +
                              '<SOAP-ENV:Body>'+content+'</SOAP-ENV:Body>' +
                              '</SOAP-ENV:Envelope>'
        }
        //  no addressing
        else
        {
            return request =  "<?xml version='1.0' encoding='UTF-8'?>"+"\n"+
                              "<SOAP-ENV:Envelope"+
                              ' xmlns:SOAP-ENV=\"'+ns+'\"'+
                              ' xmlns:xsi=\"http://www.w3.org/1999/XMLSchema-instance\"'+
                              ' xmlns:xsd=\"http://www.w3.org/1999/XMLSchema\">'+
                              '<SOAP-ENV:Body>'+content+'</SOAP-ENV:Body>' +
                              '</SOAP-ENV:Envelope>'
        }
    }

}