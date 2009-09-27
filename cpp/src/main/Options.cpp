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

#include <stdio.h>
#include <Options.h>
#include <Environment.h>

using namespace std;
using namespace wso2wsf;

/** @brief setHTTPMethod
  *
  * @todo: document this function
  */
void Options::setHTTPMethod(std::string http_method)
{
    axis2_options_set_http_method(_wsf_options, Environment::getEnv(), http_method.c_str());
}


axis2_options_t* WSF_CALL Options::getAxis2Options()
{
	return _wsf_options;
}

/** @brief getEnableMTOM
  *
  * @todo: document this function
  */
bool Options::getEnableMTOM()
{
    axis2_bool_t enabled = axis2_options_get_enable_mtom(_wsf_options, Environment::getEnv());
    if (enabled)
    {
        return true;
    }
    return false;
}

/** @brief setEnableMTOM
  *
  * @todo: document this function
  */
void Options::setEnableMTOM(bool enable)
{
    if (enable)
    {
        axis2_options_set_enable_mtom(_wsf_options, Environment::getEnv(), AXIS2_TRUE);
    }
    else
    {
        axis2_options_set_enable_mtom(_wsf_options, Environment::getEnv(), AXIS2_FALSE);
    }
}

/** @brief setSoapVersion
  *
  * @todo: document this function
  */
void Options::setSoapVersion(soap_version version)
{
    axis2_options_set_soap_version(_wsf_options, Environment::getEnv(), static_cast<int>(version));
}

/** @brief getSoapVersion
  *
  * @todo: document this function
  */
soap_version Options::getSoapVersion()
{
    return static_cast<soap_version>(axis2_options_get_soap_version(_wsf_options, Environment::getEnv()));
}

/** @brief addReferenceParameter
  *
  * @todo: document this function
  */
void Options::addReferenceParameter(OMElement * reference_parameter)
{
    axis2_options_add_reference_parameter(_wsf_options, Environment::getEnv(), reference_parameter->getAxiomNode());
}

/** @brief setTimeout
  *
  * @todo: document this function
  */
void Options::setTimeout(long timeout)
{
    axis2_options_set_timeout_in_milli_seconds(_wsf_options, Environment::getEnv(), timeout);
}

/** @brief setReplyTo
  *
  * @todo: document this function
  */
void Options::setReplyTo(std::string reply_to)
{
    _reply_to =  axis2_endpoint_ref_create(Environment::getEnv(), reply_to.c_str());
    axis2_options_set_reply_to(_wsf_options, Environment::getEnv(), _reply_to);
}

/** @brief setProperty
  *
  * @todo: document this function
  */
bool Options::setProperty(Property * property)
{
    axis2_status_t status = axis2_options_set_property(_wsf_options, Environment::getEnv(), property->getName().c_str(), property->getValue());
    return (status == AXIS2_SUCCESS);
}

/** @brief setMessageId
  *
  * @todo: document this function
  */
void Options::setMessageId(std::string message_id)
{
    const axis2_char_t* msg_id= NULL;
    if(message_id != "")
    {
        msg_id = message_id.c_str();
    }

    axis2_options_set_message_id(_wsf_options, Environment::getEnv(), msg_id);
}

/** @brief setTo
  *
  * @todo: document this function
  */
void Options::setTo(std::string to)
{
    _to =  axis2_endpoint_ref_create(Environment::getEnv(), to.c_str());
    axis2_options_set_to(_wsf_options, Environment::getEnv(), _to);
}

/** @brief setFrom
  *
  * @todo: document this function
  */
void Options::setFrom(std::string from)
{
    _from =  axis2_endpoint_ref_create(Environment::getEnv(), from.c_str());
    axis2_options_set_from(_wsf_options, Environment::getEnv(), _from);
}

/** @brief setFaultTo
  *
  * @todo: document this function
  */
void Options::setFaultTo(std::string fault_to)
{
    _fault_to =  axis2_endpoint_ref_create(Environment::getEnv(), fault_to.c_str());
    axis2_options_set_fault_to(_wsf_options, Environment::getEnv(), _fault_to);
}

/** @brief getTo
  *
  * @todo: document this function
  */
string Options::getTo()
{
    return axis2_endpoint_ref_get_address(_to, Environment::getEnv());
}

/** @brief getTimeout
  *
  * @todo: document this function
  */
long Options::getTimeout()
{
    return axis2_options_get_timeout_in_milli_seconds(_wsf_options, Environment::getEnv());
}

/** @brief getReplyTo
  *
  * @todo: document this function
  */
string Options::getReplyTo()
{
    const axis2_char_t *repltyto = axis2_endpoint_ref_get_address(_reply_to, Environment::getEnv());
	if(repltyto)
		return repltyto;
	return "";
}

/** @brief getMessageId
  *
  * @todo: document this function
  */
string Options::getMessageId()
{
    const axis2_char_t *msgid = axis2_options_get_message_id(_wsf_options, Environment::getEnv());
	return msgid != NULL ? msgid : "";
}

/** @brief getFrom
  *
  * @todo: document this function
  */
string Options::getFrom()
{
    const axis2_char_t *from = axis2_endpoint_ref_get_address(_from, Environment::getEnv());
	return from != NULL ? from : "";
}

/** @brief getFaultTo
  *
  * @todo: document this function
  */
string Options::getFaultTo()
{
    const axis2_char_t* faulto = axis2_endpoint_ref_get_address(_fault_to, Environment::getEnv());
	return faulto != NULL ? faulto : "";
}

/** @brief ~Options
  *
  * @todo: document this function
  */
 Options::~Options()
{
    if(_wsf_options)
    {
        axis2_options_free(_wsf_options, Environment::getEnv());
    }
}

/** @brief Options
  *
  * @todo: document this function
  */
 Options::Options()
{
    _wsf_options = axis2_options_create(Environment::getEnv());
    _reply_to = NULL;
    _to = NULL;
    _from = NULL;
    _fault_to = NULL;

}

/** @brief setEnableREST
  *
  * @todo: document this function
  */
void Options::setEnableREST(bool enable)
{
    if (enable)
    {
        axis2_options_set_enable_rest(_wsf_options, Environment::getEnv(), AXIS2_TRUE);
    }
    else
    {
        axis2_options_set_enable_rest(_wsf_options, Environment::getEnv(), AXIS2_FALSE);
    }
}

/** @brief setXMLParserReset
  *
  * @todo: document this function
  */
void Options::setXMLParserReset(bool paser_reset)
{
    if (paser_reset)
    {
        axis2_options_set_xml_parser_reset(_wsf_options, Environment::getEnv(), AXIS2_TRUE);
    }
    else
    {
        axis2_options_set_xml_parser_reset(_wsf_options, Environment::getEnv(), AXIS2_FALSE);
    }
}

/** @brief setUseSeparateListener
  *
  * @todo: document this function
  */
void Options::setUseSeparateListener(bool use_separate_listener)
{
    if (use_separate_listener)
    {
        axis2_options_set_use_separate_listener(_wsf_options, Environment::getEnv(), AXIS2_TRUE);
    }
    else
    {
        axis2_options_set_use_separate_listener(_wsf_options, Environment::getEnv(), AXIS2_FALSE);
    }
}

bool Options::setHTTPAuthInfo(string username, string password, string authType)
{
	axis2_status_t status = AXIS2_FAILURE;
	status = axis2_options_set_http_auth_info(_wsf_options, Environment::getEnv(),(axis2_char_t*)username.c_str(), 
		(axis2_char_t*)password.c_str(), (axis2_char_t*)authType.c_str());
	return status ? true : false;
}

bool Options::setProxyAuthInfo(string username, string password, string authType)
{
	axis2_status_t status = AXIS2_FAILURE;
	status = axis2_options_set_proxy_auth_info(_wsf_options, Environment::getEnv(), 
		(axis2_char_t*)username.c_str(), (axis2_char_t*)password.c_str(), (axis2_char_t*)authType.c_str());
	return status ? true : false;
}

bool Options::setTestHTTPAuth(bool testHTTPAuth)
{
	axis2_status_t status = AXIS2_FAILURE;
	status = axis2_options_set_test_http_auth(_wsf_options, Environment::getEnv(),(testHTTPAuth ? AXIS2_TRUE : AXIS2_FALSE));
	return status ? true : false;
}

bool Options::setTestProxyAuth(bool testProxyAuth)
{
	axis2_status_t status = AXIS2_FAILURE;
	status = axis2_options_set_test_proxy_auth(_wsf_options, Environment::getEnv(), testProxyAuth ? AXIS2_TRUE : AXIS2_FALSE);
	return status ? true : false;
}

bool Options::setAction(std::string action)
{
	axis2_status_t status = AXIS2_FAILURE;
	if(_wsf_options)
	{
		status = axis2_options_set_action(_wsf_options, Environment::getEnv(), action.c_str());
		status =axis2_options_set_soap_action(_wsf_options, 
			Environment::getEnv(),
			axutil_string_create(Environment::getEnv(),action.c_str()));
		return status  ? true :false;
	}
	return false;
}
