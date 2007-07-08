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

#include <axis2_raw_xml_in_out_msg_recv.h>
#include <string.h>
#include <axiom_element.h>
#include <axiom_soap_envelope.h>
#include <axiom_soap_header.h>
#include <axiom_soap_body.h>
#include <axiom_soap_fault.h>
#include <axiom_soap.h>

static axis2_status_t AXIS2_CALL
axis2_raw_xml_in_out_msg_recv_invoke_business_logic_sync(
    axis2_msg_recv_t *msg_recv,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axis2_msg_ctx_t *new_msg_ctx);

AXIS2_EXTERN axis2_msg_recv_t *AXIS2_CALL
axis2_raw_xml_in_out_msg_recv_create(const axutil_env_t *env)
{
    axis2_msg_recv_t *msg_recv = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_ENV_CHECK(env, NULL);
    msg_recv = axis2_msg_recv_create(env);
    if (!msg_recv)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    status = axis2_msg_recv_set_scope(msg_recv, env, AXIS2_APPLICATION_SCOPE);
    if (AXIS2_TRUE != status)
    {
        axis2_msg_recv_free(msg_recv, env);
        return NULL;
    }

    axis2_msg_recv_set_invoke_business_logic(msg_recv, env, 
        axis2_raw_xml_in_out_msg_recv_invoke_business_logic_sync);
    return msg_recv;
}

static axis2_status_t AXIS2_CALL
axis2_raw_xml_in_out_msg_recv_invoke_business_logic_sync(axis2_msg_recv_t *msg_recv,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axis2_msg_ctx_t *new_msg_ctx)
{
    axis2_svc_skeleton_t *svc_obj = NULL;
    axis2_op_ctx_t *op_ctx = NULL;
    axis2_op_t *op_desc = NULL;
    const axis2_char_t *style = NULL;
    axiom_node_t *om_node = NULL;
    axiom_element_t *om_element = NULL;
    axis2_char_t *local_name = NULL;
    axiom_node_t *result_node = NULL;
    axiom_node_t *body_content_node = NULL;
    axiom_element_t *body_content_element = NULL;
    axiom_soap_envelope_t *default_envelope = NULL;
    axiom_soap_body_t *out_body = NULL;
    axiom_soap_header_t *out_header = NULL;
    axiom_soap_fault_t *soap_fault = NULL;
    axiom_node_t *out_node = NULL;
    axis2_status_t status = AXIS2_SUCCESS;
    axis2_bool_t skel_invoked = AXIS2_FALSE;
    const axis2_char_t *soap_ns = AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI;
    int soap_version = AXIOM_SOAP12;
    axiom_namespace_t *env_ns = NULL;
	axiom_node_t *fault_node = NULL;
	axiom_soap_fault_detail_t *fault_detail;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, new_msg_ctx, AXIS2_FAILURE);

    /* get the implementation class for the Web Service */
    svc_obj = axis2_msg_recv_get_impl_obj(msg_recv, env, msg_ctx);

    if (!svc_obj)
    {
        const axis2_char_t *svc_name = NULL;
        axis2_svc_t *svc =  axis2_msg_ctx_get_svc(msg_ctx, env);

        if (svc)
        {
            svc_name = axis2_svc_get_name(svc, env);
        }
        else
        {
            svc_name = "unknown";
        }

        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
            "Impl object for service '%s' not set in message receiver. %d :: %s",
            svc_name,
            env->error->error_number,
            AXIS2_ERROR_GET_MESSAGE(env->error));
        status = AXIS2_FAILURE;
    }
    else
    {
        op_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);
        op_desc = axis2_op_ctx_get_op(op_ctx, env);

        style = axis2_op_get_style(op_desc, env);
        if (0 == axutil_strcmp(AXIS2_STYLE_DOC, style))
        {
            axiom_soap_envelope_t *envelope = NULL;
            axiom_soap_body_t *body = NULL;

            envelope = axis2_msg_ctx_get_soap_envelope(msg_ctx, env);
            body = axiom_soap_envelope_get_body(envelope, env);
            om_node = axiom_soap_body_get_base_node(body, env);
            om_element = axiom_node_get_data_element(om_node, env);
            om_node = axiom_node_get_first_element(om_node, env);
         }
        else if (0 == axutil_strcmp(AXIS2_STYLE_RPC, style))
        {
            axiom_soap_envelope_t *envelope = NULL;
            axiom_soap_body_t *body = NULL;
            axiom_node_t *op_node = NULL;
            axiom_element_t *op_element = NULL;

            envelope = axis2_msg_ctx_get_soap_envelope(msg_ctx, env);
            body = axiom_soap_envelope_get_body(envelope, env);
            op_node = axiom_soap_body_get_base_node(body, env);
            op_element = axiom_node_get_data_element(op_node, env);
            if (op_element)
            {
                local_name = axiom_element_get_localname(op_element, env);
                if (local_name)
                {
                    axutil_array_list_t *function_arr = NULL;
                    int i = 0;
                    int size = 0;
                    axis2_bool_t matches = AXIS2_FALSE;

                    function_arr = svc_obj->func_array;
                    if (function_arr)
                    {
                        size = axutil_array_list_size(function_arr, env);
                    }

                    for (i = 0; i < size; i++)
                    {
                        axis2_char_t *function_name = NULL;

                        function_name = (axis2_char_t *) axutil_array_list_get(
                            function_arr, env, i);
                        if (0 == axutil_strcmp(function_name, local_name))
                        {
                            matches = AXIS2_TRUE;

                        }
                    }

                    if (AXIS2_TRUE == matches)
                    {
                        om_node = axiom_node_get_first_child(op_node, env);
                        om_element = axiom_node_get_data_element(om_node, env);
                    }
                    else
                    {
                        AXIS2_ERROR_SET(env->error,
                            AXIS2_ERROR_OM_ELEMENT_MISMATCH, AXIS2_FAILURE);
                        status = AXIS2_FAILURE;
                    }
                }
                else
                {
                    AXIS2_ERROR_SET(env->error,
                        AXIS2_ERROR_OM_ELEMENT_INVALID_STATE, AXIS2_FAILURE);
                    status = AXIS2_FAILURE;
                }
            }
            else
           { 
                AXIS2_ERROR_SET(env->error,
                    AXIS2_ERROR_RPC_NEED_MATCHING_CHILD, AXIS2_FAILURE);
                status = AXIS2_FAILURE;
            }
        }
        else
        {
            AXIS2_ERROR_SET(env->error,
                AXIS2_ERROR_UNKNOWN_STYLE, AXIS2_FAILURE);
            status = AXIS2_FAILURE;
        }

        if (status == AXIS2_SUCCESS)
        {
            skel_invoked = AXIS2_TRUE;
            result_node = AXIS2_SVC_SKELETON_INVOKE(svc_obj, env, om_node, new_msg_ctx);
        }

        if (result_node)
        {
            if (0 == axutil_strcmp(style, AXIS2_STYLE_RPC))
            {
                axiom_namespace_t *ns = NULL;
                axis2_char_t *res_name = NULL;

                res_name = axutil_stracat(env, local_name, "Response");
                ns = axiom_namespace_create(env, "http://soapenc/", "res");
                if (!ns)
                {
                    status = AXIS2_FAILURE;
                }
                else
                {
                    body_content_element = axiom_element_create(env, NULL, res_name,
                        ns, &body_content_node);
                    axiom_node_add_child(body_content_node, env, result_node);
                }
            }
            else
            {
                body_content_node = result_node;
            }
        }
        else
        {
            status = AXIS2_ERROR_GET_STATUS_CODE(env->error);
	    fault_node = AXIS2_SVC_SKELETON_ON_FAULT(svc_obj, env, om_node);
        }
    }

    if (msg_ctx &&  axis2_msg_ctx_get_is_soap_11(msg_ctx, env))
    {
        soap_ns = AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI; /* default is 1.2 */
        soap_version = AXIOM_SOAP11;
    }

    if ( axis2_msg_ctx_get_soap_envelope(new_msg_ctx, env))
    {
        /* service implementation has set the envelope,
           useful when setting a SOAP fault.
           No need to further process */
        return AXIS2_SUCCESS;
    }

    /* create the soap envelope here*/
    env_ns = axiom_namespace_create(env, soap_ns, "soapenv");
    if (!env_ns)
    {
        return AXIS2_FAILURE;
    }

    default_envelope = axiom_soap_envelope_create(env, env_ns);

    if (!default_envelope)
    {
        return AXIS2_FAILURE;
    }

    out_header = axiom_soap_header_create_with_parent(env, default_envelope);
    if (!out_header)
    {
        return AXIS2_FAILURE;
    }

    out_body = axiom_soap_body_create_with_parent(env, default_envelope);
    if (!out_body)
    {
        return AXIS2_FAILURE;
    }

    out_node = axiom_soap_body_get_base_node(out_body, env);
    if (!out_node)
    {
        return AXIS2_FAILURE;
    }

    if (status != AXIS2_SUCCESS)
    {
        /* something went wrong. set a SOAP Fault*/
        const axis2_char_t *fault_value_str = "env:Sender";
        const axis2_char_t *fault_reason_str = NULL;
        const axis2_char_t *err_msg = NULL;

        if (!skel_invoked)
	{
            fault_value_str = "env:Receiver";
	}

        err_msg = AXIS2_ERROR_GET_MESSAGE(env->error);
        if (err_msg)
        {
            fault_reason_str = err_msg;
        }
        else
        {
            fault_reason_str = "Something went wrong";
        }

        soap_fault = axiom_soap_fault_create_default_fault(env, out_body,
            fault_value_str, fault_reason_str, soap_version);
	if (fault_node)
	{
	    fault_detail = axiom_soap_fault_detail_create_with_parent (env, soap_fault);
	    axiom_soap_fault_detail_add_detail_entry (fault_detail, env, fault_node);
	}
    }

    if (body_content_node)
    {
        axiom_node_add_child(out_node , env, body_content_node);
        status = axis2_msg_ctx_set_soap_envelope(new_msg_ctx, env, default_envelope);
    }
    else if (soap_fault)
    {
         axis2_msg_ctx_set_soap_envelope(new_msg_ctx, env, default_envelope);
	     status = AXIS2_SUCCESS;
    }
    else
    {
        /* we should free the memory as the envelope is not used, one way case */
        axiom_soap_envelope_free(default_envelope, env);
        default_envelope = NULL;
    }


    return status;
}

AXIS2_EXPORT int axis2_get_instance(struct axis2_msg_recv **inst,
    const axutil_env_t *env)
{
    *inst = axis2_raw_xml_in_out_msg_recv_create(env);
    if (!(*inst))
    {
        return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXPORT int axis2_remove_instance(struct axis2_msg_recv *inst,
    const axutil_env_t *env)
{
    if (inst)
    {
        axis2_msg_recv_free(inst, env);
    }
    return AXIS2_SUCCESS;
}


