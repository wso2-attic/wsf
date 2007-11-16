#include <stdio.h>
#include <WSSOAPClient.h>
#include <OMElement.h>
#include <iostream>
#include <AxisFault.h>
using namespace std;
using namespace wso2wsf;

int main()
{
    WSSOAPClient * sc = new WSSOAPClient("http://api.google.com/search/beta2");
    sc->initializeClient("google_client.log", AXIS2_LOG_LEVEL_TRACE);
    sc->engageModule(AXIS2_MODULE_ADDRESSING);
    Options * op = sc->getOptions();
    op->setSoapVersion(AXIOM_SOAP11);
    sc->setOptions(op);
    {
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
        printf ((payload->toString()).c_str());
        cout << endl;
        OMElement * response;
        try
        {
            response = sc->request(payload, "");
            if (response)
            {
                cout << endl << "Response: " << response->toString() << endl;
            }
        }
        catch (AxisFault e)
        {
            cout << endl << "Fault: " << (sc->getLastSOAPFault())->toString() << endl;
        }
        delete payload;
    }
    delete sc;
}

