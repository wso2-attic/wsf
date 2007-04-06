/*
 * Copyright 2005,2006 WSO2, Inc. http://www.wso2.org
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "nsWSRequest.h"
#include "nsWSRequestException.h"
#include "nsLocalDefines.h"

#include "nsIXMLHttpRequest.h"
#include "nsISupportsUtils.h"
#include "nsCOMPtr.h"
#include "nsIDOMLoadListener.h"
#include "nsIDOMEventTarget.h"
#include "nsIDOMDocument.h"
#include "nsIDOMWindow.h"
#include "nsIDOMSerializer.h"
#include "nsIURI.h"
#include "nsIHttpChannel.h"
#include "nsIDocument.h"
#include "nsIStreamListener.h"
#include "nsIEventQueueService.h"
#include "nsWeakReference.h"
#include "nsISupportsArray.h"
#include "jsapi.h"
#include "nsIScriptContext.h"
#include "nsIChannelEventSink.h"
#include "nsIInterfaceRequestor.h"
#include "nsIHttpHeaderVisitor.h"
#include "nsIProgressEventSink.h"
#include "nsIXPConnect.h"
#include "nsIComponentManager.h"
#include "nsComponentManagerUtils.h"
/** following would required to compile in firefox ver1.6 or later */
//#include "nsIClassInfoImpl.h" 
#include "nsIDOMParser.h"
#include "nsServiceManagerUtils.h"
#include "nsIJSContextStack.h"

/*string manipulation*/
#include "nsStringAPI.h"
#include "nsAString.h"
#include "nsString.h"
#include "nsEmbedString.h"
#include "nsIVariant.h"

#include "nsIServiceManager.h"
#include "nsIProperties.h"
#include "nsDirectoryServiceDefs.h"
#include "nsIFile.h"
#include "nsISimpleEnumerator.h"
#include <stdlib.h>

//AXIS2 HOME
#define AXIS2C_HOME_ENV "AXIS2C_HOME"
#define AXIS2C_HOME_DIR "deploy"

// QueryInterface implementation for nsWSRequest
NS_IMPL_ISUPPORTS3_CI(nsWSRequest,
                      nsIWSRequest,
                      nsIXMLHttpRequest,
                      nsIJSXMLHttpRequest)

		      
nsWSRequest::nsWSRequest()
{
  /* all initializing assigned to Init */
    Init();
}

nsWSRequest::~nsWSRequest()
{
  /* destructor code */
    if ( mEndpointUri) PL_strfree ( mEndpointUri);
    if ( mResponseText) PL_strfree ( mResponseText);

  /* freeing environment variables */
    if ( client_home ) PL_strfree ( client_home );

  /* make sure everything is cleaned */
    if ( env ) axutil_env_free ( env );

}

/* initialize */
nsresult nsWSRequest::Init()
{
    ChangeReadyState (WSREQUEST_UNINITIALIZED );

     /* member initializers and constructor code */
    mEndpointUri = nsnull;
    mIsAsync = PR_TRUE;
    mOnreadystatechange = nsnull;
    mEventThread = nsnull;
    mSoapVer = (float)WSREQUEST_SOAP_VER_UNKNOWN; //the default soap ver 1.2
    mResponseText = nsnull;
    mReqMethod = WSREQUEST_HTTP_METHOD_DEFAULT;
    mProcessingSend = PR_FALSE;
    mStatus = 0;

     /* loading modules */
    addressingOn = PR_FALSE;
    restOn = PR_FALSE;
  //Retrieve AXIS2C_HOME
    nsresult rv;
    rv = FindAxis2Home( &client_home);
    if(NS_FAILED(rv))
    {
        /* axis2 libs not in the pack. so try some alternatives */
        client_home = getenv ( AXIS2C_HOME_ENV );
        if(client_home)
        {
            printf( "Extracting AXIS2C_HOME from env variable \n");
        }
    else
    {
      return WSREQUEST_EXCEPTION ("NULL_AXIS2C_HOME" ,
                 "Neither AXIS2C_HOME environment vairable nor "
                 "the extension deploy directory is available", nsnull,
                 NS_ERROR_NOT_AVAILABLE);
    }
  }

    //Initializing environment
  
    env = axutil_env_create_all("mozilla_client.log", AXIS2_LOG_LEVEL_INFO);

    //Initializing or retrieving the event queue of main thread 
    nsIEventQueue* eventQ;
    nsCOMPtr<nsIEventQueueService> eventQService =
                    do_GetService( NS_EVENTQUEUESERVICE_CONTRACTID, &rv);
    if(NS_SUCCEEDED(rv))
    {
        rv = eventQService-> GetThreadEventQueue( NS_CURRENT_THREAD, &eventQ);
        if ( NS_FAILED(rv) ) 
        {
            rv = eventQService-> CreateThreadEventQueue();
            if ( NS_FAILED( rv) )
                return rv;
            else
                rv = eventQService-> GetThreadEventQueue( NS_CURRENT_THREAD, &eventQ);
        }
    }
    if (NS_FAILED( rv))
        return rv;

    rv = eventQ->QueryInterface(NS_GET_IID(nsIEventQueue), (void**)&gEventQueue);
    if (NS_FAILED(rv))
        return rv;
  
    return NS_OK;
}

/** locate the path deploy folder is extracted */
nsresult nsWSRequest::FindAxis2Home( char** axis2CHome)
{
    nsresult rv;
    nsCOMPtr<nsIServiceManager> servMan;
    rv = NS_GetServiceManager(getter_AddRefs(servMan));
    nsCOMPtr<nsIProperties> directoryService;
    rv = servMan->GetServiceByContractID(
  		  NS_DIRECTORY_SERVICE_CONTRACTID,
  		  NS_GET_IID(nsIProperties),
  		  getter_AddRefs(directoryService));
  
    nsCOMPtr<nsISimpleEnumerator> enumComponentDirs;
    rv = directoryService->Get(NS_XPCOM_COMPONENT_DIR_LIST,
  		  NS_GET_IID(nsISimpleEnumerator),
  		  getter_AddRefs(enumComponentDirs));

    if (NS_FAILED (rv ) )
    {
        return rv;
    }
    rv = NS_ERROR_FAILURE;

    nsEmbedCString targetDir;
    nsEmbedCString fullPath;
    nsEmbedCString path;
    nsCOMPtr<nsIFile> theFile;
    nsCOMPtr<nsIFile> tempF;
    nsCOMPtr<nsISimpleEnumerator> enumCurrentDir;
	
    PRBool foundAXIS2C_HOME = PR_FALSE;
    PRBool hasMoreCompDirs;
    PRBool hasMoreSubDirs;
 
	
    NS_CStringInsertData( targetDir, 0, AXIS2C_HOME_DIR );

    enumComponentDirs -> HasMoreElements ( &hasMoreCompDirs );
    while ( hasMoreCompDirs && !foundAXIS2C_HOME)
    {
        enumComponentDirs ->GetNext ( getter_AddRefs( theFile ) ); 
        //go to the parentdir
        theFile-> GetParent(getter_AddRefs ( tempF) );
        theFile = tempF;
		
        //Enumerate the directories in extension folder
        theFile-> GetDirectoryEntries( getter_AddRefs( enumCurrentDir ) );
        enumCurrentDir -> HasMoreElements (&hasMoreSubDirs );
        while (hasMoreSubDirs )
        {
            enumCurrentDir -> GetNext ( getter_AddRefs( tempF) );
            tempF-> GetNativeLeafName (path);
            if ( path.Equals(targetDir ) )
            {
	            foundAXIS2C_HOME = PR_TRUE;
            }
            enumCurrentDir -> HasMoreElements (&hasMoreSubDirs );
        }
		
        if(!foundAXIS2C_HOME)
        {
            enumComponentDirs -> HasMoreElements ( &hasMoreCompDirs );
            continue;//Continue to next extension dir
        }
    
        //Or get the path 		
        fullPath.Truncate();
        while(true)
        {
            if(theFile != NULL)
            {
                theFile-> GetNativeLeafName (path);
            }
            if(theFile == NULL || path.IsEmpty() )
            {
#ifndef WIN32
      	        NS_CStringInsertData( fullPath, 0,  "/" );
#endif
                NS_CStringAppendData( fullPath, "/");
                NS_CStringAppendData( fullPath, AXIS2C_HOME_DIR );
			
                const char* tempW = fullPath.get ();
                *axis2CHome = PL_strdup(tempW);
                rv = NS_OK;
				
                break;
            }
      
        if(!fullPath.IsEmpty() )
        {
      	    NS_CStringInsertData( fullPath, 0,  "/" );
            const char* tempW = path.get ();
      	    NS_CStringInsertData( fullPath, 0, tempW );
        }
        else
        {
            const char* tempW = path.get();
            NS_CStringSetData(fullPath, tempW);
        }
        theFile-> GetParent(getter_AddRefs(tempF));
        theFile = tempF;
    }
    enumComponentDirs->HasMoreElements(&hasMoreCompDirs );
    }
  return  rv;
}


/////////////////////////////////////////////////
//
// implementation for nsISOAPHttpRequest
//
/////////////////////////////////////////////////

///new API start

/// setOption method
nsresult nsWSRequest::setOptions(nsIVariant *optionSet)
{
    char *useSoap = ""; //need to get the length 
    char *useWsa = "";
    char *method = "";  
  
	//"useSOAP" option 
    getOptionsByKey(WSREQUEST_OPT_USE_SOAP,&useSoap);
    
    // useSOAP = true
    if(!PL_strcmp(TRUE,useSoap)  && PL_strlen(useSoap) != 0)
    {
        mSoapVer = WSREQUEST_SOAP_VER_1_2;
    }
    // useSOAP = false | user need REST  
    else if(!PL_strcmp(FALSE,useSoap) && PL_strlen(useSoap) != 0)
    {
        restOn = PR_TRUE;
    }    
                        
    else if(!PL_strcmp(SOAP_VERSION_1_1,useSoap) && PL_strlen(useSoap) != 0 )
    {  
         mSoapVer = WSREQUEST_SOAP_VER_1_1;  
    }   
    else if(!PL_strcmp(SOAP_VERSION_1_2,useSoap) && PL_strlen(useSoap)!= 0)
    { // default soap ver
         mSoapVer = WSREQUEST_SOAP_VER_1_2;
    }
    if(useSoap)
    {    
        PL_strfree(useSoap);
        useSoap = nsnull; //no wild pointers
    }    
                
	 //the http method
     if(restOn)
     {
        getOptionsByKey(WSREQUEST_HTTP_METHOD,&method);
        if((!PL_strcmp(WSREQUEST_HTTP_METHOD_POST,method) || !PL_strcmp(WSREQUEST_HTTP_METHOD_POST_LOWER,method)) && PL_strlen(method) != 0)
        {
            mReqMethod = WSREQUEST_HTTP_METHOD_POST;         
	    }
	    if(!PL_strcmp(WSREQUEST_HTTP_METHOD_GET,method)|| !PL_strcmp(WSREQUEST_HTTP_METHOD_GET_LOWER,method) && PL_strlen(method) != 0)
        {
	        mReqMethod = WSREQUEST_HTTP_METHOD_GET;	  	
	    }
        if(method)
        {    
            PL_strfree(method); 
            method = nsnull;
        }
     }
	//"useWSA" option
    getOptionsByKey(WSREQUEST_OPT_USE_WSA,&useWsa);    
    if((!PL_strcmp(TRUE,useWsa) || !PL_strcmp(WSREQUEST_WSA_1_0,useWsa)) && PL_strlen(useWsa) != 0 )
    {
        // useWSA=true | useWSA=1.0 |useWSA="1.0" |"submission" here
        addressingOn = PR_TRUE;
    }
    if(useWsa)
    {    
        PL_strfree(useWsa);
        useWsa = nsnull;
    }    
    return NS_OK; 
}

nsresult nsWSRequest::getOptionsByKey(const char *key,char **value)
{
    nsCOMPtr<nsIVariant> varVal;
    nsEmbedString str;
    nsEmbedCString cStr( key);
    str = NS_ConvertUTF8toUTF16(cStr);

    optionArray->GetProperty( str, getter_AddRefs (varVal));
    varVal->GetAsAString( str);

    *value = PL_strdup ( NS_ConvertUTF16toUTF8(str).get());
    return NS_OK;

}
/// end of getOptionByKey method
NS_IMETHODIMP nsWSRequest::Open(nsIVariant *optionSet,const nsACString &url)
{
    nsresult rv;
    PRUint16 dataType;
    rv = optionSet->GetDataType(&dataType);
    if (NS_FAILED(rv))
        return rv;

    
    switch(dataType)
    {    
        //if the option is a string
        case nsIDataType::VTYPE_CHAR_STR:
        case nsIDataType::VTYPE_UTF8STRING:
        case nsIDataType::VTYPE_CSTRING:
        case nsIDataType::VTYPE_ASTRING:
        case nsIDataType::VTYPE_STRING_SIZE_IS:
        case nsIDataType::VTYPE_WSTRING_SIZE_IS:
        {
            nsEmbedString serial;
            optionSet->GetAsAString(serial);
            mReqMethod = PL_strdup (NS_ConvertUTF16toUTF8(serial).get());
        }
        break;
        default: 
        {
            //if the option is an assosiative array
            nsISupports* supports;
            nsIID *iid;
            rv = optionSet->GetAsInterface(&iid, (void**)&supports);
            if (NS_FAILED(rv))
                return rv;
            if (iid)
                nsMemory::Free(iid);

            optionArray = do_QueryInterface (supports);
        
            if (!optionArray)
            {
                return WSREQUEST_EXCEPTION ("ILLEGAL_TYPE" ,
                          "optionsSet should be associative array", nsnull,
                          NS_ERROR_ILLEGAL_VALUE);

            } 
            setOptions(optionSet);
            break;
            
        }
    }
    
    //get the third paramete
    nsresult param;
    nsCOMPtr<nsIXPCNativeCallContext> cc;
    nsCOMPtr<nsIXPConnect> xpc(do_GetService(nsIXPConnect::GetCID(), &param));
    if(NS_SUCCEEDED(param))
    {
        param = xpc->GetCurrentNativeCallContext(getter_AddRefs(cc));
    }
    else
        return param;

  /** extract the third optional argument */
    PRUint32 argc;
    param = cc->GetArgc(&argc);
    if (NS_FAILED(param))
        return param;


    if (argc > 2)
    {
        jsval* argv;
        param = cc->GetArgvPtr(&argv);
        if (NS_FAILED(param))
        return param;

        JSContext* cx;
        param = cc->GetJSContext(&cx);
        if (NS_FAILED(param))
             return param;

        JSBool asyncBool;
        ::JS_ValueToBoolean(cx, argv[2], &asyncBool);
        mIsAsync = (PRBool)asyncBool;
    }

    char *urlStr;
    NS_CStringGetData ( url,(const char**) &urlStr);
    mEndpointUri  = PL_strdup (urlStr );
       
    ChangeReadyState (WSREQUEST_OPENED);
    return NS_OK;
}

/// end of new API

/////////////////////////////////////////////////
//
// implementation for nsIXMLHttpRequest
//
/////////////////////////////////////////////////

/* readonly attribute nsIDOMDocument responseXML; */
NS_IMETHODIMP nsWSRequest::GetResponseXML(nsIDOMDocument * *aResponseXML)
{
  /* TODO:string to dom conversion should be removed */
    nsresult rv;
    if ( mResponseText == NULL )
    {
        *aResponseXML = nsnull;
             return WSREQUEST_EXCEPTION ("NULL_RESPONSE" ,
                     "response is not available or null", nsnull,
                      NS_ERROR_NOT_AVAILABLE);

    }

    nsCOMPtr<nsIDOMParser> dom_parser(do_CreateInstance(NS_DOMPARSER_CONTRACTID, &rv ) );
    if (NS_FAILED(rv))
        return rv;

   //build the document
    nsCOMPtr<nsIDOMDocument> re_dom_doc;
    rv = dom_parser-> ParseFromBuffer ( ( PRUint8 *)mResponseText,
		                       strlen (mResponseText ),
                                       "text/xml",
		              getter_AddRefs(re_dom_doc ) );
    if (NS_FAILED(rv))
    return rv;
    *aResponseXML = re_dom_doc;
    NS_ADDREF ( *aResponseXML);
    return NS_OK;
}

/* readonly attribute AString responseText; */
NS_IMETHODIMP nsWSRequest::GetResponseText(nsAString & aResponseText)
{
    if ( mResponseText == NULL )
    {
        aResponseText = NS_ConvertUTF8toUTF16("");
        return WSREQUEST_EXCEPTION ("NULL_RESPONSE" ,
                     "response is not available or null", nsnull,
                      NS_ERROR_NOT_AVAILABLE);
    }
    nsEmbedCString nsResponseText;
    NS_CStringSetData( nsResponseText, (const char*)mResponseText );
    aResponseText = NS_ConvertUTF8toUTF16 ( nsResponseText );

    return NS_OK;
}

/* readonly attribute long readyState; */
NS_IMETHODIMP nsWSRequest::GetReadyState(PRInt32 *aReadyState)
{
    *aReadyState = mReadyState; 
    return NS_OK;
}

/* readonly attribute unsigned long status; */
NS_IMETHODIMP nsWSRequest::GetStatus(PRUint32 *aStatus)
{
    *aStatus = mStatus; 
    return NS_OK;
}

/* void open (in AUTF8String method, in AUTF8String url); */
NS_IMETHODIMP nsWSRequest::Open(const nsACString & method,
                                     const nsACString & url)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void send (in nsIVariant body); */
NS_IMETHODIMP nsWSRequest::Send(nsIVariant *body)
{
    if ( mProcessingSend)
        return NS_ERROR_ABORT;
    mProcessingSend = PR_TRUE;

    nsresult rv;
    nsEmbedString serial;
    /*nsCOMPtr<nsIInputStream> postDataStream; */

    PRUint16 dataType;
    rv = body->GetDataType(&dataType);
    if (NS_FAILED(rv))
        return rv;

    switch (dataType)
    {
        case nsIDataType::VTYPE_CHAR_STR:
        case nsIDataType::VTYPE_UTF8STRING:
        case nsIDataType::VTYPE_CSTRING:
        case nsIDataType::VTYPE_ASTRING:
        case nsIDataType::VTYPE_STRING_SIZE_IS:
        case nsIDataType::VTYPE_WSTRING_SIZE_IS:
        body -> GetAsAString(  serial);
        break;
        
        case nsIDataType::VTYPE_INTERFACE:
        case nsIDataType::VTYPE_INTERFACE_IS:
        nsISupports* supports;
        nsIID *iid;
        rv = body-> GetAsInterface(&iid, (void**)&supports);
        if (NS_FAILED(rv))
            return rv;
        if (iid)
            nsMemory::Free(iid);

        nsCOMPtr<nsIDOMNode> dom_node = do_QueryInterface ( supports);
        if ( dom_node )
        {
            nsCOMPtr<nsIDOMSerializer> serializer
                 ( do_CreateInstance( NS_XMLSERIALIZER_CONTRACTID, &rv ) );
            if (NS_FAILED(rv))
                return rv;

            rv = serializer->SerializeToString(dom_node , serial );
            if ( NS_FAILED( rv))
               return rv;
        }
        break;
    }
    char* bodyContent;
    bodyContent =PL_strdup ( NS_ConvertUTF16toUTF8(serial).get() );
    rv = SendRequest (bodyContent );
    if (NS_FAILED (rv ) )
        return rv;
        PL_strfree (bodyContent);

    return NS_OK;
}

/////////////////////////////////////////////////
//
// implementation for nsIJSXMLHttpRequest
//
/////////////////////////////////////////////////

/* attribute nsIOnReadyStateChangeHandler onreadystatechange; */
NS_IMETHODIMP
nsWSRequest::GetOnreadystatechange
			(nsIOnReadyStateChangeHandler * *aOnreadystatechange)
{
    *aOnreadystatechange = mOnreadystatechange;
    NS_ADDREF ( *aOnreadystatechange );
    return NS_OK;
}
NS_IMETHODIMP
nsWSRequest::SetOnreadystatechange
			(nsIOnReadyStateChangeHandler * aOnreadystatechange)
{
    mOnreadystatechange = aOnreadystatechange;
    // flag the declared context
    GetCurrentContext( getter_AddRefs(mScriptContext) );
    return NS_OK;
}

////////////////////////////////////////////////////
// Internal methods

/* void sendRequest (in string soapContent); */
nsresult
nsWSRequest::SendRequest(const char* soapContent )
{
    nsresult rv;

  //attaching the soap body
    axiom_node_t* cont_node  = NULL;
    rv = CreateOMFromText( (axis2_char_t*)soapContent, &cont_node );
  
    if ( NS_FAILED (rv ) )
    {
    return rv;
    }
    ChangeReadyState (WSREQUEST_LOADED);
    axiom_xml_reader_init(); 
 
 
    if ( mIsAsync)
    {
        if (mEventThread )
        {
            PR_Free ( mEventThread );
        }
        nsPassingObj_t* passingObj = new nsPassingObj_t;
        passingObj->obj = (void* ) this;
        passingObj->cont_node = cont_node;
        mEventThread = PR_CreateThread(PR_USER_THREAD,
        (void (*)(void*))threadProc,
        (void*) passingObj,
        PR_PRIORITY_NORMAL,
        PR_LOCAL_THREAD,
        PR_JOINABLE_THREAD,
        0); 
        PostAsynEvent (WSREQUEST_INTERACTIVE);
    }
    else
    {
        InvokeWS ( cont_node );
    }
  
    return NS_OK;   
}

/*new thread to handle aysnc calls*/
void nsWSRequest::threadProc(void *arg)
{
    nsPassingObj_t* passedObj = ( nsPassingObj_t* ) arg;
    nsWSRequest* obj = (nsWSRequest* )passedObj-> obj;
    obj->InvokeWS( passedObj -> cont_node);
}

nsresult
nsWSRequest::InvokeWS( axiom_node_t* cont_node )
{
    nsresult rv;
    rv = NS_OK;

    axis2_options_t *options = NULL;
    axis2_svc_client_t* svc_client = NULL;
    axiom_node_t* ret_node = NULL;
    axis2_endpoint_ref_t* endpoint_ref = NULL;

    /* Setup options */
    options = axis2_options_create(env);
    if(options == NULL)
    {
        rv = WSREQUEST_EXCEPTION ("FAIL_INVOKE" ,
                     "axis2 fails to invoke the service", nsnull,
                      NS_ERROR_FAILURE);
    }
    else
    {
        endpoint_ref = axis2_endpoint_ref_create ( env, mEndpointUri );
        axis2_options_set_to(options, env, endpoint_ref);
    }

    /* set the version */
    if(options && !restOn)
    {
        if( WSREQUEST_COMPARE_SOAP_VERSIONS(mSoapVer, WSREQUEST_SOAP_VER_1_1 ) )
        {
            axis2_options_set_soap_version(options, env, AXIOM_SOAP11);
        }
    }
    svc_client = axis2_svc_client_create(env, client_home);
    if(svc_client == NULL )
    {
        rv = WSREQUEST_EXCEPTION ("FAIL_INVOKE" ,
                     "axis2 fails to invoke the service", nsnull,
                      NS_ERROR_FAILURE);
    }
    else if ( NS_SUCCEEDED (rv ))
    {
        /*extract addressing from the list */
        if(addressingOn  && restOn == PR_FALSE)
        {
        /* Engage addressing module */
            axis2_svc_client_engage_module(svc_client, env,AXIS2_MODULE_ADDRESSING);  
            char *wsaAction = nsnull;
            getOptionsByKey(WSPREQUEST_OPT_WSA_ACTION,&wsaAction);
    
            if (wsaAction == nsnull)
            {
                rv = WSREQUEST_EXCEPTION ("NULL_WSA_ACTION" ,
                     "wsa action missing", nsnull,
                      NS_ERROR_NOT_AVAILABLE);
            }
      
            else
            {
                char *from = ""; /*need to get the length of the string*/
                getOptionsByKey(WSREQUEST_OPT_FROM,&from);
                if(PL_strlen(from) != 0)
                {
                    axis2_options_set_from(options, env,axis2_endpoint_ref_create(env,from));
                    if(from)
                    {
	    	            PL_strfree(from);
                        from = nsnull;
                    }    
                }
                char *replyTo = "";
		        getOptionsByKey(WSREQUEST_OPT_REPLY_TO,&replyTo);
                if(PL_strlen(replyTo) != 0 )
                {
                    axis2_options_set_reply_to(options, env,axis2_endpoint_ref_create(env,replyTo));
                    if(replyTo)
                    {
            		    PL_strfree(replyTo);
                        replyTo = nsnull;
                    }    
	            }        
                char *faultTo = "";
                getOptionsByKey(WSREQUEST_OPT_FAULT_TO,&faultTo);
		        if(PL_strlen(faultTo) != 0)
                {
                    axis2_options_set_fault_to(options,env,axis2_endpoint_ref_create(env,faultTo));
                    if(faultTo)
                    {
			            PL_strfree(faultTo);
                        faultTo = nsnull;
                    }
            	}   
	
            }
            axis2_options_set_action(options, env,wsaAction);
        }
      
        //TODO fix this bug in Axis2/c and come here
        /*if(restOn)
        {
            if(!PL_strcmp(mReqMethod,WSREQUEST_HTTP_METHOD_POST))
            {
                AXIS2_OPTIONS_SET_PROPERTY(options,env,AXIS2_HTTP_METHOD, AXIS2_HTTP_HEADER_POST);
	        }
            else if(!PL_strcmp(mReqMethod,WSREQUEST_HTTP_METHOD_GET))
            {
                AXIS2_OPTIONS_SET_PROPERTY(options,env,AXIS2_HTTP_METHOD,AXIS2_HTTP_HEADER_GET);
       	    }
        }*/
        if(restOn)
        {
            axutil_property_t *rest_property = NULL;
            axutil_property_set_value(rest_property,env,axutil_strdup(env,AXIS2_VALUE_TRUE));
            axis2_options_set_property(options,env,AXIS2_ENABLE_REST,rest_property);

            if(!PL_strcmp(mReqMethod,WSREQUEST_HTTP_METHOD_GET))
            {
               // get_property = axis2_property_create(env);
               // AXIS2_PROPERTY_SET_VALUE(get_property,env,axis2_strdup(AXIS2_HTTP_HEADER_GET,env));
               // AXIS2_OPTIONS_SET_PROPERTY(options,env,AXIS2_HTTP_METHOD,get_property);
            }

        }    
        /* Set service client options */
        axis2_svc_client_set_options(svc_client,env,options);
    }

  /* Send request */
    if(NS_SUCCEEDED (rv ))
    {
        ret_node = axis2_svc_client_send_receive(svc_client,env,cont_node);
    }
  
    if(mResponseText)
    {
        PL_strfree (mResponseText);
		mResponseText = nsnull;
    }
    if(!ret_node)
    {
	    mResponseText = nsnull;
        mStatus = WSREQUEST_HTTP_STATUS_FAILURE;
	    rv = WSREQUEST_EXCEPTION ("NULL_RESPONSE" ,
                     "response null", nsnull,
                      NS_ERROR_FAILURE);
    }
	else
    {
	        axiom_xml_writer_t *writer = NULL;
        	axiom_output_t *om_output = NULL;

	        writer = axiom_xml_writer_create_for_memory(env, NULL, AXIS2_TRUE, 0,
		                  AXIS2_XML_PARSER_TYPE_BUFFER);
        	om_output = axiom_output_create (env, writer);

            /*axiom_node_serialize(ret_node,env,om_output);*/
            axiom_node_serialize_sub_tree(ret_node,env,om_output);
            
        	mResponseText = PL_strdup ((char* )axiom_xml_writer_get_xml(writer, env) );
	        mStatus = WSREQUEST_HTTP_STATUS_SUCCESS;
    }
      
    	/* freeing use objects */
	//if(svc_client) AXIS2_SVC_CLIENT_FREE ( svc_client, env );
	//if(cont_node) AXIOM_NODE_FREE_TREE ( cont_node, env );
	//if(ret_node) AXIOM_NODE_FREE_TREE ( ret_node, env ); 
	//if ( endpoint_ref )AXIS2_ENDPOINT_REF_FREE ( endpoint_ref, env );

	if(mIsAsync)
    {
        	PostAsynEvent (WSREQUEST_COMPLETED);
    }
    else
    {
    	//Just call script straight
        	ChangeReadyState( WSREQUEST_COMPLETED);
    }
    mProcessingSend = PR_FALSE;
    return rv;
}

nsresult nsWSRequest::PostAsynEvent ( PRInt32 forState )
{
	    //Use native class rather the wrapper
    PLEventQueue* ntvEventQueue;
	gEventQueue-> GetPLEventQueue(&ntvEventQueue );

	   //create and post an event to the main thread
    PL_ENTER_EVENT_QUEUE_MONITOR(ntvEventQueue);

	    // construct
    nsAsyncEvent_t* event;

    event = PR_NEW( nsAsyncEvent_t);
    if(event == NULL)
    {
        	PL_EXIT_EVENT_QUEUE_MONITOR ( ntvEventQueue );
            	return NS_ERROR_OUT_OF_MEMORY;
    }

	  // initialize
	PL_InitEvent( (PLEvent*)event, this,
                     (void* (*)(PLEvent*)) HandleAsync,
                     (void (*)(PLEvent*)) DestroyAsync );
       	event->obj = this;
        event->readyState = forState;
 
	// post
	PL_PostEvent(ntvEventQueue, &event->e);
    	PL_EXIT_EVENT_QUEUE_MONITOR( ntvEventQueue);
    	return NS_OK;
}


void* nsWSRequest::HandleAsync(PLEvent* aEvent)
{
	nsAsyncEvent_t *event = (nsAsyncEvent_t*) aEvent;

	nsWSRequest* obj = (nsWSRequest* )event->obj;
	PRInt32 readyState = (PRInt32) event->readyState;
	obj->ChangeReadyState( readyState);  

	return NULL;   
}

void nsWSRequest::DestroyAsync(PLEvent* aEvent)
{
   /** no clean up for the event */
}


nsresult nsWSRequest::ChangeReadyState( PRInt32 aReadyState )
{
	mReadyState = aReadyState;

   /* no call backs if no callback function declared */
	if(mOnreadystatechange == nsnull )
        	return NS_OK;
 
	nsCOMPtr<nsIJSContextStack> stack;
    	JSContext *cx = nsnull;

	if(mScriptContext)
    {
	        stack = do_GetService("@mozilla.org/js/xpc/ContextStack;1");

        	if(stack)
            {
            		cx = (JSContext *)mScriptContext->GetNativeContext();

			    if(cx)
                {
        	        	stack->Push(cx);
                }
        	}
   	}
	mOnreadystatechange ->HandleEvent( );
	if(cx)
    {
	        stack->Pop(&cx);
   	}
	return NS_OK;
}

nsresult
nsWSRequest::GetDocumentFromScriptContext(nsIScriptContext *aScriptContext,
	       	nsIDocument** ret_doc)
{
	if (!aScriptContext)
    {
		*ret_doc = nsnull;
        	return NS_ERROR_FAILURE;
	}
  
	nsCOMPtr<nsIDOMWindow> window =
        	do_QueryInterface((nsISupports*)aScriptContext->GetGlobalObject());
	nsIDocument *doc = nsnull;
	if(window)
    {
        	nsCOMPtr<nsIDOMDocument> domdoc;
	        window->GetDocument(getter_AddRefs(domdoc));
        	if(domdoc)
            {
		        CallQueryInterface(domdoc, &doc);
		        *ret_doc = doc;
             		return NS_OK;
         	}
	}
	*ret_doc = nsnull;
	return NS_ERROR_FAILURE;

}

/* Script of the javascript context*/
nsresult nsWSRequest::GetCurrentContext( nsIScriptContext** ret_val)
{
  // Get JSContext from stack.
	nsCOMPtr<nsIJSContextStack> stack = do_GetService("@mozilla.org/js/xpc/ContextStack;1");

	if(!stack)
    {
		*ret_val = nsnull;
		return NS_ERROR_FAILURE;
	}

	JSContext *cx;

	if(NS_FAILED(stack->Peek(&cx)) || !cx)
    {
		*ret_val = nsnull;
	        return NS_ERROR_FAILURE;
	}
	*ret_val = GetScriptContextFromJSContext(cx);
	NS_ADDREF (*ret_val );
	return NS_OK;
}

/* print node - just for debugging*/
/* TODO:wrap with debug only brackets */
nsresult nsWSRequest::PrintNode ( axiom_node_t* node )
{
	axiom_xml_writer_t *writer = NULL;
	axiom_output_t *om_output = NULL;
	axis2_char_t *buffer = NULL;

	writer = axiom_xml_writer_create_for_memory(env, NULL, AXIS2_TRUE, 0, 
		                              AXIS2_XML_PARSER_TYPE_BUFFER);
	om_output = axiom_output_create (env, writer);
	axiom_node_serialize(node, env, om_output);
	buffer = (axis2_char_t*) axiom_xml_writer_get_xml(writer, env);
	printf("%s\n", buffer);
	free( buffer);
    	return NS_OK;
}

nsresult
nsWSRequest::CreateOMFromText( axis2_char_t* nodeText,
                                          axiom_node_t** retnode)
{
	axiom_node_t *node = NULL;
	axiom_document_t *document = NULL;
	axiom_stax_builder_t *om_builder = NULL;
	axiom_xml_reader_t* xml_reader = NULL;

    	//attaching the soap body
    	xml_reader = axiom_xml_reader_create_for_memory( env, nodeText,
                                                strlen (nodeText), "utf-8",
						AXIS2_XML_PARSER_TYPE_BUFFER );
    	if(!xml_reader)
        	return NS_ERROR_FAILURE;

    	om_builder = axiom_stax_builder_create(env, xml_reader);
        if(!om_builder){
        	axiom_xml_reader_free(xml_reader, env);
        	return NS_ERROR_FAILURE;
        }
    document = axiom_stax_builder_get_document(om_builder,env);    
	if(!document){
            axiom_stax_builder_free(om_builder,env);
        	return NS_ERROR_FAILURE;
	}
    node = axiom_document_get_root_element(document, env);
	if(!node){
        	return NS_ERROR_FAILURE;
    	}
     axiom_document_build_all(document, env);
    	*retnode = node;
    	return NS_OK;
}


///////////////////////////////////////////////
//
// not implemented on nsIXMLHttpRequest
//
/////////////////////////////////////////////////
//
/* readonly attribute nsIChannel channel; */
NS_IMETHODIMP nsWSRequest::GetChannel(nsIChannel * *aChannel)
{
      return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String statusText; */
NS_IMETHODIMP nsWSRequest::GetStatusText(nsACString & aStatusText)
{
      return NS_ERROR_NOT_IMPLEMENTED;
}

/* void abort (); */
NS_IMETHODIMP nsWSRequest::Abort()
{
      return NS_ERROR_NOT_IMPLEMENTED;
}

/* string getAllResponseHeaders (); */
NS_IMETHODIMP nsWSRequest::GetAllResponseHeaders(char **_retval)
{
      return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString getResponseHeader (in AUTF8String header); */
NS_IMETHODIMP nsWSRequest::GetResponseHeader(const nsACString & header,
                                                  nsACString & _retval)
{
      return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void openRequest (in AUTF8String method, in AUTF8String url,
 *                           in boolean async, in AString user, in AString password); */
NS_IMETHODIMP nsWSRequest::OpenRequest(const nsACString & method,
                                   const nsACString & url, PRBool async,
				   const nsAString & user, const nsAString & password)

{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setRequestHeader (in AUTF8String header, in AUTF8String value); */
NS_IMETHODIMP nsWSRequest::SetRequestHeader(const nsACString & header, const nsACString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void overrideMimeType (in AUTF8String mimetype); */
NS_IMETHODIMP nsWSRequest::OverrideMimeType(const nsACString & mimetype)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean multipart; */
NS_IMETHODIMP nsWSRequest::GetMultipart(PRBool *aMultipart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWSRequest::SetMultipart(PRBool aMultipart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

///////////////////////////////////////////////
//
// not implemened on nsIJSXMLHttpRequest
//
/////////////////////////////////////////////////
//

/* attribute nsIDOMEventListener onload; */
NS_IMETHODIMP nsWSRequest::GetOnload(nsIDOMEventListener * *aOnload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWSRequest::SetOnload(nsIDOMEventListener * aOnload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onerror; */
NS_IMETHODIMP nsWSRequest::GetOnerror(nsIDOMEventListener * *aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWSRequest::SetOnerror(nsIDOMEventListener * aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onprogress; */
NS_IMETHODIMP nsWSRequest::GetOnprogress(nsIDOMEventListener * *aOnprogress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWSRequest::SetOnprogress(nsIDOMEventListener * aOnprogress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
