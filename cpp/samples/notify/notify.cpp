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
    sc->initializeClient("notify.log", AXIS2_LOG_LEVEL_TRACE);
    sc->engageModule(AXIS2_MODULE_ADDRESSING);
    OMNamespace * ns = new OMNamespace("http://example.org/notify", "m");
    OMElement * payload = new OMElement(NULL,"notify", ns);
    payload->setText("notify5");
    cout << payload->toString();
    bool status = false;
    try
    {
        status = sc->send(payload, "http://example.org/action/notify");
    }
    catch (AxisFault * e)
    {
        cout << e;
    }
    if (status)
    {
        printf("\nnotify client invoke SUCCESSFUL!\n");
    }
    delete sc;
}
