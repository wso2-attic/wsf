@echo off
IF "%1" == "" (
    echo "Usage : %0 FlickerAPIKey"
    echo "Visit http://www.flickr.com/services/api/keys/ to aget a Flicker API key"
    goto end
)

echo ^<x:FlickrRequest xmlns:x='urn:flickr'^>^<method^>flickr.test.echo^</method^>^<api_key^>%1^</api_key^>^<name^>wsclient^</name^>^</x:FlickrRequest^>  > flicker_test.xml
"%WSFC_HOME%\bin\wsclient" --get  http://api.flickr.com/services/rest/ < flicker_test.xml

:end
