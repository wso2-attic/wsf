/*
* Copyright 2005,2006 WSO2, Inc. http://wso2.com
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

#include <WSFDefines.h>
#include <axutil_env.h>
#include <string>
#include <map>
#include <Process.h>
#include <MessageContext.h>
#include <axis2_endpoint_ref.h>
#include <axiom_soap.h>
#include <axiom.h>
using namespace wso2wsf;
using namespace std;

/**
* Create a message context

MessageContext::MessageContext(axis2_conf_ctx_t *conf, axis2_transport_in_desc_t *trans_in, axis2_transport_out_desc_t *trans_out)
{}
*/

/**
* Create message Context using the axis2_msg_ctx object                                                                     
*/
MessageContext::MessageContext(axis2_msg_ctx_t *msg_ctx)
{
	_msg_ctx = msg_ctx;
}

/**
* This method returns the WS-Addressing fault to address. Fault to address tells where to 
* send the fault in case there is an error.
* @return returns an string of the fault to endpoint 
*/
WSF_EXTERN std::string WSF_CALL MessageContext::getFaultTo()
{
	axis2_endpoint_ref_t *faultTo = NULL;
	faultTo = axis2_msg_ctx_get_fault_to(_msg_ctx, getEnv());
	if(faultTo)
	{
		return axis2_endpoint_ref_get_address(faultTo, getEnv());
	}
	else return NULL;
}

/**
* Gets WS-Addressing from endpoint. From address tells where the request came from.
* @return string of the from endpoint reference
*/
WSF_EXTERN std::string WSF_CALL MessageContext::getFrom()
{
	axis2_endpoint_ref_t *from = NULL;
	from = axis2_msg_ctx_get_fault_to(_msg_ctx, getEnv());
	if(from)
	{
		return axis2_endpoint_ref_get_address(from, getEnv());
	}
	else return NULL;

}

/**
* Checks if there is a SOAP fault on in flow.
* @return true if there is a fault, false otherwise
*/
WSF_EXTERN bool WSF_CALL MessageContext::getInFaultFlow()
{
	if(axis2_msg_ctx_get_in_fault_flow(_msg_ctx, getEnv()))
	{
		return true;
	}
	return false;
}

/**
* Gets the SOAP envelope associated with the MessageContex. If the MessageContex is an In Message
* Context, the SOAP Envelope will be the Request SOAP envelope. If the MessageContext is an out MessageContext,
* the returned SOAP Envelope will be a response message
* @return Pointer to an OMElement representing the SOAP Envelope
*/
WSF_EXTERN OMElement *WSF_CALL MessageContext::getSoapEnvelope()
{
	axiom_soap_envelope_t *envlope = NULL;
	envlope  = axis2_msg_ctx_get_soap_envelope(_msg_ctx, getEnv());
	if(envlope)
	{	
		axiom_node_t *envNode = axiom_soap_envelope_get_base_node(envlope, getEnv());
		if(envNode)
		{
			return new OMElement(NULL, envNode);
		}
	}
	return NULL;
}

/**
* Gets the SOAP envelope of the response.
* @return Pointer to an OMElement representing the SOAP Envelope
*/
WSF_EXTERN OMElement* WSF_CALL MessageContext::getResponseSoapEnvelope()
{
	axiom_soap_envelope_t *envlope = NULL;
	envlope  = axis2_msg_ctx_get_response_soap_envelope(_msg_ctx, getEnv());
	if(envlope)
	{	
		axiom_node_t *envNode = axiom_soap_envelope_get_base_node(envlope, getEnv());
		if(envNode)
		{
			return new OMElement(NULL, envNode);
		}
	}
	return NULL;
}

/**
* Gets the fault soap envelope 
* @return A pointer to an OMElement representing the SOAP Fault Envelope
*/
WSF_EXTERN OMElement* WSF_CALL MessageContext::getFaultSoapEnvelope()
{
	axiom_soap_envelope_t *envlope = NULL;
	envlope  = axis2_msg_ctx_get_fault_soap_envelope(_msg_ctx, getEnv());
	if(envlope)
	{	
		axiom_node_t *envNode = axiom_soap_envelope_get_base_node(envlope, getEnv());
		if(envNode)
		{
			return new OMElement(NULL, envNode);
		}
	}
	return NULL;
}
/**
* Gets message ID.
* @return message ID string corresponding to the message the message 
* context is related to
*/

WSF_EXTERN std::string WSF_CALL MessageContext::getMessageId()
{
	return axis2_msg_ctx_get_msg_id(_msg_ctx, getEnv());
}

/**
* Gets WS-Addressing reply to endpoint as a string. Reply to address tells where 
* the the response should be sent to.    
* @return return a string corresponding to the reply to endpoint uri
*/
WSF_EXTERN std::string WSF_CALL MessageContext::getReplyTo()
{
	axis2_endpoint_ref_t *endpoint = NULL;
	endpoint = axis2_msg_ctx_get_reply_to(_msg_ctx, getEnv());
	if(endpoint)
		return axis2_endpoint_ref_get_address(endpoint, getEnv());
	return NULL;
}

/**
* Gets process fault status.
* @return true if process fault is on, false otherwise
*/
WSF_EXTERN bool WSF_CALL MessageContext::getProcessFault()
{
	return true;
}

/**
* Checks if it is on the server side that the message is being dealt 
* with, or on the client side.
* @return true if it is server side, false otherwise
*/
WSF_EXTERN bool WSF_CALL MessageContext::getServerSide()
{
	if(axis2_msg_ctx_get_server_side(_msg_ctx,getEnv()))
		return true;
	return false;
}

/**
* Gets WS-Addressing to endpoint URL. To address tells where message should 
* be sent to.
* @return Returns the to Endpoint URI
*/
WSF_EXTERN std::string WSF_CALL MessageContext::getTo()
{
	axis2_endpoint_ref_t *endpoint = NULL;
	endpoint = axis2_msg_ctx_get_reply_to(_msg_ctx, getEnv());
	if(endpoint)
		return axis2_endpoint_ref_get_address(endpoint, getEnv());
	return NULL;

	return NULL;
}

/**
* Sets WS-Addressing fault to endpoint. Fault to address tells where 
* the fault message should be sent when there is an error.
* @param toUri To uri
* @return true if successful, false otherwise.
*/
WSF_EXTERN bool WSF_CALL MessageContext::setFaultTo(std::string toUri)
{

	return true;
}

/**
* Sets WS-Addressing from endpoint. From address tells where 
* the message came from.
* @return true on success, false otherwise
*/
WSF_EXTERN bool WSF_CALL setFrom(std::string toUri)
{
	return true;
}

/**
* Sets in fault flow status. 
* @param in_fault_flow true if there is a fault on in path, false otherwise
* @return true if success false otherwise
*/
WSF_EXTERN bool WSF_CALL MessageContext::setInFaultFlow(bool infault)
{
	return true;
}


/**
* Sets WS-Addressing reply to address indicating the location to which
* the reply would be sent.
* @param ReplyTo endpoint reference uri
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setReplyTo(std::string replyToUri)
{
	return true;
}

/**
* Sets the bool value indicating if it is the server side or the
* client side.
* @param server_side true if it is server side, false if it
* is client side
* @return true on success, else false
*/

WSF_EXTERN bool WSF_CALL MessageContext::setServerSide(bool serverSide)
{
	if(axis2_msg_ctx_set_server_side(_msg_ctx, getEnv(), serverSide))
		return true;
	return false;
}

/**
* Sets WS-Addressing to address.
* @param reference pointer to endpoint reference struct representing
* the address where the request should be sent to. message context
* assumes ownership of endpoint struct
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setTo(std::string toUri)
{
	return true;
}

/**
* Gets the bool value indicating if it is required to have a new thread
* for the invocation, or if the same thread of execution could be used.
*

* @return true if new thread is required, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::getNewThread_required()
{
	if(axis2_msg_ctx_get_new_thread_required(_msg_ctx,getEnv()))
		return true;
	return false;
}

/**
* Sets the bool value indicating if it is required to have a new thread
* for the invocation, or if the same thread of execution could be used.    
*

* @param new_thread_required true if a new thread is required, 
* else false
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setNewThreadRequired(bool newThreadRequired)
{
	if(axis2_msg_ctx_set_new_thread_required(_msg_ctx, getEnv(), newThreadRequired))
		return true;
	return false;
}

/**
* Sets WS-Addressing action. 
*

* @param action_uri WSA action URI string
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setWSAAction(std::string actionUri)
{
	if(axis2_msg_ctx_set_wsa_action(_msg_ctx, getEnv(), actionUri.c_str()))
		return true;
	return false;
}

/**
* Gets WS-Addressing action.
*

* @return pointer to WSA action URI string
*/
WSF_EXTERN std::string WSF_CALL MessageContext::getWSAAction()
{
	return axis2_msg_ctx_get_wsa_action(_msg_ctx, getEnv());
}

/**
* Sets WS-Addressing message ID.
*

* @param message_id pointer to message ID string
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setWSAMessageId(std::string messageId)
{
	if(axis2_msg_ctx_set_wsa_message_id(_msg_ctx, getEnv(), messageId.c_str()))
		return true;
	return false;
}

/**
* Gets WS-Addressing message ID. 
*

* @return WSA message ID string
*/
WSF_EXTERN std::string WSF_CALL MessageContext::getWSAMessageId()
{
	return axis2_msg_ctx_get_msg_id(_msg_ctx, getEnv());
}

/**
* Gets the bool value indicating the paused status. It is possible 
* to pause the engine invocation by any handler. By calling this method
* one can find out if some handler has paused the invocation.
*
* @return true if message context is paused, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::isPaused()
{
	if(axis2_msg_ctx_is_paused(_msg_ctx, getEnv()))
		return true;
	return false;
}

/**
* Sets the bool value indicating the paused status of invocation.
*
* @param paused paused
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setPaused(bool paused)
{
	return true;
}

/**
* Gets the bool value indicating the keep alive status. It is possible 
* to keep alive the message context by any handler. By calling this method
* one can see whether it is possible to clean the message context.
*

* @return true if message context is keep alive, else false
*/

WSF_EXTERN bool WSF_CALL MessageContext::isKeepAlive()
{
	return true;
}

/**
* Sets the bool value indicating the keep alive status of invocation.
* By setting this one can indicate the engine not to clean the message 
* context.
*

* @param keep_alive keep alive
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setKeepAlive(bool keepAlive)
{
	return true;
}

/**
* Gets the bool value indicating the output written status. 
*
* @return true if output is written, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::getOutputWritten()
{
	return true;
}

/**
* Sets the bool value indicating the output written status. 
*
* @param output_written true if output is written, else false
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setOutputWritten(bool outputWritten)
{
	return true;
}

/**
* Gets the HTTP Method that relates to the service that is 
* related to the message context.
*

* @return HTTP Method string, returns a reference,
* not a cloned copy
*/
WSF_EXTERN std::string WSF_CALL MessageContext::getRestHTTPMethod()
{
	return NULL;
}

/**
* Sets the HTTP Method that relates to the service that is 
* related to the message context.
*
* @param rest_http_method HTTP Method string, msg_ctx does not assume
* ownership of rest_http_method.
* @return true on success, else false
*/
WSF_EXTERN axis2_status_t WSF_CALL MessageContext::setRESTHTTPMethod(std::string HTTPMethod)
{
	return true;
}

/**
* Gets configuration descriptor parameter with given key. This method 
* recursively search the related description hierarchy for the parameter 
* with given key until it is found or the parent of the description 
* hierarchy is reached. The order of search is as follows:
* \n
* 1. search in operation description, if its there return
* \n
* 2. if the parameter is not found in operation or operation is NULL, 
* search in service
* \n
* 3. if the parameter is not found in service or service is NULL search 
* in configuration
*

* @param key parameter key  
* @return pointer to parameter struct corresponding to the given key
*/
WSF_EXTERN Parameter *WSF_CALL MessageContext::getParameter(std::string key)
{
	return NULL;
}

/**
* Gets parameters related to a named module and a given handler 
* description. The order of searching for parameter is as follows:
* \n
* 1. search in module configuration stored inside corresponding operation 
* description if its there
* \n
* 2. search in corresponding operation if its there
* \n
* 3. search in module configurations stored inside corresponding 
* service description if its there
* \n
* 4. search in corresponding service description if its there
* \n
* 5. search in module configurations stored inside configuration
* \n
* 6. search in configuration for parameters
* \n
* 7. get the corresponding module and search for the parameters
* \n
* 8. search in handler description for the parameter


* @param key parameter key
* @param module_name name of the module
* @param handler_desc pointer to handler description
* @return pointer to parameter 

WSF_EXTERN axutil_param_t *WSF_CALL
axis2_msg_ctx_get_module_parameter(
const axis2_msg_ctx_t * msg_ctx,
const axutil_env_t * env,
const axis2_char_t * key,
const axis2_char_t * module_name,
axis2_handler_desc_t * handler_desc){}
*/

/**
* Gets property corresponding to the given key.

* @param key key string with which the property is stored
* @return pointer to property struct
*/
WSF_EXTERN Property *WSF_CALL MessageContext::getProperty(std::string key)
{
	return NULL;
}

/**
* Gets property value corresponding to the property given key.
* @param property_str key string with which the property is stored
* @return pointer to property struct
*/
WSF_EXTERN void* WSF_CALL MessageContext::getPropertyValue(std::string propStr)
{
	return NULL;
}

/**
* Sets property with given key.
*

* @param key key string
* @param value property to be stored
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setProperty(std::string key, std::string value)
{
	return true;
}

/**
* Gets the QName of the handler at which invocation was paused.
* @return pointer to QName of the paused handler
*/
WSF_EXTERN std::string WSF_CALL MessageContext::getPausedHandlerName()
{
	return NULL;
}

/**
* Gets the name of the phase at which the invocation was paused.
* @return name string of the paused phase.
*/
WSF_EXTERN std::string WSF_CALL MessageContext::getPausedPhaseName()
{
	return NULL;
}

/**
* Sets the name of the phase at which the invocation was paused.
* @param paused_phase_name paused phase name string
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setPausedPhaseName(std::string pausedPhaseName)
{
	return NULL;

}

/**
* Gets SOAP action.
* @return SOAP action string
*/
WSF_EXTERN std::string WSF_CALL MessageContext::getSOAPAction()
{
	axutil_string_t *action = NULL;
	action = axis2_msg_ctx_get_soap_action(_msg_ctx,getEnv());
	if(action)
	{
		return axutil_string_get_buffer(action, getEnv());
	}
	return NULL;
}

/**
* Sets SOAP action.
* @param soap_action SOAP action string
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setSOAPAction(std::string action){ return true;}

/**
* Gets the boolean value indicating if MTOM is enabled or not.
* @return true if MTOM is enabled, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::getDoingMTOM(){ return true;}

/**
* Sets the boolean value indicating if MTOM is enabled or not.
* @param doing_mtom true if MTOM is enabled, else false
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setDoingMTOM(bool doingMTOM){ return true;}

/**
* Gets the boolean value indicating if REST is enabled or not.
* @return true if REST is enabled, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::getDoingREST(){ return true;}

/**
* Sets the boolean value indicating if REST is enabled or not.
* @param doing_rest true if REST is enabled, else false
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setDoingREST(bool doingREST){ return true;}

/**
* Sets the boolean value indicating if REST should be done through 
* HTTP POST or not.
* @param do_rest_through_post true if REST is to be done with 
* HTTP POST, else false if REST is not to be done with HTTP POST
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setDoRESTThroughPOST(bool doREST){ return true;}

/**
* Sets the boolean value indicating if REST should be done through 
* HTTP POST or not.
* @return true if REST is to be done with HTTP POST, else 
* false if REST is not to be done with HTTP POST
*/
WSF_EXTERN bool WSF_CALL MessageContext::getDoRESTThroughPOST(){ return true;}

/**
* Gets manage session bool value.
* @return true if session is managed, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::getManageSession(){ return true;}

/**
* Sets manage session bool value.
* @param manage_session manage session bool value
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setManageSession(bool manageSession){ return true;}

/**
* Gets the bool value indicating the SOAP version being used either
* SOAP 1.1 or SOAP 1.2
* @return true if SOAP 1.1 is being used, else false if 
* SOAP 1.2 is being used
*/

WSF_EXTERN bool WSF_CALL MessageContext::getIsSOAP11(){ return true;}

/**
* Sets the bool value indicating the SOAP version being used either
* SOAP 1.1 or SOAP 1.2
* @param is_soap11 true if SOAP 1.1 is being used, else 
* false if SOAP 1.2 is being used
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setIsSOAP11(){ return true;}

/**
* Gets the options to be used in invocation.
* @return options pointer to options struct, message context does not 
* assume the ownership of the struct
*/
WSF_EXTERN Options* WSF_CALL MessageContext::getOptions(){ return NULL;}



/**
* Sets the options to be used in invocation.
* @param options pointer to options struct, message context does not 
* assume the ownership of the struct
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setOptions(Options options){ return true;}

/**
* Sets the flow to be invoked.
* @param flow int value indicating the flow
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setFlow(int flow){ return true;}

/**
* Gets the flow to be invoked.
* @return int value indicating the flow
*/
WSF_EXTERN int WSF_CALL MessageContext::getFlow(){ return 0;}


/**
* Sets the list of supported REST HTTP Methods
* @param supported_rest_http_methods pointer array list containing
* the list of HTTP Methods supported. Message context does
* assumes the ownership of the array list. Anything added to this
* array list will be freed by the msg_ctx
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setSupportedRESTHTTPMethods(std::vector<std::string> *methods){ return true;}

/**
* Gets the list of supported REST HTTP Methods 
* @return pointer array list containing
* the list of HTTP Methods supported. Message context does
* assumes the ownership of the array list
*/
WSF_EXTERN  std::vector<std::string>* WSF_CALL MessageContext::getSupportedRESTHTTPMethods(){ return NULL;}

/**
* Sets current handler index, indicating which handler is currently 
* being invoked in the execution chain
* @param index index of currently executed handler
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setCurrentHandlerIndex(int index){ return true;}

/**
* Gets current handler index, indicating which handler is currently 
* being invoked in the execution chain    
* @return index of currently executed handler
*/
WSF_EXTERN int WSF_CALL MessageContext::getCurrentHandlerIndex(){ return 0;}

/**
* Gets paused handler index, indicating at which handler the execution 
* chain was paused.
* @return index of handler at which invocation was paused
*/
WSF_EXTERN int WSF_CALL MessageContext::getPausedHandlerIndex(){ return 0;}

/**
* Sets index of the current phase being invoked.    
* @param index index of current phase
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setCurrentPhaseIndex(int index){ return true;}

/**
* Gets index of the current phase being invoked.    
* @return index of current phase
*/
WSF_EXTERN int WSF_CALL MessageContext::getCurrentPhaseIndex(){ return 0;}

/**
* Gets the phase at which the invocation was paused.
* @return index of paused phase
*/
WSF_EXTERN int WSF_CALL MessageContext::getPausedPhaseIndex(){ return 0;}

/**
* Gets character set encoding to be used.
* @return true on success, else false
*/
WSF_EXTERN std::string WSF_CALL MessageContext::getCharsetEncoding(){ return NULL;}

/**
* Sets character set encoding to be used.
* @param str pointer to string struct representing encoding
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setCharsetEncodingStng(std::string str){ return true;}


/**
* Gets the integer value indicating http status_code.
* @return status value
*/

WSF_EXTERN int WSF_CALL MessageContext::getStatusCode(){ return 0;}


/**
* Sets the int value indicating http status code
* @param status_code of the http response
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setStatusCode(int statusCode){ return true;}


/**
* Retrieves HTTP Accept-Charset records.
* @return HTTP Accept-Charset records associated.
*/
WSF_EXTERN std::vector<std::string>* WSF_CALL MessageContext::getHTTPAcceptCharsetRecordList(){ return NULL;}

/**
* Retrieves HTTP Accept-Charset records, and removes them
* from the message context
* @return HTTP Accept-Charset records associated.
*/
WSF_EXTERN std::vector<std::string>* WSF_CALL MessageContext::extractHTTPAcceptCharsetRecordList(){ return NULL;}

/**
* Sets the HTTP Accept-Charset records
* @param accept_charset_record_list an Array List containing the
* HTTP Accept-Charset records
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setHTTPAcceptCharsetRecordList(std::vector<std::string> *recordList){ return true;}

/**
* Retrieves HTTP Accept-Language records.
* @return HTTP Accept-Language records associated.
*/
WSF_EXTERN std::vector<std::string>* WSF_CALL MessageContext::getHTTPAcceptLanguageRecordList(){ return NULL;}

/**
* Retrieves HTTP Accept-Language records, and removes them
* from the message context
* @return HTTP Accept-Language records associated.
*/
WSF_EXTERN std::vector<std::string>* WSF_CALL MessageContext::extractHTTPAcceptLanguageRecordList(){ return NULL;}

/**
* Sets the HTTP Accept-Language records
* @param accept_language_record_list an Array List containing the
* HTTP Accept-Language records
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setHTTPAcceptLanguageRecordList(std::vector<std::string> *acceptLanguageRecordList){ return true;}

/**
* Gets the Content Language used
* @return Content Language string
*/
WSF_EXTERN std::string WSF_CALL MessageContext::getContentLanguage(){ return NULL;}

/**
* Sets the Content Language used
* @param str Content Language string
* @return true on success, else false
*/

WSF_EXTERN bool WSF_CALL MessageContext::setContentLanguage(std::string langauge){ return true;}

/**
* Retrieves HTTP Accept records.
* @return HTTP Accept records associated.
*/
WSF_EXTERN std::vector<std::string>* WSF_CALL MessageContext::getHTTPAcceptRecordList(){ return NULL;}

/**
* Retrieves HTTP Accept records, and removes them
* from the message context
* @return HTTP Accept records associated.
*/
WSF_EXTERN std::vector<std::string>* WSF_CALL MessageContext::extractHTTPAcceptRecordList(){ return NULL;}

/**
* Sets the HTTP Accept records
* @param accept_record_list an Array List containing the
* HTTP Accept records
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setHTTPAcceptRecordList(std::vector<std::string>* recordList){ return true;}

/**
* Gets the transfer encoding used
* @return Transfer encoding string
*/
WSF_EXTERN std::string WSF_CALL MessageContext::getTransferEncoding(){ return NULL;}

/**
* Sets the transfer encoding used
* @param str Transfer encoding string
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setTransferEncoding(std::string encoding){ return NULL;}

/**
* Gets the Transport URL
* @return Transport URL string
*/
WSF_EXTERN std::string WSF_CALL MessageContext::getTransportURL(){ return NULL;}

/**
* Sets the Transport URL
* @param str Transport URL string
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setTransportURL(std::string transportURL){ return true;}

/**
* Gets whether there was no content in the response.
* This will cater for a situation where the invoke
* method in a service returns NULL when no fault has
* occurred.
* @return returns true if there was no content
* occurred or false otherwise
*/
WSF_EXTERN bool WSF_CALL MessageContext::getNoContent(){ return true;}

/**
* Sets that there was no content in the response.
* @param no_content expects true if there was no
* content in the response or false otherwise
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setNoContent(bool noContent){ return true;}

/**
* Gets whether an authentication failure occurred
* @return returns true if an authentication failure
* occurred or false if not
*/
WSF_EXTERN bool WSF_CALL MessageContext::getAuthFailed(){ return true;}


/**
* Sets whether an authentication failure occurred
*

* @param status expects true if an authentication failure
* occurred or false if not
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setAuthFailed(bool status){ return true;}

/**
* Gets whether HTTP Authentication is required or
* whether Proxy Authentication is required
*

* @return returns true for HTTP Authentication
* and false for Proxy Authentication
*/
WSF_EXTERN bool WSF_CALL MessageContext::getRequiredAuthIsHTTP(){ return true;}

/**
* Sets whether HTTP Authentication is required or
* whether Proxy Authentication is required
* @param is_http use true for HTTP Authentication
* and false for Proxy Authentication
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setRequiredAuthIsHTTP(bool isHTTP){ return true;}

/**
* Sets the authentication type
* @param auth_type Authentication type string
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setAuthType(std::string authType)
{
	if(axis2_msg_ctx_set_auth_type(_msg_ctx, getEnv(),authType.c_str()))
		return true;
	return false;
}

/**
* Gets the authentication type
* @return Authentication type string
*/
WSF_EXTERN std::string WSF_CALL MessageContext::getAuthType()
{
	return axis2_msg_ctx_get_auth_type(_msg_ctx, getEnv());
}

/*
WSF_EXTERN axutil_array_list_t *WSF_CALL
axis2_msg_ctx_get_mime_parts(
axis2_msg_ctx_t * msg_ctx,
const axutil_env_t * env){}


WSF_EXTERN void WSF_CALL
axis2_msg_ctx_set_mime_parts(
axis2_msg_ctx_t * msg_ctx,
const axutil_env_t * env,
axutil_array_list_t *mime_parts){}
*/

/**
* Incrementing the msg_ctx ref count. This is necessary when 
* prevent freeing msg_ctx through op_client when it is in use 
* as in sandesha2.
* @return true if still in use, else false 
*/
WSF_EXTERN bool WSF_CALL MessageContext::incrementRef()
{
	if(axis2_msg_ctx_increment_ref(_msg_ctx, getEnv()))
		return true;
	return false;
}