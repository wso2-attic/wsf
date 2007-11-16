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

#include <stdio.h>
#include <ServiceClient.h>
using namespace std;
using namespace wso2wsf;

/** @brief ~ServiceClient
  *
  * @todo: document this function
  */
 ServiceClient::~ServiceClient()
{
    if (_last_response_soap_envelope_element)
    {
        _last_response_soap_envelope_element->setAxiomNode(NULL);
        delete _last_response_soap_envelope_element;
    }
    if (_last_soap_fault)
    {
        _last_soap_fault->setAxiomNode(NULL);
        delete _last_soap_fault;
    }
    if (_options)
    {
        _options->_wsf_options = NULL;
        delete _options;
    }
    if (_conf_ctx)
    {
        axis2_conf_ctx_free(const_cast<axis2_conf_ctx_t *>(_conf_ctx), getEnv());
    }
    axis2_svc_client_free(_wsf_service_client, getEnv());
}

/** @brief ServiceClient
  *
  * @todo: document this function
  */
 ServiceClient::ServiceClient(const axis2_conf_ctx_t * conf_ctx, std::string endpoint_address)
{
    _conf_ctx = conf_ctx;
    _endpoint_address = endpoint_address;
    _repo_home = "";
}

/** @brief ServiceClient
  *
  * @todo: document this function
  */
 ServiceClient::ServiceClient(std::string repo_home, std::string endpoint_address)
{
    _conf_ctx = NULL;
    _endpoint_address = endpoint_address;
    _repo_home = repo_home;
}

/** @brief ServiceClient
  *
  * @todo: document this function
  */
 ServiceClient::ServiceClient(std::string endpoint_address)
{
    _conf_ctx = NULL;
    _endpoint_address = endpoint_address;
    _repo_home = string(AXIS2_GETENV("AXIS2C_HOME"));
}

/** @brief InitializeClient
  *
  * @todo: document this function
  */
void ServiceClient::initializeClient(std::string log_file, axutil_log_levels_t log_level) throw(AxisFault)
{
    initialize(log_file, log_level);
    if (_conf_ctx)
    {
        if (_repo_home == "")
        {
            axis2_conf_t * conf = axis2_conf_ctx_get_conf(_conf_ctx, getEnv());
            _repo_home = axis2_conf_get_repo(conf, getEnv());
        }
        _wsf_service_client = axis2_svc_client_create_with_conf_ctx_and_svc(getEnv(), _repo_home.c_str(),
            const_cast<axis2_conf_ctx_t *>(_conf_ctx), NULL);
    }
    _wsf_service_client = axis2_svc_client_create(getEnv(), _repo_home.c_str());
    if (!_wsf_service_client)
    {
        throw AxisFault("Creation of Service Failed");
    }
    _options = new Options();
    if (!_options->_wsf_options)
    {
        delete _options;
        throw AxisFault("Creation of Service Options Failed");
    }
    else
    {
        _options->setXMLParserReset(true);
        _options->setUseSeparateListener(false);
        _options->setTo(_endpoint_address);
        axis2_status_t status = axis2_svc_client_set_options(_wsf_service_client, getEnv(), _options->_wsf_options);
        if (status != AXIS2_TRUE)
        {
            throw AxisFault("Setting up Options Failed");
        }
    }
    _last_soap_fault = NULL;
}

/** @brief setOptions
  *
  * @todo: document this function
  */
bool ServiceClient::setOptions(Options * options)
{
    axis2_status_t status = AXIS2_FAILURE;
    if (options != NULL)
    {
        if (_options->_wsf_options == options->_wsf_options)
        {
            return true;
        }
        _options = options;
        status = axis2_svc_client_set_options(_wsf_service_client, getEnv(), _options->_wsf_options);
    }
    return (status == AXIS2_TRUE);
}

/** @brief getLastResponseSoapEnvelopeString
  *
  * @todo: document this function
  */
string ServiceClient::getLastResponseSoapEnvelopeString()
{
    axiom_soap_envelope_t * envelope =
        axis2_svc_client_get_last_response_soap_envelope(_wsf_service_client, getEnv());
    if (!envelope)
    {
        return "";
    }
    _last_response_soap_envelope = envelope;
    axiom_node_t * node = axiom_soap_envelope_get_base_node(_last_response_soap_envelope, getEnv());
    return axiom_node_to_string(node, getEnv());
}

/** @brief getLastResponseSoapEnvelope
  *
  * @todo: document this function
  */
OMElement * ServiceClient::getLastResponseSoapEnvelope()
{
    axiom_soap_envelope_t * envelope =
        axis2_svc_client_get_last_response_soap_envelope(_wsf_service_client, getEnv());
    if (!envelope)
    {
        return NULL;
    }
    _last_response_soap_envelope = envelope;
    axiom_node_t * node = axiom_soap_envelope_get_base_node(_last_response_soap_envelope, getEnv());
    axiom_element_t * element = NULL;
    if (node && (axiom_node_get_node_type(node, getEnv()) == AXIOM_ELEMENT))
    {
        element = (axiom_element_t *)axiom_node_get_data_element(node, getEnv());
    }
    if (!element)
    {
        return NULL;
    }
    axis2_bool_t has_fault =
        axis2_svc_client_get_last_response_has_fault(_wsf_service_client, getEnv());
    if (has_fault)
    {
        if (_last_soap_fault)
        {
            _last_soap_fault->setAxiomNode(NULL);
            delete _last_soap_fault;
        }
        _last_soap_fault = new OMElement(NULL, node);
        return NULL;
    }
    if (_last_response_soap_envelope_element)
    {
        _last_response_soap_envelope_element->setAxiomNode(NULL);
        delete _last_response_soap_envelope_element;
    }
    _last_response_soap_envelope_element = new OMElement(NULL, node);
    return _last_response_soap_envelope_element;
}

/** @brief request
  *
  * @todo: document this function
  */
OMElement * ServiceClient::request(OMElement * payload, std::string operation, std::string action) throw(AxisFault)
{
    return request(payload, NULL, operation, action);
}

/** @brief request
  *
  * @todo: document this function
  */
OMElement * ServiceClient::request(OMElement * payload, ICallback * callback, std::string action) throw(AxisFault)
{
    return request(payload, callback, "", action);
}

/** @brief request
  *
  * @todo: document this function
  */
OMElement * ServiceClient::request(OMElement * payload, ICallback * callback, std::string operation, std::string action) throw(AxisFault)
{
    axis2_status_t status = AXIS2_FAILURE;
    if (!payload)
    {
        throw AxisFault("Empty Payload");
    }
    if (action != "")
    {
        if (_options->getSoapVersion() == AXIOM_SOAP11)
        {
            axutil_string_t * soap_action = axutil_string_create(getEnv(), action.c_str());

            status = axis2_options_set_soap_action(_options->_wsf_options, getEnv(), soap_action);
            axutil_string_free(soap_action, getEnv());
            if (status != AXIS2_SUCCESS)
            {
                if (payload->getNamespace(false))
                {
                    (payload->getNamespace(false))->setAxiomNamespace(NULL);
                }
                payload->setAxiomNode(NULL);
                throw AxisFault("Failure occured while setting SOAP Action");
            }
        }
        else
        {
            axutil_qname_t * qname = axutil_qname_create(getEnv(), AXIS2_MODULE_ADDRESSING, NULL, NULL);
            axis2_bool_t engaged =
                axis2_svc_is_module_engaged(axis2_svc_client_get_svc(_wsf_service_client, getEnv()),
                getEnv(), qname);
            axutil_qname_free(qname, getEnv());
            if (engaged)
            {
                status = axis2_options_set_action(_options->_wsf_options, getEnv(), action.c_str());
                if (status != AXIS2_SUCCESS)
                {
                    if (payload->getNamespace(false))
                    {
                        (payload->getNamespace(false))->setAxiomNamespace(NULL);
                    }
                    payload->setAxiomNode(NULL);
                    throw AxisFault("Failure occured while setting Web Services Addressing (WSA) Action");
                }
            }
        }
    }
    axiom_node_t * node;
    if (!callback)
    {
        if (operation != "")
        {
            axutil_qname_t * qname =  axutil_qname_create(getEnv(), operation.c_str(), NULL, NULL);
            node = axis2_svc_client_send_receive_with_op_qname(_wsf_service_client, getEnv(),
                qname, payload->getAxiomNode());
            axutil_qname_free(qname, getEnv());
        }
        else
        {
            node = axis2_svc_client_send_receive(_wsf_service_client, getEnv(), payload->getAxiomNode());
        }
        if (!node)
        {
            if (payload->getNamespace(false))
            {
                (payload->getNamespace(false))->setAxiomNamespace(NULL);
            }
            payload->setAxiomNode(NULL);
            throw AxisFault("Send Recieve Operation Failed");
        }
        else
        {
            axiom_element_t * element = NULL;
            if (node && (axiom_node_get_node_type(node, getEnv()) == AXIOM_ELEMENT))
            {
                element = (axiom_element_t *)axiom_node_get_data_element(node, getEnv());
            }
            if (!element)
            {
                if (payload->getNamespace(false))
                {
                    (payload->getNamespace(false))->setAxiomNamespace(NULL);
                }
                payload->setAxiomNode(NULL);
                throw AxisFault("Unable to retrieve Response Element");
            }
            axis2_bool_t has_fault =
                axis2_svc_client_get_last_response_has_fault(_wsf_service_client, getEnv());
            if (has_fault)
            {
                if (_last_soap_fault)
                {
                    _last_soap_fault->setAxiomNode(NULL);
                    delete _last_soap_fault;
                }
                _last_soap_fault = new OMElement(NULL, node);
                if (payload->getNamespace(false))
                {
                    (payload->getNamespace(false))->setAxiomNamespace(NULL);
                }
                payload->setAxiomNode(NULL);
                throw AxisFault("A SOAP Fault Occured");
            }
            if (_last_response_soap_envelope_element)
            {
                _last_response_soap_envelope_element->setAxiomNode(NULL);
                delete _last_response_soap_envelope_element;
            }
            _last_response_soap_envelope_element = new OMElement(NULL, node);
            if (payload->getNamespace(false))
            {
                (payload->getNamespace(false))->setAxiomNamespace(NULL);
            }
            payload->setAxiomNode(NULL);
            return _last_response_soap_envelope_element;
        }
    }
    else
    {
// TODO (senaka#2#): implement callback
    }
}

/** @brief request
  *
  * @todo: document this function
  */
OMElement * ServiceClient::request(OMElement * payload, std::string action) throw(AxisFault)
{
    return request(payload, NULL, "", action);
}

/** @brief send
  *
  * @todo: document this function
  */
bool ServiceClient::send(OMElement * payload, bool robust, std::string action) throw(AxisFault)
{
    return send(payload, robust, "", action);
}

/** @brief send
  *
  * @todo: document this function
  */
bool ServiceClient::send(OMElement * payload, bool robust, std::string operation, std::string action) throw(AxisFault)
{
    axis2_status_t status = AXIS2_FAILURE;
    if (!payload)
    {
        throw AxisFault("Empty Payload");
    }
    if (action != "")
    {
        if (_options->getSoapVersion() == AXIOM_SOAP11)
        {
            axutil_string_t * soap_action = axutil_string_create(getEnv(), action.c_str());
            status = axis2_options_set_soap_action(_options->_wsf_options, getEnv(), soap_action);
            axutil_string_free(soap_action, getEnv());
            if (status != AXIS2_SUCCESS)
            {
                    if (payload->getNamespace(false))
                    {
                        (payload->getNamespace(false))->setAxiomNamespace(NULL);
                    }
                    payload->setAxiomNode(NULL);
                throw AxisFault("Failure occured while setting SOAP Action");
            }
        }
        else
        {
            axutil_qname_t * qname = axutil_qname_create(getEnv(), AXIS2_MODULE_ADDRESSING, NULL, NULL);
            axis2_bool_t engaged =
                axis2_svc_is_module_engaged(axis2_svc_client_get_svc(_wsf_service_client, getEnv()),
                getEnv(), qname);
            axutil_qname_free(qname, getEnv());
            if (engaged)
            {
                status = axis2_options_set_action(_options->_wsf_options, getEnv(), action.c_str());
                if (status != AXIS2_SUCCESS)
                {
                    if (payload->getNamespace(false))
                    {
                        (payload->getNamespace(false))->setAxiomNamespace(NULL);
                    }
                    payload->setAxiomNode(NULL);
                    throw AxisFault("Failure occured while setting Web Services Addressing (WSA) Action");
                }
            }
        }
    }
    if (robust)
    {
        if (operation != "")
        {
            axutil_qname_t * qname =  axutil_qname_create(getEnv(), operation.c_str(), NULL, NULL);
            status = axis2_svc_client_send_robust_with_op_qname(_wsf_service_client, getEnv(),
                qname, payload->getAxiomNode());
            axutil_qname_free(qname, getEnv());
        }
        else
        {
            status = axis2_svc_client_send_robust(_wsf_service_client, getEnv(), payload->getAxiomNode());
        }
        if (status != AXIS2_SUCCESS)
        {
            if (payload->getNamespace(false))
            {
                (payload->getNamespace(false))->setAxiomNamespace(NULL);
            }
            payload->setAxiomNode(NULL);
            throw AxisFault("Robust Send Operation Failed");
        }
        axis2_bool_t has_fault =
            axis2_svc_client_get_last_response_has_fault(_wsf_service_client, getEnv());
        if (has_fault)
        {
            if (payload->getNamespace(false))
            {
                (payload->getNamespace(false))->setAxiomNamespace(NULL);
            }
            payload->setAxiomNode(NULL);
            throw AxisFault("A SOAP Fault Occured");
        }
    }
    else
    {
        if (operation != "")
        {
            axutil_qname_t * qname =  axutil_qname_create(getEnv(), operation.c_str(), NULL, NULL);
            axis2_svc_client_fire_and_forget_with_op_qname(_wsf_service_client, getEnv(),
                qname, payload->getAxiomNode());
            axutil_qname_free(qname, getEnv());
        }
        else
        {
            axis2_svc_client_fire_and_forget(_wsf_service_client, getEnv(), payload->getAxiomNode());
        }
    }
    if (payload->getNamespace(false))
    {
        (payload->getNamespace(false))->setAxiomNamespace(NULL);
    }
    payload->setAxiomNode(NULL);
    return true;
}

/** @brief send
  *
  * @todo: document this function
  */
bool ServiceClient::send(OMElement * payload, std::string operation, std::string action) throw(AxisFault)
{
    return send(payload, true, operation, action);
}

/** @brief send
  *
  * @todo: document this function
  */
bool ServiceClient::send(OMElement * payload, std::string action) throw(AxisFault)
{
    return send(payload, true, "", action);
}

/** @brief setPolicy
  *
  * @todo: document this function
  */
bool ServiceClient::setPolicy(OMElement * policy)
{
// TODO (senaka#3#): implement neethi
    return false;
}

/** @brief removeAllHeaders
  *
  * @todo: document this function
  */
void ServiceClient::removeAllHeaders() throw(AxisFault)
{
    axis2_svc_client_remove_all_headers(_wsf_service_client, getEnv());
}

/** @brief addHeader
  *
  * @todo: document this function
  */
bool ServiceClient::addHeader(OMElement * header)
{
    axis2_status_t status =
        axis2_svc_client_add_header(_wsf_service_client, getEnv(), header->getAxiomNode());
    return (status == AXIS2_SUCCESS);
}

/** @brief disengageModule
  *
  * @todo: document this function
  */
bool ServiceClient::disengageModule(std::string module_name)
{
    axis2_status_t status =
        axis2_svc_client_disengage_module(_wsf_service_client, getEnv(), module_name.c_str());
    return (status == AXIS2_SUCCESS);
}

/** @brief engageModule
  *
  * @todo: document this function
  */
bool ServiceClient::engageModule(std::string module_name)
{
    axis2_status_t status =
        axis2_svc_client_engage_module(_wsf_service_client, getEnv(), module_name.c_str());
    return (status == AXIS2_SUCCESS);
}

/** @brief getOptions
  *
  * @todo: document this function
  */
Options * ServiceClient::getOptions()
{
    return _options;
}

/** @brief getLastSOAPFault
  *
  * @todo: document this function
  */
OMElement * ServiceClient::getLastSOAPFault()
{
    getLastResponseSoapEnvelope();
    return _last_soap_fault;
}

