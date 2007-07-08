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

#include <axis2_http_transport_utils.h>
#include <string.h>
#include <ctype.h>
#include <axis2_conf.h>
#include <axis2_op.h>
#include <axutil_qname.h>
#include <axis2_http_transport.h>
#include <axiom_soap_builder.h>
#include <axis2_engine.h>
#include <axiom_soap_body.h>
#include <axutil_utils.h>
#include <axiom_namespace.h>
#include <axiom_node.h>
#include <axutil_hash.h>
#include <axiom_soap_const.h>
#include <axis2_http_header.h>
#include <axutil_property.h>
#include <axutil_utils.h>
#include <axiom_mime_parser.h>
#include <axis2_disp.h>
#include <axis2_msg.h>

#define AXIOM_MIME_BOUNDARY_BYTE 45
#define FILE_READ_SIZE 2048
const axis2_char_t * AXIS2_TRANS_UTIL_DEFAULT_CHAR_ENCODING =  AXIS2_HTTP_HEADER_DEFAULT_CHAR_ENCODING;

/***************************** Function headers *******************************/

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_http_transport_utils_process_http_post_request(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axutil_stream_t *in_stream,
    axutil_stream_t *out_stream,
    const axis2_char_t *content_type,
    const int content_length,
    axutil_string_t *soap_action_header,
    const axis2_char_t *request_uri);

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axis2_http_transport_utils_process_http_get_request(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axutil_stream_t *in_stream,
    axutil_stream_t *out_stream,
    const axis2_char_t *content_type,
    axutil_string_t *soap_action_header,
    const axis2_char_t *request_uri,
    axis2_conf_ctx_t *conf_ctx,
    axutil_hash_t *request_params);

AXIS2_EXTERN axiom_stax_builder_t *AXIS2_CALL
axis2_http_transport_utils_select_builder_for_mime(
    const axutil_env_t *env,
    axis2_char_t *request_uri,
    axis2_msg_ctx_t *msg_ctx,
    axutil_stream_t *in_stream,
    axis2_char_t *content_type);

AXIS2_EXTERN axis2_bool_t  AXIS2_CALL
axis2_http_transport_utils_is_optimized(
    const axutil_env_t *env,
    axiom_element_t *om_element);

AXIS2_EXTERN axis2_bool_t  AXIS2_CALL
axis2_http_transport_utils_do_write_mtom(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx);

AXIS2_EXTERN axis2_bool_t  AXIS2_CALL
axis2_http_transport_utils_is_doing_rest(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx);

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axis2_http_transport_utils_is_doing_rest_through_post(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_http_transport_utils_strdecode(
    const axutil_env_t *env,
    axis2_char_t *dest,
    axis2_char_t *src);

AXIS2_EXTERN int AXIS2_CALL
axis2_http_transport_utils_hexit(
    axis2_char_t c);

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axis2_http_transport_utils_get_services_html(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx);

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axis2_http_transport_utils_get_services_static_wsdl(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_char_t *request_url);


AXIS2_EXTERN axutil_string_t *AXIS2_CALL
axis2_http_transport_utils_get_charset_enc(
    const axutil_env_t *env,
    const axis2_char_t *content_type);

int AXIS2_CALL
axis2_http_transport_utils_on_data_request(
    char *buffer,
    int size,
    void *ctx);

AXIS2_EXTERN axiom_soap_envelope_t *AXIS2_CALL
axis2_http_transport_utils_create_soap_msg(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    const axis2_char_t *soap_ns_uri);

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axis2_http_transport_utils_get_value_from_content_type(
    const axutil_env_t *env,
    const axis2_char_t *content_type,
    const axis2_char_t *key);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_http_transport_utils_dispatch_and_verify(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx);

/*AXIS2_EXTERN axiom_soap_envelope_t *AXIS2_CALL
axis2_http_transport_utils_handle_media_type_url_encoded(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axutil_hash_t *param_map,
    axis2_char_t *method,
    xml_schema_element_t *schema_element);*/

AXIS2_EXTERN axiom_soap_envelope_t *AXIS2_CALL
axis2_http_transport_utils_handle_media_type_url_encoded(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axutil_hash_t *param_map,
    axis2_char_t *method);

/***************************** End of function headers ************************/

AXIS2_EXTERN axis2_status_t  AXIS2_CALL
axis2_http_transport_utils_process_http_post_request(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axutil_stream_t *in_stream,
    axutil_stream_t *out_stream,
    const axis2_char_t *content_type,
    const int content_length,
    axutil_string_t *soap_action_header,
    const axis2_char_t *request_uri)
{
    axiom_soap_envelope_t *soap_envelope = NULL;
    axiom_soap_builder_t *soap_builder = NULL;
    axiom_stax_builder_t *om_builder = NULL;
    axis2_bool_t is_soap11 = AXIS2_FALSE;
    axiom_xml_reader_t *xml_reader = NULL;
    axutil_string_t *char_set_str = NULL;
    /*axis2_char_t *xml_char_set = NULL;*/
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_callback_info_t *callback_ctx;
    axutil_hash_t *headers = NULL;
    axis2_engine_t *engine = NULL;
    axiom_soap_body_t *soap_body = NULL;
    axis2_status_t status = AXIS2_FAILURE;
    axutil_hash_t *binary_data_map = NULL;
    axis2_char_t *soap_body_str = NULL;
    axutil_stream_t *stream = NULL;
    axis2_bool_t do_rest = AXIS2_FALSE;
    axis2_char_t *soap_action = NULL;
    unsigned int soap_action_len = 0;
    axutil_property_t *http_error_property = NULL;

    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, in_stream, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, out_stream, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, content_type, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, request_uri, AXIS2_FAILURE);

    conf_ctx =  axis2_msg_ctx_get_conf_ctx(msg_ctx, env);

    callback_ctx = AXIS2_MALLOC(env->allocator, sizeof(axis2_callback_info_t));
    /* Note: the memory created above is freed in xml reader free function
       as this is passed on to the reader */
    callback_ctx->in_stream = in_stream;
    callback_ctx->env = env;
    callback_ctx->content_length = content_length;
    callback_ctx->unread_len = content_length;
    callback_ctx->chunked_stream = NULL;

    soap_action = (axis2_char_t*)axutil_string_get_buffer(soap_action_header, env);
    soap_action_len = axutil_string_get_length(soap_action_header, env);
   
    if (soap_action && (soap_action_len > 0))
    {
        /* remove leading and trailing " s */
        if ('"' == soap_action[0])
        {
            memmove(soap_action, soap_action + sizeof(char),
                    soap_action_len - 1 + sizeof(char));
        }
        if ('"' == soap_action[soap_action_len - 2])
        {
            soap_action[soap_action_len - 2] = '\0';
        }
    }
 
    headers = axis2_msg_ctx_get_transport_headers(msg_ctx, env);
    if (headers)
    {
        axis2_http_header_t *encoding_header = NULL;
        encoding_header = (axis2_http_header_t *)axutil_hash_get(headers,
                AXIS2_HTTP_HEADER_TRANSFER_ENCODING,
                AXIS2_HASH_KEY_STRING);
        if (encoding_header)
        {
            axis2_char_t *encoding_value = NULL;
            encoding_value = axis2_http_header_get_value(encoding_header, env);
            if (encoding_value && 0 == axutil_strcasecmp(encoding_value,
                    AXIS2_HTTP_HEADER_TRANSFER_ENCODING_CHUNKED))
            {
                callback_ctx->chunked_stream = axis2_http_chunked_stream_create(
                            env, in_stream);
                if (! callback_ctx->chunked_stream)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error occured in"
                            " creating in chunked stream.");
                    return AXIS2_FAILURE;
                }
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "HTTP"
                        " stream chunked");
            }
        }
    }
    else
    {
        /* check content encoding from msg ctx property */
        axis2_char_t *value = axis2_msg_ctx_get_transfer_encoding(msg_ctx, env);

        if (value && axutil_strstr(value, AXIS2_HTTP_HEADER_TRANSFER_ENCODING_CHUNKED))
        {
            /* this is an UGLY hack to get some of the trnaports working 
                e.g. PHP transport where it strips the chunking info in case of chunking 
                and also gives out a content lenght of 0.
                We need to fix the transport design to fix sutuations like this.
                */
            callback_ctx->content_length = 1000000;
            callback_ctx->unread_len = callback_ctx->content_length;
        }
    }

    if (strstr(content_type, AXIS2_HTTP_HEADER_ACCEPT_MULTIPART_RELATED))
    {
        /* get mime boundry */
        axis2_char_t *mime_boundary =
            axis2_http_transport_utils_get_value_from_content_type(env,
                    content_type, AXIS2_HTTP_HEADER_CONTENT_TYPE_MIME_BOUNDARY);

        if (mime_boundary)
        {
            axiom_mime_parser_t *mime_parser = NULL;
            int soap_body_len = 0;

            mime_parser = axiom_mime_parser_create(env);
            if (mime_parser)
            {
                binary_data_map = axiom_mime_parser_parse(mime_parser, env,
                        axis2_http_transport_utils_on_data_request,
                        (void *) callback_ctx, mime_boundary);

                soap_body_len = axiom_mime_parser_get_soap_body_len(
                            mime_parser, env);
                soap_body_str = axiom_mime_parser_get_soap_body_str(
                            mime_parser, env);
            }

            stream = axutil_stream_create_basic(env);
            if (stream)
            {
                axutil_stream_write(stream, env, soap_body_str, soap_body_len);
                /*AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
                    "axis2_http_transport_utils_process_http_post_request soap_body_str = %s...%d soap_body_len=%d", 
                    soap_body_str, strlen(soap_body_str), soap_body_len);*/
                callback_ctx->in_stream = stream;
                callback_ctx->chunked_stream = NULL;
                callback_ctx->content_length = soap_body_len;
                callback_ctx->unread_len = soap_body_len;
            }
            axiom_mime_parser_free(mime_parser, env);
            mime_parser = NULL;
        }
        AXIS2_FREE(env->allocator, mime_boundary);
    }

      axis2_msg_ctx_set_soap_action(msg_ctx, env, soap_action_header);
      axis2_msg_ctx_set_to(msg_ctx, env, axis2_endpoint_ref_create(env,
            request_uri));

     axis2_msg_ctx_set_server_side(msg_ctx, env, AXIS2_TRUE);

    char_set_str = axis2_http_transport_utils_get_charset_enc(env, content_type);
    xml_reader = axiom_xml_reader_create_for_io(env,
            axis2_http_transport_utils_on_data_request, NULL,
            (void *) callback_ctx, axutil_string_get_buffer(char_set_str, env));

    if (! xml_reader)
    {
        return AXIS2_FAILURE;
    }

    axis2_msg_ctx_set_charset_encoding(msg_ctx, env, char_set_str);

    om_builder = axiom_stax_builder_create(env, xml_reader);
    if (! om_builder)
    {
        axiom_xml_reader_free(xml_reader, env);
        xml_reader = NULL;
        return AXIS2_FAILURE;
    }

    if (strstr(content_type, AXIS2_HTTP_HEADER_ACCEPT_APPL_SOAP))
    {
        is_soap11 = AXIS2_FALSE;
        soap_builder = axiom_soap_builder_create(env, om_builder,
                AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI);
        if (! soap_builder)
        {
            /* We should not be freeing om_builder here as it is done by
               axiom_soap_builder_create in case of error - Samisa*/
            /*axiom_stax_builder_free(om_builder, env);*/
            om_builder = NULL;
            xml_reader = NULL;
            return AXIS2_FAILURE;
        }

        soap_envelope = axiom_soap_builder_get_soap_envelope(soap_builder,
                env);
        if (!soap_envelope)
        {
            axiom_stax_builder_free(om_builder, env);
            om_builder = NULL;
            xml_reader = NULL;
            axiom_soap_builder_free(soap_builder, env);
            soap_builder = NULL;
            return AXIS2_FAILURE;
        }
    }
    else if (strstr(content_type, AXIS2_HTTP_HEADER_ACCEPT_TEXT_XML))
    {
        is_soap11 = AXIS2_TRUE;
        if (soap_action_header)
        {
            soap_builder = axiom_soap_builder_create(env, om_builder,
                    AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI);
            if (! soap_builder)
            {
                /* We should not be freeing om_builder here as it is done by
                   axiom_soap_builder_create in case of error - Samisa*/
                /*axiom_stax_builder_free(om_builder, env);*/
                om_builder = NULL;
                xml_reader = NULL;
                return AXIS2_FAILURE;
            }
            soap_envelope = axiom_soap_builder_get_soap_envelope(
                        soap_builder, env);
            if (! soap_envelope)
            {  
              axiom_soap_builder_free(soap_builder, env);
                om_builder = NULL;
                xml_reader = NULL;
                soap_builder = NULL;
                return AXIS2_FAILURE;
            }
        }
        else
        {
            /* REST support */
            do_rest = AXIS2_TRUE;
        }
    }
    else if (strstr(content_type, AXIS2_HTTP_HEADER_ACCEPT_X_WWW_FROM_URLENCODED))
    {
        /* REST support */
        do_rest = AXIS2_TRUE;
    }
    else
    {
        http_error_property = axutil_property_create(env);
        axutil_property_set_value(http_error_property, env, AXIS2_HTTP_UNSUPPORTED_MEDIA_TYPE);
        axis2_msg_ctx_set_property(msg_ctx, env, AXIS2_HTTP_TRANSPORT_ERROR, http_error_property);
    }

    if (do_rest)
    {
        /* REST support */
        axutil_param_t *rest_param =  axis2_msg_ctx_get_parameter(msg_ctx, env
                , AXIS2_ENABLE_REST);
        if (rest_param && 0 == axutil_strcmp(AXIS2_VALUE_TRUE,
                axutil_param_get_value(rest_param, env)))
        {
            axiom_soap_body_t *def_body = NULL;
            axiom_document_t *om_doc = NULL;
            axiom_node_t *root_node = NULL;
            soap_envelope = axiom_soap_envelope_create_default_soap_envelope
                    (env, AXIOM_SOAP11);
            def_body = axiom_soap_envelope_get_body(soap_envelope, env);
            om_doc = axiom_stax_builder_get_document(om_builder, env);
            root_node = axiom_document_build_all(om_doc, env);
            axiom_soap_body_add_child(def_body, env, root_node);
             axis2_msg_ctx_set_doing_rest(msg_ctx, env, AXIS2_TRUE);
        }
    }


    if (binary_data_map)
    {
        axiom_soap_builder_set_mime_body_parts(soap_builder, env,
                binary_data_map);
    }

    /* xml_char_set = AXIOM_DOCUMENT_GET_CHARSET_ENC(
     *               axiom_stax_builder_get_document(env om_builder),
     *               env);
     *
     *if(0 != axutil_strcmp(char_set, xml_char_set))
     *{
     *   AXIS2_ERROR_SET(env->error, AXIS2_ERROR_CHARSET_MISMATCH, 
     *               AXIS2_FAILURE);
     *   axiom_soap_envelope_free(envelope, env);
     *   envelope = NULL;
     *   axiom_xml_reader_free(xml_reader, env);
     *   xml_reader = NULL;
     *   axiom_stax_builder_free(om_builder, env);
     *   om_builder = NULL;
     *   if( soap_builder)
     *   {
     *       axiom_soap_builder_free(soap_builder, env);
     *       soap_builder = NULL;
     *   }
     *   return AXIS2_FAILURE;
     *}
     */

     axis2_msg_ctx_set_soap_envelope(msg_ctx, env, soap_envelope);

    engine = axis2_engine_create(env, conf_ctx);

    if (!soap_envelope)
        return AXIS2_FAILURE;

    soap_body = axiom_soap_envelope_get_body(soap_envelope,
            env);

    if (! soap_body)
        return AXIS2_FAILURE;

    if (AXIS2_TRUE == axiom_soap_body_has_fault(soap_body, env))
    {
        status =  axis2_engine_receive_fault(engine, env, msg_ctx);
    }
    else
    {
        status =  axis2_engine_receive(engine, env, msg_ctx);
    }
    if (!  axis2_msg_ctx_get_soap_envelope(msg_ctx, env) &&
            AXIS2_FALSE == is_soap11)
    {
        axiom_soap_envelope_t *def_envelope =
            axiom_soap_envelope_create_default_soap_envelope(env,
                    AXIOM_SOAP12);
         axis2_msg_ctx_set_soap_envelope(msg_ctx, env, def_envelope);
    }

    if (engine)
    {
         axis2_engine_free(engine, env);
    }

    if (soap_body_str)
    {
        AXIS2_FREE(env->allocator, soap_body_str);
    }

    if (stream)
    {
        axutil_stream_free(stream, env);
    }

    if(char_set_str)
    {
        axutil_string_free(char_set_str, env);
    }
    
    return status;
}


AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axis2_http_transport_utils_process_http_get_request(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axutil_stream_t *in_stream,
    axutil_stream_t *out_stream,
    const axis2_char_t *content_type,
    axutil_string_t *soap_action_header,
    const axis2_char_t *request_uri,
    axis2_conf_ctx_t *conf_ctx,
    axutil_hash_t *request_params)
{
    axiom_soap_envelope_t *soap_envelope = NULL;
    axis2_engine_t *engine = NULL;
    axis2_op_t *op = NULL;
    /*xml_schema_element_t *schema_element = NULL;*/

    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, in_stream, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, out_stream, AXIS2_FALSE);
    /*AXIS2_PARAM_CHECK(env->error, content_type, AXIS2_FALSE);*/
    AXIS2_PARAM_CHECK(env->error, request_uri, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, request_params, AXIS2_FALSE);


     axis2_msg_ctx_set_to(msg_ctx, env, axis2_endpoint_ref_create(env,
            request_uri));

     axis2_msg_ctx_set_server_side(msg_ctx, env, AXIS2_TRUE);
    if (AXIS2_SUCCESS != axis2_http_transport_utils_dispatch_and_verify(env,
            msg_ctx))
    {
        return AXIS2_FALSE;
    }
    op =  axis2_msg_ctx_get_op(msg_ctx, env);

    soap_envelope = axis2_http_transport_utils_handle_media_type_url_encoded(
                env, msg_ctx, request_params, AXIS2_HTTP_GET);
    if (! soap_envelope)
    {
        return AXIS2_FALSE;
    }
    else
    {
         axis2_msg_ctx_set_doing_rest(msg_ctx, env, AXIS2_TRUE);
         axis2_msg_ctx_set_soap_envelope(msg_ctx, env, soap_envelope);
        engine = axis2_engine_create(env, conf_ctx);
         axis2_engine_receive(engine, env, msg_ctx);
        return AXIS2_TRUE;
    }
    return AXIS2_FALSE;
}

AXIS2_EXTERN axiom_stax_builder_t *AXIS2_CALL
axis2_http_transport_utils_select_builder_for_mime(
    const axutil_env_t *env,
    axis2_char_t *request_uri,
    axis2_msg_ctx_t *msg_ctx,
    axutil_stream_t *in_stream,
    axis2_char_t *content_type)
{
    return NULL;
}

AXIS2_EXTERN axis2_bool_t  AXIS2_CALL
axis2_http_transport_utils_is_optimized(
    const axutil_env_t *env,
    axiom_element_t *om_element)
{
    return AXIS2_FALSE;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axis2_http_transport_utils_do_write_mtom(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);

    return (axis2_msg_ctx_get_doing_mtom(msg_ctx, env));
}


AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axis2_http_transport_utils_is_doing_rest(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    return AXIS2_FALSE;
}


AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axis2_http_transport_utils_is_doing_rest_through_post(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    return AXIS2_FALSE;
}

AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
axis2_http_transport_utils_get_request_params(
    const axutil_env_t *env,
    axis2_char_t *request_uri)
{


    axis2_char_t *query_str = NULL;
    axis2_char_t *tmp = strchr(request_uri, '?');
    axis2_char_t *tmp2 = NULL;
    axis2_char_t *tmp_name = NULL;
    axis2_char_t *tmp_value = NULL;
    axutil_hash_t *ret = NULL;

    AXIS2_PARAM_CHECK(env->error, request_uri, AXIS2_FAILURE);

    if (! tmp || '\0' == *(tmp + 1))
    {
        return NULL;
    }
    query_str = axutil_strdup(env, tmp + 1);

    for (tmp2 = tmp = query_str; *tmp != '\0'; ++tmp)
    {
        if ('=' == *tmp)
        {
            *tmp = '\0';
            tmp_name = axutil_strdup(env, tmp2);
            axis2_http_transport_utils_strdecode(env, tmp_name, tmp_name);
            tmp2 = tmp + 1;
        }
        if ('&' == *tmp)
        {
            *tmp = '\0';
            tmp_value = axutil_strdup(env, tmp2);
            axis2_http_transport_utils_strdecode(env, tmp_value, tmp_value);
            tmp2 = tmp + 1;
        }
        if (tmp_name && NULL != tmp_value)
        {
            if (! ret)
            {
                ret = axutil_hash_make(env);
            }
            axutil_hash_set(ret, tmp_name, AXIS2_HASH_KEY_STRING, tmp_value);
            tmp_name = NULL;
            tmp_value = NULL;
        }
    }
    if (tmp_name && '\0' != *tmp2)
    {
        if (! ret)
        {
            ret = axutil_hash_make(env);
        }
        tmp_value = axutil_strdup(env, tmp2);
        axis2_http_transport_utils_strdecode(env, tmp_value, tmp_value);
        axutil_hash_set(ret, tmp_name, AXIS2_HASH_KEY_STRING, tmp_value);
    }

    return ret;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_http_transport_utils_strdecode(
    const axutil_env_t *env,
    axis2_char_t *dest,
    axis2_char_t *src)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, dest, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, src, AXIS2_FAILURE);

    for (; *src != '\0'; ++dest, ++src)
    {
        if (src[0] == '%' && isxdigit(src[1]) && isxdigit(src[2]))
        {
            *dest = axis2_http_transport_utils_hexit(src[1]) * 16 +
                    axis2_http_transport_utils_hexit(src[2]);
            src += 2;
        }
        else
        {
            *dest = *src;
        }
    }
    *dest = '\0';

    return AXIS2_SUCCESS;
}


AXIS2_EXTERN int  AXIS2_CALL
axis2_http_transport_utils_hexit(
    axis2_char_t c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    if (c >= 'a' && c <= 'f')
    {
        return c - 'a' + 10;
    }
    if (c >= 'A' && c <= 'F')
    {
        return c - 'A' + 10;
    }
    return 0;           /* shouldn't happen, we're guarded by isxdigit() */
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axis2_http_transport_utils_get_services_html(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx)
{
    axutil_hash_t *services_map = NULL;
    axutil_hash_t *errorneous_svc_map = NULL;
    axis2_char_t *ret = NULL;
    axis2_char_t *tmp2 = (axis2_char_t *)"<h2>Deployed Services</h2>";
    axutil_hash_index_t *hi = NULL;
    axis2_bool_t svcs_exists = AXIS2_FALSE;
    axis2_conf_t *conf = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, conf_ctx, NULL);

    conf = axis2_conf_ctx_get_conf (conf_ctx, env);
    services_map =  axis2_conf_get_all_svcs(conf, env);
    errorneous_svc_map =  axis2_conf_get_all_faulty_svcs(conf, env);
    if (services_map && 0 != axutil_hash_count(services_map))
    {
        void *service = NULL;
        axis2_char_t *sname = NULL;
        axutil_hash_t *ops = NULL;
        svcs_exists = AXIS2_TRUE;

        for (hi = axutil_hash_first(services_map, env);
                hi; hi = axutil_hash_next(env, hi))
        {
            axutil_hash_this(hi, NULL, NULL, &service);
            sname = axutil_qname_get_localpart(axis2_svc_get_qname(
                        ((axis2_svc_t *)service), env), env);
            ret = axutil_stracat(env, tmp2, "<h3><u>");
            tmp2 = ret;
            ret = axutil_stracat(env,tmp2, sname);
            AXIS2_FREE(env->allocator, tmp2);
            tmp2 = ret;
            ret  = axutil_stracat(env, tmp2, "</u></h3>");
				tmp2 = ret;
				ret = axutil_stracat (env, tmp2, "<p>");
				tmp2 = ret;
							 /**
							  *setting services description */
				ret = axutil_stracat (env, tmp2, axis2_svc_get_svc_desc(
                    (axis2_svc_t *)service, env));
				tmp2 = ret;
				ret = axutil_stracat (env, tmp2, "</p>");
				tmp2 = ret;
            ops = axis2_svc_get_all_ops(((axis2_svc_t *)service), env);
            if (ops && 0 != axutil_hash_count(ops))
            {
                axutil_hash_index_t *hi2 = NULL;
                void *op = NULL;
                axis2_char_t *oname = NULL;

                ret = axutil_stracat(env, tmp2, "<i>Available Operations</i> <ul>");
                AXIS2_FREE(env->allocator, tmp2);
                tmp2 = ret;
                for (hi2 = axutil_hash_first(ops, env);  hi2;
                        hi2 = axutil_hash_next(env, hi2))
                {
                    axutil_hash_this(hi2, NULL, NULL, &op);
                    oname = axutil_qname_get_localpart(axis2_op_get_qname(
                                ((axis2_op_t *)op), env), env);
                    ret = axutil_stracat(env, tmp2, "<li>");
                    AXIS2_FREE(env->allocator, tmp2);
                    tmp2 = ret;

                    ret = axutil_stracat(env, tmp2, oname);
                    AXIS2_FREE(env->allocator, tmp2);
                    tmp2 = ret;
                    ret = axutil_stracat(env, tmp2, "</li>");
                    AXIS2_FREE(env->allocator, tmp2);
                    tmp2 = ret;
                }
                ret = axutil_stracat(env, tmp2, "</ul>");
                AXIS2_FREE(env->allocator, tmp2);
                tmp2 = ret;
            }
            else
            {
                ret = axutil_stracat(env, tmp2, "No operations Available");
                /*AXIS2_FREE(env->allocator, tmp);*/
                tmp2 = ret;
            }
        }
    }
    if (errorneous_svc_map && 0 != axutil_hash_count(errorneous_svc_map))
    {
        void *fsname = NULL;
        svcs_exists = AXIS2_TRUE;
        ret = axutil_stracat(env, tmp2, "<hr><h2><font color=\"red\">Faulty \
                Services</font></h2>");
        AXIS2_FREE(env->allocator, tmp2);
        tmp2 = ret;

        for (hi = axutil_hash_first(errorneous_svc_map, env);  hi;
                axutil_hash_next(env, hi))
        {
            axutil_hash_this(hi, (const void **)&fsname, NULL, NULL);
            ret = axutil_stracat(env, tmp2, "<h3><font color=\"red\">");
            AXIS2_FREE(env->allocator, tmp2);
            tmp2 = ret;
            ret = axutil_stracat(env, tmp2, (axis2_char_t *)fsname);
            AXIS2_FREE(env->allocator, tmp2);
            tmp2 = ret;
            ret = axutil_stracat(env, tmp2, "</font></h3>");
            AXIS2_FREE(env->allocator, tmp2);
            tmp2 = ret;
        }
    }
    if (AXIS2_FALSE == svcs_exists)
    {
        ret = axutil_strdup(env, "<h2>There are no services deployed</h2>");
    }
    ret = axutil_stracat(env, "<html><head><title>Axis2C :: Services</title></head>"
            "<body><font face=\"courier\">"
            , tmp2);
    /*AXIS2_FREE(env->allocator, tmp2);*/
    tmp2 = ret;
    ret = axutil_stracat(env, tmp2, "</font></body></html>\r\n");
    /*AXIS2_FREE(env->allocator, tmp);*/

    return ret;
}


AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axis2_http_transport_utils_get_services_static_wsdl(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_char_t *request_url)
{
    axis2_char_t *wsdl_string = NULL;
    axis2_char_t *wsdl_path = NULL;
    axis2_char_t **url_tok = NULL;
    unsigned int len = 0;
    axis2_char_t *svc_name = NULL;
    axis2_conf_t *conf = NULL;
    axutil_hash_t *services_map = NULL;
    axutil_hash_index_t *hi = NULL;

    AXIS2_PARAM_CHECK(env->error, conf_ctx, NULL);
    AXIS2_PARAM_CHECK(env->error, request_url, NULL);

    url_tok = axutil_parse_request_url_for_svc_and_op (env, request_url);
    len = strlen (url_tok[0]);
    url_tok[0][len - 5]  = 0;
    svc_name = url_tok[0];

    conf = axis2_conf_ctx_get_conf (conf_ctx, env);
    services_map =  axis2_conf_get_all_svcs(conf, env);

    if (services_map && 0 != axutil_hash_count(services_map))
    {
        void *service = NULL;
        axis2_char_t *sname = NULL;
        
        for (hi = axutil_hash_first(services_map, env);
                hi; hi = axutil_hash_next(env, hi))
        {
            axutil_hash_this(hi, NULL, NULL, &service);
            sname = axutil_qname_get_localpart(axis2_svc_get_qname(
                        ((axis2_svc_t *)service), env), env);
            if (!axutil_strcmp (svc_name, sname))
            {
                wsdl_path = (axis2_char_t *)axis2_svc_get_svc_wsdl_path ((axis2_svc_t *)service, env);
                break;
            }

        }
    }

    if (wsdl_path)
    {
        FILE *wsdl_file;
        axis2_char_t *content = NULL;
        int c;
        int size = FILE_READ_SIZE;
        axis2_char_t *tmp;
        int i = 0;
        
        content = (axis2_char_t *)AXIS2_MALLOC (env->allocator, size);
        wsdl_file = fopen (wsdl_path, "r");
        if (wsdl_file)
        {
            c = fgetc (wsdl_file);
            while (c != EOF)
            {
                if (i > size)
                {
                    size *= size * 3;
                    tmp = (axis2_char_t *)AXIS2_MALLOC (env->allocator, size);
                    memcpy (tmp, content, i);
                    AXIS2_FREE (env->allocator, content);
                    content = tmp;
                }
                sprintf (&content[i++], "%c", c);
                c = fgetc (wsdl_file);
            }
            wsdl_string = content;
        }
    }
    else 
    {
        wsdl_string = "Unable to retreive wsdl for this service";
    }

    return wsdl_string;
}

AXIS2_EXTERN axutil_string_t *AXIS2_CALL
axis2_http_transport_utils_get_charset_enc(
    const axutil_env_t *env,
    const axis2_char_t *content_type)
{
    axis2_char_t *tmp = NULL;
    axis2_char_t *tmp_content_type = NULL;
    axis2_char_t *tmp2 = NULL;
    axutil_string_t *str = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, content_type, NULL);

    tmp_content_type = (axis2_char_t *)content_type;
    if (!tmp_content_type)
    {
        return axutil_string_create_const(env, (axis2_char_t**)&AXIS2_TRANS_UTIL_DEFAULT_CHAR_ENCODING);
    }

    tmp = strstr(tmp_content_type, AXIS2_HTTP_CHAR_SET_ENCODING);

    if (tmp)
    {
        tmp = strchr(tmp, '=');
		if (tmp)
		{
			tmp2 = strchr(tmp, ';');
		}

        if (tmp2)
        {
            if ('\'' == *(tmp2 - sizeof(axis2_char_t)) ||
                    '\"' == *(tmp2 - sizeof(axis2_char_t)))
            {
                tmp2 -= sizeof(axis2_char_t);
            }
            *tmp2 = '\0';
        }
    }
    
    if (tmp)
    {
        /* Following formats are acceptable
         * charset="UTF-8"
         * charser='UTF-8'
         * charset=UTF-8
         * But for our requirements charset we get should be UTF-8
         */
        if ('\'' == *(tmp + sizeof(axis2_char_t)) || '\"' == *(tmp +
                sizeof(axis2_char_t)))
        {
            tmp += 2 * sizeof(axis2_char_t);
        }
        else
        {
            tmp += sizeof(axis2_char_t);
        }
    }

    
    if (tmp)
    {
        str = axutil_string_create(env, tmp);
    }
    else
    {
        str = axutil_string_create_const(env, (axis2_char_t**)&AXIS2_TRANS_UTIL_DEFAULT_CHAR_ENCODING);
    }
    return str;
}

int AXIS2_CALL
axis2_http_transport_utils_on_data_request(
    char *buffer,
    int size,
    void *ctx)
{
    const axutil_env_t *env = NULL;
    int len = -1;
    axis2_callback_info_t *cb_ctx = (axis2_callback_info_t *)ctx;

    if (! buffer || ! ctx)
    {
        return 0;
    }
    env = ((axis2_callback_info_t *)ctx)->env;
    if (cb_ctx->unread_len <= 0 && -1 != cb_ctx->content_length)
    {
        return 0;
    }
    if (cb_ctx->chunked_stream)
    {
        len = axis2_http_chunked_stream_read(cb_ctx->chunked_stream, env,
                buffer, size);
        buffer[len] = '\0';
        return len;
    }
    else
    {
        axutil_stream_t *in_stream = NULL;
        int read_len = size;
        in_stream = (axutil_stream_t *)((axis2_callback_info_t *)ctx)->in_stream;
        len = axutil_stream_read(in_stream, env, buffer, read_len);
        if (len > 0)
        {
            buffer[len] = '\0';
            ((axis2_callback_info_t *)ctx)->unread_len -= len;
        }
        return len;
    }
    return 0;
}

AXIS2_EXTERN axiom_soap_envelope_t *AXIS2_CALL
axis2_http_transport_utils_create_soap_msg(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    const axis2_char_t *soap_ns_uri)
{
    axis2_op_ctx_t *op_ctx = NULL;
    const axis2_char_t *char_set_enc = NULL;
    axis2_char_t *content_type = NULL;
    axutil_stream_t *in_stream = NULL;
    axis2_callback_info_t *callback_ctx = NULL;
    axis2_char_t *trans_enc = NULL;
    int *content_length = NULL;
    axutil_property_t *property = NULL;
    axutil_hash_t *binary_data_map = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, NULL);
    AXIS2_PARAM_CHECK(env->error, soap_ns_uri, NULL);


    property =  axis2_msg_ctx_get_property(msg_ctx, env,
            AXIS2_TRANSPORT_IN);
    if (property)
    {
        in_stream = axutil_property_get_value(property, env);
        property = NULL;
    }
    callback_ctx = AXIS2_MALLOC(env->allocator, sizeof(axis2_callback_info_t));
    /* Note: the memory created above is freed in xml reader free function
       as this is passed on to the reader */
    if (! callback_ctx)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    callback_ctx->in_stream = in_stream;
    callback_ctx->env = env;
    callback_ctx->content_length = -1;
    callback_ctx->unread_len = -1;
    callback_ctx->chunked_stream = NULL;

    property =  axis2_msg_ctx_get_property(msg_ctx, env,
            AXIS2_HTTP_HEADER_CONTENT_LENGTH);
    if (property)
    {
        content_length = axutil_property_get_value(property, env);
        property = NULL;
    }
    if (content_length)
    {
        callback_ctx->content_length = *content_length;
        callback_ctx->unread_len = *content_length;
    }
    if (! in_stream)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NULL_IN_STREAM_IN_MSG_CTX,
                AXIS2_FAILURE);
        AXIS2_FREE(env->allocator, callback_ctx);
        return NULL;
    }

    trans_enc = axis2_msg_ctx_get_transfer_encoding(msg_ctx, env);
    
    if (trans_enc && 0 == axutil_strcmp(trans_enc,
            AXIS2_HTTP_HEADER_TRANSFER_ENCODING_CHUNKED))
    {
        callback_ctx->chunked_stream = axis2_http_chunked_stream_create(env,
                in_stream);
        if (! callback_ctx->chunked_stream)
        {
            return NULL;
        }
    }


    op_ctx =  axis2_msg_ctx_get_op_ctx(msg_ctx, env);
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
            property =  axis2_ctx_get_property(ctx, env,
                    MTOM_RECIVED_CONTENT_TYPE);
            if (property)
            {
                content_type = axutil_property_get_value(property, env);
                property = NULL;
            }

        }
    }
    if (! char_set_enc)
    {
        char_set_enc = AXIS2_DEFAULT_CHAR_SET_ENCODING;
    }
    if (content_type)
    {
        axis2_char_t *mime_boundary = NULL;
         axis2_msg_ctx_set_doing_mtom(msg_ctx, env, AXIS2_TRUE);
        /* get mime boundry */
        mime_boundary = axis2_http_transport_utils_get_value_from_content_type(
                env, content_type, 
                AXIS2_HTTP_HEADER_CONTENT_TYPE_MIME_BOUNDARY);

        if (mime_boundary)
        {
            axiom_mime_parser_t *mime_parser = NULL;
            axutil_stream_t *stream = NULL;
            int soap_body_len = 0;
            axis2_char_t *soap_body_str = NULL;

            mime_parser = axiom_mime_parser_create(env);
            if (mime_parser)
            {
                binary_data_map = axiom_mime_parser_parse(mime_parser, env,
                        axis2_http_transport_utils_on_data_request,
                        (void *)callback_ctx, mime_boundary);

                soap_body_len = axiom_mime_parser_get_soap_body_len(
                            mime_parser, env);
                soap_body_str = axiom_mime_parser_get_soap_body_str(
                            mime_parser, env);
            }

            stream = axutil_stream_create_basic(env);
            if (stream)
            {
                axutil_stream_write(stream, env, soap_body_str, soap_body_len);
                callback_ctx->in_stream = stream;
                callback_ctx->chunked_stream = NULL;
                callback_ctx->content_length = soap_body_len;
                callback_ctx->unread_len = soap_body_len;
            }

            axiom_mime_parser_free(mime_parser, env);
            mime_parser = NULL;
        }
    }

    if (AXIS2_TRUE !=  axis2_msg_ctx_get_doing_rest(msg_ctx, env))
    {
        axiom_xml_reader_t *xml_reader = NULL;
        axiom_stax_builder_t *om_builder = NULL;
        axiom_soap_builder_t *soap_builder = NULL;
        axiom_soap_envelope_t *soap_envelope = NULL;

        xml_reader = axiom_xml_reader_create_for_io(env,
                axis2_http_transport_utils_on_data_request, NULL,
                (void *)callback_ctx, char_set_enc);
        if (! xml_reader)
        {
            return NULL;
        }
        om_builder = axiom_stax_builder_create(env, xml_reader);
        if (! om_builder)
        {
            axiom_xml_reader_free(xml_reader, env);
            xml_reader = NULL;
            return NULL;
        }
        soap_builder = axiom_soap_builder_create(env, om_builder,
                soap_ns_uri);
        if (! soap_builder)
        {
            /* We should not be freeing om_builder here as it is done by
               axiom_soap_builder_create in case of error - Samisa*/
            /*axiom_stax_builder_free(om_builder, env);*/
            om_builder = NULL;
            xml_reader = NULL;
            return NULL;
        }

        soap_envelope = axiom_soap_builder_get_soap_envelope(soap_builder, env);

        if (binary_data_map)
        {
            axiom_soap_builder_set_mime_body_parts(soap_builder, env,
                    binary_data_map);
        }

        if (soap_envelope && content_type)
        {
            /* hack to get around MTOM problem */
            axiom_soap_body_t *soap_body =
                axiom_soap_envelope_get_body(soap_envelope, env);

            if (soap_body)
            {
                axiom_soap_body_has_fault(soap_body, env);
            }
        }

        return soap_envelope;
    }
    else
    {
        axiom_xml_reader_t *xml_reader = NULL;
        axiom_stax_builder_t *om_builder = NULL;
        axiom_soap_envelope_t *soap_envelope = NULL;
        axiom_soap_body_t *def_body = NULL;
        axiom_document_t *om_doc = NULL;
        axiom_node_t *root_node = NULL;

        xml_reader = axiom_xml_reader_create_for_io(env,
                axis2_http_transport_utils_on_data_request, NULL,
                (void *)callback_ctx, char_set_enc);
        if (! xml_reader)
        {
            return NULL;
        }
        om_builder = axiom_stax_builder_create(env, xml_reader);
        if (! om_builder)
        {
            axiom_xml_reader_free(xml_reader, env);
            xml_reader = NULL;
            return NULL;
        }
        soap_envelope = axiom_soap_envelope_create_default_soap_envelope
                (env, AXIOM_SOAP11);
        def_body = axiom_soap_envelope_get_body(soap_envelope, env);
        om_doc = axiom_stax_builder_get_document(om_builder, env);
        root_node = axiom_document_build_all(om_doc, env);
        axiom_soap_body_add_child(def_body, env, root_node);

        return soap_envelope;
    }
    return NULL;
}


AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axis2_http_transport_utils_get_value_from_content_type(
    const axutil_env_t *env,
    const axis2_char_t *content_type,
    const axis2_char_t *key)
{
    axis2_char_t *tmp = NULL;
    axis2_char_t *tmp_content_type = NULL;
    axis2_char_t *tmp2 = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, content_type, NULL);
    AXIS2_PARAM_CHECK(env->error, key, NULL);

    tmp_content_type = axutil_strdup(env, content_type);
    if (! tmp_content_type)
    {
        return NULL;
    }
    tmp = strstr(tmp_content_type, key);
    if (! tmp)
    {
        AXIS2_FREE(env->allocator, tmp_content_type);
        return NULL;
    }

    tmp = strchr(tmp, '=');
    tmp2 = strchr(tmp, ';');

    if (tmp2)
    {
        *tmp2 = '\0';
    }
    if (! tmp)
    {
        AXIS2_FREE(env->allocator, tmp_content_type);
        return NULL;
    }
    tmp2 =  axutil_strdup(env, tmp + 1);
    
    AXIS2_FREE(env->allocator, tmp_content_type);
    if (*tmp2 == '"')
    {
        tmp = tmp2;
        tmp2 =  axutil_strdup(env, tmp + 1);
        tmp2[strlen(tmp2) - 1] = '\0';
    }
    return tmp2;
}

/*AXIS2_EXTERN axiom_soap_envelope_t *AXIS2_CALL
axis2_http_transport_utils_handle_media_type_url_encoded(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axutil_hash_t *param_map,
    axis2_char_t *method,
    xml_schema_element_t *schema_element)
{
    axiom_soap_envelope_t *soap_env = NULL;
    axiom_soap_body_t *soap_body = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, NULL);
    AXIS2_PARAM_CHECK(env->error, method, NULL);


    soap_env = axiom_soap_envelope_create_default_soap_envelope(env,
            AXIOM_SOAP11);
    soap_body = axiom_soap_envelope_get_body(soap_env, env);
    if (! soap_body)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_SOAP_ENVELOPE_OR_SOAP_BODY_NULL,
                AXIS2_FAILURE);
        return NULL;
    }
    if (! schema_element)
    {
        axiom_element_t *body_child = NULL;
        axiom_node_t *body_child_node = NULL;

        body_child = axiom_element_create_with_qname(env, NULL,
                axis2_op_get_qname( axis2_msg_ctx_get_op(msg_ctx, env),
                        env), &body_child_node);
        axiom_soap_body_add_child(soap_body, env, body_child_node);
        if (param_map)
        {
            axutil_hash_index_t *hi = NULL;
            for (hi = axutil_hash_first(param_map, env); hi ;
                    hi = axutil_hash_next(env, hi))
            {
                void *name = NULL;
                void *value = NULL;
                axiom_node_t *node = NULL;
                axiom_element_t *element = NULL;

                axutil_hash_this(hi, (const void **)&name, NULL, (void **)&value);
                element = axiom_element_create(env, NULL, (axis2_char_t *)name,
                        NULL, &node);
                axiom_element_set_text(element, env, (axis2_char_t *)value, node);
                axiom_node_add_child(body_child_node, env, node);
            }
        }
    }
    else
    {
        axis2_char_t *target_ns = NULL;
        axutil_qname_t *bfc_qname = NULL;
        axiom_element_t *body_child = NULL;
        axiom_node_t *body_child_node = NULL;

        target_ns = axutil_qname_get_uri(XML_SCHEMA_ELEMENT_GET_QNAME(
                    schema_element, env), env);
        bfc_qname = axutil_qname_create(env, XML_SCHEMA_ELEMENT_GET_NAME(
                    schema_element, env), target_ns, NULL);

        body_child = axiom_element_create_with_qname(env, NULL, bfc_qname,
                &body_child_node);
        axiom_soap_body_add_child(soap_body, env, body_child_node);
        if (0 == axutil_strcmp(method, AXIS2_HTTP_GET) ||
                0 == axutil_strcmp(method, AXIS2_HTTP_POST))
        {
            xml_schema_type_t *schema_type = NULL;
            schema_type = XML_SCHEMA_ELEMENT_GET_SCHEMA_TYPE(schema_element,
                    env);
            if (XML_SCHEMA_COMPLEX_TYPE == XML_SCHEMA_TYPE_GET_TYPE(schema_type,
                    env))
            {
                xml_schema_particle_t *schema_particle = NULL;
                schema_particle = XML_SCHEMA_COMPLEX_TYPE_GET_PARTICLE(
                            schema_type, env);
                if (XML_SCHEMA_SEQUENCE ==
                        XML_SCHEMA_PARTICLE_GET_TYPE(schema_particle, env))
                {
                    xml_schema_group_base_t *sequence = NULL;
                    xml_schema_obj_collection_t *seq_items = NULL;
                    int count = 0;
                    int i = 0;

                    sequence = (xml_schema_group_base_t *)schema_particle;
                    seq_items = XML_SCHEMA_GROUP_BASE_GET_ITEMS(sequence, env);
                    count = XML_SCHEMA_OBJ_COLLECTION_GET_COUNT(seq_items, env);
                    for (i = 0; i < count; i++)
                    {
                        xml_schema_element_t *inner_element = NULL;
                        axis2_char_t *element_name = NULL;
                        axis2_char_t *param_val = NULL;
                        axiom_element_t *om_element = NULL;
                        axiom_node_t *om_node = NULL;

                        inner_element = (xml_schema_element_t *)
                                XML_SCHEMA_OBJ_COLLECTION_GET_ITEM(seq_items, env,
                                        i);
                        element_name = XML_SCHEMA_ELEMENT_GET_NAME(inner_element,
                                env);
                        param_val = axutil_hash_get(param_map, element_name,
                                AXIS2_HASH_KEY_STRING);
                        if (! param_val)
                        {
                            AXIS2_ERROR_SET(env->error,
                                    AXIS2_ERROR_REQD_PARAM_MISSING, AXIS2_FAILURE);
                            return NULL;
                        }
                        om_element = axiom_element_create(env, body_child_node,
                                element_name, NULL, &om_node);
                        axiom_element_set_text(om_element, env, param_val,
                                om_node);
                    }
                }
            }
            else
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_UNSUPPORTED_SCHEMA_TYPE,
                        AXIS2_FAILURE);
                return NULL;
            }
        }
    }
    return soap_env;
}*/

AXIS2_EXTERN axiom_soap_envelope_t *AXIS2_CALL
axis2_http_transport_utils_handle_media_type_url_encoded(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axutil_hash_t *param_map,
    axis2_char_t *method)
{
    axiom_soap_envelope_t *soap_env = NULL;
    axiom_soap_body_t *soap_body = NULL;
    axiom_element_t *body_child = NULL;
    axiom_node_t *body_child_node = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, NULL);
    AXIS2_PARAM_CHECK(env->error, method, NULL);


    soap_env = axiom_soap_envelope_create_default_soap_envelope(env,
            AXIOM_SOAP11);
    soap_body = axiom_soap_envelope_get_body(soap_env, env);
    if (! soap_body)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_SOAP_ENVELOPE_OR_SOAP_BODY_NULL,
                AXIS2_FAILURE);
        return NULL;
    }

    body_child = axiom_element_create_with_qname(env, NULL,
            axis2_op_get_qname( axis2_msg_ctx_get_op(msg_ctx, env),
                    env), &body_child_node);
    axiom_soap_body_add_child(soap_body, env, body_child_node);
    if (param_map)
    {
        axutil_hash_index_t *hi = NULL;
        for (hi = axutil_hash_first(param_map, env); hi ;
                hi = axutil_hash_next(env, hi))
        {
            void *name = NULL;
            void *value = NULL;
            axiom_node_t *node = NULL;
            axiom_element_t *element = NULL;

            axutil_hash_this(hi, (const void **)&name, NULL, (void **)&value);
            element = axiom_element_create(env, NULL, (axis2_char_t *)name,
                    NULL, &node);
            axiom_element_set_text(element, env, (axis2_char_t *)value, node);
            axiom_node_add_child(body_child_node, env, node);
        }
    }
    return soap_env;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_http_transport_utils_dispatch_and_verify(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    axis2_disp_t *req_uri_disp = NULL;
    axis2_handler_t *handler = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);

    req_uri_disp = axis2_req_uri_disp_create(env);
    handler = axis2_disp_get_base(req_uri_disp, env);
    axis2_handler_invoke(handler, env, msg_ctx);

    if (!  axis2_msg_ctx_get_svc(msg_ctx, env) || !
             axis2_msg_ctx_get_op(msg_ctx, env))
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_SVC_OR_OP_NOT_FOUND,
                AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}
