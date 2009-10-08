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

#ifndef NEETHIPOLICY_H
#define NEETHIPOLICY_H

#include <WSFDefines.h>
#include <OMElement.h>
#include <neethi_policy.h>
#include <neethi_util.h>

/**
 * @file NeethiPolicy.h
 * @brief NetthiPolicy is the WS-Policy abstraction in WSF/CPP Framework.
 */

/**
 * @brief namespace wso2wsf Namespace of WSO2 Web Services Framework.
 */
namespace wso2wsf
{
    /**
     * @defgroup neethi_policy Neethi Policy
     * @ingroup wso2wsf
     * @{
     */

    /**
     * @brief class NeethiPolicy Defines a policy object that can be used to
     * provide WS-Policy information. This is a wrapper to the XML policy
     * advertisement used in WS-Security, WS-Reliable Messaging etc.
     */
    class NeethiPolicy 
    {
    private:
        /**
         * _wsf_neethi_policy protected variable holds reference for
         * neethi_policy struct.
         */
        neethi_policy_t * _wsf_neethi_policy;

    public:
        /**
         * Method to get the reference to the neethi_policy struct.
         * @return reference to the neethi_policy struct.
         */
        neethi_policy_t * WSF_CALL getNeethiPolicy();

        /**
         * Method to set the reference to the neethi_policy struct.
         * @param policy reference to the neethi_policy struct.
         */
        void WSF_CALL setNeethiPolicy(neethi_policy_t * policy);

        /**
         * Constructor for the NeethiPolicy Class. Accepts the policy file name as the argument.
         * @param file_name file name.
         */
        WSF_EXTERN WSF_CALL NeethiPolicy(std::string file_name);

        /**
         * Constructor for NeethiPolicy Class. Accepts an OMElement representing the WS-Policy XML
         * @param element OM element which is the root of WS-Policy XML.
         */
        WSF_EXTERN WSF_CALL NeethiPolicy(OMElement * element);

        /**
         * Destructor for the NeethiPolicy class.
         */
        virtual WSF_CALL ~NeethiPolicy();

        /**
         * Sets policy name.
         * @param name name to set.
         * @return true if successful, false otherwise.
         */
        WSF_EXTERN bool WSF_CALL setName(std::string name);

        /**
         * Gets policy name.
         * @return policy name as string.
         */
        WSF_EXTERN std::string WSF_CALL getName();

        /**
         * Sets policy id.
         * @param id id to set.
         * @return true if successful, false otherwise.
         */
        WSF_EXTERN bool WSF_CALL setId(std::string id);

        /**
         * Gets policy id.
         * @return policy id as string.
         */
        WSF_EXTERN std::string WSF_CALL getId();

    };
    /** @} */
}
#endif // NEETHIPOLICY_H
