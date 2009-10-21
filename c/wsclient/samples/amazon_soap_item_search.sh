if [ $# -ne 0 ]
then
    echo "Usage : $0"
    echo "Visit http://aws.amazon.com to aget a Amazon key"
    exit
fi
if test -z $WSFC_HOME; then 
    WSFC_HOME=$PWD/../../..
fi

$WSFC_HOME/bin/wsclient --soap1.1 --no-mtom --action http://soap.amazon.com http://soap.amazon.com:80/onca/soap?Service=AWSECommerceService < $WSFC_HOME/samples/bin/wsclient/data/amazon_soap_item_search.xml

#$WSFC_HOME/bin/wsclient --soap1.1 --no-mtom --action http://soap.amazon.com http://localhost:9090/onca/soap?Service=AWSECommerceService < $WSFC_HOME/samples/bin/wsclient/data/item_search.xml
