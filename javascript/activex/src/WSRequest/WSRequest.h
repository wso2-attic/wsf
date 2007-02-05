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

// WSRequest.h : Declaration of the CWSRequest

#pragma once
#include "resource.h"       // main symbols

#include "WSO2.h"
#include "_IWSRequestEvents_CP.h"

//Axis Libraries
#include <axiom.h>
#include <axiom_soap.h>
#include <axis2_util.h>
#include <axiom_soap.h>
#include <axis2_client.h>

#include <axis2_http_transport.h>

//Idispatchex header
#include <dispex.h>
#include <comutil.h>
#include <windows.h>
#include <atlctl.h>

#include <msxml.h>

//States of the WSHttpRequest 
#define WSREQUEST_UNINITIALIZED   0
#define WSREQUEST_OPENED          1	
#define WSREQUEST_LOADED          2
#define WSREQUEST_INTERACTIVE     3
#define WSREQUEST_COMPLETED       4

//values for options
#define WSREQUEST_OPT_WSA_ACTION	"action"
#define WSREQUEST_OPT_WSA_REPLY_TO	"replyTo"
#define WSREQUEST_OPT_WSA_FROM		"from"
#define WSREQUEST_OPT_WSA_FAULT_TO	"faultTo"

#define WSREQUEST_OPT_USE_WSA		"useWSA"
#define WSREQUEST_OPT_USE_SOAP		"useSOAP"
#define WSREQUEST_OPT_HTTP_METHOD	"HTTPMethod"

#define WSREQUEST_11				"1.1"
#define WSREQUEST_12				"1.2"
#define WSREQUEST_CAPITAL_FALSE		"FALSE"
#define WSREQUEST_SIMPLE_FALSE		"false"
#define WSREQUEST_CAPITAL_TRUE		"TRUE"
#define WSSREQEST_SIMPLE_TRUE		"true"
#define WSREQUEST_CAPITAL_POST		"POST"
#define WSREQUEST_CAPITAL_GET		"GET"
#define WSREQUEST_SIMPLE_POST		"post"
#define WSREQUEST_SIMPLE_GET		"get"
#define WSREQUEST_WSA_10			"1.0"


/**
The below two functions are defined as global functions because the AXIS2/c api require these 
functions in the callback situation. 
*/
/* callback function for reporting complete of operation*/
axis2_status_t AXIS2_CALL callback_on_complete(struct axis2_callback *callback,const axis2_env_t *env);

/* calllback function for reporting errors*/
axis2_status_t AXIS2_CALL callback_on_error(struct axis2_callback *callback,const axis2_env_t *env,int exception);


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif


/**
The IWSRequest implementation. This class is inherited from IDispatch. So the 
methods will be available by scripting clients. The class extends from 
ISupportError info for reporting errors.
*/
class ATL_NO_VTABLE CWSRequest :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CWSRequest, &CLSID_WSRequest>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CWSRequest>,
	public CProxy_IWSRequestEvents<CWSRequest>,
	public IDispatchImpl<IWSRequest, &IID_IWSRequest, &LIBID_WSO2Lib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IObjectSafetyImpl<CWSRequest, INTERFACESAFE_FOR_UNTRUSTED_CALLER | INTERFACESAFE_FOR_UNTRUSTED_DATA>
{
public:
	CWSRequest();

DECLARE_REGISTRY_RESOURCEID(IDR_WSREQUEST)

BEGIN_COM_MAP(CWSRequest)
	COM_INTERFACE_ENTRY(IWSRequest)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CWSRequest)
	CONNECTION_POINT_ENTRY(__uuidof(_IWSRequestEvents))
END_CONNECTION_POINT_MAP()
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

private:
	// represent weather the current request id synchronus or asynchronous
	BOOL m_IsAsync;

	// end point address
	axis2_char_t *m_pEndPointAddress;

	// Represents the ready state of the object. It can take values 0-4
	SHORT m_ReadyState;

	// Pointer to the onready state change function.
	CComPtr<IDispatchEx> m_pOnreadyDispEx;

	// Client home variable
	axis2_char_t m_pClientHome[256];	

	/**
	Store the properties by property name	
	These are the acceptable key value pairs
	
	key			values
	
	useSOAP		"1.1" , "1.2", "TRUE"
	useWSA		"TRUE", "FALSE", "1.0"
	
	action		action uri
	replyTo		reply to uri
	faultTo		fault to uri
	from		from uri
	*/
	CSimpleMap<CComBSTR, CComBSTR> m_PropertyMap_D;

	// Response is converted to text and stored here.
	char *m_pResponseText;	

	// Represent the HRESULT for reporting a invalid state exception.
	HRESULT E_INVALID_STATE;
public:
	/**
	This method initializes the WSRequest Object. And set the appropriate paremeters.
	The first argument can be IDispatchEx or BSTR.
	If another type of argument is specified a error will be throwm.
	Last Three arguments are optional.
	sUrl must be a valid URI
	*/
	STDMETHOD(open)(VARIANT *method, BSTR sUrl, VARIANT async, VARIANT sUserName, VARIANT sPasswd);

	/**
	Get the event listerner for ready state change.
	Event listerner for ready state change. If the state of the method is changes as 
	replected in the ready state property, the listerner registered will be fired.
	The user should always use a this listener to check weather the responce has arived.
	*/
	STDMETHOD(get_onreadystatechange)(VARIANT* pVal);

	/**
	Set the Event listerner for ready state change.
	Event listerner for ready state change. If the state of the method is changes as 
	replected in the ready state property, the listerner registered will be fired.
	The user should always use a this listener to check weather the responce has arived.
	*/
	STDMETHOD(put_onreadystatechange)(VARIANT newVal);

	/**
	Send the payload to the destination URI specified in the Open method. 
	If async is true in the Open method this method will return immediately. 
	Otherwise the method will not return untill it receives the responce or stack timed out. 
	payload can be a valid XML string or a XML Dom document.
	*/
	STDMETHOD(send)(VARIANT payLoad);

	/**
	When the responce has arrived it can be retrived as a XML string via this property.
	This represents a valid value only when the state of the object is 4.
	Otherwise it will be null.
	Method return a BSTR value.
	*/
	STDMETHOD(get_responseText)(BSTR* pVal);

	/**
	When the responce has arrived it can be retrived as a XML Dom Document via this property.
	This represents a valid value only when the state of the object is 4.
	Otherwise it will be null.
	The method returns a IXMLDomDocument
	*/
	STDMETHOD(get_responseXML)(VARIANT* pVal);
	
	/**
	Represent the state of the object. These are the possible values.
	0 Uninitialized The initial state of the object.
	1 Open			After invoking the Open ( ) method successfully.
	2 Sent			The user agent has successfully acknowledged the request.
	3 Receiving		Part of the message has been received.
	4 Loaded		The data transfer has been completed.
	*/
	STDMETHOD(get_readyState)(SHORT* pVal);

	/**
	This method is exposed by the IDsispatch interface. But it is not availvable throgh 
	scripting labguages.
	*/
	STDMETHOD(change)(VARIANT newVal);
private:
	/**
	Set the m_pClientHome variable. We are giving the axis2c libs with the activex control.
	So this method will find this axis2 files and set the client home accordingly.
	*/
	HRESULT SetAxis2Home();
	/**
	Store the properties specified in the javascript object in an Map.
	Key will be the associative array key and value will be the associative array value.
	This method assume that the JScript array is passed as a Dispatch interface and query 
	it for values. If ohter than a Dispatch interface is given to this method it will fail.
	*/
	STDMETHOD(InitializeProperties)(VARIANT *varParams);

	/**
	Get options using the key. Key is in accordance with the options specified in the API.
	The returened value is of type VARIANT. 
	*/
	HRESULT GetOptionsByKey(BSTR key,BSTR *retVal);

	/**
	Change the ready state to the given state. The state must be 1 - 4 inclusive. The method also invoke the listening me
	*/
	HRESULT ChangeReadyState(int state);

	/**
	When the payload is give as a string or IXMLDomDocument it will be processed by this 
	function and return a character string.
	*/
	HRESULT GetStringFromBody(VARIANT *body, CHAR **retVal);

	/**
	This is a utility function converts the given string to a OM node.	
	*/
	HRESULT GetOMFromText(CHAR *body, axiom_node_t **retVal, axis2_env_t *pEnv);

	/**
	Invoke the web service client api. 
	This method is responsible for sending the request and handle the responces. 
	*/
	HRESULT InvokeWS( axiom_node_t* cont_node, axis2_env_t* pEnv );

	/**
	Set the options. These options are specified in the API document.
	Options will be set according to the values stored in the m_PropertyMap_D map.
	*/
	HRESULT SetOptions( axis2_options_t *options , axis2_svc_client_t* svc_client, axis2_env_t *pEnv);
	
	/**
	Private method for resetting the object. This will be calle by the Open method.
	All the member variables will be set to their defaults, except the m_pOnReadyStateChange.
	*/
	HRESULT Reset(void);

	/**
	This method adds the options to the m_PropertyMap_D. The options come as a <BSTR,VARIANT> 
	key-value pairs. But the map is defined to hold <BSTR,BSTR>. So the Variant types 
	are converted to strings before storing in the map. 
	This method return error codes if the options are not in accordance with the specification.
	*/
	HRESULT AddOptions(BSTR bstrName, VARIANT *vValue);
};
OBJECT_ENTRY_AUTO(__uuidof(WSRequest), CWSRequest)