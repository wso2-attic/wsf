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

#include "stdafx.h"
#include "WSRequest.h"
#include "WSRException.h"
#include "resource.h"
#include "WSO2.h"

#define MODULE_NAME		"WSRequest.dll"
#define MODULE_PATH_END "\\lib\\WSRequest.dll"

HMODULE h;

class CWSO2Module : public CAtlDllModuleT< CWSO2Module >
{
public :
	DECLARE_LIBID(LIBID_WSO2Lib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_WSO2, "{5F4EC9C6-B4E0-4E74-9FE2-02B284D172C9}")
};

CWSO2Module _AtlModule;


#ifdef _MANAGED
#pragma managed(push, off)
#endif

// DLL Entry Point
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	hInstance;
	h = hInstance;
    return _AtlModule.DllMain(dwReason, lpReserved); 
}

#ifdef _MANAGED
#pragma managed(pop)
#endif


// Used to determine whether the DLL can be unloaded by OLE
STDAPI DllCanUnloadNow(void)
{
    return _AtlModule.DllCanUnloadNow();
}


// Returns a class factory to create an object of the requested type
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _AtlModule.DllGetClassObject(rclsid, riid, ppv);
}


// DllRegisterServer - Adds entries to the system registry
STDAPI DllRegisterServer(void)
{
    // registers object, typelib and all interfaces in typelib
    HRESULT hr = _AtlModule.DllRegisterServer();
	return hr;
}


// DllUnregisterServer - Removes entries from the system registry
STDAPI DllUnregisterServer(void)
{
	HRESULT hr = _AtlModule.DllUnregisterServer();
	return hr;
}


STDMETHODIMP CWSRequest::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IWSRequest
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}


CWSRequest::CWSRequest(): m_IsAsync(TRUE), m_ReadyState(WSREQUEST_UNINITIALIZED), m_pEndPointAddress(NULL),
					m_pOnreadyDispEx(NULL), m_PropertyMap_D()
					
{
	HRESULT hr = S_OK;
	// Default to true
	m_IsAsync = TRUE;

	m_ReadyState = WSREQUEST_UNINITIALIZED;			
	
	//m_pClientHome = (char *)malloc(sizeof(char)* 256);
	//_dupenv_s(&m_pClientHome, NULL, "AXIS2C_HOME");
	hr = SetAxis2Home();
	// axis2c home find failed. So exit.
	if(FAILED(hr))
		WSRException::DispatchError(E_FAIL, CLSID_WSRequest, 
				L"Couldn't find the initialization libraries : Initialization failed");
	
	//create the custom HRESULT types for INVALID STATE
	E_INVALID_STATE = MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0200);	
}



HRESULT CWSRequest::Reset(void)
{
	m_IsAsync = TRUE;

	ChangeReadyState(WSREQUEST_UNINITIALIZED);

	if (m_pEndPointAddress)
		free(m_pEndPointAddress);
	m_pEndPointAddress = NULL;

	m_PropertyMap_D.RemoveAll();
	return S_OK;
}

HRESULT CWSRequest::SetAxis2Home()
{
	wchar_t name[256];
	char tempName[256];
	char mName[256];
	char *a = NULL;
	int i = 0;
	size_t size = 0;
	
	GetModuleFileName(h, name, 256);
	wcstombs(tempName, name, 256);

	a = strstr(tempName, MODULE_PATH_END); 
	if (!a){
		//Retrive the AXIS2C_HOME environment variable
		//Use the library function instead of axis getenv function becuase it 
		//is depreciated	
		char *envHome = NULL;
		_dupenv_s(&envHome, &size, "AXIS2C_HOME");	
		strcpy(m_pClientHome, envHome);		
		return S_OK;
	}
	// Check for the prefix \\?\ this prefix may be in the begining of the filename.
	else if (strlen(tempName) > 4 && tempName[0] == '\\' && tempName[1] == '\\' && tempName[2] == '?' && tempName[3] == '\\'){
		i = 3;
		while(tempName[i] != '\0' && (tempName + i) < a){
			mName[i] = tempName[i];		
			i++;
		}
		mName[i] = '\0';
	}else{
		i= 0;
		while(tempName[i] != '\0' && (tempName + i) < a){
			mName[i] = tempName[i];
			i++;
		}
		mName[i++] = '\0';
	}
	strcpy(m_pClientHome, mName);	
	return S_OK;
}


STDMETHODIMP CWSRequest::open(VARIANT *method, BSTR sUrl, VARIANT bAsync, VARIANT sUserName, VARIANT sPasswd)
{		
	HRESULT hr;
	if (m_ReadyState == 2 || m_ReadyState == 3)
		return WSRException::DispatchError(E_INVALID_STATE, CLSID_WSRequest, _T("Invalid State"));

	if (method->vt != VT_BSTR && method->vt != VT_DISPATCH)
		return WSRException::DispatchError(E_INVALIDARG, CLSID_WSRequest, _T("Invalid first argument"));

	if (sUrl == NULL)
		return WSRException::DispatchError(E_INVALIDARG, CLSID_WSRequest, _T("Invalid second argument"));

	hr = Reset();
	// Get the value for async
	if (bAsync.vt == VT_BOOL){
		if(bAsync.boolVal == VARIANT_TRUE)
			m_IsAsync = true;
		if(bAsync.boolVal == VARIANT_FALSE)
			m_IsAsync = false;
	}

	char *temp = _com_util::ConvertBSTRToString(sUrl);
	m_pEndPointAddress = _strdup(temp);

	// Initialize the options from the first argument
	// This will add the key value pairs to the m_propertyMap_D
	hr = InitializeProperties(method);

	if (FAILED(hr))
		return WSRException::DispatchError(E_INVALIDARG, CLSID_WSRequest, _T("Invalid first argument"));
	
	ChangeReadyState(WSREQUEST_OPENED);	
	return S_OK;					
}


STDMETHODIMP CWSRequest::InitializeProperties(VARIANT *varParams)
{
	//if not VT_DISPATCH or VT_BSTR then return.
	if(varParams->vt != VT_DISPATCH && varParams->vt != VT_BSTR)
		return E_INVALIDARG;

	if (varParams->vt == VT_BSTR){
		if (_tcscmp(OLE2T(varParams->bstrVal), _T(WSREQUEST_CAPITAL_POST)) == 0){			
			m_PropertyMap_D.Add(_T(WSREQUEST_OPT_USE_SOAP),_T(WSREQUEST_CAPITAL_TRUE));
			return S_OK;
		}	
		else if (_tcscmp(OLE2T(varParams->bstrVal), _T(WSREQUEST_CAPITAL_GET)) == 0){			
			m_PropertyMap_D.Add(_T(WSREQUEST_OPT_USE_SOAP),_T(WSREQUEST_CAPITAL_FALSE));			
			m_PropertyMap_D.Add(_T(WSREQUEST_OPT_HTTP_METHOD), _T(WSREQUEST_CAPITAL_GET));
			return S_OK;
		}
		else
			return E_INVALIDARG;
	}
	
	// Check for the associative array
	if (varParams->vt == VT_DISPATCH){
		//get the IDispatchEx of varParams
		CComPtr<IDispatchEx> pDispEx;
		HRESULT hr = varParams->pdispVal->QueryInterface(IID_IDispatchEx, (void**)&pDispEx);

		if(FAILED(hr))
			return E_INVALIDARG;

		//Enum all the properties of the jscript array.
		DISPID dispid;

		//get the DISPID of the first item.  
		hr = pDispEx->GetNextDispID(fdexEnumAll, DISPID_STARTENUM, &dispid);

		CComVariant vValue ;
		while (hr == NOERROR)
		{
			VariantInit ( &vValue);
			//get the item name
			CComBSTR bstrName;

			hr = pDispEx->GetMemberName(dispid, &bstrName);
			if (FAILED(hr))
				return E_FAIL;

			//get the item value
			DISPPARAMS dispparamsNoArgs = {NULL, NULL, 0, 0};

			hr = pDispEx->InvokeEx(dispid, LOCALE_USER_DEFAULT,
				DISPATCH_PROPERTYGET, &dispparamsNoArgs,
				&vValue, NULL, NULL);

			if(FAILED(hr))
				return E_FAIL;

			//Add to the property map
			hr = AddOptions(bstrName, &vValue);
			//get the DISPID of the next item. 
			hr = pDispEx->GetNextDispID(fdexEnumAll, dispid, &dispid);
		}
	}
	return S_OK;
}

HRESULT CWSRequest::AddOptions(BSTR bstrName, VARIANT *pvValue)
{
	switch(pvValue->vt){
		// If value is a BSTR one directly add it to the property map.
		case VT_BSTR:
			m_PropertyMap_D.Add(bstrName, pvValue->bstrVal);
			break;
		// If value is a boolean value it is specifiyng useSOAP or use useWSA
		case VT_BOOL:
			if (_tcscmp(OLE2T(bstrName), _T(WSREQUEST_OPT_USE_SOAP)) == 0 || _tcscmp(OLE2T(bstrName), _T(WSREQUEST_OPT_USE_WSA)) == 0){
				if (pvValue->boolVal == VARIANT_FALSE){
					m_PropertyMap_D.Add(bstrName, _T(WSREQUEST_CAPITAL_FALSE));  
				}
				else if (pvValue->boolVal == VARIANT_TRUE){
					m_PropertyMap_D.Add(bstrName, _T(WSREQUEST_CAPITAL_TRUE));
				}
				else
					return E_FAIL;					
			}
			break;
		// If the value is of type floating point numbers it is specifying useSOAP or use wsa value.
		case VT_R8:
		case VT_R4:
			if (_tcscmp(OLE2T(bstrName), _T(WSREQUEST_OPT_USE_SOAP)) == 0 ){
				if (pvValue->dblVal < 1.11 && pvValue->dblVal > 1.09)   
					m_PropertyMap_D.Add(bstrName, _T(WSREQUEST_11));
				else if (pvValue->dblVal < 1.21 && pvValue->dblVal > 1.19)
					m_PropertyMap_D.Add(bstrName, _T(WSREQUEST_12));
				else
					return E_FAIL;
			}
			if (_tcscmp(OLE2T(bstrName), _T(WSREQUEST_OPT_USE_WSA)) == 0 ){
				if (pvValue->dblVal > .99 && pvValue->dblVal < 1.01){
					m_PropertyMap_D.Add(bstrName, _T(WSREQUEST_WSA_10));									
				}							
			}
			break;
		// If the value is of integer type it can be useWSA option.
		case VT_I4:
		case VT_I8:
			if (_tcscmp(OLE2T(bstrName), _T(WSREQUEST_OPT_USE_WSA)) == 0 ){
				if (pvValue->intVal == 1){
					m_PropertyMap_D.Add(bstrName, _T(WSREQUEST_WSA_10));  				
				}	
			}
			break;
		default:
			break;
	}	
	return S_OK;
}


HRESULT CWSRequest::GetOptionsByKey(BSTR key, BSTR *retVal)
{
	// Get the index of specified key
	BSTR b;
	int keyIndex = m_PropertyMap_D.FindKey(key);

	// Check weather the key is in the Map
	if(keyIndex >= 0){
		b = m_PropertyMap_D.GetValueAt(keyIndex);
		*retVal = b;		
	}
	else
		return E_FAIL;			// Return unsuccessfull

	return S_OK;
}

STDMETHODIMP CWSRequest::get_onreadystatechange(VARIANT* pVal)
{
	if (m_pOnreadyDispEx){
		(*pVal).vt = VT_DISPATCH;
		(*pVal).pdispVal = m_pOnreadyDispEx;
	}
	return S_OK;
}

STDMETHODIMP CWSRequest::put_onreadystatechange(VARIANT newVal)
{
	//if not VT_DISPATCH then return.
	if(newVal.vt != VT_DISPATCH)
		return E_INVALIDARG;

	if(m_pOnreadyDispEx)
		m_pOnreadyDispEx.Release();

	//get the IDispatchEx of varParams
	HRESULT hr = newVal.pdispVal->QueryInterface(IID_IDispatchEx, (void**)&m_pOnreadyDispEx);
	newVal.pdispVal->Release();

	if (FAILED(hr))
		return E_INVALIDARG;

	return S_OK;
}

HRESULT CWSRequest::ChangeReadyState(int state)
{

	// Check for the validity of the state
	if(state >= 0 && state < 5){
		m_ReadyState = state;
	}
	else{
		return E_INVALIDARG;
	}
	Fire_ReadyStateChange(state);

	DISPPARAMS dispparams = {NULL, NULL, 0, 0};
	VARIANT var;
	HRESULT hr = E_FAIL;

	// Invoke the method that listens for the ready state changes. 
	if(m_pOnreadyDispEx){
		hr = m_pOnreadyDispEx->InvokeEx(0, LOCALE_USER_DEFAULT, DISPATCH_METHOD, 
			&dispparams, &var, NULL, NULL);
	}

	if(FAILED(hr)){
		return E_FAIL;
	}
	return S_OK;
}



STDMETHODIMP CWSRequest::send(VARIANT payLoad)
{
	HRESULT hr;
	CHAR *body = NULL;
	axiom_node_t *pContNode = NULL;
	char logDir[256]; 
	if (m_ReadyState == 0 || m_ReadyState == 2 || m_ReadyState == 3)
		return WSRException::DispatchError(E_INVALID_STATE, CLSID_WSRequest, 
				_T("Invalid state. Ready state must be 1 or 4 to send"));

	strcpy(logDir, m_pClientHome);
	strcat(logDir, "\\logs\\WSRequest_1.log"); 
	// Create the axis2 environment to use in all the circumstances.
	axis2_env_t *pEnv = axis2_env_create_all(logDir, AXIS2_LOG_LEVEL_DEBUG);

	hr = GetStringFromBody(&payLoad , &body);
	
	if (FAILED(hr))
		return WSRException::DispatchError(E_INVALIDARG, CLSID_WSRequest, 
				_T("Invalid argument"));

	hr = GetOMFromText(body, &pContNode, pEnv);

	if (FAILED(hr)){
		return WSRException::DispatchError(E_INVALIDARG, CLSID_WSRequest, 
				_T("Invalid argument"));
	}

	ChangeReadyState(WSREQUEST_LOADED);	

	// This method will create the service client and send
	InvokeWS(pContNode, pEnv);

	if (body)
		free(body);

	body = NULL;
	return S_OK;
}

HRESULT CWSRequest::GetStringFromBody(VARIANT *body, CHAR **retVal)
{
    CHAR *bodyChar = NULL;
	BSTR b;
	VARTYPE vt = body->vt;
	int i = 0;
	// Dispatch interface of the MSXML document
	CComPtr<IDispatchEx> dispEx;

	HRESULT hr;

	// Represent the property name for converting XML to string
	BSTR xmlName=::SysAllocString(L"xml");	

	// Represent the member name
	BSTR xmlDocumentElementName= ::SysAllocString(L"documentElement");	

	switch(vt){
		case VT_BSTR:
			b = ::SysAllocString(body->bstrVal);
			bodyChar = _com_util::ConvertBSTRToString(b);
			::SysFreeString(b);
			break;

		case VT_DISPATCH:	
			// Query the supplied interface for dispatch interface
			if (!body->pdispVal)
				return E_FAIL;

			hr = body->pdispVal->QueryInterface(IID_IDispatchEx, (void **)&dispEx);
			
			if(FAILED(hr)){
				return E_FAIL;
			}
			// Dispatch ID for document element
			DISPID dpIdXML;
			DISPPARAMS dispparams2 = {NULL, NULL, 0, 0};
			VARIANT xmlVariant;
			// Get the dispId of the root element property "xml"
			hr = dispEx->GetDispID(xmlName, 0, &dpIdXML);

			if(FAILED(hr)){
				return E_FAIL;
			}
			
			// Invoke the xml property of the root element and put the retrieved string in xmlVariant
			hr = dispEx->InvokeEx(dpIdXML, LOCALE_USER_DEFAULT,
				DISPATCH_PROPERTYGET, &dispparams2,
				&xmlVariant, NULL, NULL);

			if(FAILED(hr)){
				return E_FAIL;
			}
			
			// convert the retrieved BSTR value to a char *
			if(xmlVariant.vt == VT_BSTR){
				bodyChar = _com_util::ConvertBSTRToString(xmlVariant.bstrVal);
			}			
			
			break;	
	}

	// Free the objects
	::SysFreeString(xmlName);
	::SysFreeString(xmlDocumentElementName);
	
	*retVal = bodyChar;
	return S_OK;
}

HRESULT CWSRequest::GetOMFromText(CHAR *body, axiom_node_t **retVal, axis2_env_t *pEnv)
{
	axiom_node_t *node = NULL;
	axiom_document_t *document = NULL;
	axiom_stax_builder_t *om_builder = NULL;
	axiom_xml_reader_t* xml_reader = NULL;
	
	//attaching the soap body
	if (body)
		xml_reader = axiom_xml_reader_create_for_memory( pEnv, body,
			(int)(strlen (body)), "utf-8", AXIS2_XML_PARSER_TYPE_BUFFER );

	if(!xml_reader)
		return E_FAIL;

	om_builder = axiom_stax_builder_create(pEnv, xml_reader);
	if(!om_builder)
	{
		AXIOM_XML_READER_FREE(xml_reader, pEnv);
		return E_FAIL;
	}

	document = AXIOM_STAX_BUILDER_GET_DOCUMENT(om_builder, pEnv);
	if(!document)
	{
		AXIOM_STAX_BUILDER_FREE(om_builder, pEnv);
		return E_FAIL;
	}

	node = AXIOM_DOCUMENT_GET_ROOT_ELEMENT(document, pEnv);
	if (!node)
	{
		return E_FAIL;
	}

	AXIOM_DOCUMENT_BUILD_ALL ( document , pEnv );
	*retVal = node;

	if (xml_reader)
		AXIOM_XML_READER_FREE(xml_reader, pEnv);

	return S_OK;
}


HRESULT CWSRequest::InvokeWS( axiom_node_t* pContNode, axis2_env_t* pEnv)
{	
	axiom_node_t *pRetNode = NULL;
	axis2_options_t *pOptions = NULL;
	axis2_endpoint_ref_t* pEndpointRef = NULL;
	axis2_svc_client_t* pSvcClient = NULL;
	
	if (!pEnv){
		return E_FAIL;	
	}
	
	// If client home is not set
	if (!m_pClientHome){
		return E_FAIL;
	}
	// Create the service client
	pSvcClient = axis2_svc_client_create(pEnv, m_pClientHome);
	if (!pSvcClient){
		return E_FAIL;
	}

	// Create the options for AXIS
	pOptions = axis2_options_create(pEnv);
	if (!pOptions)
		return E_FAIL;

	if(!m_pEndPointAddress)
		return E_FAIL;

	// Set the end point address.
	pEndpointRef = axis2_endpoint_ref_create(pEnv, m_pEndPointAddress);
	if(!pEndpointRef)
		return E_FAIL;

	// Neccessary option, So set it here.
	AXIS2_OPTIONS_SET_TO( pOptions, pEnv, pEndpointRef );
	AXIS2_OPTIONS_SET_TIMEOUT_IN_MILLI_SECONDS(pOptions, pEnv, 10000);

	// Retrieve the options from m_propertyMap_D and set the options.
	SetOptions(pOptions, pSvcClient, pEnv);

	// set the options for service client.
	AXIS2_SVC_CLIENT_SET_OPTIONS(pSvcClient, pEnv, pOptions);

	// check for synchronous or asynchronous mode
	if (m_IsAsync){
		axis2_callback_t *callback = axis2_callback_create(pEnv);					
		// marshall the interface before giving it to the callback thread
		CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
		IUnknown*  pIUnknown = NULL;
		IStream*  pIStream = NULL;
		this -> QueryInterface (IID_IUnknown, (void**)&pIUnknown);
		if (pIUnknown)
		{
			::CoMarshalInterThreadInterfaceInStream(__uuidof(IWSRequest), pIUnknown, &pIStream);
			pIUnknown -> Release();
			pIUnknown = NULL;
		}
		// Set the on_complete and error callback functions 
		// Give the marshelled interface to call back as data
		AXIS2_CALLBACK_SET_DATA(callback, pIStream);
		AXIS2_CALLBACK_SET_ON_COMPLETE(callback ,callback_on_complete);		  			
		AXIS2_SVC_CLIENT_SEND_RECEIVE_NON_BLOCKING(pSvcClient, pEnv, pContNode, callback);

		ChangeReadyState(WSREQUEST_INTERACTIVE);
	}
	else{		
		// if synchrounous no worries. Just call and block until the data arrives.		
 		pRetNode = AXIS2_SVC_CLIENT_SEND_RECEIVE(pSvcClient, pEnv, pContNode);

		if (pRetNode)
			m_pResponseText = AXIOM_NODE_TO_STRING(pRetNode, pEnv);
		else
			m_pResponseText = NULL;
		
		ChangeReadyState(WSREQUEST_INTERACTIVE);
		ChangeReadyState(WSREQUEST_COMPLETED);				
	}
	return S_OK;			
}

STDMETHODIMP CWSRequest::get_responseText(BSTR* pVal)
{
	// If m_RetNode is valid convert its content to a BSTR and return it.
	if (m_pResponseText){
		*pVal = _com_util::ConvertStringToBSTR(m_pResponseText); 
	}
	return S_OK;
}

STDMETHODIMP CWSRequest::get_responseXML(VARIANT* pVal)
{
	// MSXML document for out value     
	IXMLDOMDocument *pXMlDomDoc = NULL;
	HRESULT hr;
	// Create a instance of the IXMLDocument
	hr =  CoCreateInstance(__uuidof(DOMDocument),NULL,CLSCTX_INPROC_SERVER,
                  __uuidof(IXMLDOMDocument),
                  (void**)&pXMlDomDoc);

	if(FAILED(hr))
		return E_FAIL;

	// Set the options for XMLDocument. No validation
	pXMlDomDoc->put_async(VARIANT_FALSE);
	pXMlDomDoc->put_resolveExternals(VARIANT_FALSE);
	pXMlDomDoc->put_validateOnParse(VARIANT_FALSE);
	

	// Convert the axiom node to string
	CComBSTR tempBstr = NULL;
	if(m_pResponseText)
		tempBstr = _com_util::ConvertStringToBSTR(m_pResponseText);
	else{
		V_VT( pVal ) = VT_DISPATCH;
		V_DISPATCH( pVal ) = NULL; 
		return S_FALSE;
	}

	VARIANT_BOOL isSuccessful;
	hr = pXMlDomDoc->loadXML( tempBstr, &isSuccessful );

	if(FAILED(hr))
		return E_FAIL;

	if(isSuccessful == VARIANT_FALSE)
		return E_FAIL;

	IXMLDOMElement *elem = NULL;
	hr = pXMlDomDoc->get_documentElement(&elem);

	(*pVal).vt = VT_DISPATCH;
	(*pVal).pdispVal = pXMlDomDoc;

	// Free the string
	::SysFreeString(tempBstr);
	return S_OK;
}

STDMETHODIMP CWSRequest::get_readyState(SHORT* pVal)
{
	*pVal = m_ReadyState;
	return S_OK;
}


HRESULT CWSRequest::SetOptions(axis2_options_t *options , axis2_svc_client_t* svc_client, axis2_env_t *pEnv)
{
	HRESULT hr;
	BSTR bstrSoap;
	BOOLEAN restEnabled = FALSE;
	// Set the soap related options
	hr = GetOptionsByKey(_T(WSREQUEST_OPT_USE_SOAP), &bstrSoap);
	if(SUCCEEDED(hr)){
		if (_tcscmp(OLE2T(bstrSoap), _T(WSREQUEST_11)) == 0){
			AXIS2_OPTIONS_SET_SOAP_VERSION ( options, pEnv, AXIOM_SOAP11);
		}
		else if ( _tcscmp(OLE2T(bstrSoap),_T(WSREQUEST_12)) == 0 ){
			AXIS2_OPTIONS_SET_SOAP_VERSION ( options, pEnv, AXIOM_SOAP12);
		}
		else if (_tcscmp (OLE2T (bstrSoap), _T(WSREQUEST_CAPITAL_FALSE)) == 0){
			AXIS2_OPTIONS_SET_PROPERTY(options, pEnv, AXIS2_ENABLE_REST, AXIS2_VALUE_TRUE);
			restEnabled = TRUE;
		}
		else if (_tcscmp (OLE2T (bstrSoap), _T(WSREQUEST_CAPITAL_TRUE)) == 0){
			AXIS2_OPTIONS_SET_PROPERTY(options, pEnv, AXIS2_ENABLE_REST, AXIS2_VALUE_FALSE);
		}
		else
			return E_FAIL;			
	}	
	else {
		// Set the default value
		AXIS2_OPTIONS_SET_SOAP_VERSION(options, pEnv, AXIOM_SOAP12) ;		
	}
	
	// Set the Http Method.
	BSTR bstrHttp;
	hr = GetOptionsByKey(_T(WSREQUEST_OPT_HTTP_METHOD), &bstrHttp);
	if(SUCCEEDED(hr)) {	
		if (_tcscmp(OLE2T(bstrHttp), _T(WSREQUEST_CAPITAL_GET)) == 0 || _tcscmp(OLE2T(bstrHttp), _T(WSREQUEST_SIMPLE_GET)) == 0){
			  AXIS2_OPTIONS_SET_PROPERTY(options, pEnv, AXIS2_HTTP_METHOD, AXIS2_HTTP_HEADER_GET);
		}							
		if (_tcscmp(OLE2T(bstrHttp), _T(WSREQUEST_CAPITAL_POST)) == 0 || _tcscmp(OLE2T(bstrHttp), _T(WSREQUEST_SIMPLE_POST)) == 0){
			  AXIS2_OPTIONS_SET_PROPERTY(options, pEnv, AXIS2_HTTP_METHOD, AXIS2_HTTP_HEADER_POST);
		}	
	}
	
	BSTR bstrWSA;
	BOOL m_AddressingOn = FALSE; 
	// Engage addressing
	hr = GetOptionsByKey(_T(WSREQUEST_OPT_USE_WSA),&bstrWSA);
	if (SUCCEEDED(hr)){
		if ( _tcscmp(OLE2T(bstrWSA), _T(WSREQUEST_WSA_10)) == 0 ||  _tcscmp(OLE2T(bstrWSA), _T(WSREQUEST_CAPITAL_TRUE)) == 0) {
			m_AddressingOn = TRUE;
			AXIS2_SVC_CLIENT_ENGAGE_MODULE(svc_client, pEnv, AXIS2_MODULE_ADDRESSING);				
		}		
	}
	
	BSTR bstrAction;
	// Set the action uri 
	BOOL setAction = FALSE;
	hr = GetOptionsByKey(_T(WSREQUEST_OPT_WSA_ACTION), &bstrAction);
	if(SUCCEEDED(hr) ){
		if(!m_AddressingOn){
			m_AddressingOn = TRUE;
			AXIS2_SVC_CLIENT_ENGAGE_MODULE(svc_client, pEnv, AXIS2_MODULE_ADDRESSING);
		}

		CHAR *action = _com_util::ConvertBSTRToString(bstrAction);
		AXIS2_OPTIONS_SET_ACTION(options, pEnv, action);
		setAction = TRUE;
		free(action);
	}
	
	BSTR bstrReplyTo;
	hr = GetOptionsByKey(_T(WSREQUEST_OPT_WSA_REPLY_TO), &bstrReplyTo);
	if( SUCCEEDED(hr) ){
		if (!setAction)
			return E_FAIL;
		//If addressing is not engaged no point in setting this option. So assume 
		//that addressing should be engaged		
		if(!m_AddressingOn){
			m_AddressingOn = TRUE;
			AXIS2_SVC_CLIENT_ENGAGE_MODULE(svc_client, pEnv, AXIS2_MODULE_ADDRESSING);
		}
		CHAR *reply_to = _com_util::ConvertBSTRToString(bstrReplyTo);
		AXIS2_OPTIONS_SET_REPLY_TO(options, pEnv, axis2_endpoint_ref_create(pEnv, reply_to));
		free(reply_to);		
	}
	
	BSTR bstrFrom;
	hr = GetOptionsByKey(_T(WSREQUEST_OPT_WSA_FROM), &bstrFrom);
	if(SUCCEEDED(hr) ){
		//Action must be specified
		if (!setAction)
			return E_FAIL;
		//If addressing is not engaged no point in setting this option. So assume 
		//that addressing should be engaged		
		if(!m_AddressingOn){
			m_AddressingOn = TRUE;
			AXIS2_SVC_CLIENT_ENGAGE_MODULE(svc_client, pEnv, AXIS2_MODULE_ADDRESSING);
		}

		CHAR *from = _com_util::ConvertBSTRToString(bstrFrom);
		AXIS2_OPTIONS_SET_FROM(options, pEnv, axis2_endpoint_ref_create(pEnv,from));		
		free(from);
	}
	BSTR bstrFaultTo;
	hr = GetOptionsByKey (_T(WSREQUEST_OPT_WSA_FAULT_TO),&bstrFaultTo);
	if(SUCCEEDED(hr) ){
		// action must be specified
		if (!setAction)
			return E_FAIL;
		//If addressing is not engaged no point in setting this option. So assume 
		//that addressing should be engaged
		if(!m_AddressingOn){
			m_AddressingOn = TRUE;
			AXIS2_SVC_CLIENT_ENGAGE_MODULE(svc_client, pEnv, AXIS2_MODULE_ADDRESSING);
		}

		CHAR *fault_to = _com_util::ConvertBSTRToString(bstrFaultTo);
		AXIS2_OPTIONS_SET_FAULT_TO(options, pEnv, axis2_endpoint_ref_create(pEnv, fault_to));		
		free(fault_to);
	}	
	return S_OK;
}

/**
Private internal method for dealing with the Call back situation. This 
function is called by the call back thread. To enable this methid to 
be called by a seperate thread this method is part of the interface. 
But it is declared restricted to avoid it from calling by the scripts.
*/
STDMETHODIMP CWSRequest::change(VARIANT newVal)
{
	CoInitializeEx(NULL, COINIT_MULTITHREADED);
	HRESULT hr;
	
	hr = GetStringFromBody(&newVal, &m_pResponseText);	

	// Invoke the method that listens for the ready state changes.
	DISPPARAMS dispparams = {NULL, NULL, 0, 0};

	if (m_pOnreadyDispEx){
		// Change the ready state
		m_ReadyState = 4;

		//Invoke the listening method of JScript
		hr = m_pOnreadyDispEx->InvokeEx(0, LOCALE_USER_DEFAULT, 
			DISPATCH_METHOD, &dispparams, NULL, NULL, NULL);
	}

	if(FAILED(hr)){
		return E_FAIL;
	}
	return S_OK;
}

axis2_status_t AXIS2_CALL callback_on_complete(struct axis2_callback *callback , const axis2_env_t *env)
{
    /** SOAP response has arrived here; get the soap envelope*/
   	axiom_soap_envelope_t *soap_envelope = NULL;
	axis2_status_t status = AXIS2_SUCCESS;
	axiom_node_t *ret_body_node = NULL;
	axiom_soap_body *ret_node = NULL;
	VARIANT pVal;

	VariantInit(&pVal);
	// Thread marshaling
	::CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
	IStream *pStream = NULL; 

	// Retrieve the IStream from the call back
	LPSTREAM  pIStream = (LPSTREAM)AXIS2_CALLBACK_GET_DATA(callback);
	IWSRequest *ws = NULL;
	if (!pIStream)
		return AXIS2_FAILURE;

	// Create the WSHttpRequest interface
	::CoGetInterfaceAndReleaseStream( pIStream, __uuidof(IWSRequest), (void**)&ws);
	
	if(pStream)
		pStream->Release();

	// Get the soap envelop from the callback
	soap_envelope = AXIS2_CALLBACK_GET_ENVELOPE(callback, env);	

	if (!soap_envelope){
		if(ws){
			ws->change(pVal);
			ws->Release();
		}
	}

	if (soap_envelope){
		// Get the return node from the envelop
		ret_node = AXIOM_SOAP_ENVELOPE_GET_BODY(soap_envelope, env);

		CHAR *temp = NULL;
		ret_body_node = AXIOM_SOAP_BODY_GET_BASE_NODE(ret_node, env);
		axiom_node_t *payload = NULL;
		payload = AXIOM_NODE_GET_FIRST_CHILD(ret_body_node, env);
		if(ret_node)
			temp = AXIOM_NODE_TO_STRING(payload, env);

		// Convert the return node into an IXMLDocument and pass it to the WSHttpRequest
		IXMLDOMDocument *pXMlDomDoc = NULL;
		HRESULT hr;

		hr =  CoCreateInstance(__uuidof(DOMDocument),NULL,CLSCTX_INPROC_SERVER,
			__uuidof(IXMLDOMDocument),
			(void**)&pXMlDomDoc);

		if(FAILED(hr))
			return E_FAIL;

		pXMlDomDoc->put_async(VARIANT_FALSE);
		pXMlDomDoc->put_resolveExternals(VARIANT_FALSE);
		pXMlDomDoc->put_validateOnParse(VARIANT_FALSE);

		CComBSTR tempBstr = _com_util::ConvertStringToBSTR(temp);
		VARIANT_BOOL isSuccessful;

		hr = pXMlDomDoc->loadXML(tempBstr, &isSuccessful);

		if(FAILED(hr))
			return AXIS2_FAILURE;

		pVal.vt = VT_DISPATCH;
		pVal.pdispVal = pXMlDomDoc;
				
		if(ws){
			ws->change(pVal);
			ws->Release();
			ws = NULL;
		}

		if (pXMlDomDoc){
			pXMlDomDoc->Release();
			pXMlDomDoc = NULL;
		}
	}

	if (ret_body_node){
		AXIOM_NODE_FREE_TREE(ret_body_node, env);
		ret_body_node = NULL;
	}
	// Unmarshall the thread
	::CoUninitialize();
	return status;
}


