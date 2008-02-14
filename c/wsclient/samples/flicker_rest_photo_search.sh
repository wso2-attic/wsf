if [ $# -ne 1 ]
then
    echo "Usage : $0 FlickerAPIKey"
    echo "Visit http://www.flickr.com/services/api/keys/ to aget a Flicker API key"
    exit
fi
if test -z $WSFC_HOME; then 
    WSFC_HOME=$PWD/../../..
fi
echo "<x:FlickrRequest xmlns:x='urn:flickr'><method>flickr.photos.search</method><api_key>$1</api_key><tags>peace</tags></x:FlickrRequest>" | $WSFC_HOME/bin/wsclient --get http://api.flickr.com/services/rest/?method=flickr.photos.search
