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

#ifndef WSRESTCLIENT_H
#define WSRESTCLIENT_H

#include <WSFDefines.h>
#include <ServiceClient.h>

/**
 * @file WSRESTClient.h
 */

/**
 * @brief namespace wso2wsf Namespace of WSO2 Web Services Framework.
 */
namespace wso2wsf
{
    /**
     * @defgroup ws_rest_client WS REST Client
     * @ingroup wso2wsf
     * @{
     */

    /**
     * @brief class WSRESTClient This object serves as the primary client
     * for consuming REST services.
     */
    class WSRESTClient: public ServiceClient
    {
    public:
        /**
         * Sets the options to be used by service client.
         * @param options pointer to options struct to be set.
         * @return true on success or false on failure.
         */
        WSF_EXTERN bool WSF_CALL setOptions(Options * options);

        /**
         * create a WS REST client from the default repository.
         * @param endpoint_address endpoint address to be used.
         */
        WSF_EXTERN WSF_CALL WSRESTClient(std::string endpoint_address);

        /**
         * create a WS REST client from the repository.
         * @param repo_home location of the repository.
         * @param endpoint_address endpoint address to be used.
         */
        WSF_EXTERN WSF_CALL WSRESTClient(std::string repo_home, std::string endpoint_address);

        /**
         * create a WS REST client from a configuration context.
         * @param conf_ctx pointer to configuration context.
         * @param endpoint_address endpoint address to be used.
         */
        WSF_EXTERN WSF_CALL WSRESTClient(const axis2_conf_ctx_t * conf_ctx, std::string endpoint_address);
    };
    /** @} */
}
#endif // WSRESTCLIENT_H
