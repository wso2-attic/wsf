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

#include  "_axiom_soap_envelope.h"
#include "_axiom_soap_header.h"
#include <axiom_soap_header_block.h>
#include <axutil_hash.h>
#include <axiom_soap_const.h>
#include <axiom_soap_builder.h>
#include <stdio.h>
#include <axiom_node_internal.h>
#include <axutil_array_list.h>

struct axiom_soap_header
{
    axiom_node_t *om_ele_node;

    int soap_version;

    axutil_hash_t *header_blocks;

    int hbnumber;

    axiom_soap_builder_t *soap_builder;

    axutil_array_list_t *header_block_keys;
};

static axis2_bool_t AXIS2_CALL
axiom_soap_header_qname_matches(const axutil_env_t *env,
        axutil_qname_t *element_qname,
        axutil_qname_t *qname_to_match);

AXIS2_EXTERN axiom_soap_header_t * AXIS2_CALL
axiom_soap_header_create(const axutil_env_t *env)
{
    axiom_soap_header_t *soap_header = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    soap_header = (axiom_soap_header_t*)AXIS2_MALLOC(
                env->allocator,
                sizeof(axiom_soap_header_t));
    if (!soap_header)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    soap_header->om_ele_node     = NULL;
    soap_header->hbnumber = 0;
    soap_header->header_blocks = NULL;
    /** default value */
    soap_header->soap_version = AXIOM_SOAP12;
    soap_header->header_block_keys = NULL;

    soap_header->header_block_keys = axutil_array_list_create(env, 10);
    if (!soap_header->header_block_keys)
    {
        AXIS2_FREE(env->allocator, soap_header);
        return NULL;
    }

    return soap_header;
}


AXIS2_EXTERN axiom_soap_header_t * AXIS2_CALL
axiom_soap_header_create_with_parent(const axutil_env_t *env,
        axiom_soap_envelope_t *envelope)
{
    axiom_soap_header_t *soap_header = NULL;

    axiom_element_t *this_ele = NULL;
    axiom_node_t *this_node = NULL;
    axiom_node_t *body_node = NULL;
    axiom_node_t *parent_node = NULL;
    axiom_element_t *parent_ele = NULL;

    axiom_namespace_t *parent_ns = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, envelope, NULL);

    soap_header = axiom_soap_header_create(env);
    if (!soap_header)
        return NULL;

    soap_header->soap_version = axiom_soap_envelope_get_soap_version(envelope, env);

    parent_node = axiom_soap_envelope_get_base_node(envelope, env);

    if (!parent_node ||
            axiom_node_get_node_type(parent_node, env) != AXIOM_ELEMENT)
    {
        axiom_soap_header_free(soap_header, env);
        return NULL;
    }

    parent_ele = (axiom_element_t *)
            axiom_node_get_data_element(parent_node, env);
    if (!parent_ele)
    {
        axiom_soap_header_free(soap_header, env);
        return NULL;
    }
    if (axiom_node_get_first_child(parent_node, env))
    {
        body_node = axiom_node_get_first_child(parent_node, env);
        axiom_node_detach(body_node, env);
    }

    parent_ns = axiom_element_get_namespace(parent_ele, env, parent_node);
    this_ele = axiom_element_create(env, parent_node,
            AXIOM_SOAP_HEADER_LOCAL_NAME, parent_ns, &this_node);
    if (!this_ele)
    {
        axiom_soap_header_free(soap_header, env);
        return NULL;
    }

    soap_header->om_ele_node = this_node;
    axiom_soap_envelope_set_header(envelope, env, soap_header);

    if (body_node)
    {
        axiom_node_add_child(parent_node, env, body_node);
    }
    return soap_header;
}

AXIS2_EXTERN void AXIS2_CALL
axiom_soap_header_free(axiom_soap_header_t *soap_header,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (soap_header->header_blocks)
    {
        axutil_hash_index_t *hi = NULL;
        void *val = NULL;
        for (hi = axutil_hash_first(soap_header->header_blocks , env); hi;
                hi = axutil_hash_next(env, hi))
        {
            axutil_hash_this(hi, NULL , NULL, &val);

            if (val)
            {
                axiom_soap_header_block_free((axiom_soap_header_block_t *)val, env);
                val = NULL;
            }
        }

        axutil_hash_free(soap_header->header_blocks, env);
    }
    if (soap_header->header_block_keys)
    {
        int size = 0;
        void *val = NULL;
        int i = 0;
        size = axutil_array_list_size(soap_header->header_block_keys, env);
        for (i = 0; i < size; i++)
        {
            val = axutil_array_list_get(soap_header->header_block_keys, env, i);
            if (val)
            {
                AXIS2_FREE(env->allocator, (char*)val);
                val = NULL;
            }
        }
        axutil_array_list_free(soap_header->header_block_keys, env);
        soap_header->header_block_keys = NULL;
    }
    AXIS2_FREE(env->allocator, soap_header);

    soap_header = NULL;

    return;
}

AXIS2_EXTERN axiom_soap_header_block_t* AXIS2_CALL
axiom_soap_header_add_header_block(axiom_soap_header_t* soap_header,
        const axutil_env_t *env,
        const axis2_char_t *localname,
        axiom_namespace_t *ns)
{
    axiom_soap_header_block_t *header_block = NULL;

    axiom_namespace_t *cloned_ns = NULL;

    axiom_node_t* header_block_node = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, localname, NULL);
    AXIS2_PARAM_CHECK(env->error, ns, NULL);

    cloned_ns = axiom_namespace_clone(ns, env);
    if (!cloned_ns)
        return NULL;

    header_block = axiom_soap_header_block_create_with_parent(env, localname, cloned_ns, soap_header);

    if (!header_block)
        return NULL;

    header_block_node = axiom_soap_header_block_get_base_node(
                header_block, env);

    if (header_block_node)
    {
        axiom_element_t *hb_ele =  NULL;
        axis2_char_t *uri = NULL;
        axis2_char_t *prefix = NULL;

        axiom_node_set_complete(header_block_node, env, AXIS2_TRUE);

        hb_ele = (axiom_element_t *)
                axiom_node_get_data_element(header_block_node, env);
        if (hb_ele)
        {
            axiom_namespace_t *dec_ns = NULL;
            uri = axiom_namespace_get_uri(cloned_ns, env);
            prefix = axiom_namespace_get_prefix(cloned_ns, env);

            dec_ns = axiom_element_find_declared_namespace(hb_ele, env, uri, prefix);
            if (!dec_ns)
            {
                /** this namespace it not in hb_ele list so free it */
                axiom_namespace_free(cloned_ns, env);
                cloned_ns = NULL;
            }

        }
        return header_block;
    }
    else
    {
        return  NULL;
    }
}
AXIS2_EXTERN axutil_hash_t* AXIS2_CALL
axiom_soap_header_examine_header_blocks
(axiom_soap_header_t* soap_header,
        const axutil_env_t *env,
        axis2_char_t* param_role)
{
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, param_role, NULL);

    return soap_header->header_blocks;
}

AXIS2_EXTERN axiom_children_qname_iterator_t* AXIS2_CALL
axiom_soap_header_examine_all_header_blocks
(axiom_soap_header_t* soap_header,
        const axutil_env_t *env)
{
    axiom_element_t *om_ele = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    if (!soap_header->om_ele_node)
        return NULL;

    om_ele = (axiom_element_t *)axiom_node_get_data_element(soap_header->om_ele_node, env);

    if (om_ele)
    {
        return axiom_element_get_children_with_qname(om_ele,
                env, NULL, soap_header->om_ele_node);
    }
    else
        return NULL;
}

AXIS2_EXTERN axiom_children_with_specific_attribute_iterator_t *
AXIS2_CALL axiom_soap_header_extract_header_blocks
(axiom_soap_header_t *soap_header,
        const axutil_env_t *env,
        axis2_char_t *role)
{
    const axis2_char_t *localname = NULL;
    const axis2_char_t *nsuri     = NULL;

    axiom_node_t *first_node = NULL;
    axiom_element_t *first_ele =  NULL;

    axutil_qname_t *qn = NULL;

    axiom_element_t *header_om_ele = NULL;
    axiom_children_with_specific_attribute_iterator_t* iter = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    if (soap_header->soap_version == AXIOM_SOAP_VERSION_NOT_SET)
        return NULL;
    if (soap_header->soap_version == AXIOM_SOAP11)
    {
        localname = AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI;
        nsuri     = AXIOM_SOAP11_ATTR_ACTOR;
    }
    if (soap_header->soap_version == AXIOM_SOAP12)
    {
        localname = AXIOM_SOAP12_SOAP_ROLE;
        nsuri     = AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI;
    }

    qn = axutil_qname_create(env, localname, nsuri, NULL);
    if (!qn)
        return NULL;

    header_om_ele = (axiom_element_t*)
            axiom_node_get_data_element(soap_header->om_ele_node, env);

    if (header_om_ele)
    {
        first_ele = axiom_element_get_first_element(header_om_ele, env,
                soap_header->om_ele_node, &first_node);
        if (first_node)
        {
            return axiom_children_with_specific_attribute_iterator_create(env,
                    first_node, qn, role,   AXIS2_TRUE);
        }
    }

    axutil_qname_free(qn, env);

    return iter;

}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_header_set_base_node(axiom_soap_header_t *soap_header,
        const axutil_env_t *env,
        axiom_node_t *node)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, node, AXIS2_FAILURE);

    if (axiom_node_get_node_type(node, env) != AXIOM_ELEMENT)
    {
        AXIS2_ERROR_SET(env->error,
                AXIS2_ERROR_INVALID_BASE_TYPE, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }

    soap_header->om_ele_node = node;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axiom_node_t* AXIS2_CALL
axiom_soap_header_get_base_node(axiom_soap_header_t *soap_header,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    return soap_header->om_ele_node;
}
/**
    set soap version and get soap version are internal functions

*/
AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_header_get_soap_version(axiom_soap_header_t *soap_header,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    return soap_header->soap_version;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_header_set_soap_version(axiom_soap_header_t *soap_header,
        const axutil_env_t *env,
        int soap_version)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    soap_header->soap_version = soap_version;
    return AXIS2_SUCCESS;

}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_header_set_header_block(axiom_soap_header_t *soap_header,
        const axutil_env_t *env,
        struct axiom_soap_header_block *header_block)
{
    axis2_char_t *key = NULL ;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, header_block, AXIS2_FAILURE);

    key = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t)*10);

    if (!key)
        return AXIS2_FAILURE;

    sprintf(key, "%d", soap_header->hbnumber++);

    if (soap_header->header_blocks)
    {
        axutil_hash_set(soap_header->header_blocks,
                key , AXIS2_HASH_KEY_STRING, header_block);
    }
    else
    {
        soap_header->header_blocks = axutil_hash_make(env);
        axutil_hash_set(soap_header->header_blocks,
                key , AXIS2_HASH_KEY_STRING, header_block);
    }
    if (soap_header->header_block_keys)
    {
        axutil_array_list_add(soap_header->header_block_keys, env, key);
    }
    return AXIS2_SUCCESS;

}
AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_header_set_builder(axiom_soap_header_t *soap_header,
        const axutil_env_t *env,
        struct axiom_soap_builder *builder)
{
    AXIS2_PARAM_CHECK(env->error, builder, AXIS2_FAILURE);

    soap_header->soap_builder = builder;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axutil_array_list_t* AXIS2_CALL
axiom_soap_header_get_header_blocks_with_namespace_uri
(axiom_soap_header_t* soap_header,
        const axutil_env_t *env,
        const axis2_char_t *ns_uri)
{
    axutil_array_list_t *header_block_list = NULL;
    axutil_hash_index_t *hash_index = NULL;

    axiom_soap_header_block_t *header_block = NULL;

    axiom_node_t *header_block_om_node = NULL;
    axiom_element_t *header_block_om_ele = NULL;

    axiom_namespace_t *ns = NULL;
    axis2_char_t *hb_namespace_uri = NULL;

    int found = 0;
    void *hb =  NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, ns_uri, NULL);

    if (!(soap_header->header_blocks))
        return NULL;

    header_block_list = axutil_array_list_create(env, 10);
    if (!header_block_list)
        return NULL;

    for (hash_index = axutil_hash_first(soap_header->header_blocks, env);
            hash_index; hash_index = axutil_hash_next(env, hash_index))
    {
        axutil_hash_this(hash_index, NULL, NULL, &hb);
        if (hb)
        {
            header_block = (axiom_soap_header_block_t*)hb;

            header_block_om_node = axiom_soap_header_block_get_base_node(header_block, env);
            if (header_block_om_node)
            {
                header_block_om_ele  = (axiom_element_t *)
                        axiom_node_get_data_element(header_block_om_node, env);
                if (header_block_om_ele)
                {
                    ns = axiom_element_get_namespace(header_block_om_ele, env,
                            header_block_om_node);
                    if (ns)
                    {
                        hb_namespace_uri = axiom_namespace_get_uri(ns, env);
                        if (axutil_strcmp(hb_namespace_uri, ns_uri) == 0)
                        {
                            axutil_array_list_add(header_block_list, env, header_block);
                            found++;
                        }
                    }
                }
            }
            hb = NULL;
            header_block = NULL;
            header_block_om_ele = NULL;
            header_block_om_node = NULL;
            ns = NULL;
            hb_namespace_uri = NULL;
        }
    }
    if (found > 0)
    {
        return header_block_list;
    }
    else
    {
        axutil_array_list_free(header_block_list, env);
    }
    return NULL;
}

AXIS2_EXTERN axutil_hash_t* AXIS2_CALL
axiom_soap_header_get_all_header_blocks(axiom_soap_header_t *soap_header,
        const axutil_env_t *env)
{
    return soap_header->header_blocks;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_header_remove_header_block(axiom_soap_header_t *soap_header,
        const axutil_env_t *env,
        axutil_qname_t *qname)
{
    axis2_char_t *qn_localname = NULL;
    axis2_char_t *qname_ns = NULL;
    axis2_char_t *qname_prefix = NULL;
    axutil_hash_index_t *hi  = NULL;

    AXIS2_PARAM_CHECK(env->error, qname, AXIS2_FAILURE);

    qn_localname = axutil_qname_get_localpart(qname, env);
    qname_ns  = axutil_qname_get_uri(qname, env);
    qname_prefix = axutil_qname_get_prefix(qname, env);

    if (!soap_header->header_blocks)
        return AXIS2_FAILURE;


    for (hi = axutil_hash_first(soap_header->header_blocks, env);
            hi; hi = axutil_hash_next(env, hi))
    {
        const void *key = NULL;
        void *val = NULL;

        axutil_hash_this(hi, &key, NULL, &val);
        if (val)
        {
            axiom_soap_header_block_t *header_block = NULL;
            axiom_element_t *ele = NULL;
            axiom_node_t *node   = NULL;

            header_block = (axiom_soap_header_block_t*)val;
            node = axiom_soap_header_block_get_base_node(header_block, env);
            if (node)
            {
                axutil_qname_t *element_qname = NULL;

                ele = (axiom_element_t*)axiom_node_get_data_element(node, env);
                element_qname = axiom_element_get_qname(ele, env, node);
                if (axiom_soap_header_qname_matches(env, element_qname, qname) == AXIS2_TRUE)
                {
                    axiom_node_detach(node, env);
                    /* axiom_node_free_tree(node, env); */
                    axutil_hash_set(soap_header->header_blocks, key, AXIS2_HASH_KEY_STRING,
                            NULL);
                    axiom_soap_header_block_free(header_block, env);
                    return AXIS2_SUCCESS;
                }
            }
        }
    }
    return AXIS2_SUCCESS;
}

static axis2_bool_t AXIS2_CALL
axiom_soap_header_qname_matches(const axutil_env_t *env,
        axutil_qname_t *element_qname,
        axutil_qname_t *qname_to_match)
{
    int lparts_match =  0;
    int uris_match = 0;
    axis2_char_t *ele_lpart = NULL;
    axis2_char_t *match_lpart = NULL;
    axis2_char_t *ele_nsuri = NULL;
    axis2_char_t *match_nsuri = NULL;

    if (!(qname_to_match))
        return AXIS2_TRUE;
    if (qname_to_match)
    {
        match_lpart = axutil_qname_get_localpart(qname_to_match, env);
        match_nsuri = axutil_qname_get_uri(qname_to_match, env);
    }
    if (element_qname)
    {
        ele_lpart = axutil_qname_get_localpart(element_qname, env);
        ele_nsuri = axutil_qname_get_uri(element_qname, env);
    }

    lparts_match = (!match_lpart ||
            (axutil_strcmp(match_lpart, "") == 0) ||
            (element_qname && (axutil_strcmp(ele_lpart, match_lpart) == 0)));


    uris_match = (!match_nsuri || (axutil_strcmp(match_nsuri, "") == 0) ||
            (element_qname && (axutil_strcmp(ele_nsuri, match_nsuri) == 0)));

    return lparts_match && uris_match;
}


