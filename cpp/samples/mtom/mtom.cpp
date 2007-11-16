#include <stdio.h>
#include <WSSOAPClient.h>
#include <OMElement.h>
#include <OMText.h>
#include <OMDataHandler.h>
#include <iostream>
#include <AxisFault.h>
using namespace std;
using namespace wso2wsf;

int main()
{
    WSSOAPClient * sc = new WSSOAPClient("http://localhost:9090/axis2/services/mtom");
    sc->initializeClient("mtom.log", AXIS2_LOG_LEVEL_TRACE);
    sc->engageModule(AXIS2_MODULE_ADDRESSING);
    Options * op = sc->getOptions();
    op->setSoapVersion(AXIOM_SOAP11);
    op->setEnableMTOM(true);
    sc->setOptions(op);
    {
        OMNamespace * ns1 = new OMNamespace("http://ws.apache.org/axis2/c/samples/mtom", "ns1");
        OMElement * payload = new OMElement(NULL,"mtomSample", ns1);
        OMElement * child1 = new OMElement(payload,"fileName", ns1);
        child1->setText("test.jpg");
        OMElement * child2 = new OMElement(payload,"image", ns1);
        OMDataHandler * data_handler = new OMDataHandler("resources/axis2.jpg", "image/jpeg");
        OMText * child3 = new OMText(child2, data_handler);
        child3->optimize(true);
        printf ((payload->toString()).c_str());
        cout << endl;
        OMElement * response;
        try
        {
            response = sc->request(payload, "http://ws.apache.org/axis2/c/samples/mtomSample");
            if (response)
            {
                cout << endl << "Response: " << response->toString() << endl;
            }
        }
        catch (AxisFault e)
        {
            cout << endl << "Fault: " << e << endl;
        }
        delete payload;
    }
    delete sc;
}

