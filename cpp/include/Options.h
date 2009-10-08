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

#ifndef OPTIONS_H
#define OPTIONS_H

#include <WSFDefines.h>
#include <axis2_options.h>
#include <axis2_const.h>
#include <axiom_soap_const.h>
#include <WSFault.h>
#include <OMElement.h>
#include <Property.h>
#include <string>

/**
 * @file Options.h
 * @brief Options class, the primary client configuratator class is defined here.
 */

/**
 * @brief namespace wso2wsf Namespace of WSO2 Web Services Framework.
 */
namespace wso2wsf
{
    /**
     * @defgroup options Options
     * @ingroup wso2wsf
     * @{
     */

    /** @brief class Options Holder for operation client options. This is
      * used by the other classes in this package to configure various aspects
      * of how a client communicates with a service. It exposes a number of
      * predefined properties as part of the API (with specific getXXX and setXXX
      * methods), and also allows for arbitrary named properties to be passed
      * using a properties map with the property name as the key value. Instances
      * of this class can be chained together for property inheritance, so that if
      * a property is not set in one instance it will check its parent for a setting.
      */
    class Options 
    {
    /**
     * The ServiceClient Class can access private resources of this class.
     */
    friend class ServiceClient;

    private:
        /**
         * _wsf_options private variable holds reference for
         * axis2_options struct.
         */
        axis2_options_t * _wsf_options;

        /**
         * _reply_to private variable holds reference for
         * reply to epr.
         */
        axis2_endpoint_ref_t * _reply_to;

        /**
         * _reply_to private variable holds reference for
         * to epr.
         */
        axis2_endpoint_ref_t * _to;

        /**
         * _reply_to private variable holds reference for
         * from epr.
         */
        axis2_endpoint_ref_t * _from;

        /**
         * _reply_to private variable holds reference for
         * fault to epr.
         */
        axis2_endpoint_ref_t * _fault_to;

    public:

		/**
		* Sets xml parser reset. By default, set to true.
		* @param paser_reset is a boolean value.
		*/
		void WSF_CALL setXMLParserReset(bool paser_reset);

        /**
         * Creates the options struct with or without given parent.
         */
        WSF_CALL Options();

        /**
         * destructor frees resources.
         */
        WSF_CALL ~Options();

        /**
         * Gets WSA fault to address.
         * @return pointer to fault to address if set, else NULL.
         */
        WSF_EXTERN std::string WSF_CALL getFaultTo();

        /**
         * Gets WSA from address.
         * @return pointer to from address if set, else NULL.
         */
        WSF_EXTERN std::string WSF_CALL getFrom();

        /**
         * Gets message ID.
         * @return pointer to message ID string if set, else NULL.
         */
        WSF_EXTERN std::string WSF_CALL getMessageId();

        /**
         * Gets WSA reply to address.
         * @return pointer to reply to address if set, else NULL.
         */
        WSF_EXTERN std::string WSF_CALL getReplyTo();

        /**
         * Sets the bool value indicating whether to enable REST or not.
         * @param enable bool value indicating whether to enable REST
         * or not, true to enable, false to disable.
         */
        WSF_EXTERN void WSF_CALL setEnableREST(bool enable);

        /**
         * Sets the bool value indicating whether to use a separate listener or not.
         * @param use_separate_listener bool value indicating whether to use
         * a separate listener or not.
         */
        WSF_EXTERN void WSF_CALL setUseSeparateListener(bool use_separate_listener);

        /**
         * Gets the wait time after which a client times out in a blocking scenario.
         * The default is AXIS2_DEFAULT_TIMEOUT_MILLISECONDS.
         * @return timeout in milliseconds.
         */
        WSF_EXTERN long WSF_CALL getTimeout();

        /**
         * Gets WSA to address.
         * @return pointer to, to address if set, else NULL.
         */
        WSF_EXTERN std::string WSF_CALL getTo();

        /**
         * Sets fault to address.
         * @param fault_to pointer to, fault to address. Options takes over the
         * ownership of the struct.
         */
        WSF_EXTERN void WSF_CALL setFaultTo(std::string fault_to);

        /**
         * Sets from address.
         * @param from pointer to, from address. Options takes over the ownership
         * of the struct.
         */
        WSF_EXTERN void WSF_CALL setFrom(std::string from);

        /**
         * sets from address.
         * @param to pointer to , to address. Options takes over the ownership of the struct.
         */
        WSF_EXTERN void WSF_CALL setTo(std::string to);

        /**
         * Sets message ID.
         * @param message_id pointer to message_id struct.
         */
        WSF_EXTERN void WSF_CALL setMessageId(std::string message_id);

        /**
         * Sets the properties.
         * @param property pointer to properties object.
         * @return true on success, else false.
         */
        WSF_EXTERN bool WSF_CALL setProperty(Property * property);

        /**
         * Sets reply to address.
         * @param reply_to pointer to endpoint reference struct representing
         * reply to address. options takes over the ownership of the struct.
         */
        WSF_EXTERN void WSF_CALL setReplyTo(std::string reply_to);

        /**
         * Sets timeout in Milli seconds.
         * @param timeout timeout in milli seconds.
         * @return true on success, else false.
         */
        WSF_EXTERN void WSF_CALL setTimeout(long timeout);

        /**
         * Adds a WSA reference parameter.
         * @param reference_parameter pointer to reference parameter in the form
         * of an AXIOM tree. options takes over the ownership of the struct.
         */
        WSF_EXTERN void WSF_CALL addReferenceParameter(OMElement * reference_parameter);

        /**
         * Gets SOAP version.
         * @return AXIOM_SOAP11 if SOAP version 1.1 is in use, else AXIOM_SOAP12.
         */
        WSF_EXTERN soap_version WSF_CALL getSoapVersion();

        /**
         * Sets SOAP version.
         * @param version soap version, either AXIOM_SOAP11 or AXIOM_SOAP12.
         */
        WSF_EXTERN void WSF_CALL setSoapVersion(soap_version version);

        /**
         * Enable/disable MTOM handling.
         * @param enable true if MTOM is to be enabled, if not, false.
         */
        WSF_EXTERN void WSF_CALL setEnableMTOM(bool enable);

        /**
         * Gets Enable/disable MTOM status.
         * @return true if MTOM enabled, else false.
         */
        WSF_EXTERN bool WSF_CALL getEnableMTOM();

		/**
		* configure client to use the specified the SOAP/Addressing action                                                   
		* @param action, The soap action
		* @return true if the action is successfully set, false otherwise.
		*/
		WSF_EXTERN bool WSF_CALL setAction(std::string action);
        /**
         * Sets the HTTP method to be used
         * @param http_method string representing HTTP method to use,
         * can be either AXIS2_HTTP_GET or AXIS2_HTTP_POST
         */
        WSF_EXTERN void WSF_CALL setHTTPMethod(std::string http_method);
		/**
		* Returns the axis2_options used within Options class                                                   
		*
		*/
		WSF_EXTERN axis2_options_t* WSF_CALL getAxis2Options();

		/**
		* Sets the bool value indicating whether to test whether HTTP
		* Authentication is required or not.
		* @param testHTTPAuth bool value indicating whether to test
		* or not, true to enable, false to disable
		* @return true on success, false otherwise.
		*/
		WSF_EXTERN bool WSF_CALL
		setTestHTTPAuth(bool testHTTPAuth);

		/**
		* Sets the bool value indicating whether to test whether Proxy
		* Authentication is required or not.
		* @param  testProxyAuth bool value indicating whether to test
		* or not, true to enable, false to disable
		* @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
		*/
		WSF_EXTERN bool WSF_CALL
		setTestProxyAuth(bool testProxyAuth);

		/**
		* Sets HTTP authentication information.
		* @param username string representing username
		* @param password string representing password
		* @param authType use "Basic" to force basic authentication
		* and "Digest" to force digest authentication or NULL for not
		* forcing authentication
		* @return true on success, else false
		*/
		WSF_EXTERN bool WSF_CALL
		setHTTPAuthInfo(std::string username, std::string password, std::string authType);

		/**
		* Sets proxy authentication information.
		* @param username string representing username
		* @param password string representing password
		* @param authType use "Basic" to force basic authentication
		* and "Digest" to force digest authentication or NULL for not
		* forcing authentication
		* @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
		*/
		WSF_EXTERN bool WSF_CALL 
		setProxyAuthInfo(std::string username, std::string password, std::string authType);

    };
    /** @} */
}
#endif // OPTIONS_H
