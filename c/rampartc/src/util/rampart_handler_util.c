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

#include <rampart_handler_util.h>
#include <axis2_handler_desc.h>
#include <axutil_qname.h>
#include <axis2_svc.h>
#include <axiom_soap_header.h>
#include <axiom_soap_body.h>
#include <axiom_soap_header_block.h>
#include <axis2_endpoint_ref.h>
#include <axutil_property.h>
#include <rampart_constants.h>
#include <axutil_dll_desc.h>
#include <axutil_class_loader.h>
#include <axis2_conf_ctx.h>
#include <oxs_axiom.h>


AXIS2_EXTERN axis2_char_t* AXIS2_CALL
rampart_get_property_from_ctx(const axutil_env_t *env,
                              axis2_ctx_t *ctx,
                              const axis2_char_t *key);

AXIS2_EXTERN axutil_param_t* AXIS2_CALL
rampart_get_security_param(const axutil_env_t *env,
                           axis2_msg_ctx_t *msg_ctx,
                           axis2_char_t *parameter);

AXIS2_EXTERN axiom_node_t *AXIS2_CALL
rampart_get_security_token(const axutil_env_t *env,
                           axis2_msg_ctx_t *msg_ctx,
                           axiom_soap_header_t *soap_header);

AXIS2_EXTERN void AXIS2_CALL
rampart_create_fault_envelope(const axutil_env_t *env,
                              const axis2_char_t *sub_code,
                              const axis2_char_t *reason_text,
                              const axis2_char_t *detail_node_text,
                              axis2_msg_ctx_t *msg_ctx);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rampart_validate_security_token(const axutil_env_t *env,
                                axis2_msg_ctx_t *msg_ctx,
                                axiom_node_t *sec_node);

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
rampart_get_policy_location(const axutil_env_t *env,
                            axis2_msg_ctx_t *msg_ctx,
                            axis2_char_t *param_name);

/**********************end of header functions ****************************/


axis2_char_t* AXIS2_CALL
rampart_get_property_from_ctx(const axutil_env_t *env,
                              axis2_ctx_t *ctx,
                              const axis2_char_t *key)
{
    axutil_property_t* property = NULL;
    axis2_char_t* str_property = NULL;

    /*Get value from the dynamic settings*/

    property =  axis2_ctx_get_property(ctx, env, key);
    if (property)
    {
        str_property = axutil_property_get_value(property, env);
        property = NULL;
    }

    return str_property;
}


axutil_param_t* AXIS2_CALL
rampart_get_security_param(const axutil_env_t *env,
                           axis2_msg_ctx_t *msg_ctx,
                           axis2_char_t *parameter)
{
    /*parameter can be either RAMPART_OUTFLOW_SECURITY or RAMPART_INFLOW_SECURITY*/
    axutil_param_t *param = NULL;
    param =  axis2_msg_ctx_get_parameter(msg_ctx, env, parameter);
    return param;
}



axiom_node_t *AXIS2_CALL
rampart_get_security_token(const axutil_env_t *env,
                           axis2_msg_ctx_t *msg_ctx,
                           axiom_soap_header_t *soap_header
                          )
{
    axutil_array_list_t *sec_headers = NULL;
    axis2_char_t *sec_ns_str = NULL;
    axutil_hash_index_t *hash_index =  NULL;
    axutil_hash_t *header_block_ht = NULL;
    axiom_element_t *header_block_ele = NULL;
    axiom_node_t *header_block_node = NULL;

    sec_headers = axiom_soap_header_get_header_blocks_with_namespace_uri(soap_header, env, RAMPART_WSSE_XMLNS);
    if (sec_headers)
    {
        sec_ns_str = axutil_strdup(env, RAMPART_WSSE_XMLNS);

        header_block_ht = axiom_soap_header_get_all_header_blocks(soap_header, env);
        if (!header_block_ht)
            return AXIS2_FAILURE;

        /*BETTER IF : If there are multiple security header elements, get the one with @role=rampart*/
        for (hash_index = axutil_hash_first(header_block_ht, env); hash_index;
                hash_index = axutil_hash_next(env, hash_index))
        {

            void *hb = NULL;
            axiom_soap_header_block_t *header_block =    NULL;
            axis2_char_t *ele_localname = NULL;

            axutil_hash_this(hash_index, NULL, NULL, &hb);
            header_block = (axiom_soap_header_block_t *)hb;
            header_block_node = axiom_soap_header_block_get_base_node(header_block, env);
            header_block_ele  = (axiom_element_t*)axiom_node_get_data_element(header_block_node, env);
            ele_localname = axiom_element_get_localname(header_block_ele, env);

            if (axutil_strcmp(ele_localname, RAMPART_SECURITY) == 0)
            {
                /*Set mustUnderstand = 0*/
                axiom_soap_header_block_set_must_understand_with_bool(header_block, env, AXIS2_FALSE);
                return header_block_node;
            }

        }/*End of for*/
    }
    return header_block_node;

}

AXIS2_EXTERN void AXIS2_CALL
rampart_create_fault_envelope(const axutil_env_t *env,
                              const axis2_char_t *sub_code,
                              const axis2_char_t *reason_text,
                              const axis2_char_t *detail_node_text,
                              axis2_msg_ctx_t *msg_ctx)
{
    axiom_soap_envelope_t *envelope = NULL;
    int soap_version = AXIOM_SOAP12;
    axiom_node_t* text_om_node = NULL;
    axiom_element_t * text_om_ele = NULL;
    axiom_namespace_t *ns1 = NULL;
    axutil_array_list_t *sub_codes = NULL;

    sub_codes = axutil_array_list_create(env, 1);
    axutil_array_list_add(sub_codes, env, sub_code);

    ns1 = axiom_namespace_create(env, RAMPART_WSSE_XMLNS, RAMPART_WSSE);
    text_om_ele = axiom_element_create(env, NULL, "ProblemSecurityHeader", ns1, &text_om_node);
    axiom_element_set_text(text_om_ele, env, detail_node_text, text_om_node);

    envelope = axiom_soap_envelope_create_default_soap_fault_envelope(env,
               "soapenv:Sender",
               reason_text,
               soap_version, sub_codes, text_om_node);

    axis2_msg_ctx_set_fault_soap_envelope(msg_ctx, env, envelope);
    /*free sub codes*/
    return;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rampart_validate_security_token(const axutil_env_t *env,
                                axis2_msg_ctx_t *msg_ctx,
                                axiom_node_t *sec_node)
{
    int num = 0;
    /*Check if there are multiple timestamp tokens*/
    num = oxs_axiom_get_number_of_children_with_qname(env, sec_node, RAMPART_SECURITY_TIMESTAMP, NULL, NULL);
    if (num > 1)
    {
        return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}


AXIS2_EXTERN void *AXIS2_CALL
rampart_get_rampart_configuration(const axutil_env_t *env,
                                  axis2_msg_ctx_t *msg_ctx,
                                  axis2_char_t *param_name)

{
    axutil_param_t *param_x_flow_security = NULL;
    void *value = NULL;

    param_x_flow_security = rampart_get_security_param(env, msg_ctx,
                            param_name);

    if (!param_x_flow_security)
    {
        AXIS2_LOG_INFO(env->log,
                       "[rampart][rampart_handler_utils] %s parameter is not set.",param_x_flow_security);
        return NULL;
    }
    value = axutil_param_get_value(param_x_flow_security, env);
    return value;
}

/*This method will check whether rampart should process the message*/

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
rampart_is_rampart_engaged(const axutil_env_t *env,
                           axis2_msg_ctx_t *msg_ctx)
{
    struct axis2_svc *svc = NULL;
    axutil_array_list_t *engaged_modules = NULL;
    int size = 0;
    int i = 0;
    const axutil_qname_t *qname = NULL;
    axis2_char_t *local_name = NULL;
    axis2_conf_t *conf = NULL;
    struct axis2_conf_ctx *conf_ctx = NULL;

    conf_ctx =  axis2_msg_ctx_get_conf_ctx(msg_ctx,env);
    if(!conf_ctx)
    {
        AXIS2_LOG_INFO(env->log, "[rampart][rhu] Conf context is NULL ");
        return AXIS2_FALSE;
    }
    conf =  axis2_conf_ctx_get_conf(conf_ctx, env);
    if(!conf)
    {
        AXIS2_LOG_INFO(env->log, "[rampart][rhu] Cannot get the axis2 conf from conf context. ");
        return AXIS2_FALSE;
    }

    engaged_modules =  axis2_conf_get_all_engaged_modules(conf, env);
    if(engaged_modules)
    {
        size = axutil_array_list_size(engaged_modules,env);
        for(i=0; i<size; i++)
        {
            qname = (axutil_qname_t *) axutil_array_list_get(engaged_modules,env,i);
            local_name = axutil_qname_get_localpart(qname,env);
            if(axutil_strcmp(local_name,RAMPART_RAMPART)==0)
                return AXIS2_TRUE;
        }
    }
    /*If not engaed gloabally check whether it is engaged at service level.
     *And If service is not there check whether the rampart is enabled by 
     a previous invocation of a handler.*/

    svc =  axis2_msg_ctx_get_svc(msg_ctx,env);
    if(!svc)
    {
        AXIS2_LOG_INFO(env->log, "[rampart][rhu] Service is NULL.");
        return axis2_conf_get_enable_security(conf,env);
    }

    engaged_modules = axis2_svc_get_all_module_qnames(svc,env);
    if(engaged_modules)
    {
        size = axutil_array_list_size(engaged_modules,env);
        for(i=0; i<size; i++)
        {
            qname = (axutil_qname_t *) axutil_array_list_get(engaged_modules,env,i);
            local_name = axutil_qname_get_localpart(qname,env);
            if(axutil_strcmp(local_name,RAMPART_RAMPART)==0)
            {
                axis2_conf_set_enable_security(conf,env,AXIS2_TRUE);
                return AXIS2_TRUE;
            }
        }
    }
    return AXIS2_FALSE;
}

