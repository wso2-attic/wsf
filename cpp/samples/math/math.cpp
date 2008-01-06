#include <stdio.h>
#include <WSSOAPClient.h>
#include <OMElement.h>
#include <iostream>
#include <AxisFault.h>
using namespace std;
using namespace wso2wsf;

int main(int argc, char *argv[])
{
    string operation, param1, param2, end_point;
    WSSOAPClient * sc;

    operation = "add";
    param1 = "40";
    param2 = "8";
    end_point = "http://localhost:9090/axis2/services/math";

    if (argc > 1)
    {
        if (string (argv[1]).compare("-h") == 0)
        {
            cout << "Usage : " << argv[0] << " [operation] [param1] [param2] [end_point]" << endl;
            cout << "use -h for help" << endl;
            cout << "default operation " << operation << endl;
            cout << "default param1 " << param1 << endl;
            cout << "default param2 " << param2 << endl;
            cout << "default end_point " << end_point << endl;
            cout << "NOTE: command line arguments must appear in given order, with trailing ones being optional" << endl;
            return 0;
        }
        else
            operation = argv[1];
    }
    if (argc > 2)
        param1 = argv[2];
    if (argc > 3)
        param2 = argv[3];
    if (argc > 4)
        end_point = argv[4];
    
    sc = new WSSOAPClient(end_point);
    sc->initializeClient("math_blocking.log", AXIS2_LOG_LEVEL_TRACE);
    sc->engageModule(AXIS2_MODULE_ADDRESSING);
    {
        OMNamespace * ns = new OMNamespace("http://ws.apache.org/axis2/services/math", "ns1");
        OMElement * payload = new OMElement(NULL,operation, ns);
        OMElement * child1 = new OMElement(payload,"param1", NULL);
        child1->setText(param1);
        OMElement * child2 = new OMElement(payload,"param2", NULL);
        child2->setText(param2);
        cout << endl << "Request: " << payload << endl;
        OMElement * response;
        try
        {
            response = sc->request(payload, "http://ws.apache.org/axis2/c/samples/echoString");
            if (response)
            {
                cout << endl << "Response: " << response << endl;
            }
        }
        catch (AxisFault & e)
        {
            if (sc->getLastSOAPFault())
            {
                cout << endl << "Response: " << sc->getLastSOAPFault() << endl;
            }
            else
            {
                cout << endl << "Response: " << e << endl;
            }
        }
        delete payload;
    }
    delete sc;
}

