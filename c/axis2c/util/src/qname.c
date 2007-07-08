/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <axutil_qname.h>
#include <axutil_env.h>
#include <axutil_utils.h>
#include <axutil_utils_defines.h>
#include <string.h>
#include <stdio.h>

struct axutil_qname
{
    /** localpart of qname is mandatory */
    axis2_char_t *localpart;
    /** namespace uri is optional */
    axis2_char_t *namespace_uri;
    /**  prefix mandatory */
    axis2_char_t *prefix;
    /** qname represented as a string, used as keys in hash tables, etc. */
    axis2_char_t *qname_string;
    unsigned int ref;
};

AXIS2_EXTERN axutil_qname_t * AXIS2_CALL
axutil_qname_create(const axutil_env_t *env,
    const axis2_char_t *localpart,
    const axis2_char_t *namespace_uri,
    const axis2_char_t *prefix)
{

    axutil_qname_t *qname = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    /* localpart can't be null */
    if (!localpart)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, 
            AXIS2_FAILURE);
        return NULL;
    }

    qname = (axutil_qname_t *) AXIS2_MALLOC(env->allocator,
            sizeof(axutil_qname_t));
    if (!qname)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    /* set properties */
    qname->localpart = NULL;
    qname->qname_string = NULL;
    qname->prefix = NULL;
    qname->namespace_uri = NULL;
    qname->ref = 1;


    qname->localpart = (axis2_char_t *)axutil_strdup(env, localpart);
    if (!(qname->localpart))
    {
        AXIS2_ERROR_SET_ERROR_NUMBER(env->error, AXIS2_ERROR_NO_MEMORY);
        AXIS2_ERROR_SET_STATUS_CODE(env->error, AXIS2_FAILURE);
        axutil_qname_free(qname, env);
        return NULL;
    }
    
    if (prefix)
    {
        qname->prefix = (axis2_char_t*)axutil_strdup(env, prefix);
    }
    
    if (prefix && !(qname->prefix))
    {
        AXIS2_ERROR_SET_ERROR_NUMBER(env->error, AXIS2_ERROR_NO_MEMORY);
        AXIS2_ERROR_SET_STATUS_CODE(env->error, AXIS2_FAILURE);
        axutil_qname_free(qname, env);
        return NULL;
    }
    
    if (namespace_uri)
    {
        qname->namespace_uri = (axis2_char_t*)axutil_strdup(env, namespace_uri);
    }

    if (namespace_uri && !(qname->namespace_uri))
    {
        AXIS2_ERROR_SET_ERROR_NUMBER(env->error, AXIS2_ERROR_NO_MEMORY);
        AXIS2_ERROR_SET_STATUS_CODE(env->error, AXIS2_FAILURE);
        axutil_qname_free(qname, env);
        return NULL;
    }

    return qname;
}


AXIS2_EXTERN void AXIS2_CALL
axutil_qname_free(axutil_qname_t * qname,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    qname->ref--;

    if (qname->ref > 0)
    {
        return;
    }

    if (qname->localpart)
    {
        AXIS2_FREE(env->allocator, qname->localpart);
    }
    if (qname->namespace_uri)
    {
        AXIS2_FREE(env->allocator, qname->namespace_uri);
    }
    if (qname->prefix)
    {
        AXIS2_FREE(env->allocator, qname->prefix);
    }
    if (qname->qname_string)
    {
        AXIS2_FREE(env->allocator, qname->qname_string);
    }

    AXIS2_FREE(env->allocator, qname);

    return;
}


AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axutil_qname_equals(const axutil_qname_t *qname,
    const axutil_env_t *env,
    const axutil_qname_t *qname2)
{
    int uris_differ = 0;
    int localparts_differ = 0;

    AXIS2_ENV_CHECK(env, AXIS2_FALSE);

    if (!qname2)
    {
        AXIS2_ERROR_SET_ERROR_NUMBER(env->error, AXIS2_ERROR_INVALID_NULL_PARAM);
        AXIS2_ERROR_SET_STATUS_CODE(env->error, AXIS2_FAILURE);
        return AXIS2_FALSE;
    }

    if (qname->localpart && qname2->localpart)
    {
        localparts_differ =
            axutil_strcmp(qname->localpart,
                qname2->localpart);
    }
    else
    {
        localparts_differ = ((qname->localpart) || (qname2->localpart));
    }
    
    if (qname->namespace_uri && qname2->namespace_uri)
    {
        uris_differ =
            axutil_strcmp(qname->namespace_uri,
                qname2->namespace_uri);
    }
    else
    {
        uris_differ = ((qname->namespace_uri) || (qname2->namespace_uri));
    }
    
    return (!uris_differ && !localparts_differ) ? AXIS2_TRUE : AXIS2_FALSE;
}


AXIS2_EXTERN axutil_qname_t* AXIS2_CALL
axutil_qname_clone(axutil_qname_t *qname,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    
    if (!qname)
    {
        return NULL;
    }

    qname->ref++;
    
    return qname;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
axutil_qname_get_uri(const axutil_qname_t *qname,
    const axutil_env_t *env)
{
    return qname->namespace_uri;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
axutil_qname_get_prefix(const axutil_qname_t *qname,
    const axutil_env_t *env)
{
    return qname->prefix;
}


AXIS2_EXTERN axis2_char_t* AXIS2_CALL
axutil_qname_get_localpart(const axutil_qname_t *qname,
    const axutil_env_t *env)
{
    return qname->localpart;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
axutil_qname_to_string(axutil_qname_t *qname,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    if (qname->qname_string)
    {
        return qname->qname_string;
    }

    if (!(qname->namespace_uri) || axutil_strcmp(qname->namespace_uri, "") == 0)
    {
        qname->qname_string = axutil_strdup(env, qname->localpart);
    }
    else if (!(qname->prefix) || axutil_strcmp(qname->prefix, "") == 0)
    {

        axis2_char_t *temp_string1 = NULL;
        temp_string1 = axutil_stracat(env, qname->localpart, "|");
        qname->qname_string = axutil_stracat(env, temp_string1, qname->namespace_uri);
        if (temp_string1)
        {
            AXIS2_FREE(env->allocator, temp_string1);
        }
    }
    else
    {
        axis2_char_t *temp_string1 = NULL;
        axis2_char_t *temp_string2 = NULL;
        axis2_char_t *temp_string3 = NULL;

        temp_string1 = axutil_stracat(env, qname->localpart, "|");
        temp_string2 = axutil_stracat(env, temp_string1, qname->namespace_uri);
        temp_string3 = axutil_stracat(env, temp_string2, "|");
        qname->qname_string = axutil_stracat(env, temp_string3, qname->prefix);

        if (temp_string1)
        {
            AXIS2_FREE(env->allocator, temp_string1);
        }
        if (temp_string2)
        {
            AXIS2_FREE(env->allocator, temp_string2);
        }
        if (temp_string3)
        {
            AXIS2_FREE(env->allocator, temp_string3);
        }
    }
    return qname->qname_string;
}

AXIS2_EXTERN axutil_qname_t* AXIS2_CALL
axutil_qname_create_from_string(const axutil_env_t *env,
    const axis2_char_t *qstring)
{
    axis2_char_t *localpart = NULL;
    axis2_char_t *namespace_uri = NULL;
    axis2_char_t *prefix = NULL;
    axis2_char_t *index = NULL;
    axis2_char_t *next = NULL;
    axis2_char_t *temp_string = NULL;
    axutil_qname_t *qname = NULL;
    if (!qstring || axutil_strcmp(qstring, "") == 0)
        return NULL;

    temp_string = axutil_strdup(env, qstring);

    index = strchr(temp_string, '|');
    if (index)
    {

        next = index + 1;
        temp_string[index - temp_string] = '\0';

        localpart = temp_string;

        index = strchr(next, '|');
        if (index)
        {
            prefix = index + 1;
            next[index - next] = '\0';
            namespace_uri = next;

            qname = axutil_qname_create(env, localpart, namespace_uri, prefix);
        }
        else
        {
            /** only uri and localpart is available */
            qname = axutil_qname_create(env, localpart, next, NULL);
        }
    }
    else
    {
        /** only localpart is there in this qname */
        qname = axutil_qname_create(env, temp_string, NULL, NULL);
    }
    if (temp_string)
    {
        AXIS2_FREE(env->allocator, temp_string);
    }
    return qname;
}

