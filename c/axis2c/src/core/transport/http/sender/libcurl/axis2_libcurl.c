#include "axis2_libcurl.h"
#include <axiom_soap.h>
#include <axutil_string.h>
#include <axis2_http_transport.h>
#include <axiom_output.h>
#include <axis2_op_ctx.h>
#include <axis2_ctx.h>
#include <axis2_conf_ctx.h>
#include <axis2_http_client.h>
#include <axiom_xml_writer.h>
#include <axutil_property.h>
#include <axutil_param.h>
#include <axutil_types.h>
#include <axutil_generic_obj.h>
#include <axis2_const.h>
#include <axis2_util.h>
#include <stdlib.h>
#include <axis2_http_sender.h>
#include <axis2_http_transport.h>
#include "libcurl_stream.h"

static int ref = 0;
static CURL *handler;

typedef struct axis2_libcurl
{
	axis2_char_t *memory;
	axutil_array_list_t *alist;
	unsigned int size;
	const axutil_env_t *env;
}axis2_libcurl_t;

size_t 
axis2_libcurl_write_memory_callback(
	void *ptr, 
	size_t size, 
	size_t nmemb, 
	void *data);

size_t
axis2_libcurl_header_callback(
	void *ptr, 
	size_t size, 
	size_t nmemb, 
	void *data);

axis2_libcurl_t *
axis2_libcurl_create (
	const axutil_env_t *env);

void
axis2_libcurl_free (
	void *curl,
	const axutil_env_t *env);



axis2_status_t AXIS2_CALL
axis2_libcurl_send (
    axiom_output_t *om_output,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
	axiom_soap_envelope_t *out,
    const axis2_char_t *str_url,
    const axis2_char_t *soap_action)
{
	struct curl_slist *headers = NULL;
	axiom_soap_body_t *soap_body;
	axis2_bool_t is_soap = AXIS2_TRUE;
	axis2_bool_t send_via_get = AXIS2_FALSE;
	axis2_bool_t doing_mtom = AXIS2_FALSE;
	axiom_node_t *body_node = NULL;
	axiom_node_t *data_out = NULL;
	axutil_property_t *method = NULL;
	axis2_char_t *method_value = NULL;
	axiom_xml_writer_t *xml_writer = NULL;
	axis2_char_t *buffer = NULL;
	unsigned int buffer_size = 0;
	axis2_char_t *content_type;
	axis2_char_t *content_len = AXIS2_HTTP_HEADER_CONTENT_LENGTH_;
	const axis2_char_t *char_set_enc = NULL;
	axis2_char_t *content = AXIS2_HTTP_HEADER_CONTENT_TYPE_;
	axis2_char_t *soap_action_header = AXIS2_HTTP_HEADER_SOAP_ACTION_;
	axis2_libcurl_t *data;
	axutil_stream_t *in_stream;
	axutil_property_t *trans_in_property;
	axutil_string_t *char_set_enc_str;
    axis2_byte_t *output_stream = NULL;
    int output_stream_size = 0;

	data = axis2_libcurl_create (env);
    if (!ref)
    {
        handler = curl_easy_init ();
        ref ++;
    }
    else
    {
        curl_easy_reset (handler);
    }
	headers = curl_slist_append (headers, AXIS2_HTTP_HEADER_USER_AGENT_AXIS2C);
	headers = curl_slist_append (headers,  AXIS2_HTTP_HEADER_ACCEPT_);
	headers = curl_slist_append (headers, AXIS2_HTTP_HEADER_EXPECT_);

    if (AXIS2_TRUE ==  axis2_msg_ctx_get_doing_rest(msg_ctx, env))
		is_soap = AXIS2_FALSE;
	else
		is_soap = AXIS2_TRUE;

	if (!is_soap)
	{
		soap_body = axiom_soap_envelope_get_body(out, env);
        if (!soap_body)
        {
            AXIS2_ERROR_SET(env->error,
							AXIS2_ERROR_SOAP_ENVELOPE_OR_SOAP_BODY_NULL,
							AXIS2_FAILURE);
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "%s",
							AXIS2_ERROR_GET_MESSAGE(env->error));
            return AXIS2_FAILURE;
        }
        body_node = axiom_soap_body_get_base_node(soap_body, env);
        if (!body_node)
        {
            return AXIS2_FAILURE;
        }
        data_out = axiom_node_get_first_element(body_node, env);

		method = (axutil_property_t *) axis2_msg_ctx_get_property(msg_ctx, env,
            AXIS2_HTTP_METHOD);

		if (method)
        {
			method_value = (axis2_char_t *) axutil_property_get_value (method, env);
        }
		/* The default is POST */
		if (method_value && 0 == axutil_strcmp(method_value, AXIS2_HTTP_GET))
		{
			send_via_get = AXIS2_TRUE;
		}
	}

	if (!send_via_get)
	{
		xml_writer = axiom_output_get_xml_writer(om_output, env);

		char_set_enc_str = axis2_msg_ctx_get_charset_encoding(msg_ctx, env);

		if (!char_set_enc_str)
		{
			char_set_enc = AXIS2_DEFAULT_CHAR_SET_ENCODING;
		}
		else
		{
			char_set_enc = axutil_string_get_buffer(char_set_enc_str, env);
		}

		if (is_soap)
		{
			doing_mtom =  axis2_msg_ctx_get_doing_mtom(msg_ctx, env);

			axiom_output_set_do_optimize(om_output, env,
										 doing_mtom); 
			axiom_soap_envelope_serialize(out, env, om_output,
										  AXIS2_FALSE);
			if (AXIS2_TRUE ==  axis2_msg_ctx_get_is_soap_11(msg_ctx, env))
			{
				if ('\"' != *soap_action)
				{
					axis2_char_t *tmp_soap_action = NULL;
					tmp_soap_action = AXIS2_MALLOC(env->allocator, (
													   axutil_strlen(soap_action) + 5) * sizeof(axis2_char_t));
					sprintf(tmp_soap_action, "\"%s\"", soap_action);
					headers = curl_slist_append (headers, 
												 axutil_stracat (env, soap_action_header, tmp_soap_action));
					AXIS2_FREE(env->allocator, tmp_soap_action);
				}
				else
				{
					headers = curl_slist_append (headers, 
												 axutil_stracat (env, soap_action_header, soap_action));
				}
			}

			if (doing_mtom)
			{
				axiom_output_flush(om_output, env, &output_stream,
								   &output_stream_size);
				content_type = (axis2_char_t *)axiom_output_get_content_type(om_output,
																			 env);
				if (AXIS2_TRUE !=  axis2_msg_ctx_get_is_soap_11(msg_ctx, env))
				{
					/* handle SOAP action for SOAP 1.2 case */
					if (axutil_strcmp(soap_action, ""))
					{
						axis2_char_t *temp_content_type = NULL;
						temp_content_type = axutil_stracat(env, content_type, ";action=");
						AXIS2_FREE(env->allocator, content_type);
						content_type = temp_content_type;
						temp_content_type = axutil_stracat(env, content_type, soap_action);
						AXIS2_FREE(env->allocator, content_type);
						content_type = temp_content_type;
					}
				}
			}
			else if (AXIS2_TRUE ==  axis2_msg_ctx_get_is_soap_11(msg_ctx, env))
			{
				axis2_char_t *temp_content_type = NULL;
				content_type = (axis2_char_t *)AXIS2_HTTP_HEADER_ACCEPT_TEXT_XML;
				content_type = axutil_stracat(env, content_type, ";charset=");
				temp_content_type = axutil_stracat(env, content_type, char_set_enc);
				AXIS2_FREE(env->allocator, content_type);
				content_type = temp_content_type;
			}
			else
			{
				axis2_char_t *temp_content_type = NULL;
				content_type = (axis2_char_t *)AXIS2_HTTP_HEADER_ACCEPT_APPL_SOAP;
				content_type = axutil_stracat(env, content_type, ";charset=");
				temp_content_type = axutil_stracat(env, content_type, char_set_enc);
				AXIS2_FREE(env->allocator, content_type);
				content_type = temp_content_type;
				if (axutil_strcmp(soap_action, ""))
				{
					temp_content_type = axutil_stracat(env, content_type, ";action=");
					AXIS2_FREE(env->allocator, content_type);
					content_type = temp_content_type;
					temp_content_type = axutil_stracat(env, content_type, soap_action);
					AXIS2_FREE(env->allocator, content_type);
					content_type = temp_content_type;
				}
				temp_content_type = axutil_stracat(env, content_type, ";");
				AXIS2_FREE(env->allocator, content_type);
				content_type = temp_content_type;
			}
		}
		else
		{
			axutil_property_t *content_type_property = NULL;
			axutil_hash_t *content_type_hash = NULL;
			axis2_char_t *content_type_value = NULL;

			axiom_node_serialize(data_out, env, om_output);
			content_type_property  = (axutil_property_t *) axis2_msg_ctx_get_property(
				msg_ctx, env,
				AXIS2_USER_DEFINED_HTTP_HEADER_CONTENT_TYPE);
		
			if (content_type_property)
			{
				content_type_hash = (axutil_hash_t *) axutil_property_get_value (content_type_property, env);
				if (content_type_hash)
					content_type_value = (char *) axutil_hash_get (content_type_hash, 
																  AXIS2_HTTP_HEADER_CONTENT_TYPE, 
																  AXIS2_HASH_KEY_STRING);
			}
			if (content_type_value)
				content_type = content_type_value;
			else
				content_type = AXIS2_HTTP_HEADER_ACCEPT_TEXT_XML;

		}

		buffer = axiom_xml_writer_get_xml(xml_writer, env);
		if (!doing_mtom)
		{
			buffer_size = axiom_xml_writer_get_xml_size(xml_writer, env);
		}
		else
			buffer_size = output_stream_size;
		{
			char tmp_buf[10];
			sprintf (tmp_buf, "%d", buffer_size);
			headers = curl_slist_append (headers, axutil_stracat (env, content_len, tmp_buf));
			headers = curl_slist_append (headers, axutil_stracat (env, content,content_type));
		}
		if (!doing_mtom)
		{
			curl_easy_setopt (handler, CURLOPT_POSTFIELDSIZE, buffer_size);
			curl_easy_setopt (handler, CURLOPT_POSTFIELDS, buffer);
		}
		else 
		{
			curl_easy_setopt (handler, CURLOPT_POSTFIELDSIZE, output_stream_size);
			curl_easy_setopt (handler, CURLOPT_POSTFIELDS, output_stream);
		}
		curl_easy_setopt (handler, CURLOPT_URL, str_url);
	}
	else
	{
		axis2_char_t *request_param;
		axis2_char_t *url_encode;
		request_param = (axis2_char_t *) axis2_http_sender_get_param_string( NULL, env, msg_ctx);
		url_encode = axutil_strcat(env, str_url, "?",
								  request_param, NULL);
		curl_easy_setopt (handler, CURLOPT_HTTPGET, 1);
		curl_easy_setopt (handler, CURLOPT_URL, url_encode);
	}

/* 	curl_easy_setopt (handler, CURLOPT_VERBOSE, 1); */
	curl_easy_setopt (handler, CURLOPT_HTTPHEADER, headers);
	curl_easy_setopt (handler, CURLOPT_WRITEFUNCTION, axis2_libcurl_write_memory_callback);
	curl_easy_setopt (handler, CURLOPT_WRITEDATA, data);
/* 	curl_easy_setopt (handler, CURLOPT_HEADERFUNCTION, axis2_libcurl_header_callback); */
/* 	curl_easy_setopt (handler, CURLOPT_WRITEHEADER, header); */
	curl_easy_perform (handler);
/* 	curl_slist_free_all (headers); */
/* 	curl_easy_cleanup (handler); */

	in_stream = axutil_stream_create_libcurl (env, data->memory, data->size);
    trans_in_property = axutil_property_create(env);
    axutil_property_set_scope(trans_in_property, env, AXIS2_SCOPE_REQUEST);
    axutil_property_set_free_func(trans_in_property, env, axutil_stream_free_void_arg);
    axutil_property_set_value(trans_in_property, env, in_stream);
    axis2_msg_ctx_set_property(msg_ctx, env, AXIS2_TRANSPORT_IN, trans_in_property);
	return AXIS2_SUCCESS;
}

size_t
axis2_libcurl_write_memory_callback(void *ptr, size_t size, size_t nmemb, void *data)
{
	size_t realsize = size * nmemb;
	axis2_libcurl_t *mem = (axis2_libcurl_t *)data;
	axis2_char_t *buffer = (axis2_char_t *) AXIS2_MALLOC (mem->env->allocator, mem->size + realsize + 1);
	if (buffer) 
	{
		if (mem->size)
			memcpy (&(buffer[0]), mem->memory, mem->size);

			memcpy(&(buffer[mem->size]), ptr, realsize);
			mem->size += realsize;
			buffer[mem->size] = 0;
			mem->memory = buffer;
	}
	return realsize;
}

size_t
axis2_libcurl_header_callback(void *ptr, size_t size, size_t nmemb, void *data)
{
	size_t realsize = size * nmemb;
	axis2_libcurl_t *mem = (axis2_libcurl_t *)data;
	mem->memory = AXIS2_MALLOC (mem->env->allocator, realsize + 1);
	mem->size = 0;
	if (mem->memory) 
	{
		memcpy(&(mem->memory[mem->size]), ptr, realsize);
		mem->size += realsize;
		mem->memory[mem->size] = 0;
		axutil_array_list_add (mem->alist, mem->env, axutil_strdup (mem->env, mem->memory));
	}
	return realsize;
}

axis2_libcurl_t *
axis2_libcurl_create (const axutil_env_t *env)
{
	axis2_libcurl_t *curl = NULL;
	curl = (axis2_libcurl_t *) AXIS2_MALLOC (env->allocator, sizeof (axis2_libcurl_t));
	curl->size = 0;
	curl->alist = axutil_array_list_create (env, 7);
	curl->env = env;
	return curl;
}

void
axis2_libcurl_free (void *curl, const axutil_env_t *env)
{
	AXIS2_FREE (env->allocator, curl);
/* 	curl_slist_free_all (headers); */
/* 	curl_easy_cleanup (handler); */
}
