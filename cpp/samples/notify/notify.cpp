#include <stdio.h>
#include <WSSOAPClient.h>
#include <OMElement.h>
#include <iostream>
#include <AxisFault.h>
using namespace std;
using namespace wso2wsf;

int main()
{
    WSSOAPClient * sc = new WSSOAPClient("http://localhost:9090/axis2/services/notify");
    try 
    {   
        sc->initializeClient("notify.log", AXIS2_LOG_LEVEL_TRACE);
    }   
    catch (AxisFault & e)
    {   
        cout << endl << "Error: " << e << endl;
        return 0;
    }
    sc->engageModule(AXIS2_MODULE_ADDRESSING);
    OMNamespace * ns = new OMNamespace("http://example.org/notify", "m");
    OMElement * payload = new OMElement(NULL,"notify", ns);
    payload->setText("notify5");
    cout << endl << "Request: " << payload << endl;
    bool status = false;
    try
    {
        status = sc->send(payload, "http://example.org/action/notify");
    }
    catch (AxisFault & e)
    {
        cout << endl << "Error: " << e << endl;
    }
    if (status)
    {
        cout << endl << "notify client invoke SUCCESSFUL!" << endl;
    }
    delete sc;
}
