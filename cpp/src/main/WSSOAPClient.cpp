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
#include <WSSOAPClient.h>
using namespace std;
using namespace wso2wsf;

/** @brief setOptions
  *
  * @todo: document this function
  */
bool WSSOAPClient::setOptions(Options * options)
{
    options->setEnableREST(false);
    return ServiceClient::setOptions(options);
}

/** @brief WSSOAPClient
  *
  * @todo: document this function
  */
 WSSOAPClient::WSSOAPClient(const axis2_conf_ctx_t * conf_ctx, std::string endpoint_address)
    :ServiceClient(conf_ctx, endpoint_address)
{}

/** @brief WSSOAPClient
  *
  * @todo: document this function
  */
 WSSOAPClient::WSSOAPClient(std::string repo_home, std::string endpoint_address)
    :ServiceClient(repo_home, endpoint_address)
{}

/** @brief WSSOAPClient
  *
  * @todo: document this function
  */
 WSSOAPClient::WSSOAPClient(std::string endpoint_address)
    :ServiceClient(endpoint_address)
{}
