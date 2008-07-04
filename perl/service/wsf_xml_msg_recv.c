/*
 * Copyright 2005 - 2008 WSO2, Inc. http://wso2.com
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

#include <axis2_msg_recv.h>
#include "wsf_xml_msg_recv.h"
#include "wsf_util.h"
#include <string.h>
#include <axiom.h>
#include <axiom_soap.h>
#include <axutil_error.h>
#include <axutil_env.h>
#include <axutil_string.h>
#include <EXTERN.h>
#include <perl.h>

static void xs_init(pTHX);

EXTERN_C void boot_DynaLoader(pTHX_ CV* cv);

static PerlInterpreter *my_perl;

static axiom_node_t *
wsf_xml_msg_recv_invoke_other(axis2_msg_recv_t* msg_recv,
        const axutil_env_t* env,
        wsf_svc_info_t* svc_info,
        axis2_msg_ctx_t* in_msg_ctx,
        axis2_msg_ctx_t* out_msg_ctx,
        axis2_char_t* function_name,
        axis2_char_t* class_name);

static axis2_char_t *
invoke_perl_function(const axutil_env_t *env,
        axiom_node_t *om_node,
        axis2_char_t *operation,
        axis2_char_t *class_name);

axis2_msg_recv_t*
wsf_xml_msg_recv_create(const axutil_env_t* env)
{
    axis2_msg_recv_t* msg_recv = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_ENV_CHECK(env, NULL);
    msg_recv = axis2_msg_recv_create(env);

    if (!msg_recv)
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "xml msg recv null");
        return NULL;
    }

    status = axis2_msg_recv_set_scope(msg_recv, env, AXIS2_APPLICATION_SCOPE);

    if (AXIS2_TRUE != status)
    {
        axis2_msg_recv_free(msg_recv, env);
        return NULL;
    }
    axis2_msg_recv_set_invoke_business_logic(msg_recv, env,
            wsf_xml_msg_recv_invoke_business_logic_sync);
    return msg_recv;
}

axis2_status_t AXIS2_CALL
wsf_xml_msg_recv_invoke_business_logic_sync(axis2_msg_recv_t* msg_recv,
        const axutil_env_t* env,
        axis2_msg_ctx_t* in_msg_ctx,
        axis2_msg_ctx_t* out_msg_ctx)
{
    axis2_op_ctx_t *op_ctx = NULL;
    axis2_op_t *op_desc = NULL;

    axiom_node_t *om_node = NULL;
    axiom_element_t *om_element = NULL;
    axiom_node_t *result_node = NULL;
    axiom_node_t *body_content_node = NULL;
    axiom_element_t *body_content_element = NULL;
    axiom_node_t *out_node = NULL;

    axiom_namespace_t *env_ns = NULL;
    axutil_property_t *prop = NULL;
    int soap_version = AXIOM_SOAP12;
    axis2_status_t status = AXIS2_SUCCESS;
    axis2_bool_t skel_invoked = AXIS2_FALSE;
    int use_mtom = AXIS2_TRUE;
    int request_xop = AXIS2_FALSE;

    const axis2_char_t *style = NULL;
    axis2_char_t *local_name = NULL;
    axis2_char_t *soap_ns = AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI;
    axis2_char_t *operation_name = NULL;
    axis2_char_t *classname = NULL;
    wsf_svc_info_t *svc_info = NULL;

    /** store in_msg_ctx envelope */
    axiom_soap_envelope_t *envelope = NULL;
    axiom_soap_body_t *body = NULL;

    /* store out_msg_ctx envelope */
    axiom_soap_envelope_t *default_envelope = NULL;

    axiom_soap_body_t *out_body = NULL;
    axiom_soap_header_t *out_header = NULL;
    axiom_soap_fault_t *soap_fault = NULL;

    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "invoking business logic");
    AXIS2_PARAM_CHECK(env->error, in_msg_ctx, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, out_msg_ctx, AXIS2_FAILURE);

    op_ctx = axis2_msg_ctx_get_op_ctx(in_msg_ctx, env);
    op_desc = axis2_op_ctx_get_op(op_ctx, env);

    style = axis2_op_get_style(op_desc, env);

    envelope = axis2_msg_ctx_get_soap_envelope(in_msg_ctx, env);
    body = axiom_soap_envelope_get_body(envelope, env);
    if (0 == axutil_strcmp(AXIS2_STYLE_DOC, style))
    {
        om_node = axiom_soap_body_get_base_node(body, env);
        om_element = axiom_node_get_data_element(om_node, env);
        om_node = axiom_node_get_first_child(om_node, env);
        local_name = wsf_xml_msg_recv_get_method_name(in_msg_ctx, env);

        if (!local_name)
        {
            return AXIS2_FAILURE;
        }
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "localname %s", local_name);
    }
    else if (0 == axutil_strcmp(AXIS2_STYLE_RPC, style))
    {
        axiom_node_t *op_node = NULL;
        axiom_element_t *op_element = NULL;
        op_node = axiom_soap_body_get_base_node(body, env);
        op_element = axiom_node_get_data_element(op_node, env);

        if (!op_element)
        {
            return AXIS2_FAILURE;
        }

        local_name = axiom_element_get_localname(op_element, env);

        if (!local_name)
        {
            return AXIS2_FAILURE;
        }
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "localname %s", local_name);
        om_node = axiom_node_get_first_child(op_node, env);
        om_element = axiom_node_get_data_element(om_node, env);
    }

    /** set soap version and soap namespace to local variables */
    if (in_msg_ctx && axis2_msg_ctx_get_is_soap_11(in_msg_ctx, env))
    {
        soap_ns = AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI; /* default is 1.2 */
        soap_version = AXIOM_SOAP11;
    }
    prop = axis2_msg_ctx_get_property(in_msg_ctx, env, WS_SVC_INFO);
    if (prop)
    {
        svc_info = (wsf_svc_info_t *) axutil_property_get_value(prop, env);
        if (svc_info)
        {
            use_mtom = svc_info->use_mtom;
            request_xop = svc_info->request_xop;
            operation_name =
                axutil_hash_get(svc_info->ops_to_functions, local_name,
                        AXIS2_HASH_KEY_STRING);
            if (!operation_name)
            {
                return AXIS2_FAILURE;
            }
        }
        else
        {
            return AXIS2_FAILURE;
        }

        if (svc_info->ops_to_classes)
        {
            classname = axutil_hash_get(svc_info->ops_to_classes,
                    local_name, AXIS2_HASH_KEY_STRING);
        }
    }
    result_node = wsf_xml_msg_recv_invoke_other(msg_recv, env, svc_info, in_msg_ctx,
            out_msg_ctx, operation_name, classname);
    if (!result_node)
    {
        status = AXIS2_ERROR_GET_STATUS_CODE(env->error);
    }
    else
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
                "response node is not null");
    }

    prop = axis2_msg_ctx_get_property(in_msg_ctx, env, WS_SVC_INFO);
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
                return AXIS2_FAILURE;
            }

            body_content_element = axiom_element_create(env, NULL, res_name,
                    ns, &body_content_node);
            axiom_node_add_child(body_content_node, env, result_node);
        }
        else
        {
            body_content_node = result_node;
        }
    }

    if (axis2_msg_ctx_get_soap_envelope(out_msg_ctx, env))
    {
        /* service implementation has set the envelope,
           useful when setting a SOAP fault.
           No need to further process */
        return AXIS2_SUCCESS;
    }

    /* create the soap envelope here */
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
        /* something went wrong, set a SOAP Fault */
        axis2_char_t *fault_value_str = "env:Sender";
        axis2_char_t *fault_reason_str = NULL;
        axis2_char_t *err_msg = NULL;

        if (!skel_invoked)
        {
            fault_value_str = "env:Receiver";
        }

        err_msg = (char *) AXIS2_ERROR_GET_MESSAGE(env->error);

        if (err_msg)
        {
            fault_reason_str = err_msg;
        }
        else
        {
            fault_reason_str = "Error occured while processing SOAP message";
        }

        soap_fault = axiom_soap_fault_create_default_fault(env, out_body,
                fault_value_str,
                fault_reason_str,
                soap_version);
    }

    if (body_content_node)
    {
        axiom_node_add_child(out_node, env, body_content_node);
        status = axis2_msg_ctx_set_soap_envelope(out_msg_ctx, env,
                default_envelope);
    }
    else if (soap_fault)
    {
        axis2_msg_ctx_set_soap_envelope(out_msg_ctx, env, default_envelope);
        status = AXIS2_FAILURE; /* if there is a failure we have to return a failure code */
    }
    else
    {
        /* we should free the memory as the envelope is not used, one way case */
        axiom_soap_envelope_free(default_envelope, env);
        default_envelope = NULL;
    }

    return AXIS2_SUCCESS;
}


static axis2_char_t*
wsf_xml_msg_recv_get_method_name(axis2_msg_ctx_t*    msg_ctx,
        const axutil_env_t* env)
{
    axis2_op_ctx_t *op_ctx = NULL;
    axis2_op_t *op = NULL;
    const axutil_qname_t *qname = NULL;
    axis2_char_t *name = NULL;

    op_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);

    if (!op_ctx)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Operation Context is not found");
        return NULL;
    }

    op = axis2_op_ctx_get_op(op_ctx, env);

    if (!op)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Operation is not found");
        return NULL;
    }

    qname = axis2_op_get_qname(op, env);

    if (!qname)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Operation QName is not found");
        return NULL;
    }

    name = axutil_qname_get_localpart(qname, env);

    return name;
}


static axiom_node_t *
wsf_xml_msg_recv_invoke_other(axis2_msg_recv_t* msg_recv,
        const axutil_env_t* env,
        wsf_svc_info_t* svc_info,
        axis2_msg_ctx_t* in_msg_ctx,
        axis2_msg_ctx_t* out_msg_ctx,
        axis2_char_t* function_name,
        axis2_char_t* class_name)
{
    AXIS2_PARAM_CHECK(env->error, svc_info, NULL);
    AXIS2_PARAM_CHECK(env->error, in_msg_ctx, NULL);
    AXIS2_PARAM_CHECK(env->error, out_msg_ctx, NULL);

    axiom_node_t *node = NULL;
    axiom_node_t *om_node = NULL;
    axiom_soap_envelope_t *envelope = NULL;
    axiom_soap_body_t *body = NULL;
    axis2_char_t *retstr = NULL;
    axiom_node_t *soap_body_node = NULL;

    /* extracting payload from the soap message */
    envelope = axis2_msg_ctx_get_soap_envelope(in_msg_ctx, env);
    if (!envelope)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[wsf-perl-service] soap envelope not found");
        return NULL;
    }

    body = axiom_soap_envelope_get_body(envelope, env);
    if (!body)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[wsf-perl-service] soap body not found");
        return NULL;
    }

    soap_body_node = axiom_soap_body_get_base_node(body, env);
    if (!soap_body_node)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[wsf-perl-service] soap body base node not found");
        return NULL;
    }

    om_node = axiom_node_get_first_child(soap_body_node, env);
    if (!om_node)
    {
        return NULL;
    }

    axis2_char_t *embedding[] = {"-M'WSO2::WSF::C; WSO2::WSF::Service;'", ""};
    if (!svc_info->script_filename)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
                "perl function invocation failed, script_file name not found for "
                "service %s", svc_info->svc_name);
        return NULL;
    }
    /* passing script real path into perl interpreter. */
    embedding[1] = svc_info->script_filename;

    my_perl = perl_alloc();
    PL_perl_destruct_level = 0;
/*    PL_use_safe_putenv = 1; */
    PERL_SET_CONTEXT(my_perl);
    perl_construct(my_perl);

    PL_origalen = 1;
    PERL_SET_CONTEXT(my_perl);
    if (perl_parse(my_perl, xs_init, 2, embedding, NULL))
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "perl_parse method failed");
        return NULL;
    }
    PL_exit_flags |= PERL_EXIT_DESTRUCT_END;
    /* perl_run(my_perl); */

    if (SvTRUE(ERRSV))
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "invoke perl function failed");
    }

    retstr = invoke_perl_function(env, om_node, function_name, NULL);

    if (retstr)
    {
        node = wsf_util_deserialize_buffer(env, retstr);
    }

    PERL_SET_CONTEXT(my_perl);
    perl_destruct(my_perl);
    PERL_SET_CONTEXT(my_perl);
    perl_free(my_perl);
    PERL_SYS_TERM();
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, axiom_node_to_string(node, env));
    return node;
}

static axis2_char_t *
invoke_perl_function(const axutil_env_t *env, axiom_node_t *om_node,
        axis2_char_t *operation, axis2_char_t *class_name)
{
    int count = 0;
    axis2_char_t *inmsg = NULL;
    SV **wsmsg_str = NULL; /* hold the value for the key 'payload' in WSMessage */
    SV *wsmsg_ref = NULL; /* reference to a WSMessage object */
    HV *wsmsg = NULL; /* WSMessage object */
    char *tmp_str = NULL;
    axis2_char_t *res_payload_str = NULL;

    if (!operation)
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
                "invoking perl function failed, operation not available");
        return NULL;
    }

    if (om_node)
    {
        inmsg = axiom_node_to_string(om_node, env);
    }

    /* declare and init a local copy of the Perl stack pointer */
    dSP;

    /* mortal SVs for the stack */
    ENTER;
    SAVETMPS;

    /* "record" the current stack pointer */
    PUSHMARK(SP);

    /* push parameters to the stack */
    XPUSHs(sv_2mortal(newSVpv(inmsg, 0)));

    /* make the global copy of the stack pointer same as the local copy */
    PUTBACK;

    /* call the Perl function, expecting a scalar to be returned */
    count = call_pv(operation, G_SCALAR);

    /* refreshing the local copy of the stack pointer, call_pv might have reallocated it */
    SPAGAIN;

    if (count != 1)
    {
        croak("perl function invocation failed") ;
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "perl function %s invocation failed", operation);
    }

    /* get the scalar reference from the stack */
    wsmsg_ref = (SV *) POPs;

    /* getting the object from the reference */
    wsmsg = SvRV(wsmsg_ref);

    /* fetching the value of the member variable 'payload' from WSMessage */
    wsmsg_str = hv_fetch(wsmsg, "payload", 7, FALSE);

    /* perl scalar to c string */
    tmp_str = SvPVutf8_nolen(*wsmsg_str);
    res_payload_str = (axis2_char_t *) savepvn(tmp_str, strlen(tmp_str));

    PUTBACK;

    /* cleaning up mortal SVs */
    FREETMPS;
    LEAVE;

    return res_payload_str;
}

/* xs_init is for support dynamic loading of modules */
static void
xs_init(pTHX)
{
    char *file = __FILE__;
    dXSUB_SYS;

    /* DynaLoader is a special case */
    newXS("DynaLoader::boot_DynaLoader", boot_DynaLoader, file);
}
