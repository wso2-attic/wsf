if [ $# -ne 1 ]
then
    echo "Usage : $0 FlickerAPIKey"
    echo "Visit http://www.flickr.com/services/api/keys/ to aget a Flicker API key"
    exit
fi
if test -z $WSFC_HOME; then 
    WSFC_HOME=$PWD/../../..
fi
#echo "<x:FlickrRequest xmlns:x='urn:flickr'><method>flickr.test.echo</method><api_key>$1</api_key><name>wsclient</name></x:FlickrRequest>" | $WSFC_HOME/bin/wsclient --soap --no-mtom --no-wsa  http://api.flickr.com/services/soap/
echo "<x:FlickrRequest xmlns:x='urn:flickr'><method>flickr.test.echo</method><api_key>$1</api_key><name>wsclient</name></x:FlickrRequest>" | $WSFC_HOME/bin/wsclient --soap --no-mtom --no-wsa  http://localhost:9090/services/soap/
