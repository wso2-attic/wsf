#include <stdio.h>
#include <WSSOAPClient.h>
#include <OMElement.h>
#include <iostream>
#include <AxisFault.h>
using namespace std;
using namespace wso2wsf;

int main(int argc, char *argv[])
{
    string end_point, reply_to;
    WSSOAPClient * sc;

    end_point = "http://localhost:9090/axis2/services/echo";
    reply_to = "http://localhost:6060/axis2/services/__ANONYMOUS_SERVICE__/__OPERATION_OUT_IN__";

    if (argc > 1)
    {
        if (string (argv[1]).compare("-h") == 0)
        {
            cout << "Usage : " << argv[0] << " [end_point] [reply_to]" << endl;
            cout << "use -h for help" << endl;
            cout << "default end_point " << end_point << endl;
            cout << "default reply_to " << reply_to << endl;
            cout << "NOTE: command line arguments must appear in given order, with trailing ones being optional" << endl;
            return 0;
        }
        else
            end_point = argv[1];
    }
    if (argc > 2)
        reply_to = argv[2];

    sc = new WSSOAPClient(end_point);
    sc->initializeClient("echo_blocking_dual.log", AXIS2_LOG_LEVEL_TRACE);
    sc->engageModule(AXIS2_MODULE_ADDRESSING);
    Options * op = sc->getOptions();
    op->setUseSeparateListener(true);
    op->setReplyTo(reply_to);
    sc->setOptions(op);
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
