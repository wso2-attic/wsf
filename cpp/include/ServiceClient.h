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

#ifndef SERVICECLIENT_H
#define SERVICECLIENT_H

/**
 * @file ServiceClient.h
 */
#include <string>
#include <axis2_conf_ctx.h>
#include <axis2_conf.h>
#include <axis2_svc_client.h>
#include <axis2_svc.h>
#include <axis2_const.h>
#include <axis2_http_transport.h>
#include <AxisObject.h>
#include <AxisFault.h>
#include <ICallback.h>
#include <Options.h>
#include <OMElement.h>
#include <OMNamespace.h>

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
     * @brief class ServiceClient The service client interface serves as the primary client
     * interface for consuming services. The Service Client is
     * derived either from the repository, or by using a configuration
     * context. Optionally, you can pass options during the
     * initilization. You also can explicitly set options. Advanced
     * features such as engaging and disengaing modules, adding and
     * removing headers are supported. Some methods in the client may
     * throw exceptions identified as Axis Faults. There are several
     * ways of invoking a service operation, which are based on the
     * concept of a message exchange pattern (MEP). The two basic MEPs
     * supported by service client are out-only and out-in. Each MEP
     * can be used in either blocking or non-blocking mode. The operation
     * invocations using the service client API are based on the
     * XML-in/XML-out principle: both the payload to be sent to the
     * service and the result from the service are in XML, represented
     * in AXIOM.
     */
    class ServiceClient : public AxisObject
    {
    private:
        /**
         * @var _wsf_service_client private variable holds reference for
         * axis2_svc_client struct.
         */
        axis2_svc_client_t * _wsf_service_client;

        /**
         * @var _last_soap_fault private variable holds reference for
         * last SOAP fault.
         */
        OMElement * _last_soap_fault;

        /**
         * @var _last_response_soap_envelope_element private variable holds reference for
         * last response SOAP envelope element.
         */
        OMElement * _last_response_soap_envelope_element;

        /**
         * @var _last_response_soap_envelope private variable holds reference for
         * last response SOAP envelope.
         */
        axiom_soap_envelope_t * _last_response_soap_envelope;

        /**
         * @var _options private variable holds reference for
         * composite Options object.
         */
        Options * _options;

        /**
         * @var _endpoint_address private variable holds reference of the
         * endpoint address.
         */
        std::string _endpoint_address;

        /**
         * @var _repo_home private variable holds reference of the
         * repository home.
         */
        std::string _repo_home;

        /**
         * @var _conf_ctx private variable holds reference for
         * axis2_conf_ctx_t struct.
         */
        const axis2_conf_ctx_t * _conf_ctx;

    protected:
        /**
         * Sets the options to be used by service client.
         * @param options pointer to options struct to be set.
         * @return true on success or false on failure.
         */
        virtual bool setOptions(Options * options)=0;

    public:
        /**
         * create a service client from the default repository.
         * @param endpoint_address endpoint address to be used.
         */
        ServiceClient(std::string endpoint_address);

        /**
         * create a service client from the repository.
         * @param repo_home location of the repository.
         * @param endpoint_address endpoint address to be used.
         */
        ServiceClient(std::string repo_home, std::string endpoint_address);

        /**
         * create a service client from a configuration context.
         * @param conf_ctx pointer to configuration context.
         * @param endpoint_address endpoint address to be used.
         */
        ServiceClient(const axis2_conf_ctx_t * conf_ctx, std::string endpoint_address);

        /**
         * destructor frees resources.
         */
        virtual ~ServiceClient();

        /**
         * initializes service client.
         * @param log_file name of the log file. If NULL, a default log would be created.
         * @param log_level log level to be used. If not valid, debug would be
         * used as the default log level.
         * @exception AxisFault an exception is thrown if something goes wrong
         * while creating a config context.
         */
        void initializeClient(std::string log_file, axutil_log_levels_t log_level) throw(AxisFault);

        /**
         * Method to retrieve the last SOAP fault that resulted after invoking
         * a send or a request operation.
         * @return returns an OMElement containing the SOAP fault.
         */
        OMElement * getLastSOAPFault ();

        /**
         * Gets options used by service client.
         * @return a pointer to the options struct if options set, else NULL.
         * Returns a reference, not a cloned copy.
         */
        Options * getOptions();

        /**
         * Engages the named module. The engaged modules extend the message
         * processing when consuming services. Modules help to apply QoS
         * norms in messaging. Once a module is engaged to a service client,
         * the axis2_engine makes sure to invoke the module for all the
         * interactions between the client and the service.
         * @param module_name name of the module to be engaged.
         * @return true on success or false on failure.
         */
        bool engageModule(std::string module_name);

        /**
         * Dis-engages the named module. Dis-engaging a module on a service
         * client ensures that the axis2_engine would not invoke the named
         * module when sending and receiving messages.
         * @param module_name name of the module to be dis-engaged.
         * @return true on success or false on failure.
         */
        bool disengageModule(std::string module_name);

        /**
         * Adds an XML element as a header to be sent to the server side.
         * This allows users to go beyond the usual XML-in/XML-out pattern,
         * and send custom SOAP headers. Once added, service client owns
         * the header and will clean up when the service client is freed.
         * @param header om node representing the SOAP header in XML.
         * @return true on success or false on failure.
         */
        bool addHeader(OMElement * header);

        /**
         * Removes all the headers added to service client.
         * @exception AxisFault an exception is thrown if something goes wrong
         * while removing headers.
         */
        void removeAllHeaders() throw(AxisFault);

        /**
         * Set the given policy object to the description hierarchy.
         * @param policy neethi_policy_t to a policy struct.
         * @return true on success or false on failure.
         */
        bool setPolicy(OMElement * policy);

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
        bool send(OMElement * payload, std::string action) throw(AxisFault);

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
        bool send(OMElement * payload, std::string operation, std::string action) throw(AxisFault);

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
        bool send(OMElement * payload, bool robust, std::string operation, std::string action) throw(AxisFault);

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
        bool send(OMElement * payload, bool robust, std::string action) throw(AxisFault);

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
        OMElement * request(OMElement * payload, std::string action) throw(AxisFault);

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
        OMElement * request(OMElement * payload, ICallback * callback, std::string operation, std::string action) throw(AxisFault);

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
        OMElement * request(OMElement * payload, ICallback * callback, std::string action) throw(AxisFault);

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
        OMElement * request(OMElement * payload, std::string operation, std::string action) throw(AxisFault);

        /**
         * Gets the last respose SOAP envelope.
         * @return pointer to SOAP envelope that was returned as a result
         * when request was called last time.
         */
        OMElement * getLastResponseSoapEnvelope();

        /**
         * Gets the last respose SOAP envelope.
         * @return SOAP envelope that was returned as a result
         * when request was called last time, as a String.
         */
        std::string getLastResponseSoapEnvelopeString();
    };
    /** @} */
}
#endif // SERVICECLIENT_H
