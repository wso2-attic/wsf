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

#include <axis2_http_transport_sender.h>
#include <axutil_string.h>
#include <axis2_endpoint_ref.h>
#include <axis2_addr.h>
#include <axiom_xml_writer.h>
#include <axiom_output.h>
#include <axis2_http_transport_utils.h>
#include <axis2_http_out_transport_info.h>
#include <axis2_http_transport.h>
#include <axis2_http_sender.h>
#include <axiom_soap_body.h>
#include <axutil_types.h>


/**
 * HTTP Transport Sender struct impl
 * Axis2 HTTP Transport Sender impl
 */

typedef struct axis2_http_transport_sender_impl
{
    axis2_transport_sender_t transport_sender;
    axis2_char_t *http_version;
    axis2_bool_t chunked;
    int connection_timeout;
    int so_timeout;

}
axis2_http_transport_sender_impl_t;

#define AXIS2_WS_RM_ANONYMOUS_URL "http://docs.oasis-open.org/ws-rx/wsmc/200702/anonymous?id="

#define AXIS2_INTF_TO_IMPL(transport_sender) \
                         ((axis2_http_transport_sender_impl_t *)\
                     (transport_sender))

/***************************** Function headers *******************************/
axis2_status_t AXIS2_CALL
axis2_http_transport_sender_invoke(
    axis2_transport_sender_t *transport_sender,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx);

axis2_status_t AXIS2_CALL
axis2_http_transport_sender_clean_up(
    axis2_transport_sender_t *transport_sender,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx);

axis2_status_t AXIS2_CALL
axis2_http_transport_sender_init(
    axis2_transport_sender_t *transport_sender,
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_transport_out_desc_t *out_desc);

axis2_status_t AXIS2_CALL
axis2_http_transport_sender_write_message(
    axis2_transport_sender_t *transport_sender,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axis2_endpoint_ref_t *epr,
    axiom_soap_envelope_t *out,
    axiom_output_t *om_output);

void AXIS2_CALL
axis2_http_transport_sender_free(
    axis2_transport_sender_t *transport_sender,
    const axutil_env_t *env);

static const axis2_transport_sender_ops_t http_transport_sender_ops_var = {
    axis2_http_transport_sender_init,
    axis2_http_transport_sender_invoke,
    axis2_http_transport_sender_clean_up,
    axis2_http_transport_sender_free
};

axis2_transport_sender_t *AXIS2_CALL
axis2_http_transport_sender_create(
    const axutil_env_t *env)
{
    axis2_http_transport_sender_impl_t *transport_sender_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    transport_sender_impl = (axis2_http_transport_sender_impl_t *)AXIS2_MALLOC
            (env->allocator, sizeof(
                        axis2_http_transport_sender_impl_t));

    if (! transport_sender_impl)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    transport_sender_impl->http_version = axutil_strdup(env, AXIS2_HTTP_HEADER_PROTOCOL_11);
    transport_sender_impl->chunked = AXIS2_TRUE;
    transport_sender_impl->connection_timeout =
        AXIS2_HTTP_DEFAULT_CONNECTION_TIMEOUT;
    transport_sender_impl->so_timeout = AXIS2_HTTP_DEFAULT_SO_TIMEOUT;
    transport_sender_impl->transport_sender.ops = &http_transport_sender_ops_var;

    return &(transport_sender_impl->transport_sender);
}


void AXIS2_CALL
axis2_http_transport_sender_free(
    axis2_transport_sender_t *transport_sender,
    const axutil_env_t *env)
{
    axis2_http_transport_sender_impl_t *transport_sender_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    transport_sender_impl = AXIS2_INTF_TO_IMPL(transport_sender);

    if (transport_sender_impl->http_version)
    {
        AXIS2_FREE(env->allocator, transport_sender_impl->http_version);
        transport_sender_impl->http_version = NULL;
    }

    AXIS2_FREE(env->allocator, transport_sender_impl);
    return;
}


axis2_status_t AXIS2_CALL
axis2_http_transport_sender_invoke(
    axis2_transport_sender_t *transport_sender,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    const axis2_char_t *char_set_enc = NULL;
    axutil_string_t *char_set_enc_str = NULL;
    axis2_endpoint_ref_t *epr = NULL;
    axis2_char_t *transport_url = NULL;
    axiom_xml_writer_t *xml_writer = NULL;
    axiom_output_t *om_output = NULL;
    axis2_char_t *buffer = NULL;
    axiom_soap_envelope_t *soap_data_out = NULL;
    axis2_bool_t do_mtom;
    axutil_property_t *property = NULL;
    axiom_node_t *data_out = NULL;
    axis2_byte_t *output_stream = NULL;
    int buffer_size = 0;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);

    /*property =  axis2_msg_ctx_get_property(msg_ctx, env,
            AXIS2_CHARACTER_SET_ENCODING);
    if (property)
    {
        char_set_enc = axutil_property_get_value(property, env);
        property = NULL;
    }*/
    char_set_enc_str = axis2_msg_ctx_get_charset_encoding(msg_ctx, env);
    if (char_set_enc_str)
    {
        char_set_enc = axutil_string_get_buffer(char_set_enc_str, env);
    }
    
    if (!char_set_enc)
    {
        axis2_op_ctx_t *op_ctx =  axis2_msg_ctx_get_op_ctx(msg_ctx, env);
        if (op_ctx)
        {
            axis2_ctx_t *ctx = axis2_op_ctx_get_base(op_ctx, env);
            if (ctx)
            {
                property =  axis2_ctx_get_property(ctx, env,
                        AXIS2_CHARACTER_SET_ENCODING);
                if (property)
                {
                    char_set_enc = axutil_property_get_value(property, env);
                    property = NULL;
                }
            }
        }
    }
    /**
     * If we still can't find the char set enc we will
     * use default
     */
    if (! char_set_enc)
    {
        char_set_enc = AXIS2_DEFAULT_CHAR_SET_ENCODING;
    }

    do_mtom = axis2_http_transport_utils_do_write_mtom(env,
            msg_ctx);
     axis2_msg_ctx_set_doing_mtom(msg_ctx, env, do_mtom);
    /*do_mtom =  axis2_msg_ctx_get_doing_mtom(msg_ctx, env);*/
    /* axis2_msg_ctx_set_doing_rest(msg_ctx,
                      env, axis2_http_transport_utils_is_doing_rest(env, 
                      msg_ctx));*/

    transport_url = axis2_msg_ctx_get_transport_url(msg_ctx, env);
    if (transport_url)
    {
        epr = axis2_endpoint_ref_create(env, transport_url);
    }
    else
    {
        axis2_endpoint_ref_t *ctx_epr =  axis2_msg_ctx_get_to(msg_ctx, env);
        if (ctx_epr && 0 != axutil_strcmp(
                    AXIS2_WSA_ANONYMOUS_URL_SUBMISSION,
                    axis2_endpoint_ref_get_address(ctx_epr, env)) &&
                0 != axutil_strcmp(AXIS2_WSA_ANONYMOUS_URL,
                        axis2_endpoint_ref_get_address(ctx_epr, env)) &&
                !(axutil_strstr(axis2_endpoint_ref_get_address(ctx_epr, env), AXIS2_WS_RM_ANONYMOUS_URL)))
        {
            epr = ctx_epr;
        }
    }

    soap_data_out =  axis2_msg_ctx_get_soap_envelope(msg_ctx, env);
    if (! soap_data_out)
    {
        AXIS2_ERROR_SET(env->error,
                AXIS2_ERROR_NULL_SOAP_ENVELOPE_IN_MSG_CTX,
                AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "%s",
                AXIS2_ERROR_GET_MESSAGE(env->error));
        /*return AXIS2_FAILURE;*/
        return AXIS2_SUCCESS;
    }
    xml_writer = axiom_xml_writer_create_for_memory(env, NULL,
            AXIS2_TRUE, 0, AXIS2_XML_PARSER_TYPE_BUFFER);
    if (! xml_writer)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Could not create xml_writer");
        return AXIS2_FAILURE;
    }
    om_output = axiom_output_create(env, xml_writer);
    if (! om_output)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Could not create om_output");
        axiom_xml_writer_free(xml_writer, env);
        xml_writer = NULL;
        return AXIS2_FAILURE;
    }

    axiom_output_set_soap11(om_output, env,  axis2_msg_ctx_get_is_soap_11(msg_ctx, env));
    if (epr)
    {
        if (axutil_strcmp(AXIS2_WSA_NONE_URL_SUBMISSION, axis2_endpoint_ref_get_address(epr, env)) == 0 ||
                axutil_strcmp(AXIS2_WSA_NONE_URL, axis2_endpoint_ref_get_address(epr, env)) == 0)
        {
            epr = NULL;
        }
        else
        {
            axis2_http_transport_sender_write_message(transport_sender, env, msg_ctx
                    , epr, soap_data_out, om_output);
        }
    }

    if (!epr)
    {
        axutil_stream_t *out_stream = axis2_msg_ctx_get_transport_out_stream(msg_ctx, env);
        
        if (AXIS2_TRUE ==  axis2_msg_ctx_get_server_side(msg_ctx, env))
        {
            axis2_http_out_transport_info_t *out_info = NULL;
            axis2_bool_t is_soap11 = AXIS2_FALSE;
            axis2_op_ctx_t *op_ctx = NULL; 

            out_info = axis2_msg_ctx_get_http_out_transport_info(msg_ctx, env);

            if (! out_info)
            {
                AXIS2_ERROR_SET(env->error,
                        AXIS2_ERROR_OUT_TRNSPORT_INFO_NULL, AXIS2_FAILURE);
                axiom_output_free(om_output, env);
                om_output = NULL;
                xml_writer = NULL;
                return AXIS2_FAILURE;
            }
            is_soap11 =  axis2_msg_ctx_get_is_soap_11(msg_ctx, env);
            /* axiom_output_set_soap11(om_output, env, is_soap_11);
             */
            AXIS2_HTTP_OUT_TRANSPORT_INFO_SET_CHAR_ENCODING(out_info, env,
                    char_set_enc);
            if (AXIS2_TRUE == is_soap11)
            {
                AXIS2_HTTP_OUT_TRANSPORT_INFO_SET_CONTENT_TYPE(out_info, env,
                        AXIS2_HTTP_HEADER_ACCEPT_TEXT_XML);
            }
            else
            {
                AXIS2_HTTP_OUT_TRANSPORT_INFO_SET_CONTENT_TYPE(out_info, env,
                        AXIS2_HTTP_HEADER_ACCEPT_APPL_SOAP);
            }
		
            if (AXIS2_TRUE ==  axis2_msg_ctx_get_doing_rest(msg_ctx, env))
            {
                axiom_node_t *body_node = NULL;
                axiom_soap_body_t *soap_body = axiom_soap_envelope_get_body(
                            soap_data_out, env);

                if (! soap_body)
                {
                    AXIS2_ERROR_SET(env->error,
                            AXIS2_ERROR_SOAP_ENVELOPE_OR_SOAP_BODY_NULL,
                            AXIS2_FAILURE);
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "%s",
                            AXIS2_ERROR_GET_MESSAGE(env->error));
                    axiom_output_free(om_output, env);
                    om_output = NULL;
                    xml_writer = NULL;
                    return AXIS2_FAILURE;
                }
                body_node = axiom_soap_body_get_base_node(soap_body, env);
                if (! body_node)
                {
                    axiom_output_free(om_output, env);
                    om_output = NULL;
                    xml_writer = NULL;
                    return AXIS2_FAILURE;
                }
                data_out = axiom_node_get_first_element(body_node, env);
                if (! data_out || axiom_node_get_node_type(data_out, env)
                        != AXIOM_ELEMENT)
                {
                    axiom_output_free(om_output, env);
                    om_output = NULL;
                    xml_writer = NULL;
                    return AXIS2_FAILURE;
                }
                axiom_node_serialize(data_out, env, om_output);
                buffer = (axis2_char_t*)axiom_xml_writer_get_xml(xml_writer, env);
                buffer_size = axiom_xml_writer_get_xml_size(xml_writer, env);
            }
            else
            {
                axiom_output_set_do_optimize(om_output, env,
                        do_mtom);
                axiom_soap_envelope_serialize(soap_data_out, env, om_output,
                        AXIS2_FALSE);
                if (do_mtom)
                {
                    axis2_char_t *content_type = NULL;
                    axiom_output_flush(om_output, env, &output_stream,
                            &buffer_size);
                    content_type = (axis2_char_t *)axiom_output_get_content_type(
                                om_output,
                                env);
                    AXIS2_HTTP_OUT_TRANSPORT_INFO_SET_CONTENT_TYPE(out_info,
                            env, content_type);
                    buffer = output_stream;
                }
                else
                {
                    buffer = (axis2_char_t *)axiom_xml_writer_get_xml(xml_writer, env);
                    buffer_size = axiom_xml_writer_get_xml_size(xml_writer, env);
                }
            }
            axutil_stream_write(out_stream, env, buffer, buffer_size);
            /*AXIS2_FREE(env->allocator, buffer);*/

            op_ctx =  axis2_msg_ctx_get_op_ctx(msg_ctx, env);
            axis2_op_ctx_set_response_written(op_ctx, env, AXIS2_TRUE);
        }
    }

	
    axiom_output_free(om_output, env);
    om_output = NULL;
    xml_writer = NULL;

    if (transport_url)
    {
        if (epr)
        {
            axis2_endpoint_ref_free(epr, env);
            epr = NULL;
        }
    }
    return AXIS2_SUCCESS;
}


axis2_status_t AXIS2_CALL
axis2_http_transport_sender_clean_up(
    axis2_transport_sender_t *transport_sender,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);
    /*
     * Clean up is not used. If the http sender needs
     * to be cleaned up it should be done here.
     */
    return AXIS2_SUCCESS;
}


axis2_status_t AXIS2_CALL
axis2_http_transport_sender_init(
    axis2_transport_sender_t *transport_sender,
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_transport_out_desc_t *out_desc)
{
    axutil_param_t *version_param = NULL;
    axis2_char_t *version = NULL;
    axis2_char_t *temp = NULL;
    axutil_param_t *temp_param = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, conf_ctx, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, out_desc, AXIS2_FAILURE);

    version_param = axutil_param_container_get_param(
                axis2_transport_out_desc_param_container(out_desc, env), env,
                AXIS2_HTTP_PROTOCOL_VERSION);
    if (version_param)
    {
        version = axutil_param_get_value(version_param, env);
    }
    if (version)
    {
        if (0 == axutil_strcmp(version, AXIS2_HTTP_HEADER_PROTOCOL_11))
        {
            axis2_char_t *encoding = NULL;
            axutil_param_t *encoding_param = NULL;
            if (AXIS2_INTF_TO_IMPL(transport_sender)->http_version)
            {
                AXIS2_FREE(env->allocator,
                        AXIS2_INTF_TO_IMPL(transport_sender)->http_version);
            }
            AXIS2_INTF_TO_IMPL(transport_sender)->http_version = axutil_strdup(env, version);
            encoding_param = axutil_param_container_get_param(
                        axis2_transport_out_desc_param_container(out_desc, env), env,
                        AXIS2_HTTP_HEADER_TRANSFER_ENCODING);
            if (encoding_param)
            {
                encoding = axutil_param_get_value(encoding_param, env);
            }
            if (encoding && 0 == axutil_strcmp(encoding,
                    AXIS2_HTTP_HEADER_TRANSFER_ENCODING_CHUNKED))
            {
                AXIS2_INTF_TO_IMPL(transport_sender)->chunked = AXIS2_TRUE;
            }
            else
            {
                AXIS2_INTF_TO_IMPL(transport_sender)->chunked = AXIS2_FALSE;
            }
        }
        else if (0 == axutil_strcmp(version, AXIS2_HTTP_HEADER_PROTOCOL_10))
        {
            if (AXIS2_INTF_TO_IMPL(transport_sender)->http_version)
            {
                AXIS2_FREE(env->allocator,
                        AXIS2_INTF_TO_IMPL(transport_sender)->http_version);
            }
            AXIS2_INTF_TO_IMPL(transport_sender)->http_version = axutil_strdup(env, version);
            AXIS2_INTF_TO_IMPL(transport_sender)->chunked = AXIS2_FALSE;
        }
    }
    else
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NULL_HTTP_VERSION,
                AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }


    temp_param = axutil_param_container_get_param(
                axis2_transport_out_desc_param_container(out_desc, env), env,
                AXIS2_HTTP_SO_TIMEOUT);
    if (temp_param)
    {
        temp = axutil_param_get_value(temp_param, env);
    }
    if (temp)
    {
        AXIS2_INTF_TO_IMPL(transport_sender)->so_timeout = AXIS2_ATOI(temp);
    }
    temp = (axis2_char_t *)axutil_param_container_get_param(
                axis2_transport_out_desc_param_container(out_desc, env), env,
                AXIS2_HTTP_CONNECTION_TIMEOUT);
    if (temp_param)
    {
        temp = axutil_param_get_value(temp_param, env);
    }
    if (temp)
    {
        AXIS2_INTF_TO_IMPL(transport_sender)->connection_timeout =
            AXIS2_ATOI(temp);
    }

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_http_transport_sender_write_message(
    axis2_transport_sender_t *transport_sender,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axis2_endpoint_ref_t *epr,
    axiom_soap_envelope_t *out,
    axiom_output_t *om_output)
{
    const axis2_char_t *soap_action = NULL;
    const axis2_char_t *url = NULL;
    axis2_http_sender_t *sender = NULL;
    axis2_status_t status = AXIS2_FAILURE;
	const axis2_char_t *soap_ns_uri = NULL;
	axiom_soap_envelope_t *response_envelope = NULL;
	axis2_op_t *op = NULL;
/*     axis2_http_client_t *client = NULL; */

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, epr, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, om_output, AXIS2_FAILURE);

    url = axis2_endpoint_ref_get_address(epr, env);
    
    soap_action = axutil_string_get_buffer( axis2_msg_ctx_get_soap_action(msg_ctx, env), env);
    
    if (! soap_action)
    {
        soap_action = "";
    }

	sender = axis2_http_sender_create(env);

	if (! sender)
	{
		return AXIS2_FAILURE;
	}

	AXIS2_HTTP_SENDER_SET_CHUNKED(sender, env,
								  AXIS2_INTF_TO_IMPL(transport_sender)->chunked);
	AXIS2_HTTP_SENDER_SET_OM_OUTPUT(sender, env, om_output);
	AXIOM_SENDER_SET_HTTP_VERSION(sender, env,
								  AXIS2_INTF_TO_IMPL(transport_sender)->http_version);
	status = AXIS2_HTTP_SENDER_SEND(sender, env, msg_ctx, out, url, soap_action);

	AXIS2_HTTP_SENDER_FREE(sender, env);
	sender = NULL;

    op =  axis2_msg_ctx_get_op(msg_ctx, env);
    if (op)
    {
        /* handle one way case */
        const axis2_char_t *mep = axis2_op_get_msg_exchange_pattern(op, env);
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "OP name axutil_qname_get_localpart = %s",
                mep);
        if (axutil_strcmp(mep, AXIS2_MEP_URI_OUT_ONLY) == 0 ||
            axutil_strcmp(mep, AXIS2_MEP_URI_ROBUST_OUT_ONLY) == 0 ||
            axutil_strcmp(mep, AXIS2_MEP_URI_IN_ONLY) == 0)
        {
            return status;
        }
		else
		{
			soap_ns_uri =  axis2_msg_ctx_get_is_soap_11(msg_ctx, env) ?
				AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI : AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI;
			response_envelope = axis2_http_transport_utils_create_soap_msg(env,
																		   msg_ctx, soap_ns_uri);
            if (response_envelope)
    			 axis2_msg_ctx_set_response_soap_envelope (msg_ctx, env, response_envelope);
		}
    }
    /* Free the client */
/*     if (client) */
/*     { */
/*         axis2_http_client_free(client, env); */
/*         client = NULL; */
/*     } */

    return status;
}

/**
 * Following block distinguish the exposed part of the dll.
 */

/* When building for static deployment, give the get and remove methods
 * unique names.  This avoids having the linker fail with duplicate symbol
 * errors.
 */

AXIS2_EXPORT int
#ifndef AXIS2_STATIC_DEPLOY
axis2_get_instance(
#else
axis2_http_transport_sender_get_instance(
#endif
    struct axis2_transport_sender **inst,
    const axutil_env_t *env)
{
    *inst = axis2_http_transport_sender_create(env);
    if (!(*inst))
    {
        return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXPORT int
#ifndef AXIS2_STATIC_DEPLOY
axis2_remove_instance(
#else
axis2_http_transport_sender_remove_instance(
#endif
    axis2_transport_sender_t *inst,
    const axutil_env_t *env)
{
    if (inst)
    {
        AXIS2_TRANSPORT_SENDER_FREE(inst, env);
    }
    return AXIS2_SUCCESS;
}



