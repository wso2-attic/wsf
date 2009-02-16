#include <stdio.h>
#include <WSSOAPClient.h>
#include <OMElement.h>
#include <iostream>
#include <AxisFault.h>
using namespace std;
using namespace wso2wsf;

int main(int argc, char *argv[])
{
    string end_point;
    int iterations;
    WSSOAPClient * sc;

    end_point = "http://localhost:9090/axis2/services/echo";
    iterations = 2;

    if (argc > 1)
    {   
        if (string (argv[1]).compare("-h") == 0)
        {   
            cout << "Usage : " << argv[0] << " [end_point]" << endl;
            cout << "use -h for help" << endl;
            cout << "default end_point " << end_point << endl;
            return 0;
        }   
        else
            end_point = argv[1];
    }   

    sc = new WSSOAPClient(end_point);
    cout << endl << "Using end_point: " << end_point << endl;
    try
    {
        sc->initializeClient("echo.log", AXIS2_LOG_LEVEL_TRACE);
    }
    catch (AxisFault & e)
    {
        cout << endl << "Error: " << e << endl;
        return 0;
    }
    sc->engageModule(AXIS2_MODULE_ADDRESSING);
    for (int i = 0; i < iterations; i++)
    {
        OMNamespace * ns = new OMNamespace("http://ws.apache.org/axis2/services/echo", "ns1");
        OMElement * payload = new OMElement(NULL,"echoString", ns);
        OMElement * child = new OMElement(payload,"text", NULL);
        child->setText("Hello World!");
        cout << endl << "Request: " << payload << endl;
        OMElement * response;
        try
        {
            response = sc->request(payload, "http://ws.apache.org/axis2/c/samples/echoString");
            if (response)
            {
                cout << endl << "Response: " << response->getFirstElement() << endl;
            }
        }
        catch (AxisFault & e)
        {
            if (sc->getLastSOAPFault())
            {
                cout << endl << "Fault: " << sc->getLastSOAPFault() << endl;
            }
            else
            {
                cout << endl << "Error: " << e << endl;
            }
        }
        delete payload;
    }
    delete sc;
}

