#include <stdio.h>
#include <WSSOAPClient.h>
#include <OMElement.h>
#include <iostream>
#include <AxisFault.h>
using namespace std;
using namespace wso2wsf;

int main()
{
    WSSOAPClient * sc = new WSSOAPClient("../client_repo","http://localhost:9090/axis2/services/sec_echo");
    sc->initializeClient("echo_security.log", AXIS2_LOG_LEVEL_TRACE);
    sc->engageModule(AXIS2_MODULE_ADDRESSING);
    sc->setPolicy(new NeethiPolicy("../client_repo/policy.xml"));
    {
        OMNamespace * ns = new OMNamespace("http://ws.apache.org/rampart/c/samples", "ns1");
        OMElement * payload = new OMElement(NULL,"echoIn", ns);
        OMElement * child = new OMElement(payload,"text", NULL);
        child->setText("Hello");
        printf ((payload->toString()).c_str());
        cout << endl;
        OMElement * response;
        try
        {
            response = sc->request(payload, "http://example.com/ws/2004/09/policy/Test/EchoRequest");
            if (response)
            {
                cout << endl << "Response: " << sc->getLastResponseSoapEnvelopeString() << endl;
                //cout << endl << "Response: " << response->toString() << endl;
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

