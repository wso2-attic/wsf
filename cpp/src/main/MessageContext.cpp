/*
* Copyright 2005-2009 WSO2, Inc. http://wso2.com
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
#include <Environment.h>
#include <MessageContext.h>
#include <axis2_endpoint_ref.h>
#include <axiom_soap.h>
#include <axiom.h>
#include <axutil_param.h>
using namespace wso2wsf;
using namespace std;

/**
* Create message Context using the axis2_msg_ctx object                                                                     
*/
MessageContext::MessageContext(axis2_msg_ctx_t *msg_ctx)
{
	_msg_ctx = msg_ctx;
}

/**
* Returns existing axis2_msg_ctx object
*/
axis2_msg_ctx_t* MessageContext::getAxis2MessageContext()
{
    return _msg_ctx;
}

/**
* This method returns the WS-Addressing fault to address. Fault to address tells where to 
* send the fault in case there is an error.
* @return returns an string of the fault to endpoint 
*/
WSF_EXTERN std::string WSF_CALL MessageContext::getFaultTo()
{
	axis2_endpoint_ref_t *faultTo = NULL;
	faultTo = axis2_msg_ctx_get_fault_to(_msg_ctx, Environment::getEnv());
	if(faultTo)
	{
		const axis2_char_t *endpoint_ref = NULL;
		endpoint_ref = axis2_endpoint_ref_get_address(faultTo, Environment::getEnv());
		if(endpoint_ref)
		{
			return endpoint_ref;
		}
		else
		{
			return "";
		}

	}
	else
		return "";
}

/**
* Gets WS-Addressing from endpoint. From address tells where the request came from.
* @return string of the from endpoint reference
*/
WSF_EXTERN std::string WSF_CALL MessageContext::getFrom()
{
	axis2_endpoint_ref_t *from = NULL;
	from = axis2_msg_ctx_get_fault_to(_msg_ctx, Environment::getEnv());
	if(from)
	{
		const axis2_char_t *address = NULL;
		address = axis2_endpoint_ref_get_address(from, Environment::getEnv());
		if(address)
		{
			return address;
		}
	}
	return "";
}

/**
* Checks if there is a SOAP fault on in flow.
* @return true if there is a fault, false otherwise
*/
WSF_EXTERN bool WSF_CALL MessageContext::getInFaultFlow()
{
	if(axis2_msg_ctx_get_in_fault_flow(_msg_ctx, Environment::getEnv()))
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
	envlope  = axis2_msg_ctx_get_soap_envelope(_msg_ctx, Environment::getEnv());
	if(envlope)
	{	
		axiom_node_t *envNode = axiom_soap_envelope_get_base_node(envlope, Environment::getEnv());
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
	envlope  = axis2_msg_ctx_get_response_soap_envelope(_msg_ctx, Environment::getEnv());
	if(envlope)
	{	
		axiom_node_t *envNode = axiom_soap_envelope_get_base_node(envlope, Environment::getEnv());
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
	envlope  = axis2_msg_ctx_get_fault_soap_envelope(_msg_ctx, Environment::getEnv());
	if(envlope)
	{	
		axiom_node_t *envNode = axiom_soap_envelope_get_base_node(envlope, Environment::getEnv());
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
	const axis2_char_t *msgid = NULL;
	msgid = axis2_msg_ctx_get_msg_id(_msg_ctx, Environment::getEnv());
	return msgid != NULL ? msgid : "";
}

/**
* Gets WS-Addressing reply to endpoint as a string. Reply to address tells where 
* the the response should be sent to.    
* @return return a string corresponding to the reply to endpoint uri
*/
WSF_EXTERN std::string WSF_CALL MessageContext::getReplyTo()
{
	axis2_endpoint_ref_t *endpoint = NULL;
	endpoint = axis2_msg_ctx_get_reply_to(_msg_ctx, Environment::getEnv());
	if(endpoint)
	{
		const axis2_char_t *address = NULL;
		address = axis2_endpoint_ref_get_address(endpoint, Environment::getEnv());
		return address != NULL ? address : "";

	}
	return "";
}

/**
* Gets process fault status.
* @return true if process fault is on, false otherwise
*/
WSF_EXTERN bool WSF_CALL MessageContext::getProcessFault()
{
	if(axis2_msg_ctx_get_process_fault(_msg_ctx, Environment::getEnv()))
		return true;
	return false;
}

/**
* Checks if it is on the server side that the message is being dealt 
* with, or on the client side.
* @return true if it is server side, false otherwise
*/
WSF_EXTERN bool WSF_CALL MessageContext::getServerSide()
{
	if(axis2_msg_ctx_get_server_side(_msg_ctx,Environment::getEnv()))
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
	endpoint = axis2_msg_ctx_get_reply_to(_msg_ctx, Environment::getEnv());
	if(endpoint)
	{
		const axis2_char_t *address = NULL;
		address = axis2_endpoint_ref_get_address(endpoint, Environment::getEnv());
		if(address)
			return address;
	}	
	return "";
}

/**
* Sets WS-Addressing fault to endpoint. Fault to address tells where 
* the fault message should be sent when there is an error.
* @param toUri To uri
* @return true if successful, false otherwise.
*/
WSF_EXTERN bool WSF_CALL MessageContext::setFaultTo(std::string faultToUri)
{
	axis2_endpoint_ref_t *endpoint = NULL;
	if(!faultToUri.empty())
	{
		endpoint = axis2_endpoint_ref_create(Environment::getEnv(), faultToUri.c_str());
		if(axis2_msg_ctx_set_fault_to(_msg_ctx, Environment::getEnv(), endpoint))
			return true;
	}
	return false;
}

/**
* Sets WS-Addressing from endpoint. From address tells where 
* the message came from.
* @return true on success, false otherwise
*/
WSF_EXTERN bool WSF_CALL MessageContext::setFrom(std::string fromUri)
{
	axis2_endpoint_ref_t *endpoint = NULL;
	if(fromUri.c_str())
	{
		endpoint = axis2_endpoint_ref_create(Environment::getEnv(), fromUri.c_str());
		if(axis2_msg_ctx_set_from(_msg_ctx, Environment::getEnv(), endpoint))
			return true;
	}
	return false;
}

/**
* Sets in fault flow status. 
* @param in_fault_flow true if there is a fault on in path, false otherwise
* @return true if success false otherwise
*/
WSF_EXTERN bool WSF_CALL MessageContext::setInFaultFlow(bool infault)
{
	if(axis2_msg_ctx_set_in_fault_flow(_msg_ctx,Environment::getEnv(), infault))
		return true;
	return false;
}


/**
* Sets WS-Addressing reply to address indicating the location to which
* the reply would be sent.
* @param ReplyTo endpoint reference uri
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setReplyTo(std::string replyToUri)
{

	axis2_endpoint_ref_t *endpoint = NULL;
	if(!replyToUri.empty())
	{
		endpoint = axis2_endpoint_ref_create(Environment::getEnv(), replyToUri.c_str());
		if(axis2_msg_ctx_set_from(_msg_ctx, Environment::getEnv(), endpoint))
			return true;
	}
	return false;
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
	if(axis2_msg_ctx_set_server_side(_msg_ctx, Environment::getEnv(), serverSide))
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
	axis2_endpoint_ref_t *endpoint = NULL;
	if(!toUri.empty())
	{
		endpoint = axis2_endpoint_ref_create(Environment::getEnv(), toUri.c_str());
		if(axis2_msg_ctx_set_to(_msg_ctx, Environment::getEnv(), endpoint))
			return true;

	}
	return false;
}

/**
* Gets the bool value indicating if it is required to have a new thread
* for the invocation, or if the same thread of execution could be used.
*

* @return true if new thread is required, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::getNewThreadRequired()
{
	if(axis2_msg_ctx_get_new_thread_required(_msg_ctx,Environment::getEnv()))
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
	if(axis2_msg_ctx_set_new_thread_required(_msg_ctx, Environment::getEnv(), newThreadRequired))
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
	if(axis2_msg_ctx_set_wsa_action(_msg_ctx, Environment::getEnv(), actionUri.c_str()))
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
	const axis2_char_t *action = NULL;
	action = axis2_msg_ctx_get_wsa_action(_msg_ctx, Environment::getEnv());
	return action != NULL ? action : "";
}

/**
* Sets WS-Addressing message ID.
*

* @param message_id pointer to message ID string
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setWSAMessageId(std::string messageId)
{
	if(axis2_msg_ctx_set_wsa_message_id(_msg_ctx, Environment::getEnv(), messageId.c_str()))
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
	const axis2_char_t *msgid = NULL;
	msgid = axis2_msg_ctx_get_msg_id(_msg_ctx, Environment::getEnv());
	return msgid != NULL ? msgid : "";
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
	if(axis2_msg_ctx_is_paused(_msg_ctx, Environment::getEnv()))
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
	if(axis2_msg_ctx_set_paused(_msg_ctx, Environment::getEnv(), paused ? AXIS2_TRUE: AXIS2_FALSE))
		return true;
	return false;
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
	if(axis2_msg_ctx_is_keep_alive(_msg_ctx, Environment::getEnv()))
		return true;
	return false;
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
	if(axis2_msg_ctx_set_keep_alive(_msg_ctx, Environment::getEnv(), keepAlive ? AXIS2_TRUE: AXIS2_FALSE))
		return true;
	return false;
}

/**
* Gets the bool value indicating the output written status. 
*
* @return true if output is written, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::getOutputWritten()
{
	if(axis2_msg_ctx_get_output_written(_msg_ctx, Environment::getEnv()))
		return true;
	return false;
}

/**
* Sets the bool value indicating the output written status. 
*
* @param output_written true if output is written, else false
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setOutputWritten(bool outputWritten)
{
	if(axis2_msg_ctx_set_output_written(_msg_ctx, Environment::getEnv(), outputWritten ? AXIS2_TRUE : AXIS2_FALSE))
		return true;
	return false;
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
	const axis2_char_t *http_method = NULL;
	http_method = axis2_msg_ctx_get_rest_http_method(_msg_ctx, Environment::getEnv());
	return http_method != NULL ? http_method : "";
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
	if(!HTTPMethod.empty() && axis2_msg_ctx_set_rest_http_method(_msg_ctx, Environment::getEnv(), HTTPMethod.c_str()))
		return true;
	return false;
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
	if(!key.empty())
	{
		axutil_param_t *param = axis2_msg_ctx_get_parameter(_msg_ctx, Environment::getEnv(), key.c_str());
		if(param)
		{
			return new Parameter(axutil_param_get_name(param, Environment::getEnv()), 
								 axutil_param_get_value(param, Environment::getEnv()),
								 axutil_param_get_param_type(param, Environment::getEnv()));
		}
	}
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

	axutil_property_t *prop = NULL;
	if(!key.empty())
	{
		prop = axis2_msg_ctx_get_property(_msg_ctx, Environment::getEnv(),key.c_str());
		if(prop)
		{
			void *value = NULL;
			value = axutil_property_get_value(prop,Environment::getEnv());
			/** Add method to get the scope of property */
			return new Property(key, value, AXIS2_SCOPE_REQUEST);
		}
	}
	return NULL;
}

/**
* Gets property value corresponding to the property given key.
* @param property_str key string with which the property is stored
* @return pointer to property struct
*/
WSF_EXTERN void* WSF_CALL MessageContext::getPropertyValue(std::string propStr)
{
	axutil_property_t *prop = NULL;
	if(!propStr.empty())
	{
		prop = axis2_msg_ctx_get_property(_msg_ctx, Environment::getEnv(),propStr.c_str());
		if(prop)
		{
			void *value = NULL;
			value = axutil_property_get_value(prop,Environment::getEnv());
			return value;
		}
	}
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
	/** TODO */
	return true;
}

/**
* Gets the QName of the handler at which invocation was paused.
* @return pointer to QName of the paused handler
*/
WSF_EXTERN std::string WSF_CALL MessageContext::getPausedHandlerName()
{
	const axutil_string_t *str = NULL;
	str =  axis2_msg_ctx_get_paused_handler_name(_msg_ctx, Environment::getEnv());
	if(str)
	{
		const axis2_char_t *handlerName = NULL;
		handlerName = axutil_string_get_buffer(str,Environment::getEnv());
		if(handlerName)
			return handlerName;
	}
	return "";
}

/**
* Gets the name of the phase at which the invocation was paused.
* @return name string of the paused phase.
*/
WSF_EXTERN std::string WSF_CALL MessageContext::getPausedPhaseName()
{
	const axis2_char_t *phaseName = NULL;
	phaseName = axis2_msg_ctx_get_paused_phase_name(_msg_ctx, Environment::getEnv());
	return phaseName != NULL ? phaseName : "";
}

/**
* Sets the name of the phase at which the invocation was paused.
* @param paused_phase_name paused phase name string
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setPausedPhaseName(std::string pausedPhaseName)
{
	if(!pausedPhaseName.empty())
	{
		if(axis2_msg_ctx_set_paused_phase_name(_msg_ctx, Environment::getEnv(),pausedPhaseName.c_str()))
			return true;
	}
	return false;

}

/**
* Gets SOAP action.
* @return SOAP action string
*/
WSF_EXTERN std::string WSF_CALL MessageContext::getSOAPAction()
{
	axutil_string_t *action = NULL;
	action = axis2_msg_ctx_get_soap_action(_msg_ctx,Environment::getEnv());
	if(action)
	{
		const axis2_char_t *actionval = NULL;
		actionval = axutil_string_get_buffer(action, Environment::getEnv());
		if(actionval)
			return actionval;
	}
	return "";
}

/**
* Sets SOAP action.
* @param soap_action SOAP action string
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setSOAPAction(std::string action)
{
	if(!action.empty())
		if(axis2_msg_ctx_set_soap_action(_msg_ctx, Environment::getEnv(), 
			axutil_string_create(Environment::getEnv(), action.c_str())))
		return true;
	return false;
}

/**
* Gets the boolean value indicating if MTOM is enabled or not.
* @return true if MTOM is enabled, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::getDoingMTOM()
{
	if(axis2_msg_ctx_get_doing_mtom(_msg_ctx, Environment::getEnv()))
		return true;
	return false;
}

/**
* Sets the boolean value indicating if MTOM is enabled or not.
* @param doing_mtom true if MTOM is enabled, else false
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setDoingMTOM(bool doingMTOM)
{
	if(axis2_msg_ctx_set_doing_mtom(_msg_ctx, Environment::getEnv(), doingMTOM ? AXIS2_TRUE : AXIS2_FALSE))
		return true;
	return false;
}

/**
* Gets the boolean value indicating if REST is enabled or not.
* @return true if REST is enabled, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::getDoingREST()
{ 
	if(axis2_msg_ctx_get_doing_rest(_msg_ctx,Environment::getEnv()))
		return true;
	return false;
}

/**
* Sets the boolean value indicating if REST is enabled or not.
* @param doing_rest true if REST is enabled, else false
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setDoingREST(bool doingREST)
{
	if(axis2_msg_ctx_set_doing_rest(_msg_ctx,Environment::getEnv(),doingREST ? AXIS2_TRUE : AXIS2_FALSE))
		return true;
	return false;
}

/**
* Sets the boolean value indicating if REST should be done through 
* HTTP POST or not.
* @param do_rest_through_post true if REST is to be done with 
* HTTP POST, else false if REST is not to be done with HTTP POST
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setDoRESTThroughPOST(bool doREST)
{
	if(axis2_msg_ctx_set_do_rest_through_post(_msg_ctx,Environment::getEnv(),doREST ? AXIS2_TRUE : AXIS2_FALSE))
		return true;
	return false;
}

/**
* Sets the boolean value indicating if REST should be done through 
* HTTP POST or not.
* @return true if REST is to be done with HTTP POST, else 
* false if REST is not to be done with HTTP POST
*/
WSF_EXTERN bool WSF_CALL MessageContext::getDoRESTThroughPOST()
{ 
	if(axis2_msg_ctx_get_do_rest_through_post(_msg_ctx,Environment::getEnv()))
		return true;
	return false;
}

/**
* Gets manage session bool value.
* @return true if session is managed, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::getManageSession()
{
	if(axis2_msg_ctx_get_manage_session(_msg_ctx,Environment::getEnv()))
		return true;
	return false;
}

/**
* Sets manage session bool value.
* @param manage_session manage session bool value
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setManageSession(bool manageSession)
{
	if(axis2_msg_ctx_set_manage_session(_msg_ctx,Environment::getEnv(),manageSession ? AXIS2_TRUE : AXIS2_FALSE))
		return true;
	return false;
}

/**
* Gets the bool value indicating the SOAP version being used either
* SOAP 1.1 or SOAP 1.2
* @return true if SOAP 1.1 is being used, else false if 
* SOAP 1.2 is being used
*/

WSF_EXTERN bool WSF_CALL MessageContext::getIsSOAP11()
{
	if(axis2_msg_ctx_get_is_soap_11(_msg_ctx,Environment::getEnv()))
		return true;
	return false;
}

/**
* Sets the bool value indicating the SOAP version being used either
* SOAP 1.1 or SOAP 1.2
* @param is_soap11 true if SOAP 1.1 is being used, else 
* false if SOAP 1.2 is being used
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setIsSOAP11(bool isSOAP11)
{
	if(axis2_msg_ctx_set_is_soap_11(_msg_ctx, Environment::getEnv(),isSOAP11? AXIS2_TRUE : AXIS2_FALSE))
		return true;
	return false;
}

/**
* Gets the options to be used in invocation.
* @return options pointer to options struct, message context does not 
* assume the ownership of the struct
*/
WSF_EXTERN Options* WSF_CALL MessageContext::getOptions()
{
	/** TODO Is this required ? */
	return NULL;
}



/**
* Sets the options to be used in invocation.
* @param options pointer to options struct, message context does not 
* assume the ownership of the struct
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setOptions(Options options)
{
	/* TODO is this required */
	return true;
}

/**
* Sets the flow to be invoked.
* @param flow int value indicating the flow
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setFlow(int flow)
{
	if(axis2_msg_ctx_set_flow(_msg_ctx,Environment::getEnv(),flow))
		return true;
	return false;
}

/**
* Gets the flow to be invoked.
* @return int value indicating the flow
*/
WSF_EXTERN int WSF_CALL MessageContext::getFlow()
{
	return axis2_msg_ctx_get_flow(_msg_ctx, Environment::getEnv());
}


/**
* Sets the list of supported REST HTTP Methods
* @param supported_rest_http_methods pointer array list containing
* the list of HTTP Methods supported. Message context does
* assumes the ownership of the array list. Anything added to this
* array list will be freed by the msg_ctx
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setSupportedRESTHTTPMethods(std::vector<std::string> *methods)
{
	if(methods)
	{
		axutil_array_list_t *methods_list = NULL;
		for(std::vector<std::string>::iterator strIt = methods->begin();strIt != methods->end(); strIt++)
		{
			axutil_array_list_add(methods_list, Environment::getEnv(), (*strIt).c_str());
		}
		if(axis2_msg_ctx_set_supported_rest_http_methods(_msg_ctx, Environment::getEnv(), methods_list))
		{
			return true;
		}
	}
	return false;
}

/**
* Gets the list of supported REST HTTP Methods 
* @return pointer array list containing
* the list of HTTP Methods supported. Message context does
* assumes the ownership of the array list
*/
WSF_EXTERN  std::vector<std::string>* WSF_CALL MessageContext::getSupportedRESTHTTPMethods()
{
	axutil_array_list_t *methods_list = NULL;
	methods_list = axis2_msg_ctx_get_supported_rest_http_methods(_msg_ctx, Environment::getEnv());
	if(methods_list)
	{
		int size =0;
		std::vector<std::string> *methods = new std::vector<std::string>;
		size = axutil_array_list_size(methods_list, Environment::getEnv());
		for(int i =0; i< size; i++)
		{
			char * value = (char*)axutil_array_list_get(methods_list, Environment::getEnv(),i);
			methods->push_back(value);
		}
		return methods;
	}
	return NULL;
}

/**
* Sets current handler index, indicating which handler is currently 
* being invoked in the execution chain
* @param index index of currently executed handler
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setCurrentHandlerIndex(int index)
{
	if(axis2_msg_ctx_set_current_handler_index(_msg_ctx,Environment::getEnv(),index))
	{
		return true;
	}
	return false;
}

/**
* Gets current handler index, indicating which handler is currently 
* being invoked in the execution chain    
* @return index of currently executed handler
*/
WSF_EXTERN int WSF_CALL MessageContext::getCurrentHandlerIndex()
{
	return axis2_msg_ctx_get_current_handler_index(_msg_ctx,Environment::getEnv());
}

/**
* Gets paused handler index, indicating at which handler the execution 
* chain was paused.
* @return index of handler at which invocation was paused
*/
WSF_EXTERN int WSF_CALL MessageContext::getPausedHandlerIndex()
{
	return axis2_msg_ctx_get_paused_handler_index(_msg_ctx,Environment::getEnv());
}

/**
* Sets index of the current phase being invoked.    
* @param index index of current phase
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setCurrentPhaseIndex(int index)
{
	if(axis2_msg_ctx_set_current_phase_index(_msg_ctx,Environment::getEnv(), index))
	{
		return true;
	}
	return false;
}

/**
* Gets index of the current phase being invoked.    
* @return index of current phase
*/
WSF_EXTERN int WSF_CALL MessageContext::getCurrentPhaseIndex()
{
	return axis2_msg_ctx_get_current_phase_index(_msg_ctx,Environment::getEnv());
}

/**
* Gets the phase at which the invocation was paused.
* @return index of paused phase
*/
WSF_EXTERN int WSF_CALL MessageContext::getPausedPhaseIndex()
{
	return axis2_msg_ctx_get_paused_phase_index(_msg_ctx,Environment::getEnv());
}

/**
* Gets character set encoding to be used.
* @return true on success, else false
*/
WSF_EXTERN std::string WSF_CALL MessageContext::getCharsetEncoding()
{
	axutil_string_t *str = NULL;
	str = axis2_msg_ctx_get_charset_encoding(_msg_ctx,Environment::getEnv());
	if(str)
	{
		const axis2_char_t *charset = NULL;
		charset = axutil_string_get_buffer(str, Environment::getEnv());
		if(charset)
			return charset;
	}
	return "";
}

/**
* Sets character set encoding to be used.
* @param str pointer to string struct representing encoding
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setCharsetEncodingStng(std::string str)
{
	if(!str.empty())
	{
		if(axis2_msg_ctx_set_charset_encoding(_msg_ctx,Environment::getEnv(), 
			axutil_string_create(Environment::getEnv(), str.c_str())))
		{
			return true;
		}
	}
	return false;
}


/**
* Gets the integer value indicating HTTP status_code.
* @return status value
*/

WSF_EXTERN int WSF_CALL MessageContext::getStatusCode()
{
	return axis2_msg_ctx_get_status_code(_msg_ctx,Environment::getEnv());
}


/**
* Sets the int value indicating HTTP status code
* @param status_code of the HTTP response
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setStatusCode(int statusCode)
{
	if(axis2_msg_ctx_set_status_code(_msg_ctx,Environment::getEnv(), statusCode))
		return true;
	return false;
}


/**
* Retrieves HTTP Accept-Charset records.
* @return HTTP Accept-Charset records associated.
*/
WSF_EXTERN std::vector<std::string>* WSF_CALL MessageContext::getHTTPAcceptCharsetRecordList()
{ 
	axutil_array_list_t *record_list = NULL;
	record_list = axis2_msg_ctx_get_http_accept_charset_record_list(_msg_ctx, Environment::getEnv());
	if(record_list)
	{
		int size =0;
		std::vector<std::string> *methods = new std::vector<std::string>;
		size = axutil_array_list_size(record_list, Environment::getEnv());
		for(int i =0; i< size; i++)
		{
			char * value = (char*)axutil_array_list_get(record_list, Environment::getEnv(),i);
			methods->push_back(value);
		}
		return methods;
	}
	return NULL;
}

/**
* Retrieves HTTP Accept-Charset records, and removes them
* from the message context
* @return HTTP Accept-Charset records associated.
*/
WSF_EXTERN std::vector<std::string>* WSF_CALL MessageContext::extractHTTPAcceptCharsetRecordList()
{ 
	axutil_array_list_t *record_list = NULL;
	record_list = axis2_msg_ctx_extract_http_accept_charset_record_list(_msg_ctx, Environment::getEnv());
	if(record_list)
	{
		int size =0;
		std::vector<std::string> *methods = new std::vector<std::string>;
		size = axutil_array_list_size(record_list, Environment::getEnv());
		for(int i =0; i< size; i++)
		{
			char * value = (char*)axutil_array_list_get(record_list, Environment::getEnv(),i);
			methods->push_back(value);
		}
		return methods;
	}
	return NULL;
}

/**
* Sets the HTTP Accept-Charset records
* @param accept_charset_record_list an Array List containing the
* HTTP Accept-Charset records
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setHTTPAcceptCharsetRecordList(std::vector<std::string> *recordList)
{
	if(recordList)
	{
		axutil_array_list_t *methods_list = NULL;
		for(std::vector<std::string>::iterator strIt = recordList->begin();strIt != recordList->end(); strIt++)
		{
			axutil_array_list_add(methods_list, Environment::getEnv(), (*strIt).c_str());
		}
		if(axis2_msg_ctx_set_http_accept_charset_record_list(_msg_ctx, Environment::getEnv(), methods_list))
		{
			return true;
		}
	}
	return false;
}

/**
* Retrieves HTTP Accept-Language records.
* @return HTTP Accept-Language records associated.
*/
WSF_EXTERN std::vector<std::string>* WSF_CALL MessageContext::getHTTPAcceptLanguageRecordList()
{ 
	axutil_array_list_t *record_list = NULL;
	record_list = axis2_msg_ctx_get_http_accept_language_record_list(_msg_ctx, Environment::getEnv());
	if(record_list)
	{
		int size =0;
		std::vector<std::string> *records = new std::vector<std::string>;
		size = axutil_array_list_size(record_list, Environment::getEnv());
		for(int i =0; i< size; i++)
		{
			char * value = (char*)axutil_array_list_get(record_list, Environment::getEnv(),i);
			records->push_back(value);
		}
		return records;
	}
	return NULL;
}

/**
* Retrieves HTTP Accept-Language records, and removes them
* from the message context
* @return HTTP Accept-Language records associated.
*/
WSF_EXTERN std::vector<std::string>* WSF_CALL MessageContext::extractHTTPAcceptLanguageRecordList()
{ 
	axutil_array_list_t *record_list = NULL;
	record_list = axis2_msg_ctx_extract_http_accept_language_record_list(_msg_ctx, Environment::getEnv());
	if(record_list)
	{
		int size =0;
		std::vector<std::string> *records = new std::vector<std::string>;
		size = axutil_array_list_size(record_list, Environment::getEnv());
		for(int i =0; i< size; i++)
		{
			char * value = (char*)axutil_array_list_get(record_list, Environment::getEnv(),i);
			records->push_back(value);
		}
		return records;
	}
	return NULL;
}

/**
* Sets the HTTP Accept-Language records
* @param accept_language_record_list an Array List containing the
* HTTP Accept-Language records
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setHTTPAcceptLanguageRecordList(std::vector<std::string> *acceptLanguageRecordList)
{
	if(acceptLanguageRecordList)
	{
		axutil_array_list_t *methods_list = NULL;
		for(std::vector<std::string>::iterator strIt = acceptLanguageRecordList->begin();strIt != acceptLanguageRecordList->end(); strIt++)
		{
			axutil_array_list_add(methods_list, Environment::getEnv(), (*strIt).c_str());
		}
		if(axis2_msg_ctx_set_http_accept_language_record_list(_msg_ctx, Environment::getEnv(), methods_list))
		{
			return true;
		}
	}
	return false;
}

/**
* Gets the Content Language used
* @return Content Language string
*/
WSF_EXTERN std::string WSF_CALL MessageContext::getContentLanguage()
{ 
	axis2_char_t *contentLanguage = NULL;
	contentLanguage = axis2_msg_ctx_get_content_language(_msg_ctx,Environment::getEnv());
	return contentLanguage != NULL ? contentLanguage : "";
}

/**
* Sets the Content Language used
* @param str Content Language string
* @return true on success, else false
*/

WSF_EXTERN bool WSF_CALL MessageContext::setContentLanguage(std::string langauge)
{ 
	if(axis2_msg_ctx_set_content_language(_msg_ctx,Environment::getEnv(),(axis2_char_t*)langauge.c_str()))
		return true;
	return false;
}

/**
* Retrieves HTTP Accept records.
* @return HTTP Accept records associated.
*/
WSF_EXTERN std::vector<std::string>* WSF_CALL MessageContext::getHTTPAcceptRecordList()
{ 
	axutil_array_list_t *record_list = NULL;
	record_list = axis2_msg_ctx_get_http_accept_record_list(_msg_ctx, Environment::getEnv());
	if(record_list)
	{
		int size =0;
		std::vector<std::string> *records = new std::vector<std::string>;
		size = axutil_array_list_size(record_list, Environment::getEnv());
		for(int i =0; i< size; i++)
		{
			char * value = (char*)axutil_array_list_get(record_list, Environment::getEnv(),i);
			records->push_back(value);
		}
		return records;
	}
	return NULL;
}

/**
* Retrieves HTTP Accept records, and removes them
* from the message context
* @return HTTP Accept records associated.
*/
WSF_EXTERN std::vector<std::string>* WSF_CALL MessageContext::extractHTTPAcceptRecordList()
{ 
	axutil_array_list_t *record_list = NULL;
	record_list = axis2_msg_ctx_extract_http_accept_record_list(_msg_ctx, Environment::getEnv());
	if(record_list)
	{
		int size =0;
		std::vector<std::string> *records = new std::vector<std::string>;
		size = axutil_array_list_size(record_list, Environment::getEnv());
		for(int i =0; i< size; i++)
		{
			char * value = (char*)axutil_array_list_get(record_list, Environment::getEnv(),i);
			records->push_back(value);
		}
		return records;
	}
	return NULL;
}

/**
* Sets the HTTP Accept records
* @param accept_record_list an Array List containing the
* HTTP Accept records
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setHTTPAcceptRecordList(std::vector<std::string>* recordList)
{ 
	if(recordList)
	{
		axutil_array_list_t *methods_list = NULL;
		for(std::vector<std::string>::iterator strIt = recordList->begin();strIt != recordList->end(); strIt++)
		{
			axutil_array_list_add(methods_list, Environment::getEnv(), (*strIt).c_str());
		}
		if(axis2_msg_ctx_set_http_accept_language_record_list(_msg_ctx, Environment::getEnv(), methods_list))
		{
			return true;
		}
	}
	return false;
}

/**
* Gets the transfer encoding used
* @return Transfer encoding string
*/
WSF_EXTERN std::string WSF_CALL MessageContext::getTransferEncoding()
{ 
	axis2_char_t *transferEncoding = NULL;
	transferEncoding = axis2_msg_ctx_get_transfer_encoding(_msg_ctx,Environment::getEnv());
	return transferEncoding != NULL ? transferEncoding : "";
}

/**
* Sets the transfer encoding used
* @param str Transfer encoding string
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setTransferEncoding(std::string encoding)
{ 
	if(axis2_msg_ctx_set_transfer_encoding(_msg_ctx,Environment::getEnv(), (axis2_char_t*)encoding.c_str()))
		return true;
	return false;
}

/**
* Gets the Transport URL
* @return Transport URL string
*/
WSF_EXTERN std::string WSF_CALL MessageContext::getTransportURL()
{ 
	axis2_char_t *transportUrl = NULL;
	transportUrl = axis2_msg_ctx_get_transport_url(_msg_ctx,Environment::getEnv());
	return transportUrl != NULL ? transportUrl : "";
}

/**
* Sets the Transport URL
* @param str Transport URL string
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setTransportURL(std::string transportURL)
{ 
	if(!transportURL.empty())
	{
		if(axis2_msg_ctx_set_transport_url(_msg_ctx,Environment::getEnv(), (axis2_char_t*)transportURL.c_str()))
			return true;
	}
	return false;
}

/**
* Gets whether there was no content in the response.
* This will cater for a situation where the invoke
* method in a service returns NULL when no fault has
* occurred.
* @return returns true if there was no content
* occurred or false otherwise
*/
WSF_EXTERN bool WSF_CALL MessageContext::getNoContent()
{
	if(axis2_msg_ctx_get_no_content(_msg_ctx,Environment::getEnv()))
		return true;
	return false;
}

/**
* Sets that there was no content in the response.
* @param no_content expects true if there was no
* content in the response or false otherwise
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setNoContent(bool noContent)
{
	if(axis2_msg_ctx_set_no_content(_msg_ctx,Environment::getEnv(), noContent ? AXIS2_TRUE : AXIS2_FALSE))
		return true;
	return false;
}

/**
* Gets whether an authentication failure occurred
* @return returns true if an authentication failure
* occurred or false if not
*/
WSF_EXTERN bool WSF_CALL MessageContext::getAuthFailed()
{
	if(axis2_msg_ctx_get_auth_failed(_msg_ctx,Environment::getEnv()))
		return true;
	return false;
}


/**
* Sets whether an authentication failure occurred
*

* @param status expects true if an authentication failure
* occurred or false if not
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setAuthFailed(bool status)
{
	if(axis2_msg_ctx_set_auth_failed(_msg_ctx,Environment::getEnv(), status ? AXIS2_TRUE : AXIS2_FALSE ))
		return true;
	return false;
}

/**
* Gets whether HTTP Authentication is required or
* whether Proxy Authentication is required
*

* @return returns true for HTTP Authentication
* and false for Proxy Authentication
*/
WSF_EXTERN bool WSF_CALL MessageContext::getRequiredAuthIsHTTP()
{ 
	if(axis2_msg_ctx_get_required_auth_is_http(_msg_ctx, Environment::getEnv()))
	{
		return true;
	}
	return false;
}

/**
* Sets whether HTTP Authentication is required or
* whether Proxy Authentication is required
* @param is_http use true for HTTP Authentication
* and false for Proxy Authentication
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setRequiredAuthIsHTTP(bool isHTTP)
{ 
	if(axis2_msg_ctx_set_required_auth_is_http(_msg_ctx, Environment::getEnv(), isHTTP ? AXIS2_TRUE : AXIS2_FALSE))
	{
		return true;
	}
	return false;
}

/**
* Sets the authentication type
* @param auth_type Authentication type string
* @return true on success, else false
*/
WSF_EXTERN bool WSF_CALL MessageContext::setAuthType(std::string authType)
{
	if(axis2_msg_ctx_set_auth_type(_msg_ctx, Environment::getEnv(),authType.c_str()))
		return true;
	return false;
}

/**
* Gets the authentication type
* @return Authentication type string
*/
WSF_EXTERN std::string WSF_CALL MessageContext::getAuthType()
{
	axis2_char_t *authType = NULL;
	authType  = axis2_msg_ctx_get_auth_type(_msg_ctx, Environment::getEnv());
	return authType != NULL ? authType : "";
}

/**
* Incrementing the msg_ctx ref count. This is necessary when 
* prevent freeing msg_ctx through op_client when it is in use 
* as in sandesha2.
* @return true if still in use, else false 
*/
WSF_EXTERN bool WSF_CALL MessageContext::incrementRef()
{
	if(axis2_msg_ctx_increment_ref(_msg_ctx, Environment::getEnv()))
		return true;
	return false;
}

WSF_EXTERN WSF_CALL MessageContext::~MessageContext()
{
	if(_msg_ctx)
	{
		axis2_msg_ctx_free(_msg_ctx, Environment::getEnv());
	}
}

WSF_EXTERN bool MessageContext::setAxis2MessageContext(axis2_msg_ctx_t *msg_ctx)
{
	if(_msg_ctx)
	{
		_msg_ctx = msg_ctx;
		return true;
	}
	return false;
}

