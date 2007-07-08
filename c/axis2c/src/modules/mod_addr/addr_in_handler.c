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

#include <axis2_addr_mod.h>
#include <axis2_addr.h>
#include <axis2_handler_desc.h>
#include <axutil_array_list.h>
#include <axiom_soap_const.h>
#include <axiom_soap_envelope.h>
#include <axiom_soap_header.h>
#include <axiom_soap_header_block.h>
#include <axis2_op.h>
#include <axis2_msg_ctx.h>
#include <axis2_conf_ctx.h>
#include <axis2_msg_info_headers.h>
#include <axutil_property.h>

axis2_status_t AXIS2_CALL
axis2_addr_in_handler_invoke(struct axis2_handler *handler,
        const axutil_env_t *env,
        struct axis2_msg_ctx *msg_ctx);

axis2_bool_t
axis2_addr_in_check_element(const axutil_env_t *env, axutil_qname_t *expected_qname,
        axutil_qname_t *actual_qname);

axis2_status_t
axis2_addr_in_extract_svc_grp_ctx_id(const axutil_env_t *env,
        axiom_soap_header_t *soap_header,
        axis2_msg_ctx_t *msg_ctx);

axis2_status_t
axis2_addr_in_extract_ref_params(const axutil_env_t *env,
        axiom_soap_header_t *soap_header,
        axis2_msg_info_headers_t *msg_info_headers);

axis2_status_t
axis2_addr_in_extract_addr_final_info(const axutil_env_t *env,
        axiom_soap_header_t *soap_header,
        axis2_msg_info_headers_t **msg_info_headers,
        axutil_array_list_t *addr_headers,
        axis2_msg_ctx_t *msg_ctx);


axis2_status_t
axis2_addr_in_extract_to_epr_ref_params(const axutil_env_t *env,
        axis2_endpoint_ref_t * to_epr,
        axiom_soap_header_t *soap_header,
        const axis2_char_t *addr_ns);

axis2_status_t
axis2_addr_in_extract_epr_information(const axutil_env_t *env,
        axiom_soap_header_block_t *soap_header_block,
        axis2_endpoint_ref_t *endpoint_ref,
        const axis2_char_t *addr_ns);

axis2_status_t
axis2_addr_in_extract_addr_params(const axutil_env_t *env,
        axiom_soap_header_t *soap_header,
        axis2_msg_info_headers_t **msg_info_headers,
        axutil_array_list_t *addr_headers,
        const axis2_char_t *addr_ns,
        axis2_msg_ctx_t *msg_ctx);

axis2_status_t axis2_addr_in_extract_addr_submission_info(const axutil_env_t *env,
        axiom_soap_header_t *soap_header,
        axis2_msg_info_headers_t **msg_info_headers,
        axutil_array_list_t *addr_headers,
        axis2_msg_ctx_t *msg_ctx);

void
axis2_addr_in_create_fault_envelope(const axutil_env_t *env,
        const axis2_char_t *header_name,
        const axis2_char_t *addr_ns_str,
        axis2_msg_ctx_t *msg_ctx);

/******************************************************************************/

AXIS2_EXTERN axis2_handler_t* AXIS2_CALL
axis2_addr_in_handler_create(const axutil_env_t *env,
        axutil_string_t *name)
{
    axis2_handler_t *handler = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    handler = axis2_handler_create(env);
    if (!handler)
    {
        return NULL;
    }

    /* handler init is handled by conf loading, so no need to do it here */

    axis2_handler_set_invoke(handler, env, axis2_addr_in_handler_invoke);

    return handler;
}


axis2_status_t AXIS2_CALL
axis2_addr_in_handler_invoke(struct axis2_handler *handler,
        const axutil_env_t *env,
        struct axis2_msg_ctx *msg_ctx)
{
    axiom_soap_envelope_t *soap_envelope = NULL;
    axiom_soap_header_t *soap_header = NULL;
    axutil_property_t *property = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);

    AXIS2_LOG_INFO(env->log, "Starting addressing in handler .........");

    soap_envelope =  axis2_msg_ctx_get_soap_envelope(msg_ctx, env);

    if (soap_envelope)
    {
        soap_header = axiom_soap_envelope_get_header(soap_envelope, env);
        if (soap_header)
        {
            axutil_array_list_t *addr_headers = NULL;
            axis2_ctx_t *ctx = NULL;
            axis2_char_t *addr_ns_str = NULL;
            axis2_msg_info_headers_t *msg_info_headers =  axis2_msg_ctx_get_msg_info_headers(msg_ctx, env);

            addr_headers = axiom_soap_header_get_header_blocks_with_namespace_uri(soap_header, env, AXIS2_WSA_NAMESPACE_SUBMISSION);
            if (addr_headers)
            {
                addr_ns_str = axutil_strdup(env, AXIS2_WSA_NAMESPACE_SUBMISSION);
                status = axis2_addr_in_extract_addr_submission_info(env,
                        soap_header,
                        &msg_info_headers,
                        addr_headers,
                        msg_ctx);
            }
            else
            {
                addr_headers = axiom_soap_header_get_header_blocks_with_namespace_uri(soap_header, env, AXIS2_WSA_NAMESPACE);
                if (addr_headers)
                {
                    addr_ns_str = axutil_strdup(env, AXIS2_WSA_NAMESPACE);
                    status = axis2_addr_in_extract_addr_final_info(env,
                            soap_header,
                            &msg_info_headers,
                            addr_headers,
                            msg_ctx);
                    axis2_addr_in_extract_ref_params(env, soap_header,  axis2_msg_ctx_get_msg_info_headers(msg_ctx, env));

                }
                else
                {
                    /* addressing headers are not present in the SOAP message*/
                    AXIS2_LOG_INFO(env->log, AXIS2_LOG_SI, "No Addressing Headers present in the IN message. Addressing In Handler cannot do anything.");
                    return AXIS2_SUCCESS; /* no addressing heades means addressing not in use */
                }
            }

            ctx = axis2_msg_ctx_get_base(msg_ctx, env);
            if (ctx)
            {
                property = axutil_property_create(env);
                axutil_property_set_scope(property, env, AXIS2_SCOPE_REQUEST);
                axutil_property_set_value(property, env, addr_ns_str);
                axis2_ctx_set_property(ctx, env, AXIS2_WSA_VERSION, property);
            }

            /* extract service group context, if available */
            axis2_addr_in_extract_svc_grp_ctx_id(env, soap_header, msg_ctx);

            axutil_array_list_free(addr_headers, env);
            return status;
        }
    }

    return AXIS2_SUCCESS;
}

axis2_status_t
axis2_addr_in_extract_svc_grp_ctx_id(const axutil_env_t *env,
        axiom_soap_header_t *soap_header,
        axis2_msg_ctx_t *msg_ctx)
{
    axiom_node_t *node = NULL;
    axiom_element_t *element = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    node = axiom_soap_header_get_base_node(soap_header, env);
    if (node && axiom_node_get_node_type(node, env) == AXIOM_ELEMENT)
    {
        axutil_qname_t *qname = NULL;
        element = (axiom_element_t *)axiom_node_get_data_element(node, env);
        qname = axutil_qname_create(env, AXIS2_SVC_GRP_ID, AXIS2_NAMESPACE_URI,
                AXIS2_NAMESPACE_PREFIX);
        if (qname)
        {
            axiom_node_t *child_node = NULL;
            axiom_element_t *child_element = NULL;
            child_element = axiom_element_get_first_child_with_qname(element, env, qname, node, &child_node);
            if (child_element)
            {
                axis2_conf_ctx_t * conf_ctx = NULL;
                axis2_char_t *grp_id = axiom_element_get_text(child_element, env,
                        child_node);
                conf_ctx =  axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
                if (conf_ctx && grp_id)
                {
                    axutil_string_t *svc_grp_ctx_id_str = axutil_string_create(env, grp_id);
                    axis2_svc_grp_ctx_t *svc_ctx_grp_ctx =  axis2_conf_ctx_get_svc_grp_ctx(conf_ctx, env, grp_id);
                    if (!svc_ctx_grp_ctx)
                    {
                        return AXIS2_FAILURE;
                    }
                     axis2_msg_ctx_set_svc_grp_ctx_id(msg_ctx, env, svc_grp_ctx_id_str);
                    axutil_string_free(svc_grp_ctx_id_str, env);
                    return AXIS2_SUCCESS;
                }
            }
        }
        axutil_qname_free(qname, env);
    }
    return AXIS2_FAILURE;
}



axis2_status_t
axis2_addr_in_extract_addr_final_info(const axutil_env_t *env,
        axiom_soap_header_t *soap_header,
        axis2_msg_info_headers_t **msg_info_headers,
        axutil_array_list_t *addr_headers,
        axis2_msg_ctx_t *msg_ctx)
{
    return axis2_addr_in_extract_addr_params(env,
            soap_header,
            msg_info_headers,
            addr_headers,
            AXIS2_WSA_NAMESPACE,
            msg_ctx);
}

axis2_status_t axis2_addr_in_extract_addr_submission_info(const axutil_env_t *env,
        axiom_soap_header_t *soap_header,
        axis2_msg_info_headers_t **msg_info_headers,
        axutil_array_list_t *addr_headers,
        axis2_msg_ctx_t *msg_ctx)
{
    return axis2_addr_in_extract_addr_params(env,
            soap_header,
            msg_info_headers,
            addr_headers,
            AXIS2_WSA_NAMESPACE_SUBMISSION,
            msg_ctx);
}

axis2_status_t
axis2_addr_in_extract_addr_params(const axutil_env_t *env,
        axiom_soap_header_t *soap_header,
        axis2_msg_info_headers_t **msg_info_headers_p,
        axutil_array_list_t *addr_headers,
        const axis2_char_t *addr_ns_str,
        axis2_msg_ctx_t *msg_ctx)
{
    axutil_hash_t *header_block_ht = NULL;
    axutil_hash_index_t *hash_index =  NULL;
    axis2_msg_info_headers_t *msg_info_headers = *(msg_info_headers_p);
    axis2_status_t status = AXIS2_SUCCESS;
    axis2_bool_t to_found = AXIS2_FALSE;
    axis2_bool_t reply_to_found = AXIS2_FALSE;
    axis2_bool_t fault_to_found = AXIS2_FALSE;
    axis2_bool_t action_found = AXIS2_FALSE;
    axis2_bool_t msg_id_found = AXIS2_FALSE;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, soap_header, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_info_headers_p, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, addr_headers, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, addr_ns_str, AXIS2_FAILURE);



    if (!msg_info_headers)
        msg_info_headers = axis2_msg_info_headers_create(env, NULL, NULL);
    if (!msg_info_headers)
        return AXIS2_FAILURE;

    header_block_ht = axiom_soap_header_get_all_header_blocks(soap_header, env);
    if (!header_block_ht)
        return AXIS2_FAILURE;

    for (hash_index = axutil_hash_first(header_block_ht, env); hash_index;
            hash_index = axutil_hash_next(env, hash_index))
    {
        void *hb = NULL;
        axiom_soap_header_block_t *header_block =    NULL;
        axiom_node_t *header_block_node = NULL;
        axiom_element_t *header_block_ele = NULL;
        axis2_char_t *ele_localname = NULL;
        axis2_endpoint_ref_t *epr = NULL;
        axis2_char_t *role = NULL;

        axutil_hash_this(hash_index, NULL, NULL, &hb);

        header_block = (axiom_soap_header_block_t *)hb;
        header_block_node = axiom_soap_header_block_get_base_node(header_block, env);
        header_block_ele  = (axiom_element_t*)axiom_node_get_data_element(header_block_node, env);
        ele_localname = axiom_element_get_localname(header_block_ele, env);

        role = axiom_soap_header_block_get_role(header_block, env);
        if (role && axutil_strcmp(role, AXIOM_SOAP12_SOAP_ROLE_NONE) == 0)
        {
            /* Role is none, no need of processing */
            continue;
        }

        if (axutil_strcmp(ele_localname, AXIS2_WSA_TO) == 0)
        {
            /* here the addressing epr overidde what ever already there in the message context */

            epr = axis2_endpoint_ref_create(env, axiom_element_get_text(header_block_ele, env, header_block_node));
            if (to_found == AXIS2_TRUE)
            {
                /* Duplicate To */
                axis2_addr_in_create_fault_envelope(env,
                        "wsa:To", addr_ns_str, msg_ctx);
                status = AXIS2_FAILURE;
                continue;
            }
            axis2_msg_info_headers_set_to(msg_info_headers, env, epr);

            axis2_addr_in_extract_to_epr_ref_params(env, epr, soap_header, addr_ns_str);
            axiom_soap_header_block_set_processed(header_block, env);
            to_found = AXIS2_TRUE;
        }
        else if (axutil_strcmp(ele_localname, AXIS2_WSA_FROM) == 0)
        {
            epr = axis2_msg_info_headers_get_from(msg_info_headers, env);
            if (!epr)
            {
                /* The address is not know now. Pass the empty
                    string now and fill this once the element 
                    under this is processed. */

                epr = axis2_endpoint_ref_create(env, "");
                axis2_msg_info_headers_set_from(msg_info_headers, env, epr);
            }
            axis2_addr_in_extract_epr_information(env, header_block, epr, addr_ns_str);
            axiom_soap_header_block_set_processed(header_block, env);
        }
        else if (axutil_strcmp(ele_localname, AXIS2_WSA_REPLY_TO) == 0)
        {
            epr = axis2_msg_info_headers_get_reply_to(msg_info_headers, env);

            if (reply_to_found == AXIS2_TRUE)
            {
                /* Duplicate Reply To */
                axis2_addr_in_create_fault_envelope(env,
                        "wsa:ReplyTo", addr_ns_str, msg_ctx);
                status = AXIS2_FAILURE;
                continue;
            }

            if (!epr)
            {
                epr = axis2_endpoint_ref_create(env, "");
                axis2_msg_info_headers_set_reply_to(msg_info_headers, env, epr);
            }
            axis2_addr_in_extract_epr_information(env, header_block, epr, addr_ns_str);
            axiom_soap_header_block_set_processed(header_block, env);
            reply_to_found = AXIS2_TRUE;
        }
        else if (axutil_strcmp(ele_localname, AXIS2_WSA_FAULT_TO) == 0)
        {
            epr = axis2_msg_info_headers_get_fault_to(msg_info_headers , env);

            if (fault_to_found == AXIS2_TRUE)
            {
                /* Duplicate Fault To */
                axis2_addr_in_create_fault_envelope(env,
                        "wsa:FaultTo", addr_ns_str, msg_ctx);
                status = AXIS2_FAILURE;
                axis2_msg_info_headers_set_fault_to(msg_info_headers, env, NULL);
                continue;
            }

            if (!epr)
            {
                epr = axis2_endpoint_ref_create(env, "");
                axis2_msg_info_headers_set_fault_to(msg_info_headers, env, epr);
            }
            axis2_addr_in_extract_epr_information(env, header_block, epr, addr_ns_str);
            axiom_soap_header_block_set_processed(header_block, env);
            fault_to_found = AXIS2_TRUE;
        }
        else if (axutil_strcmp(ele_localname, AXIS2_WSA_MESSAGE_ID) == 0)
        {
            axis2_char_t *text = NULL;

            if (msg_id_found == AXIS2_TRUE)
            {
                /* Duplicate Message ID */
                axis2_addr_in_create_fault_envelope(env,
                        "wsa:MessageID", addr_ns_str, msg_ctx);
                status = AXIS2_FAILURE;
                continue;
            }

            text = axiom_element_get_text(header_block_ele, env, header_block_node);
            axis2_msg_info_headers_set_message_id(msg_info_headers, env, text);
            axiom_soap_header_block_set_processed(header_block, env);
            msg_id_found = AXIS2_TRUE;
        }
        else if (axutil_strcmp(ele_localname, AXIS2_WSA_ACTION) == 0)
        {
            axis2_char_t *text = NULL;

            if (action_found == AXIS2_TRUE)
            {
                /* Duplicate Action */
                axis2_addr_in_create_fault_envelope(env,
                        "wsa:Action", addr_ns_str, msg_ctx);
                status = AXIS2_FAILURE;
                continue;
            }

            text = axiom_element_get_text(header_block_ele, env, header_block_node);
            axis2_msg_info_headers_set_action(msg_info_headers, env, text);
            axiom_soap_header_block_set_processed(header_block, env);
            action_found = AXIS2_TRUE;
        }
        else if (axutil_strcmp(ele_localname, AXIS2_WSA_RELATES_TO) == 0)
        {
            axis2_char_t *address = NULL;
            axutil_qname_t *rqn = NULL;
            axiom_attribute_t *relationship_type = NULL;
            const axis2_char_t *relationship_type_default_value =  NULL;
            const axis2_char_t *relationship_type_value = NULL;
            axis2_relates_to_t *relates_to =  NULL;
            if (axutil_strcmp(AXIS2_WSA_NAMESPACE_SUBMISSION , addr_ns_str) == 0)
            {
                relationship_type_default_value =
                    AXIS2_WSA_RELATES_TO_RELATIONSHIP_TYPE_DEFAULT_VALUE_SUBMISSION;
            }
            else
            {
                relationship_type_default_value = AXIS2_WSA_ANONYMOUS_URL_SUBMISSION;
            }
            rqn = axutil_qname_create(env, AXIS2_WSA_RELATES_TO_RELATIONSHIP_TYPE, NULL, NULL);

            relationship_type = axiom_element_get_attribute(header_block_ele, env, rqn);

            if (!relationship_type)
            {
                relationship_type_value =
                    AXIS2_WSA_RELATES_TO_RELATIONSHIP_TYPE_DEFAULT_VALUE_SUBMISSION;
            }
            else
            {
                relationship_type_value = axiom_attribute_get_value(relationship_type, env);
            }

            address = axiom_element_get_text(header_block_ele, env, header_block_node);
            relates_to = axis2_relates_to_create(env, address, relationship_type_value);
            axis2_msg_info_headers_set_relates_to(msg_info_headers, env, relates_to);
            axiom_soap_header_block_set_processed(header_block, env);

            axutil_qname_free(rqn, env);
        }
    }

    if (action_found == AXIS2_FALSE) /* Check is an action was found */
    {
        axis2_addr_in_create_fault_envelope(env,
                "wsa:Action", addr_ns_str, msg_ctx);
        status = AXIS2_FAILURE;
    }

    return status;
}

axis2_status_t
axis2_addr_in_extract_epr_information(const axutil_env_t *env,
        axiom_soap_header_block_t *soap_header_block,
        axis2_endpoint_ref_t *endpoint_ref,
        const axis2_char_t *addr_ns_str)
{
    axutil_qname_t *epr_addr_qn = NULL;
    axutil_qname_t *epr_ref_qn = NULL;
    axutil_qname_t *wsa_meta_qn = NULL;
    axiom_node_t *header_block_node = NULL;
    axiom_element_t *header_block_ele = NULL;
    axiom_child_element_iterator_t *child_ele_iter = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, soap_header_block, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, endpoint_ref, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, addr_ns_str, AXIS2_FAILURE);

    header_block_node = axiom_soap_header_block_get_base_node(soap_header_block, env);
    header_block_ele  = (axiom_element_t *)axiom_node_get_data_element(header_block_node, env);


    child_ele_iter = axiom_element_get_child_elements(header_block_ele, env, header_block_node);
    if (!child_ele_iter)
        return AXIS2_FAILURE;
    epr_addr_qn = axutil_qname_create(env, EPR_ADDRESS, addr_ns_str, NULL);
    epr_ref_qn = axutil_qname_create(env, EPR_REFERENCE_PARAMETERS, addr_ns_str, NULL);
    wsa_meta_qn = axutil_qname_create(env, AXIS2_WSA_METADATA, addr_ns_str, NULL);
    while (AXIOM_CHILD_ELEMENT_ITERATOR_HAS_NEXT(child_ele_iter, env))
    {
        axiom_node_t *child_node = NULL;
        axiom_element_t *child_ele = NULL;
        axutil_qname_t *child_qn = NULL;
        child_node = AXIOM_CHILD_ELEMENT_ITERATOR_NEXT(child_ele_iter, env);
        child_ele = (axiom_element_t*)axiom_node_get_data_element(child_node, env);


        child_qn = axiom_element_get_qname(child_ele, env, child_node);
        if (axis2_addr_in_check_element(env, epr_addr_qn, child_qn))
        {
            axis2_endpoint_ref_set_address(endpoint_ref, env,
                    axiom_element_get_text(child_ele, env, child_node));
        }
        else if (axis2_addr_in_check_element(env, epr_ref_qn , child_qn))
        {
            axiom_child_element_iterator_t *ref_param_iter = NULL;

            ref_param_iter = axiom_element_get_child_elements(child_ele, env, child_node);
            if (ref_param_iter)
            {
                while (AXIOM_CHILD_ELEMENT_ITERATOR_HAS_NEXT(ref_param_iter, env))
                {
                    axiom_node_t *om_node =  NULL;
                    axiom_element_t *om_ele = NULL;
                    om_node = AXIOM_CHILD_ELEMENT_ITERATOR_NEXT(ref_param_iter, env);
                    om_ele  = (axiom_element_t*)axiom_node_get_data_element(om_node, env);
                }
            }

        }
        else if (axis2_addr_in_check_element(env, wsa_meta_qn, child_qn))
        {}
    }
    axutil_qname_free(epr_addr_qn, env);
    axutil_qname_free(epr_ref_qn, env);
    axutil_qname_free(wsa_meta_qn, env);
    return AXIS2_SUCCESS;
}

axis2_status_t
axis2_addr_in_extract_ref_params(const axutil_env_t *env,
        axiom_soap_header_t *soap_header,
        axis2_msg_info_headers_t* msg_info_headers)
{
    axutil_hash_t *header_block_ht = NULL;
    axutil_hash_index_t *hash_index = NULL;
    axutil_qname_t *wsa_qname = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, soap_header, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_info_headers, AXIS2_FAILURE);

    header_block_ht = axiom_soap_header_get_all_header_blocks(soap_header, env);
    if (!header_block_ht)
        return AXIS2_FAILURE;
    wsa_qname = axutil_qname_create(env, AXIS2_WSA_IS_REFERENCE_PARAMETER_ATTRIBUTE,
            AXIS2_WSA_NAMESPACE, NULL);

    for (hash_index = axutil_hash_first(header_block_ht, env); hash_index;
            hash_index = axutil_hash_next(env, hash_index))
    {
        void *hb = NULL;
        axiom_soap_header_block_t *header_block =    NULL;
        axiom_node_t *header_block_node = NULL;
        axiom_element_t *header_block_ele = NULL;

        axutil_hash_this(hash_index, NULL, NULL, &hb);

        header_block = (axiom_soap_header_block_t *)hb;
        header_block_node = axiom_soap_header_block_get_base_node(header_block, env);

        if (header_block_node &&
                (axiom_node_get_node_type(header_block_node, env) == AXIOM_ELEMENT))
        {
            axiom_attribute_t *om_attr = NULL;
            axis2_char_t *attr_value = NULL;
            header_block_ele = (axiom_element_t*)axiom_node_get_data_element(header_block_node, env);
            om_attr = axiom_element_get_attribute(header_block_ele, env, wsa_qname);
            if (om_attr)
            {
                attr_value = axiom_attribute_get_localname(om_attr, env);
                if (axutil_strcmp(attr_value, AXIS2_WSA_TYPE_ATTRIBUTE_VALUE) == 0)
                {
                    axis2_msg_info_headers_add_ref_param(msg_info_headers, env, header_block_node);
                }
            }
        }
    }

    axutil_qname_free(wsa_qname, env);

    return AXIS2_SUCCESS;
}


axis2_status_t
axis2_addr_in_extract_to_epr_ref_params(const axutil_env_t *env,
        axis2_endpoint_ref_t * to_epr,
        axiom_soap_header_t *soap_header,
        const axis2_char_t *addr_ns_str)
{
    axutil_hash_t *header_blocks_ht = NULL;
    axutil_hash_index_t *hash_index = NULL;
    axutil_qname_t *is_ref_qn = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, to_epr, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, soap_header, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, addr_ns_str, AXIS2_FAILURE);

    header_blocks_ht = axiom_soap_header_get_all_header_blocks(soap_header, env);
    if (!header_blocks_ht)
        return AXIS2_FAILURE;

    is_ref_qn = axutil_qname_create(env, "IsReferenceParameter", addr_ns_str, NULL);
    if (!is_ref_qn)
        return AXIS2_FAILURE;

    for (hash_index = axutil_hash_first(header_blocks_ht, env); hash_index;
            hash_index = axutil_hash_next(env, hash_index))
    {
        axiom_element_t *header_block_ele = NULL;
        axiom_node_t *header_block_node = NULL;
        axiom_soap_header_block_t *header_block = NULL;
        void *hb = NULL;
        axiom_attribute_t *is_ref_param_attr = NULL;
        axis2_char_t *attr_value = NULL;

        axutil_hash_this(hash_index, NULL, NULL, &hb);
        if (hb)
        {
            header_block = (axiom_soap_header_block_t*)hb;
            header_block_node = axiom_soap_header_block_get_base_node(header_block, env);
            header_block_ele = (axiom_element_t*)
                    axiom_node_get_data_element(header_block_node, env);
            is_ref_param_attr  = axiom_element_get_attribute(header_block_ele, env, is_ref_qn);
            if (is_ref_param_attr)
            {
                attr_value = axiom_attribute_get_localname(is_ref_param_attr, env);
                if (axutil_strcmp("true", attr_value) == 0)
                {
                    axis2_endpoint_ref_add_ref_param(to_epr, env, header_block_node);
                }
            }
        }
    }

    axutil_qname_free(is_ref_qn, env);
    return AXIS2_SUCCESS;
}


axis2_bool_t
axis2_addr_in_check_element(const axutil_env_t *env,
        axutil_qname_t *expected_qname,
        axutil_qname_t *actual_qname)
{
    axis2_char_t *exp_qn_lpart =  NULL;
    axis2_char_t *act_qn_lpart = NULL;
    axis2_char_t *exp_qn_nsuri = NULL;
    axis2_char_t *act_qn_nsuri = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, expected_qname, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, actual_qname, AXIS2_FAILURE);

    exp_qn_lpart = axutil_qname_get_localpart(expected_qname, env);
    act_qn_lpart = axutil_qname_get_localpart(actual_qname, env);

    exp_qn_nsuri = axutil_qname_get_localpart(expected_qname, env);
    act_qn_nsuri = axutil_qname_get_localpart(actual_qname, env);

    return ((axutil_strcmp(exp_qn_lpart, act_qn_lpart) == 0) &&
            (axutil_strcmp(exp_qn_nsuri, act_qn_nsuri) == 0));
}

void
axis2_addr_in_create_fault_envelope(const axutil_env_t *env,
        const axis2_char_t *header_name,
        const axis2_char_t *addr_ns_str,
        axis2_msg_ctx_t *msg_ctx)
{
    axiom_soap_envelope_t *envelope = NULL;
    axutil_array_list_t *sub_codes = NULL;
    int soap_version = AXIOM_SOAP12;
    axiom_node_t* text_om_node = NULL;
    axiom_element_t * text_om_ele = NULL;
    axiom_namespace_t *ns1 = NULL;

    if ( axis2_msg_ctx_get_is_soap_11(msg_ctx, env))
    {
        soap_version = AXIOM_SOAP11;
    }


    ns1 = axiom_namespace_create(env, addr_ns_str, "wsa");
    text_om_ele = axiom_element_create(env, NULL, "ProblemHeaderQName", ns1, &text_om_node);
    axiom_element_set_text(text_om_ele, env, header_name, text_om_node);

    sub_codes = axutil_array_list_create(env, 2);
    if (sub_codes)
    {
        axutil_array_list_add(sub_codes, env, "wsa:InvalidAddressingHeader");
        axutil_array_list_add(sub_codes, env, "wsa:InvalidCardinality");
    }

    envelope = axiom_soap_envelope_create_default_soap_fault_envelope(env,
            "soapenv:Sender",
            "A header representing a Message Addressing Property is not valid and the message cannot be processed",
            soap_version, sub_codes, text_om_node);
     axis2_msg_ctx_set_fault_soap_envelope(msg_ctx, env, envelope);
     axis2_msg_ctx_set_wsa_action(msg_ctx, env,
            "http://www.w3.org/2005/08/addressing/fault");
    return;
}
