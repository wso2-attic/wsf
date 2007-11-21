#include <stdio.h>
#include <WSSOAPClient.h>
#include <OMElement.h>
#include <iostream>
#include <AxisFault.h>
using namespace std;
using namespace wso2wsf;

int main()
{
    WSSOAPClient * sc = new WSSOAPClient("http://localhost:9090/axis2/services/echo");
    sc->initializeClient("echo_blocking_soap11.log", AXIS2_LOG_LEVEL_TRACE);
    Options * op = sc->getOptions();
    op->setSoapVersion(AXIOM_SOAP11);
    sc->setOptions(op);
    {
        OMNamespace * ns = new OMNamespace("http://ws.apache.org/axis2/services/echo", "ns1");
        OMElement * payload = new OMElement(NULL,"echoString", ns);
        OMElement * child = new OMElement(payload,"text", NULL);
        child->setText("Hello World!");
        printf ((payload->toString()).c_str());
        cout << endl;
        OMElement * response;
        try
        {
            response = sc->request(payload, "http://ws.apache.org/axis2/c/samples/echo/soap_action");
            if (response)
            {
                cout << endl << "Response: " << response->toString() << endl;
            }
        }
        catch (AxisFault e)
        {
            cout << endl << "Response: " << (sc->getLastSOAPFault())->toString() << endl;
        }
        delete payload;
    }
    delete sc;
}

