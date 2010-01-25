@ECHO OFF
:checkparameters
:: REM Grab the first variable supplied as a whole. Ex. /action:start
set SWITCHPARSE=%1
:: REM Check to see if there are no more switches, if so goto end of
:: parsing, prevents endless loop
IF [%SWITCHPARSE%] == [] goto endswitchparsing
:: REM Reset variables as clean up. Dont know if i need this anymore
:: since i am checking for exit above. Oh well.
set SWITCH=
set VALUE=
:: In the SWITCHPARSE variable, grab the two tokens separated
:: by a : and assign the first to SWITCH and the second to VALUE
for /F "tokens=1,2 delims=: " %%a IN ("%SWITCHPARSE%") DO SET SWITCH=%%a&set VALUE=%%b
:: Check which action to perform based on the switch
IF [%SWITCH%] == [/subscriptionid] goto setsubscriptionid
IF [%SWITCH%] == [/op] goto setop
IF [%SWITCH%] == [/opargs] goto setopargs
IF [%SWITCH%] == [/soap] goto setsoap
IF [%SWITCH%] == [/dump] goto setdump
IF [%SWITCH%] == [/help] goto sethelp
:: Perform the action by setting the variable for later use and
:: shift the command line parameters so the next in line is
:: ready to be processed
:setsubscriptionid
set subscriptionid=%VALUE%
echo %subscriptionid%
SHIFT
goto checkparameters

:setop
set op=%VALUE%
set op_xml=%op%.xml
set op_xml_response=%op%Response.xml
echo %op_xml_response%
SHIFT
goto checkparameters

:setopargs
set opargs=%VALUE%
echo %opargs%
SHIFT
goto checkparameters

:setsoap
set soap=%VALUE%
SHIFT
goto checkparameters

:setdump
set dump=%VALUE%
SHIFT
goto checkparameters

:sethelp
echo help called
SHIFT
goto checkparameters

:endswitchparsing
set op_xml=%op%.xml
echo %op_xml%

IF [%soap%] == [true] (goto dosoap)
IF [%soap%] == [false] (goto dorest)
:dosoap
cscript /nologo amazoneclient.js --subscription_id=%subscriptionid% --op=%op% --op_args=%opargs% --soap
echo "do soap"
wsclient --soap1.1 --no-mtom --action http://soap.amazon.com http://soap.amazon.com:80/onca/soap?Service=AWSECommerceService < %op_xml% > %op_xml_response%
IF [%op%] == [CartClear] (goto clean)
goto end
:dorest
cscript /nologo amazoneclient.js --subscription_id=%subscriptionid% --op=%op% --op_args=%opargs%
echo "do rest"
wsclient --get --to http://webservices.amazon.com:80/onca/xml < %op_xml% > %op_xml_response%
IF [%op%] == [CartClear] (goto clean)
goto end

:clean
    del ItemSearch.xml
    del ItemSearchResponse.xml
    del ItemLookup.xml
    del ItemLookupResponse.xml
    del CartCreate.xml
    del CartCreateResponse.xml
    del CartAdd.xml
    del CartAddResponse.xml
    del CartModify.xml
    del CartModifyResponse.xml
    del CartClear.xml
    del CartClearResponse.xml

:end
