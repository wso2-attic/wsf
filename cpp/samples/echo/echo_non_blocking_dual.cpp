#include <stdio.h>
#include <WSSOAPClient.h>
#include <OMElement.h>
#include <iostream>
#include <AxisFault.h>
using namespace std;
using namespace wso2wsf;

class EchoCallback: public ICallback
{
public:
    void onComplete(OMElement* message);

    void onFault(OMElement* message);

    ~EchoCallback();
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
    cout << endl << "Response: " << message->toString() << endl;
    isComplete = true;
}

int main()
{
    WSSOAPClient * sc = new WSSOAPClient("http://localhost:9090/axis2/services/echo");
    sc->initializeClient("echo_non_blocking_dual.log", AXIS2_LOG_LEVEL_TRACE);
    sc->engageModule(AXIS2_MODULE_ADDRESSING);
    Options * op = sc->getOptions();
    op->setUseSeparateListener(true);
    op->setReplyTo("http://localhost:6060/axis2/services/__ANONYMOUS_SERVICE__/__OPERATION_OUT_IN__");
    sc->setOptions(op);
    {
        OMNamespace * ns = new OMNamespace("http://ws.apache.org/axis2/services/echo", "ns1");
        OMElement * payload = new OMElement(NULL,"echoString", ns);
        OMElement * child = new OMElement(payload,"text", NULL);
        child->setText("Hello World!");
        printf ((payload->toString()).c_str());
        cout << endl;
        EchoCallback * callback = new EchoCallback();
        if (callback)
        {
            try
            {
                sc->request(payload, callback, "http://ws.apache.org/axis2/c/samples/echoString");
            }
            catch (AxisFault * e)
            {
                cout << e;
            }
            int count = 0;  
            while (count < 30)
            {
                if (isComplete)
                {
                    break;
                }
                AXIS2_USLEEP(100);
                count++;
            }
            cout << endl << endl << "Time: " << count << endl;
            if (count == 30)
            {
                return 0;
            }
        }
        delete payload;
    }
    delete sc;
}
