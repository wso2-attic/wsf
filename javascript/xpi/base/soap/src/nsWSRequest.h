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


#ifndef NS_WSREQUEST_H_
#define NS_WSREQUEST_H_

#include "nsIXMLHttpRequest.h"

#include "nsIWSRequest.h"

#include "nsISupportsUtils.h"
#include "nsCOMPtr.h"
#include "nsIDOMLoadListener.h"
#include "nsIDOMEventTarget.h"
#include "nsIDOMDocument.h"
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
#include "nsIDOMLSProgressEvent.h"
#include "nsIPropertyBag.h"

//Event Posting +  Handling
#include "plevent.h"
#include "nsIEventQueue.h"
#include "nsIEventQueueService.h"

/*Axis2 Headers*/
#include "axiom.h"
#include "axiom_soap.h"
#include "axis2_client.h"
#include "axis2_util.h"
#include "axis2_http_transport.h"

/*thread handling*/
#include "nsIThread.h"
#include "nsIRunnable.h"
#include "nspr.h"

/* Event generated for callbacks*/
typedef struct nsAsyncEvent{
  PLEvent e;

  // arguments ...
  void* obj;
  PRInt32 readyState;

} nsAsyncEvent_t;

/* Passed obj for new thread*/
typedef struct nsPassingObj{

  void* obj;
  axiom_node_t* cont_node;

} nsPassingObj_t;



/* Declaration for SOAPHttpRequest*/
class nsWSRequest : public nsIWSRequest,
                          public nsIXMLHttpRequest,
                          public nsIJSXMLHttpRequest
{
public:
  nsWSRequest();
  ~nsWSRequest();
  
  /* Initialize variables */
  nsresult Init();

  // nsISupports
  NS_DECL_ISUPPORTS
  
  // nsIWSRequest
  NS_DECL_NSIWSREQUEST

  // nsIXMLHttpRequest
  NS_DECL_NSIXMLHTTPREQUEST

  // nsIJSXMLHttpRequest
  NS_DECL_NSIJSXMLHTTPREQUEST

  nsresult InvokeWS( axiom_node_t* cont_node );
  nsresult ChangeReadyState(PRInt32 aReadyState );
  static nsresult FindAxis2Home( char** axis2CHome );


protected:
  
  /* additional members */
  float mSoapVer;
  char *mEndpointUri;
  PRBool mIsAsync;
  PRInt32 mReadyState;
  PRInt32 mStatus;
  //PRBool mHasFaults;

  PRBool addressingOn;
  PRBool restOn;
  PRBool mGet;
  PRBool mProcessingSend;

  /* handling response */
  char *mResponseText;
  nsIDOMDocument* mResponseXML;
  nsCOMPtr<nsIOnReadyStateChangeHandler> mOnreadystatechange;

  /* set options */
  nsCOMPtr<nsIPropertyBag> propertySet;
  /// optionArray
  nsCOMPtr<nsIPropertyBag> optionArray;
  /// end of optionArray
  
  
  /* threads events and callbacks */
  PRThread*  mEventThread;

  nsIEventQueue *gEventQueue;
  PR_STATIC_CALLBACK(void*) HandleAsync(PLEvent* aEvent);
  PR_STATIC_CALLBACK(void) DestroyAsync(PLEvent* aEvent);
  nsresult PostAsynEvent ( PRInt32 forState );

  PR_STATIC_CALLBACK(void) threadProc(void *arg);
  PR_STATIC_CALLBACK(void) threadProc1(void *arg);

  /* javascript context*/
  nsCOMPtr<nsIScriptContext> mScriptContext;

///////////////////////////////
//axis2 declarations
//
  /* additional members */
  char *mReqMethod;

  /* axis2c variables */
  /////////////////////////////////
  // Setting environment/
  
  axutil_env_t *env ;
  axis2_char_t *client_home;

  ///////////////////////////////
  // Createing request Message

  /* internal operations */
  nsresult SendRequest( const char* soapContent );
  nsresult PrintNode(axiom_node_t* node);
  nsresult CreateOMFromText( axis2_char_t* nodeText,
                             axiom_node_t** retnode);


  nsresult GetCurrentContext(nsIScriptContext** ret_val);
  nsresult
  GetDocumentFromScriptContext(nsIScriptContext *aScriptContext,
		             nsIDocument** doc);
  ///new APT methods
  nsresult setOptions(nsIVariant *optionsSet); 
  nsresult getOptionsByKey(const char *key,char **value);
  ///end of new method
    
  
	
};



#define NS_WSREQUEST_CID                   \
  { /*cf131d3d-0f17-4e21-a19a-d486735cbc93*/     \
  0xcf131d3d, 0x0f17, 0x4e21,                    \
  { 0xa1, 0x9a, 0xd4,0x86, 0x73, 0x5c, 0xbc, 0x93 } }
#define NS_WSREQUEST_CONTRACTID "@mozilla.org/tungsten/soaphttprequest;1"

#endif

