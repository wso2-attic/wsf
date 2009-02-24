/*
 * Copyright 2005,2009 WSO2, Inc. http://wso2.com
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
using namespace std;
using namespace wso2wsf;

/** @brief ~NeethiPolicy
  *
  * @todo: document this function
  */
 NeethiPolicy::~NeethiPolicy()
 {
	 if ( _wsf_neethi_policy)
	 {
		 delete _wsf_neethi_policy;
	 }
 }

/** @brief NeethiPolicy
  *
  * @todo: document this function
  */
 NeethiPolicy::NeethiPolicy(OMElement * element) throw (NeethiException)
{
    _wsf_neethi_policy = NULL;
    if (element && (element->getAxiomNode()))
    {
        _wsf_neethi_policy = neethi_util_create_policy_from_om(getEnv(), element->getAxiomNode());
    }
    if (!_wsf_neethi_policy)
    {
        throw NeethiException(CREATION_OF_NEETHI_POLICY_OBJECT_FAILED);
    }
}

/** @brief NeethiPolicy
  *
  * @todo: document this function
  */
 NeethiPolicy::NeethiPolicy(std::string file_name) throw (NeethiException)
{
    _wsf_neethi_policy = NULL;
    if (file_name != "")
    {
// TODO (senaka#4#): report bug 2 axis and remove const_cast
        _wsf_neethi_policy = neethi_util_create_policy_from_file(getEnv(), const_cast<char *>(file_name.c_str()));
    }
    if (!_wsf_neethi_policy)
    {
        throw NeethiException(CREATION_OF_NEETHI_POLICY_OBJECT_FAILED);
    }
}

/** @brief setNeethiPolicy
  *
  * @todo: document this function
  */
void NeethiPolicy::setNeethiPolicy(neethi_policy_t * policy)
{
    _wsf_neethi_policy = policy;
}

/** @brief getNeethiPolicy
  *
  * @todo: document this function
  */
neethi_policy_t * NeethiPolicy::getNeethiPolicy()
{
    return _wsf_neethi_policy;
}

/** @brief setName
  *
  * @todo: document this function
  */
bool NeethiPolicy::setName(std::string name)
{
// TODO (senaka#4#): report bug 2 axis and remove const_cast
    axis2_status_t status =
        neethi_policy_set_name(_wsf_neethi_policy, getEnv(), const_cast<char *>(name.c_str()));
    return (status == AXIS2_SUCCESS);
}

/** @brief getName
  *
  * @todo: document this function
  */
std::string NeethiPolicy::getName()
{
    return neethi_policy_get_name(_wsf_neethi_policy, getEnv());
}

/** @brief setId
  *
  * @todo: document this function
  */
bool NeethiPolicy::setId(std::string id)
{
// TODO (senaka#4#): report bug 2 axis and remove const_cast
    axis2_status_t status =
        neethi_policy_set_id(_wsf_neethi_policy, getEnv(), const_cast<char *>(id.c_str()));
    return (status == AXIS2_SUCCESS);
}

/** @brief getId
  *
  * @todo: document this function
  */
std::string NeethiPolicy::getId()
{
    return neethi_policy_get_id(_wsf_neethi_policy, getEnv());
}
