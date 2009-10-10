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

#ifndef SERVICECLIENT_H
#define SERVICECLIENT_H

#include <WSFDefines.h>
#include <string>
#include <axis2_conf_ctx.h>
#include <axis2_conf.h>
#include <axis2_svc_client.h>
#include <axis2_svc.h>
#include <axis2_const.h>
#include <axis2_http_transport.h>
#include <platforms/axutil_platform_auto_sense.h>
#include <WSFault.h>
#include <ICallback.h>
#include <Options.h>
#include <OMElement.h>
#include <OMNamespace.h>
#include <NeethiPolicy.h>
#include <MessageContext.h>

/**
 * @file ServiceClient.h
 * @brief Primary client API class Serviceclient is defined here.
 */

/**
 * @brief namespace wso2wsf Namespace of WSO2 Web Services Framework.
 */
namespace wso2wsf
{
    /**
     * @defgroup service_client Service Client
     * @ingroup wso2wsf
     * @{
     */

    /**
     * @brief Class ServiceClient 
     * The service client Class serves as the primary client
     * interface for consuming services. The Service Client is
     * associated to a repository which includes an axis2.xml.
     * Service client can be constructed by passing a configuration
     * context as well. Optionally, you can pass options during the
     * initialization. You also can explicitly set options. Advanced
     * features such as engaging and disengaging modules, adding and
     * removing headers are supported. Some methods in the client may
     * throw exceptions identified as Axis Faults. There are several
     * ways of invoking a service operation, which are based on the
     * concept of a message exchange pattern (MEP). The two basic MEPs
     * supported by service client are out-only and out-in. Each MEP
     * can be used in either blocking or non-blocking mode.Out-only MEP
     * means one way message which does not expect a response. Out-In MEP means
     * a request response message exchange. The operation invocations using 
     * the service client API are based on the XML-in/XML-out principle: both 
     * the payload to be sent to the service and the result from the service 
     * are in XML, represented in AXIOM.
     */
    class ServiceClient 
    {

	friend class Stub;

    private:
        /**
         * _wsf_service_client private variable holds reference for
         * axis2_svc_client struct.
         */
        axis2_svc_client_t * _wsf_service_client;

        /**
         * _last_soap_fault private variable holds reference for
         * last SOAP fault.
         */
        OMElement * _last_soap_fault;

        /**
         * _last_response_soap_envelope_element private variable holds reference for
         * last response SOAP envelope element.
         */
        OMElement * _last_response_soap_envelope_element;

        /**
         * _last_response_soap_envelope private variable holds reference for
         * last response SOAP envelope.
         */
        axiom_soap_envelope_t * _last_response_soap_envelope;

        /**
         * _options private variable holds reference for
         * composite Options object.
         */
        Options * _options;

	/**
     * _policy private variable holds reference for
     * associated policy object.
     */
    NeethiPolicy * _policy;

    /**
     * _endpoint_address private variable holds reference of the
     * endpoint address.
     */
    std::string _endpoint_address;

    /**
     * _repo_home private variable holds reference of the
     * repository home.
     */
	std::string _repo_home;

    /**
     * _conf_ctx private variable holds reference for
     * axis2_conf_ctx_t struct.
     */
    const axis2_conf_ctx_t * _conf_ctx;

	/**
	*  isValid This variable is used to keep track of the consistency of
	* service client. If the value is false, that means, ServiceClient object 
	* instance is in an inconsistent stage due to an error condition.                                                    
	*/
	bool isValid;
    /**
     * initializes service client.
     * @return boolean result of the operation
     */
    bool WSF_CALL initializeClient();
	/**
	*  @returns the message contexts associated with the current service client.                                                   
	*/
	MessageContext* WSF_CALL getMessageContext(axis2_wsdl_msg_labels_t message_lebel);

	/**
	* Reset the OMNamespace for the remove of the Payload Axiom Node                                                   
	*/
	void resetAxiomPayloadNamespace(OMElement *payload);

    protected:


    public:
    /**
     * Create a Service Client which is associated with the default repository.
	 * The service client assumes that WSFCPP_HOME environment variable is defined
	 * to point to the repo.
     * @param endpoint_address endpoint address which would be invoked using this
     * service Client Object.
     */
    WSF_EXTERN WSF_CALL ServiceClient(std::string endpoint_address);

    /**
     * Create a Service Client from the repository.
     * @param repo_home location of the repository.
     * @param endpoint_address endpoint address to be used.
     */
    WSF_EXTERN WSF_CALL ServiceClient(std::string repo_home, std::string endpoint_address);

    /**
     * Create a service client from a configuration context.
     * @param conf_ctx pointer to configuration context.
     * @param endpoint_address endpoint address to be used.
     */
    WSF_EXTERN WSF_CALL ServiceClient(const axis2_conf_ctx_t * conf_ctx, std::string endpoint_address);

    /**
     * Destructor frees resources. 
     */
    WSF_EXTERN virtual WSF_CALL ~ServiceClient();
	/**
	* Checks whether the ServiceClient got properly initialized or not. 
	* If the service client is properly initialized, it will return true  and will return false otherwise.
	* @return true on success, false otherwise.
	*/

	WSF_EXTERN bool WSF_CALL isValidClient();

	/**
	* Sets the options to be used by service client.
	* @param options pointer to options struct to be set.
	* @return true on success or false on failure.
	*/
	WSF_EXTERN bool WSF_CALL setOptions(Options * options);

    /**
     * Method to retrieve the last SOAP fault that resulted after invoking
     * a send or a request operation.
     * @return returns an OMElement containing the SOAP fault.
     */
    WSF_EXTERN OMElement * WSF_CALL getLastSOAPFault ();

    /**
     * Gets options used by service client.
     * @return a pointer to the options struct if options set, else NULL.
     * Returns a reference, not a cloned copy.
     */
    WSF_EXTERN Options * WSF_CALL getOptions();

    /**
     * Engages the named module. The engaged modules extend the message
     * processing when consuming services. Modules help to apply QoS
     * norms in messaging. Once a module is engaged to a service client,
     * the axis2_engine makes sure to invoke the module for all the
     * interactions between the client and the service.
     * @param module_name name of the module to be engaged.
     * @return true on success or false on failure.
     */
    WSF_EXTERN bool WSF_CALL engageModule(std::string module_name);

    /**
     * Dis-engages the named module. Dis-engaging a module on a service
     * client ensures that the axis2_engine would not invoke the named
     * module when sending and receiving messages.
     * @param module_name name of the module to be dis-engaged.
     * @return true on success or false on failure.
     */
    WSF_EXTERN bool WSF_CALL disengageModule(std::string module_name);

    /**
     * Adds an XML element as a header to be sent to the server side.
     * This allows users to go beyond the usual XML-in/XML-out pattern,
     * and send custom SOAP headers. Once added, service client owns
     * the header and will clean up when the service client is freed.
     * @param header om node representing the SOAP header in XML.
     * @return true on success or false on failure.
     */
    WSF_EXTERN bool WSF_CALL addHeader(OMElement * header);

    /**
     * Removes all the headers added to service client.
     * @exception AxisFault an exception is thrown if something goes wrong
     * while removing headers.
     */
    WSF_EXTERN void WSF_CALL removeAllHeaders();

    /**
     * Set the given policy object to the description hierarchy.
     * @param policy pointer to a policy struct.
     * @return true on success or false on failure.
     */
    WSF_EXTERN bool WSF_CALL setPolicy(NeethiPolicy * policy);

    /**
     * This method is used to interact with a service operation whose MEP is Robust Out-Only.
     * That is, there is an opportunity to get an error from the service via this method; one may still
     * get client-side errors, such as host unknown etc.
     * @param payload pointer to OM node representing the XML payload to be sent.
     * @param action soap/addressing action.
     * @return true if no soap fault was received, and false if received.
     * @exception AxisFault an exception is thrown if something goes wrong
     * while creating a config context.
     */
    WSF_EXTERN bool WSF_CALL send(OMElement * payload, std::string action) throw (WSFault);

    /**
     * This method is used to interact with a service operation whose MEP is Robust Out-Only.
     * That is, there is an opportunity to get an error from the service via this method; one may still
     * get client-side errors, such as host unknown etc.
     * @param payload pointer to OM node representing the XML payload to be sent.
     * @param operation operation name. "" is equivalent to an
     * operation name of "__OPERATION_OUT_ONLY__".
     * @param action soap/addressing action.
     * @return true if no soap fault was received, and false if received.
     * @exception AxisFault an exception is thrown if something goes wrong
     * while creating a config context.
     */
    WSF_EXTERN bool WSF_CALL send(OMElement * payload, std::string operation, std::string action) throw (WSFault);

    /**
     * This method is used to interact with a service operation whose MEP is Out-Only, or Robust Out-Only.
     * That is, there is an opportunity to get an error from the service via this method; one may still
     * get client-side errors, such as host unknown etc.
     * @param operation operation name. "" is equivalent to an
     * operation name of "__OPERATION_OUT_ONLY__".
     * @param payload pointer to OM node representing the XML payload to be sent.
     * @param robust true represents a robust operation, and false represents an ordinary send operation.
     * @param action soap/addressing action.
     * @return true if no soap fault was received, and false if received.
     * @exception AxisFault an exception is thrown if something goes wrong
     * while creating a config context.
     */
    WSF_EXTERN bool WSF_CALL send(OMElement * payload, bool robust, std::string operation, std::string action) throw (WSFault);

    /**
     * This method is used to interact with a service operation whose MEP is Out-Only, or Robust Out-Only.
     * That is, there is an opportunity to get an error from the service via this method; one may still
     * get client-side errors, such as host unknown etc.
     * @param payload pointer to OM node representing the XML payload to be sent.
     * @param robust true represents a robust operation, and false represents an ordinary send operation.
     * @param action soap/addressing action.
     * @return true if no soap fault was received, and false if received.
     * @exception AxisFault an exception is thrown if something goes wrong
     * while creating a config context.
     */
    WSF_EXTERN bool WSF_CALL send(OMElement * payload, bool robust, std::string action) throw (WSFault);

    /**
     * Sends XML request and receives XML response.
     * This method is used to interact with a service operation whose MEP is In-Out.
     * @param payload pointer to OM node representing the XML payload to be sent
     * @return pointer to OM node representing the XML response. The
     * caller owns the returned node.
     * @param action soap/addressing action.
     * @exception AxisFault an exception is thrown if something goes wrong
     * while creating a config context.
     */
    WSF_EXTERN OMElement * WSF_CALL request(OMElement * payload, std::string action) throw (WSFault);

    /**
     * Sends XML request and receives XML response.
     * This method is used to interact with a service operation whose MEP is In-Out.
     * @param operation operation name. "" is equivalent to an
     * operation name of "__OPERATION_OUT_IN__".
     * @param payload pointer to OM node representing the XML payload to be sent.
     * @param callback pointer to callback object used to capture response, in a
     * non-blocking operation, NULL represents a blocking operation.
     * @return pointer to OM node representing the XML response. The
     * caller owns the returned node.
     * @param action soap/addressing action.
     * @exception AxisFault an exception is thrown if something goes wrong
     * while creating a config context.
     */
    WSF_EXTERN OMElement * WSF_CALL request(OMElement * payload, ICallback * callback, std::string operation, std::string action) throw (WSFault);

    /**
     * Sends XML request and receives XML response.
     * This method is used to interact with a service operation whose MEP is In-Out.
     * @param payload pointer to OM node representing the XML payload to be sent.
     * @param callback pointer to callback object used to capture response, in a
     * non-blocking operation, NULL represents a blocking operation.
     * @return pointer to OM node representing the XML response. The
     * caller owns the returned node.
     * @param action soap/addressing action.
     * @exception AxisFault an exception is thrown if something goes wrong
     * while creating a config context.
     */
    WSF_EXTERN OMElement * WSF_CALL request(OMElement * payload, ICallback * callback, std::string action) throw (WSFault);

    /**
     * Sends XML request and receives XML response.
     * This method is used to interact with a service operation whose MEP is In-Out.
     * @param operation operation name. "" is equivalent to an
     * operation name of "__OPERATION_OUT_IN__".
     * @param payload pointer to OM node representing the XML payload to be sent.
     * @return pointer to OM node representing the XML response. The
     * caller owns the returned node.
     * @param action soap/addressing action.
     * @exception AxisFault an exception is thrown if something goes wrong
     * while creating a config context.
     */
    WSF_EXTERN OMElement * WSF_CALL request(OMElement * payload, std::string operation, std::string action) throw (WSFault);

    /**
     * Gets the last response SOAP envelope.
     * @return pointer to SOAP envelope that was returned as a result
     * when request was called last time.
     */
    WSF_EXTERN OMElement * WSF_CALL getLastResponseSoapEnvelope();

    /**
     * Gets the last response SOAP envelope.
     * @return SOAP envelope that was returned as a result
     * when request was called last time, as a String.
     */
    WSF_EXTERN std::string WSF_CALL getLastResponseSoapEnvelopeString();

	/**
     * Returns the axis2_svc_client used within ServiceClient.
	 */
	WSF_EXTERN axis2_svc_client_t* WSF_CALL getAxis2SvcClient();
	/** 
	 * Returns the axis2_conf_ctx_t which can be used to create a configuration context once and pass it when creating multiple service clients.
	 */
	WSF_EXTERN axis2_conf_ctx_t* WSF_CALL getAxis2ConfCtx(std::string repositoryPath);

	/**
	 * Configure Service client with a proxy.
	 * @param proxyHost proxy host
	 * @param proxyPort proxy port
	 *
	 */
	WSF_EXTERN bool WSF_CALL setProxy(std::string proxyHost, std::string proxyPort);

	/**
	 * Set proxy with authentication                                                   
	 * @param proxyHost Proxy host
	 * @param proxyPort proxy port
	 * @param username  username required for proxy authentication
	 * @param password  password required for proxy authentication
	 */
	WSF_EXTERN bool WSF_CALL setProxyWithAuth(std::string proxyHost,
		std::string proxyPort, std::string username, std::string password);

	/**
	 * Gets the boolean value indicating whether HTTP Authentication is required.
	 * @return true if HTTP authentication is required, false otherwise.
	 */
	WSF_EXTERN bool WSF_CALL getHttpAuthRequired();

	/**
	 * Gets the boolean value indicating whether Proxy Authentication
	 * is required.
	 * @return true if proxy authentication is required and false otherwise.
	 */
	WSF_EXTERN bool WSF_CALL getProxyAuthRequired();

	/**
	 * Returns the MessageContext object used in the inflow of the Engine.                                                   
	 * @returns MessageContext
	 */
	WSF_EXTERN MessageContext* WSF_CALL getInMessageContext();

	/**
	 * Returns the MessageContext object used in the outflow of the engine. 
	 * This method is only valid when calling after a service invocation call using
	 * ServiceClient::request or ServiceClient::send methods. 
	 * @returns MessageContext. Freeing the returned MessageContext must be freed by the
	 * user. Before freeing the message context use 
	 */
	WSF_EXTERN MessageContext* WSF_CALL	getOutMessageContext();
    
    WSF_EXTERN bool WSF_CALL close();

    };
    /** @} */
}
#endif // SERVICECLIENT_H
