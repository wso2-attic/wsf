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
#include <WSFError.h>
#include <NeethiPolicy.h>
#include <Environment.h>
using namespace std;
using namespace wso2wsf;

NeethiPolicy::~NeethiPolicy()
 {
	 if ( _wsf_neethi_policy)
	 {
		 neethi_policy_free(_wsf_neethi_policy,Environment::getEnv());
	 }
 }

NeethiPolicy::NeethiPolicy(OMElement * element)
{
    _wsf_neethi_policy = NULL;
    if (element && (element->getAxiomNode()))
    {
        _wsf_neethi_policy = neethi_util_create_policy_from_om(Environment::getEnv(), element->getAxiomNode());
    }
}

NeethiPolicy::NeethiPolicy(std::string file_name)
{
    _wsf_neethi_policy = NULL;
    if (file_name != "")
    {
        _wsf_neethi_policy = neethi_util_create_policy_from_file(
            Environment::getEnv(), const_cast<char *>(file_name.c_str()));
    }
}

void NeethiPolicy::setNeethiPolicy(neethi_policy_t * policy)
{
    _wsf_neethi_policy = policy;
}

neethi_policy_t * NeethiPolicy::getNeethiPolicy()
{
    return _wsf_neethi_policy;
}

bool NeethiPolicy::setName(std::string name)
{
    axis2_status_t status =
        neethi_policy_set_name(_wsf_neethi_policy, Environment::getEnv(), const_cast<char *>(name.c_str()));
    return (status == AXIS2_SUCCESS);
}

std::string NeethiPolicy::getName()
{
	axis2_char_t* policyName = neethi_policy_get_name(_wsf_neethi_policy, Environment::getEnv());
	if(policyName)
		return policyName;
	else
		return "";
}

bool NeethiPolicy::setId(std::string id)
{
    axis2_status_t status =
        neethi_policy_set_id(_wsf_neethi_policy, Environment::getEnv(), const_cast<char *>(id.c_str()));
    return (status == AXIS2_SUCCESS);
}

std::string NeethiPolicy::getId()
{
	axis2_char_t *policyId = neethi_policy_get_id(_wsf_neethi_policy, Environment::getEnv());
	if(policyId)
		return policyId;
	else
		return "";
}
