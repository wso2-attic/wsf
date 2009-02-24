#include <stdio.h>
#include <WSSOAPClient.h>
#include <OMElement.h>
#include <iostream>
#include <AxisFault.h>
#include <WSFDefines.h>
using namespace std;
using namespace wso2wsf;

class EchoCallback: public ICallback
{
public:
    void WSF_CALL onComplete(OMElement* message);

    void WSF_CALL onFault(OMElement* message);

    WSF_CALL ~EchoCallback();
};

bool isComplete = false;
EchoCallback * callback = NULL;

EchoCallback::~EchoCallback()
{}

void EchoCallback::onComplete(OMElement* message)
{
    cout << endl << "Response: " << message->toString() << endl;
    isComplete = true;
}

void EchoCallback::onFault(OMElement* message)
{
    cout << endl << "Fault: " << message->toString() << endl;
    isComplete = true;
}

int main(int argc, char *argv[])
{
    string end_point;
    int timeout;
    WSSOAPClient * sc;

    end_point = "http://localhost:9090/axis2/services/echo";
    timeout = 10000;

    if (argc > 1)
    {
        if (string (argv[1]).compare("-h") == 0)
        {
            cout << "Usage : " << argv[0] << " [timeout] [end_point]" << endl;
            cout << "use -h for help" << endl;
            cout << "default timeout " << timeout << endl;
            cout << "default end_point " << end_point << endl;
            cout << "NOTE: command line arguments must appear in given order, with trailing ones being optional" << endl;
            return 0;
        }
        else
            timeout = atoi(argv[1]);
    }
    if (argc > 2)
        end_point = argv[2];

    sc = new WSSOAPClient(end_point);
    try 
    {   
        //sc->initializeClient("echo_non_blocking.log", AXIS2_LOG_LEVEL_TRACE);
    }   
    catch (AxisFault & e)
    {   
        cout << endl << "Error: " << e << endl;
        return 0;
    }
    {
        OMNamespace * ns = new OMNamespace("http://ws.apache.org/axis2/services/echo", "ns1");
        OMElement * payload = new OMElement(NULL,"echoString", ns);
        OMElement * child = new OMElement(payload,"text", NULL);
        child->setText("Hello World!");
        cout << endl << "Request: " << payload << endl;
        EchoCallback * callback = new EchoCallback();
        if (callback)
        {
            try
            {
                sc->request(payload, callback, "");
            }
            catch (AxisFault & e)
            {
                cout << "Error: " << e << endl;
            }
            int count = 0;
            while (count < timeout)
            {
                if (isComplete)
                {
                    break;
                }
               	WSF_USLEEP(100);
                count++;
            }
            cout << endl << endl << "Time: " << count << endl;
            if (count == timeout)
            {
                return 0;
            }
        }
        delete payload;
    }
    delete sc;
}
