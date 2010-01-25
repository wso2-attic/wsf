/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License")
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
#ifndef REG_CLIENT_CONSTANTS_H
#define REG_CLIENT_CONSTANTS_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @defgroup reg_client_constants
 * @ingroup reg_client
 * @{
 */
    
    #define REG_CLIENT_ACTIVE_STATE  100
    #define REG_CLIENT_DELETED_STATE 101

	#define REG_CLIENT "reg_client"
    #define REG_CLIENT_USER_AGENT "RESTClient C Library"
    #define REG_CLIENT_ATOM_DATA_FILE_NAME "atom_data.xml"
    #define REG_CLIENT_ATOM_NS "http://www.w3.org/2005/Atom"
    #define REG_CLIENT_REGISTRY_URL "registry_url"
    #define REG_CLIENT_REGISTRY_USERNAME "registry_username"
    #define REG_CLIENT_REGISTRY_PASSWORD "registry_password"

/** @} */
#ifdef __cplusplus
}
#endif
 
#endif /*REG_CLIENT_CONSTANTS_H*/
