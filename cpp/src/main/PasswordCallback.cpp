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

#include <PasswordCallback.h>
#include <axutil_string.h>

using namespace std;
using namespace wso2wsf;

WSF_EXTERN axis2_char_t* WSF_CALL PasswordCallback::callbackPassword(
    rampart_callback_t * callback, const axutil_env_t* env, const axis2_char_t *username, void *param)
{
    wsf_rampart_callback_t * cb = (wsf_rampart_callback_t*) callback;
    string str_username;
    if(username)
        str_username = username;
    string password = cb->callback->getPassword(str_username);
    return (axis2_char_t*)axutil_strdup(env, password.c_str());
}

WSF_EXTERN axis2_char_t* WSF_CALL PasswordCallback::callbackPKCS12Password(
    rampart_callback_t * callback, const axutil_env_t* env, const axis2_char_t *username, void *param)
{
    wsf_rampart_callback_t * cb = (wsf_rampart_callback_t*) callback;
    string str_username;
    if(username)
        str_username = username;
    string password = cb->callback->getPKCS12Password(str_username);
    return (axis2_char_t*)axutil_strdup(env, password.c_str());
}

WSF_EXTERN WSF_CALL PasswordCallback::~PasswordCallback()
{
}