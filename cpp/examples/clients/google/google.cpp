/*
* Copyright 2005-2009 WSO2, Inc. http://wso2.com
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


#include <stdio.h>
#include <WSSOAPClient.h>
#include <OMElement.h>
#include <iostream>
#include <AxisFault.h>
using namespace std;
using namespace wso2wsf;

int main()
{

	Process::initialize("google.log", AXIS2_LOG_LEVEL_TRACE);

    WSSOAPClient sc("http://api.google.com/search/beta2");
    sc.engageModule(AXIS2_MODULE_ADDRESSING);
    
    Options * op = sc.getOptions();
    op->setSoapVersion(AXIOM_SOAP11);

    OMNamespace * ns0 = new OMNamespace(AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI, "soapenv");
    OMNamespace * ns1 = new OMNamespace("urn:GoogleSearch", "ns1");
    OMNamespace * ns2 = new OMNamespace("http://www.w3.org/1999/XMLSchema-instance", "xsi");
    OMNamespace * ns3 = new OMNamespace("http://www.w3.org/1999/XMLSchema", "xsd");
    OMAttribute * at1 = new OMAttribute("encodingStyle", "http://schemas.xmlsoap.org/soap/encoding/", ns0);
    OMElement * payload = new OMElement(NULL,"doSpellingSuggestion", ns1);
    payload->addAttribute(at1);
    payload->setNamespace(ns2, false);
    payload->setNamespace(ns3, false);
    OMElement * child1 = new OMElement(payload,"key", NULL);
    OMAttribute * at2 = new OMAttribute("type", "xsd:string", ns2);
    child1->addAttribute(at2);
    child1->setText("00000000000000000000000000000000");
    OMElement * child2 = new OMElement(payload,"phrase", NULL);
    OMAttribute * at3 = new OMAttribute("type", "xsd:string", ns2);
    child2->addAttribute(at2);
    child2->setText("salvasion");
    cout << endl << "Request: " << payload << endl;

    try
    {
        OMElement * response = sc.request(payload, "");
        if (response)
        {
            cout << endl << "Response: " << response << endl;
        }
    }
    catch (AxisFault & e)
    {
        if (sc.getLastSOAPFault())
        {
            cout << endl << "Fault: " << sc.getLastSOAPFault() << endl;
        }
        else
        {
            cout << endl << "Error: " << e << endl;
        }
    }
    delete payload;
}

