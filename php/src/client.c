/*
 * Copyright 2005,2006 WSO2, Inc. http://wso2.com
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

#include "php.h"
#include <axis2_addr.h>
#include "wsf.h"
#include "wsf_util.h"
#include <axis2_error_default.h>
#include <axis2_http_transport.h>
#include <axis2_log_default.h>
#include <axis2_uuid_gen.h>
#include <axiom_util.h>
#include "wsf_client.h"

#ifdef USE_SANDESHA2
#include <sandesha2_client.h>
#endif

int wsf_client_set_rm_db(axis2_env_t *env, 
						  axis2_svc_client_t *svc_client, axis2_char_t *db_location TSRMLS_DC)
{
	axis2_conf_ctx_t *conf_ctx = NULL;
	axis2_svc_ctx_t *svc_ctx = NULL;
	axis2_module_desc_t *module_desc = NULL;
	axis2_conf_t *conf = NULL;
	axis2_hash_t *modules = NULL;
	axis2_qname_t *sandesha_qname = NULL;
	axis2_param_t *rm_db_param = NULL;

	sandesha_qname = axis2_qname_create(env, "sandesha2", NULL, NULL);

	svc_ctx = AXIS2_SVC_CLIENT_GET_SVC_CTX(svc_client, env);
	conf_ctx = AXIS2_SVC_CTX_GET_CONF_CTX(svc_ctx, env);
	conf = AXIS2_CONF_CTX_GET_CONF(conf_ctx, env);
	module_desc = AXIS2_CONF_GET_MODULE(conf, env, sandesha_qname);
	if(!module_desc)
		return AXIS2_FAILURE;
	rm_db_param = AXIS2_MODULE_DESC_GET_PARAM(module_desc, env, "sandesha2_db");
	if(!rm_db_param)
		return AXIS2_FAILURE;
	axis2_param_set_value(rm_db_param, env, AXIS2_STRDUP(db_location, env));

	AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] db path set to param %s", db_location);
	axis2_qname_free(sandesha_qname, env);

	return AXIS2_SUCCESS;
}


static xmlNodePtr wsf_get_xml_node(zval *node TSRMLS_DC)
{
	php_libxml_node_object *object;
	xmlNodePtr nodep;

	object = (php_libxml_node_object *)zend_object_store_get_object(node TSRMLS_CC);
	nodep = php_libxml_import_node(node TSRMLS_CC);
    if (!nodep) {
		return NULL;
	}
	if (nodep->doc == NULL) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Imported Node must have \
							associated Document");
		return NULL;
	}
	if (nodep->type == XML_DOCUMENT_NODE || nodep->type == XML_HTML_DOCUMENT_NODE) {
		nodep = xmlDocGetRootElement((xmlDocPtr) nodep);
	}
	return nodep;
}

int wsf_client_set_headers(const axis2_env_t *env,
						 axis2_svc_client_t *svc_client, zval *msg TSRMLS_DC){
	if(!svc_client || !msg)
		return 0;
	{
		zval **tmp = NULL;
		HashTable *ht = NULL;
		ht = Z_OBJPROP_P(msg);

		AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] setting header node ");

		if(zend_hash_find(ht, WS_HEADERS, sizeof(WS_HEADERS), (void**)&tmp) == SUCCESS){
			if(Z_TYPE_PP(tmp) == IS_ARRAY){
				HashPosition pos;
				HashTable *ht = Z_ARRVAL_PP(tmp);
				zval **val = NULL;
				zend_hash_internal_pointer_reset_ex(ht, &pos);
				
				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] headers found");

				while(zend_hash_get_current_data_ex(ht, (void**)&val , &pos) != FAILURE){
					zval *header = *val;
					axiom_node_t *header_node = NULL;
					header_node = wsf_util_construct_header_node(env, header TSRMLS_CC);
					if(header_node)
					{
						AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] adding header block to svc_client");
						AXIS2_SVC_CLIENT_ADD_HEADER(svc_client, env, header_node);					
					}
					zend_hash_move_forward_ex(ht, &pos);
				}
			}
		}
	}
	return 1;
}


void wsf_client_set_security_options(zval *zval_client, zval *zval_msg, 
	axis2_env_t *env, axis2_options_t *client_options, axis2_svc_client_t *svc_client TSRMLS_DC)
{
	zval **tmp = NULL;
	zval **msg_tmp = NULL;

	int username_present = AXIS2_FALSE;
	int password_present = AXIS2_FALSE;
	int timestamp_present = AXIS2_FALSE;
	
	AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] wsf_util_set_security_options" );
	if(zval_msg){
		if(zend_hash_find(Z_OBJPROP_P(zval_msg), "user", sizeof("user"), (void **)&msg_tmp) == SUCCESS && 
				Z_TYPE_PP(msg_tmp) == IS_STRING){
				char *username = NULL;
				axis2_property_t *property = NULL;
				username = Z_STRVAL_PP(msg_tmp);                
				property = axis2_property_create(env);
				AXIS2_PROPERTY_SET_VALUE(property, env, username);
				AXIS2_OPTIONS_SET_PROPERTY(client_options, env, "user" ,property);
				username_present = AXIS2_TRUE;
		}
		if(zend_hash_find(Z_OBJPROP_P(zval_msg), "password", sizeof("password"), (void **)&msg_tmp) == SUCCESS && 
			Z_TYPE_PP(msg_tmp) == IS_STRING){
			char *password = NULL;
			axis2_property_t *property = NULL;
			
			property = axis2_property_create(env);
			
			password = Z_STRVAL_PP(msg_tmp);
			
			AXIS2_PROPERTY_SET_VALUE(property,
									 env, 
									 password);

			AXIS2_OPTIONS_SET_PROPERTY(client_options,  
										env, 
										"password", 
										property);
			
			password_present = AXIS2_TRUE;

			AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] password present :- %s", password);
		}
		if(zend_hash_find(Z_OBJPROP_P(zval_msg), "digest", sizeof("digest"), (void **)&msg_tmp) == SUCCESS && 
			Z_TYPE_PP(msg_tmp) == IS_BOOL){
			int use_digest = 0;
			char *password_type = NULL;
			axis2_property_t *property = NULL;
			use_digest = Z_BVAL_PP(msg_tmp);
			if(use_digest){
				password_type = "passwordDigest";
				property = axis2_property_create(env);

				AXIS2_PROPERTY_SET_VALUE(property, env, password_type);

				AXIS2_OPTIONS_SET_PROPERTY(client_options, env, "passwordType" ,property);

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] password type is digest");
			}
		}
		else if(password_present){
			char *password_type = NULL;
				axis2_property_t *property = NULL;
				password_type = "passwordText";
				property = axis2_property_create(env);
				AXIS2_PROPERTY_SET_VALUE(property, env, password_type);
				AXIS2_OPTIONS_SET_PROPERTY(client_options, env, "passwordType" ,property);

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] passwordType :- passwordText");
		}	
		if(zend_hash_find(Z_OBJPROP_P(zval_msg), "timeToLive", sizeof("timeToLive"), 
			(void **)&msg_tmp) == SUCCESS && Z_TYPE_PP(msg_tmp) == IS_STRING){
			char *timeto_live = NULL;
			axis2_property_t *property = NULL;
			timeto_live = Z_STRVAL_PP(msg_tmp);
			if(timeto_live){
				property = axis2_property_create(env);
				AXIS2_PROPERTY_SET_VALUE(property, env, wsf_util_get_ttl(timeto_live, env));
				AXIS2_OPTIONS_SET_PROPERTY(client_options, env, "timeToLive" ,property);
			}
			AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] timeToLive :- %s", timeto_live);

			timestamp_present = AXIS2_TRUE;
		}
		if(username_present && password_present){
			
			axis2_property_t *sec_prop = NULL;
			axis2_property_t *outflow_prop = NULL;

			sec_prop = axis2_property_create(env);
			if(timestamp_present){
				
				AXIS2_PROPERTY_SET_VALUE(sec_prop, env, "UsernameToken Timestamp");        
				
				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] seurity properties :- UsernameToken Timestamp");
			}	
			else {

				AXIS2_PROPERTY_SET_VALUE(sec_prop, env, "UsernameToken");            

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] seurity properties :- UsernameToken");

			}	

			outflow_prop = axis2_property_create_with_args(env, AXIS2_SCOPE_APPLICATION, 0,
				NULL,"TRUE");
			
			AXIS2_OPTIONS_SET_PROPERTY(client_options, env, "OutflowSecurity", outflow_prop);

			AXIS2_OPTIONS_SET_PROPERTY(client_options, env, "items", sec_prop);
			AXIS2_SVC_CLIENT_ENGAGE_MODULE(svc_client , env, "rampart");
		}		
	}else{
		username_present = AXIS2_FALSE;
		password_present = AXIS2_FALSE;
		
		if(zend_hash_find(Z_OBJPROP_P(zval_client), "user", sizeof("user"), 
			(void **)&tmp) == SUCCESS && Z_TYPE_PP(tmp) == IS_STRING){
				char *username = NULL;
				axis2_property_t *property = NULL;
				username = Z_STRVAL_PP(tmp);                
				property = axis2_property_create(env);
				AXIS2_PROPERTY_SET_VALUE(property, env, username);
				AXIS2_OPTIONS_SET_PROPERTY(client_options, env, "user" ,property);
				username_present = AXIS2_TRUE;
		}
		if(zend_hash_find(Z_OBJPROP_P(zval_client), "password", sizeof("password"), (void **)&msg_tmp) == SUCCESS && 
			Z_TYPE_PP(tmp) == IS_STRING){
			char *password = NULL;
			axis2_property_t *property = NULL;
			property = axis2_property_create(env);
			password = Z_STRVAL_PP(tmp);
			AXIS2_PROPERTY_SET_VALUE(property,env, password);
			AXIS2_OPTIONS_SET_PROPERTY(client_options,  env, "password", property);
			password_present = AXIS2_TRUE;
		}
		
		if(zend_hash_find(Z_OBJPROP_P(zval_client), "digest", sizeof("digest"), (void **)&tmp) == SUCCESS && 
			Z_TYPE_PP(tmp) == IS_BOOL){
			int use_digest = 0;
			char *password_type = NULL;
			axis2_property_t *property = NULL;
			use_digest = Z_BVAL_PP(tmp);
			if(use_digest){
				password_type = "passwordDigest";
				property = axis2_property_create(env);
				AXIS2_PROPERTY_SET_VALUE(property, env, password_type);
				AXIS2_OPTIONS_SET_PROPERTY(client_options, env, "passwordType" ,property);
			}
		}else if(password_present){
				char *password_type = NULL;
			axis2_property_t *property = NULL;		
				password_type = "passwordText";
				property = axis2_property_create(env);
				AXIS2_PROPERTY_SET_VALUE(property, env, password_type);
				AXIS2_OPTIONS_SET_PROPERTY(client_options, env, "passwordType" ,property);
		}
		
		if(zend_hash_find(Z_OBJPROP_P(zval_client), "timeToLive", sizeof("timeToLive"), 
			(void **)&tmp) == SUCCESS && Z_TYPE_PP(tmp) == IS_STRING)
		{
			char *timeto_live = NULL;
			axis2_property_t *property = NULL;
			timeto_live = Z_STRVAL_PP(tmp);
			if(timeto_live){
				property = axis2_property_create(env);
				AXIS2_PROPERTY_SET_VALUE(property, env, wsf_util_get_ttl(timeto_live, env));
				AXIS2_OPTIONS_SET_PROPERTY(client_options, env, "timeToLive" ,property);
			}
			timestamp_present = AXIS2_TRUE;
		}                    
		if(username_present && password_present){
			axis2_property_t *sec_prop = NULL;
			axis2_property_t *outflow_prop = NULL;
			sec_prop = axis2_property_create(env);
			if(timestamp_present){
				AXIS2_PROPERTY_SET_VALUE(sec_prop, env, "UsernameToken Timestamp");        
			}else{
				AXIS2_PROPERTY_SET_VALUE(sec_prop, env, "UsernameToken");
			}            
			AXIS2_OPTIONS_SET_PROPERTY(client_options, env, "items", sec_prop);
			
			outflow_prop = axis2_property_create_with_args(env, AXIS2_SCOPE_APPLICATION, 0,
				NULL, "TRUE");
			
			AXIS2_OPTIONS_SET_PROPERTY(client_options, env, "OutflowSecurity", outflow_prop);

			AXIS2_SVC_CLIENT_ENGAGE_MODULE(svc_client , env, "rampart");
		}
	}
/*
	if(zval_msg){
		wsf_util_set_security_opts(Z_OBJPROP_P(zval_msg), env, svc_client TSRMLS_CC);
	}else if(zval_client){
		wsf_util_set_security_opts(Z_OBJPROP_P(zval_msg), env, svc_client TSRMLS_CC);
	}
*/		
}



int wsf_client_set_addr_options(zval *zval_client, zval *zval_msg, axis2_env_t *env,
    axis2_options_t *client_options, axis2_svc_client_t *svc_client, int *is_addr_action_present  TSRMLS_DC){
		
	zval **tmp = NULL;
    int is_addressing_engaged = AXIS2_FALSE;
	int addr_action_present = AXIS2_FALSE;
	char *value = NULL;	
	
	AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] setting addressing options ");

	if(zend_hash_find(Z_OBJPROP_P(zval_client), "useWSA", sizeof("useWSA"), 
        (void**)&tmp) == SUCCESS) {
        if(Z_TYPE_PP(tmp) == IS_BOOL && Z_BVAL_PP(tmp) == 1){ 
            	value = "1.0";

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] useWSA true, version 1.0");

       	} else if(Z_TYPE_PP(tmp) == IS_STRING){

				value = Z_STRVAL_PP(tmp);

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] useWSA is string, value is %s", value);
        }
	}
	/*
	else{
		return AXIS2_FALSE;	
	}
	*/
	
    if(zval_msg){
		
		AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] ws_message is present setting options using ws_message options");

		if(zend_hash_find(Z_OBJPROP_P(zval_msg), "action", sizeof("action"), 
					(void**)&tmp) == SUCCESS) {

				AXIS2_OPTIONS_SET_ACTION(client_options, env, Z_STRVAL_PP(tmp));
				
				addr_action_present = AXIS2_TRUE;   

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
					"[wsf_client] addressing action is %s", Z_STRVAL_PP(tmp));

		}
		if(zend_hash_find(Z_OBJPROP_P(zval_msg), "replyTo", sizeof("replyTo"), 
					(void**)&tmp) == SUCCESS) {

				axis2_endpoint_ref_t *replyto_epr = NULL;
				char *replyto = Z_STRVAL_PP(tmp);

				replyto_epr = axis2_endpoint_ref_create(env, replyto);
				
				AXIS2_OPTIONS_SET_REPLY_TO(client_options, env, replyto_epr);

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
					"[wsf_client] replyTo present :- %s", replyto);
		}
		if(zend_hash_find(Z_OBJPROP_P(zval_msg), "faultTo", sizeof("faultTo"), 
					(void**)&tmp) == SUCCESS) {

				axis2_endpoint_ref_t *faultto_epr = NULL;
				char *faultto = Z_STRVAL_PP(tmp);

				faultto_epr = axis2_endpoint_ref_create(env, faultto);
				AXIS2_OPTIONS_SET_FAULT_TO(client_options, env, faultto_epr);

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
					"[wsf_client] faultTo present :- %s" , faultto);
		}
		if(zend_hash_find(Z_OBJPROP_P(zval_msg), "from", sizeof("from"), 
			(void**)&tmp) == SUCCESS) {

				axis2_endpoint_ref_t *from_epr = NULL;
				char *from = Z_STRVAL_PP(tmp);
				
				from_epr = axis2_endpoint_ref_create(env, from);
				AXIS2_OPTIONS_SET_REPLY_TO(client_options, env, from_epr);

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
					"[wsf_client] from  present :- %s", from);
		}

		if(addr_action_present == AXIS2_TRUE){

				is_addressing_engaged = AXIS2_TRUE;
		
				AXIS2_SVC_CLIENT_ENGAGE_MODULE(svc_client, env, "addressing");
				
				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] engage addressing ");
				
				if(strcmp(value,"submission") == 0){

					axis2_property_t *property = NULL;
					
					property = axis2_property_create(env);
					
					AXIS2_PROPERTY_SET_SCOPE(property, env, AXIS2_SCOPE_REQUEST);
					
					AXIS2_PROPERTY_SET_VALUE(property, env, 
						AXIS2_STRDUP(AXIS2_WSA_NAMESPACE_SUBMISSION, env));

					AXIS2_OPTIONS_SET_PROPERTY(client_options, env, AXIS2_WSA_VERSION, property);

					AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] addressing version is submission");
			}
		}
	}				
    else{
			
		AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI , "[wsf_client] setting options using ws_client options");

			if(zend_hash_find(Z_OBJPROP_P(zval_client), "action", sizeof("action"), 
                (void**)&tmp) == SUCCESS) {

				AXIS2_OPTIONS_SET_ACTION(client_options, env, Z_STRVAL_PP(tmp));
                addr_action_present = AXIS2_TRUE;   

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] addressing action present :- %s", Z_STRVAL_PP(tmp));

            }
            if(zend_hash_find(Z_OBJPROP_P(zval_client), "replyTo", sizeof("replyTo"), 
                (void**)&tmp) == SUCCESS) {
             
				axis2_endpoint_ref_t *replyto_epr = NULL;
                
				char *replyto = Z_STRVAL_PP(tmp);
                
				replyto_epr = axis2_endpoint_ref_create(env, replyto);
                
				AXIS2_OPTIONS_SET_REPLY_TO(client_options, env, replyto_epr);

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
					"[wsf_client] replyTo present :- %s", replyto);
            }

			if(zend_hash_find(Z_OBJPROP_P(zval_client), "faultTo", sizeof("faultTo"), 
                (void**)&tmp) == SUCCESS) {

				axis2_endpoint_ref_t *faultto_epr = NULL;
                
				char *faultto = Z_STRVAL_PP(tmp);
                
				faultto_epr = axis2_endpoint_ref_create(env, faultto);
                
				AXIS2_OPTIONS_SET_FAULT_TO(client_options, env, faultto_epr);

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] faultTo present %s", faultto);

            }
            if(zend_hash_find(Z_OBJPROP_P(zval_client), "from", sizeof("from"), 
                (void**)&tmp) == SUCCESS) {
                axis2_endpoint_ref_t *from_epr = NULL;
                
				char *from = Z_STRVAL_PP(tmp);

                from_epr = axis2_endpoint_ref_create(env, from);
                AXIS2_OPTIONS_SET_REPLY_TO(client_options, env, from_epr);

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] from present %s", from);
            }
            if(addr_action_present == AXIS2_TRUE){
				is_addressing_engaged = AXIS2_TRUE;
				
                AXIS2_SVC_CLIENT_ENGAGE_MODULE(svc_client, env, "addressing");
			
				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] engage addressing");

				if(strcmp(value,"submission") == 0){
                    axis2_property_t *property = NULL;
                    property = axis2_property_create(env);
				    AXIS2_PROPERTY_SET_SCOPE(property, env, AXIS2_SCOPE_REQUEST);
				    AXIS2_PROPERTY_SET_VALUE(property, env, 
					AXIS2_STRDUP(AXIS2_WSA_NAMESPACE_SUBMISSION, env));
				    AXIS2_OPTIONS_SET_PROPERTY(client_options, env, AXIS2_WSA_VERSION, property);

					AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] addressing versio is submission");
                }
            }   
		} 
	*is_addr_action_present = addr_action_present;
	return is_addressing_engaged;
}

int wsf_client_set_options(zval *zval_client, zval *zval_msg, axis2_env_t *env,
        axis2_options_t *client_options, axis2_svc_client_t *svc_client, int is_send TSRMLS_DC)
{
    zval **tmp = NULL;
    zval **msg_tmp = NULL;
    int use_soap = 0;

    if(zend_hash_find(Z_OBJPROP_P(zval_client), "useSOAP", sizeof("useSOAP"), 
        (void **)&tmp) == SUCCESS){
        if(Z_TYPE_PP(tmp) == IS_STRING){
            char *value = NULL;
            value = Z_STRVAL_PP(tmp);

            if(value && strcmp(value,"1.2") == 0){
            
				AXIS2_OPTIONS_SET_SOAP_VERSION(client_options, env, AXIOM_SOAP12);

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] soap version SOAP12");

            }
            else if(value && strcmp(value,"1.1") == 0){

                AXIS2_OPTIONS_SET_SOAP_VERSION(client_options, env, AXIOM_SOAP11);

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] soap version SOAP11");

				WSF_GLOBAL(soap_version) = AXIOM_SOAP11;

				WSF_GLOBAL(soap_uri) = WS_SOAP_1_1_NAMESPACE_URI;
			}
            else if(value && strcmp(value, "false") == 0) {
                use_soap = 0;

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] use soap value is false ");
            }
        }else if(Z_TYPE_PP(tmp) == IS_DOUBLE){
            double val = Z_DVAL_PP(tmp);
            if(val == 1.2){

                AXIS2_OPTIONS_SET_SOAP_VERSION(client_options, env, AXIOM_SOAP12);

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] use soap value is false ");

            }else if(val == 1.1){
                AXIS2_OPTIONS_SET_SOAP_VERSION(client_options, env, AXIOM_SOAP11);

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] soap version soap11");

				WSF_GLOBAL(soap_version) = AXIOM_SOAP11;
				WSF_GLOBAL(soap_uri) = WS_SOAP_1_1_NAMESPACE_URI;
            }
        }else if(Z_TYPE_PP(tmp) == IS_BOOL){
            int bval = Z_BVAL_PP(tmp);
            if(bval == 1){
                AXIS2_OPTIONS_SET_SOAP_VERSION(client_options, env, AXIOM_SOAP12);
            }else if(bval == 0){
                use_soap = 0;
            }    
        }
    }else
    {
        use_soap = 0;

		AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] soap version is soap12");

    }
    if(zend_hash_find(Z_OBJPROP_P(zval_client), "HTTPMethod", sizeof("HTTPMethod"), 
        (void **)&tmp) == SUCCESS){
        if(use_soap == 0){
            char *value = NULL;
            value = Z_STRVAL_PP(tmp);
            AXIS2_OPTIONS_SET_PROPERTY(client_options, env, AXIS2_ENABLE_REST,
                AXIS2_VALUE_TRUE);
            if(value && strcmp(value, "GET") == 0){
                AXIS2_OPTIONS_SET_PROPERTY(client_options, env, AXIS2_HTTP_METHOD,
                    AXIS2_HTTP_HEADER_GET);  
            }
        }       
    }
    
    if(zend_hash_find(Z_OBJPROP_P(zval_client), "useMTOM", sizeof("useMTOM"), 
        (void **)&tmp) == SUCCESS){
        if(Z_TYPE_PP(tmp) == IS_BOOL){
            int val = Z_BVAL_PP(tmp);
            if(val == 0){

                AXIS2_OPTIONS_SET_ENABLE_MTOM(client_options, env, AXIS2_FALSE);

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] enable mtom false");

            }else{

                AXIS2_OPTIONS_SET_ENABLE_MTOM(client_options, env, AXIS2_TRUE);

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] enable mtom true");

            }
        }                
    }
    if(zval_msg && zend_hash_find(Z_OBJPROP_P(zval_msg), "to", sizeof("to"), 
        (void**)&msg_tmp) == SUCCESS) {
        axis2_endpoint_ref_t *to_epr = NULL;
        char *to = Z_STRVAL_PP(msg_tmp);
        to_epr = axis2_endpoint_ref_create(env, to);
        AXIS2_OPTIONS_SET_TO(client_options, env, to_epr);
    }else if(zend_hash_find(Z_OBJPROP_P(zval_client), "to", sizeof("to"), 
        (void**)&msg_tmp) == SUCCESS) {
        axis2_endpoint_ref_t *to_epr = NULL;
        char *to = Z_STRVAL_PP(msg_tmp);
        to_epr = axis2_endpoint_ref_create(env, to);
        AXIS2_OPTIONS_SET_TO(client_options, env, to_epr);
    }
    else
    {
        return AXIS2_FAILURE;
    }
			

	wsf_client_set_security_options(zval_client, zval_msg, env, client_options, svc_client TSRMLS_CC);
	
    /*
	if(zval_msg && zend_hash_find(Z_OBJPROP_P(zval_msg), "reliable", sizeof("reliable"), (void**)&msg_tmp) == SUCCESS
		&& Z_TYPE_PP(msg_tmp) == IS_BOOL){
			is_rm_enabled = Z_BVAL_PP(tmp);
			
	}else if(zend_hash_find(Z_OBJPROP_P(zval_client), "reliable", sizeof("reliable"),(void**)&tmp) == SUCCESS 
		&& Z_TYPE_PP(tmp) == IS_BOOL){
			is_rm_enabled = Z_BVAL_PP(tmp);
	}
	
	if(is_rm_enabled && is_addressing_engaged){
		axis2_property_t *rmprop = NULL;
		rmprop = axis2_property_create(env);
		AXIS2_PROPERTY_SET_SCOPE(rmprop, env, AXIS2_SCOPE_APPLICATION);
		AXIS2_PROPERTY_SET_VALUE(rmprop, env, AXIS2_VALUE_TRUE);
		AXIS2_OPTIONS_SET_PROPERTY(client_options, env, "Sandesha2LastMessage", rmprop);
        if(!is_send){
        AXIS2_OPTIONS_SET_USE_SEPARATE_LISTENER(client_options, env, AXIS2_TRUE);
        }
		AXIS2_SVC_CLIENT_ENGAGE_MODULE(svc_client, env, "sandesha2");
	}
	*/
    return AXIS2_SUCCESS;
}

/**
this_ptr -> ws_client 
param    -> payload ( ws_message, string, dom node)

*/
int wsf_client_do_request(
		zval *this_ptr, 
		zval *param, 
		zval *return_value,
		axis2_env_t *env,
		axis2_svc_client_t *svc_client,
		int is_oneway TSRMLS_DC)
{
/** for dom  */
    int status = AXIS2_SUCCESS;
    int input_type = WS_USING_INCORRECT_INPUT;

	xmlNodePtr nodep;
	zval **data = NULL;

	axiom_node_t *request_payload = NULL;
    axiom_node_t *response_payload = NULL;
    axiom_xml_reader_t *reader = NULL;
	axis2_options_t *client_options = NULL;

    zval **client_tmp = NULL;
    zval **msg_tmp = NULL;

    int responseXOP = 0;

	char *str_payload = NULL;
	int str_payload_len = 0;

	/** RM OPTION VARIABLES */
	int ws_client_will_continue_sequence = AXIS2_FALSE;
	int engage_rm = AXIS2_FALSE;
	int rm_spec_version = WS_RM_VERSION_1_0;
	char *rm_spec_version_str = WS_RM_VERSION_1_0_STR;
	int is_addressing_engaged = AXIS2_FALSE;
	int is_addressing_action_present = AXIS2_FALSE;
	int is_rm_engaged = AXIS2_FALSE;

    if(Z_TYPE_P(param) == IS_OBJECT &&
        instanceof_function(Z_OBJCE_P(param), ws_message_class_entry TSRMLS_CC))
    {
        zval **tmp_val = NULL;

		if(zend_hash_find(Z_OBJPROP_P(param), WS_MSG_PAYLOAD_STR, 
			sizeof(WS_MSG_PAYLOAD_STR), (void**)&tmp_val) == SUCCESS){
				
				str_payload = Z_STRVAL_PP(tmp_val);
				str_payload_len = Z_STRLEN_PP(tmp_val);
       			reader = axiom_xml_reader_create_for_memory(env, 
    				str_payload, str_payload_len, "utf-8", AXIS2_XML_PARSER_TYPE_BUFFER);

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] Input WSMessage - string ");

        		if (!reader) {
					zend_throw_exception_ex(zend_exception_get_default(TSRMLS_C), 1 TSRMLS_CC, 
	    				"xml reader create failed");
		        }
        }
		else if((zend_hash_find(Z_OBJPROP_P(param), WS_MSG_PAYLOAD_DOM, sizeof(WS_MSG_PAYLOAD_DOM), 
			(void**)&tmp_val) == SUCCESS) || 
			(zend_hash_find(Z_OBJPROP_P(param), WS_MSG_PAYLOAD_SXML, sizeof(WS_MSG_PAYLOAD_SXML), 
			(void**)&tmp_val) == SUCCESS)){
						
				nodep = wsf_get_xml_node(*tmp_val TSRMLS_CC);
				reader = axiom_xml_reader_create_for_memory(env, (void*)nodep->doc, 
							0, "utf-8", AXIS2_XML_PARSER_TYPE_DOC);

				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] Input WSMessage - dom node ");

				if (!reader) {
    	    		zend_throw_exception_ex(zend_exception_get_default(TSRMLS_C), 1 TSRMLS_CC, 
	    				"xml reader create failed");
				}
        }
	  
        input_type = WS_USING_MSG;

		AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] do_request Input type is WSMessage ");

    }else if(Z_TYPE_P(param) == IS_STRING){
	    /** we have an xml string */
	    str_payload = Z_STRVAL_P(param);
	    str_payload_len = Z_STRLEN_P(param);
	    input_type = WS_USING_STRING;
	    reader = axiom_xml_reader_create_for_memory(env, 
    			str_payload, str_payload_len, "utf-8", AXIS2_XML_PARSER_TYPE_BUFFER);
    	if (!reader) {
		    zend_throw_exception_ex(zend_exception_get_default(TSRMLS_C), 1 TSRMLS_CC, 
	    		"xml reader create failed");
	    }
		AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] Input Type is a String ");

    }else if(Z_TYPE_P(param) == IS_OBJECT && instanceof_function(Z_OBJCE_P(param), dom_node_class_entry TSRMLS_CC)) {

		nodep = wsf_get_xml_node(param TSRMLS_CC);
        reader = axiom_xml_reader_create_for_memory(env, 
				(void*)nodep->doc, 0, "utf-8", AXIS2_XML_PARSER_TYPE_DOC);
	    if (!reader) {
    		zend_throw_exception_ex(zend_exception_get_default(TSRMLS_C), 1 TSRMLS_CC, 
	    		"xml reader create failed");
	    }
	    input_type = WS_USING_DOM;    

		AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] Input Type is a Dom Node ");

    }       
    	
	request_payload = ws_util_read_payload(reader, env);
	
	if (!request_payload) {
		zend_throw_exception_ex(zend_exception_get_default(TSRMLS_C), 1 TSRMLS_CC, 
			"request payload should not be null");

		AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "request payload node is null");
	}
	
	client_options = (axis2_options_t *)AXIS2_SVC_CLIENT_GET_OPTIONS(svc_client, env);

	/** add ssl properties */
	wsf_client_enable_ssl(Z_OBJPROP_P(this_ptr), env, client_options, svc_client TSRMLS_CC);


    if(input_type == WS_USING_MSG){

		axis2_char_t *default_cnt_type = NULL;
		status = wsf_client_set_options(this_ptr, param, env,
            client_options, svc_client, 0 TSRMLS_CC);

        if(status == AXIS2_FAILURE){
            php_error_docref(NULL TSRMLS_CC, E_ERROR, "service endpoint uri is needed for invocation ");
        }

		is_addressing_engaged = wsf_client_set_addr_options(this_ptr, param, env, 
			client_options, svc_client, &is_addressing_action_present TSRMLS_CC);
		/** add set headers function here */

		wsf_client_set_headers(env, svc_client, param TSRMLS_CC);

		
        if(zend_hash_find(Z_OBJPROP_P(param), WS_DEFAULT_ATTACHEMENT_CONTENT_TYPE, 
			sizeof(WS_DEFAULT_ATTACHEMENT_CONTENT_TYPE), 
			(void **)&msg_tmp) == SUCCESS && Z_TYPE_PP(msg_tmp) == IS_STRING){
            default_cnt_type = Z_STRVAL_PP(msg_tmp);   
        }else{
            default_cnt_type = "application/octet-stream";
        }
		if(zend_hash_find(Z_OBJPROP_P(this_ptr), WS_RESPONSE_XOP, 
			sizeof(WS_RESPONSE_XOP), 
				(void **)&client_tmp) == SUCCESS && Z_TYPE_PP(client_tmp) == IS_BOOL){
					responseXOP = Z_BVAL_PP(client_tmp);
        }          
                 
		if(zend_hash_find(Z_OBJPROP_P(param), WS_ATTACHMENTS, sizeof(WS_ATTACHMENTS), 
            (void **)&msg_tmp) == SUCCESS && Z_TYPE_PP(msg_tmp) == IS_ARRAY){
				HashTable *ht = NULL;
				int enable_mtom = AXIS2_TRUE;
				enable_mtom = AXIS2_OPTIONS_GET_ENABLE_MTOM(client_options, env);
				
				ht = Z_ARRVAL_PP(msg_tmp);
                if(ht){
                    wsf_util_set_attachments_with_cids(env, enable_mtom, request_payload,
                        ht, default_cnt_type TSRMLS_CC);
                }                    
       }
    }else if(input_type == WS_USING_DOM || input_type == WS_USING_STRING){

			status = wsf_client_set_options(this_ptr, NULL, env,
		        client_options, svc_client, 0 TSRMLS_CC);
		
			if(status == AXIS2_FAILURE){
				php_error_docref(NULL TSRMLS_CC, E_ERROR, "service enpoint uri is needed for service invocation");
			}
			is_addressing_engaged = wsf_client_set_addr_options(this_ptr, NULL, env, 
			client_options, svc_client, &is_addressing_action_present TSRMLS_CC);
		
    }

	{/** RM OPTIONS */
		
		/** this value is a long value and is the rm version */
		if(zend_hash_find(Z_OBJPROP_P(this_ptr), WS_RELIABLE, sizeof(WS_RELIABLE),
			(void**)&client_tmp) == SUCCESS){
				axis2_property_t *rm_prop = NULL;
				
				if(Z_LVAL_PP(client_tmp) == WS_RM_VERSION_1_0){
					rm_spec_version = WS_RM_VERSION_1_0;
					rm_spec_version_str = WS_RM_VERSION_1_0_STR;
					AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] rm spec version 1.0");

				}else if(Z_LVAL_PP(client_tmp) == WS_RM_VERSION_1_1){
					rm_spec_version = WS_RM_VERSION_1_1;
					rm_spec_version_str = WS_RM_VERSION_1_1_STR;
					AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] rm spec version 1.1");
				}

				rm_prop = axis2_property_create_with_args(env, 0, 0, 0, rm_spec_version_str);
				AXIS2_OPTIONS_SET_PROPERTY(client_options, env, WS_SANDESHA2_CLIENT_RM_SPEC_VERSION, rm_prop);
				engage_rm  = AXIS2_TRUE;
		}
		/**
				reliable = TRUE
					1. addressing is engaged by user specifing useWSA and Action
					2. addressing is not specified by useWSA but action presnt
							then engage addressing
					If Addressing is engaged
					engage RM
		*/
		if((is_addressing_engaged || 
			(!is_addressing_engaged && is_addressing_action_present )) && engage_rm){
			
				if(!is_addressing_engaged){
					AXIS2_SVC_CLIENT_ENGAGE_MODULE(svc_client, env, "addressing");
					AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] useWSA not specified, addressing engaged since rm is engaed");
				}
				AXIS2_SVC_CLIENT_ENGAGE_MODULE(svc_client, env, "sandesha2");
				is_rm_engaged = AXIS2_TRUE;
				
				wsf_client_set_rm_db(env, svc_client, WSF_GLOBAL(rm_db_dir) TSRMLS_CC);

				
				/** rm is engaged , process other rm params */
				if(zend_hash_find(Z_OBJPROP_P(this_ptr), WS_SEQUENCE_EXPIRY_TIME, sizeof(WS_SEQUENCE_EXPIRY_TIME),
					(void**)&client_tmp) == SUCCESS){
						axis2_property_t *seq_exp_time_prop = axis2_property_create_with_args(env, AXIS2_SCOPE_APPLICATION,
							0, NULL, (void*)Z_LVAL_PP(client_tmp));
						AXIS2_OPTIONS_SET_PROPERTY(client_options, env, "InactivityTimeout", seq_exp_time_prop); 

						AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] sequenceExpiryTime is %d", Z_LVAL_PP(client_tmp));
				}
				if(zend_hash_find(Z_OBJPROP_P(this_ptr), WS_WILL_CONTINUE_SEQUENCE, 
						sizeof(WS_WILL_CONTINUE_SEQUENCE), (void **)&client_tmp) == SUCCESS){
						if(Z_TYPE_PP(client_tmp) && Z_BVAL_PP(client_tmp) == 1){
						
							ws_client_will_continue_sequence = 1;
						
							AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] willContinueSequence true");
						}
				}
		}
		if(is_rm_engaged){
			if(ws_client_will_continue_sequence && input_type == WS_USING_MSG){
				/** if input_type is ws_message and continueSequence is true on client, we should look for 
					false value in ws_message to end the sequence ,
					WSMessage only accepts a false value*/
				if(zend_hash_find(Z_OBJPROP_P(param), WS_WILL_CONTINUE_SEQUENCE, sizeof(WS_WILL_CONTINUE_SEQUENCE),
						(void**)&msg_tmp) == SUCCESS){
				
						ws_client_will_continue_sequence = 0;
						if(rm_spec_version == WS_RM_VERSION_1_0){
							
							axis2_property_t *last_msg_prop = axis2_property_create_with_args(env, 
													AXIS2_SCOPE_APPLICATION, 0, NULL, AXIS2_VALUE_TRUE);
							AXIS2_OPTIONS_SET_PROPERTY(client_options, env, "Sandesha2LastMessage", last_msg_prop);

							AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] seting Sandesha2LastMessage");
						}
					
					}/** END willContinueSequence */
				
			}else if(!ws_client_will_continue_sequence){
					AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] setting TreminateSequence property");
					if(rm_spec_version == WS_RM_VERSION_1_0){
						axis2_property_t *last_msg_prop = axis2_property_create_with_args(env, 
											0, 0, 0, AXIS2_VALUE_TRUE);
						AXIS2_OPTIONS_SET_PROPERTY(client_options, env, "Sandesha2LastMessage", last_msg_prop);

						AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_client] setting Sandesha2LastMessage");
					}
			}

			if(!is_oneway){
			char *offered_seq_id = NULL;
			axis2_property_t *sequence_property = NULL;
			offered_seq_id = axis2_uuid_gen(env);
			sequence_property = axis2_property_create(env);
			AXIS2_PROPERTY_SET_VALUE(sequence_property, env, AXIS2_STRDUP(offered_seq_id, env));
			AXIS2_OPTIONS_SET_PROPERTY(client_options, env, "Sandesha2OfferedSequenceId", sequence_property);
			AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, " [wsf-log] Sandesha2OfferedSequenceId is set as property");
			}
		}
	}/** END RM OPTIONS */	

	if(is_oneway)
	{
		int ret_val = 0;


		ret_val = AXIS2_SVC_CLIENT_SEND_ROBUST(svc_client, env, request_payload);
		if(is_rm_engaged && !ws_client_will_continue_sequence && rm_spec_version == WS_RM_VERSION_1_1){
		/**currently there are no callbacks disscuss and implement */

		}

		if(ret_val == 1)
		{
			ZVAL_TRUE(return_value);
		}else{
			ZVAL_FALSE(return_value);
		}

	}else {
		response_payload = AXIS2_SVC_CLIENT_SEND_RECEIVE(svc_client, env, request_payload);	
		if (response_payload) {
			axis2_char_t *res_text = NULL;
    		axis2_char_t *fault = NULL;
	        
			fault = axiom_util_get_localname(response_payload, env);
		    
			if( fault && 0 == strcmp(fault, "Fault"))
			{
	    		zval *rfault = NULL;
				MAKE_STD_ZVAL(rfault);
    			object_init_ex(rfault, ws_fault_class_entry);
				res_text = wsf_util_serialize_om(env, response_payload);
				add_property_stringl(rfault, "str", res_text, strlen(res_text), 1);
				ZVAL_ZVAL(return_value, rfault, NULL, NULL);
			}
			else {
	    		zval *rmsg = NULL;
    			MAKE_STD_ZVAL(rmsg);
    			object_init_ex(rmsg, ws_message_class_entry);
	    		if(input_type == WS_USING_MSG){
    				if(responseXOP == 1)
	    			{
        				int attachments_found = AXIS2_FALSE;
	        			zval *cid2str = NULL;
						zval *cid2contentType = NULL;
		                
		        		MAKE_STD_ZVAL(cid2str);
        				MAKE_STD_ZVAL(cid2contentType);
		            
		        		array_init(cid2str);
        				array_init(cid2contentType);
						wsf_util_get_attachments(env, response_payload, cid2str, cid2contentType TSRMLS_CC);
		            
        				add_property_zval(rmsg, "attachments", cid2str);
        				add_property_zval(rmsg, "cid2contentType", cid2contentType);
					}
				}
				res_text = wsf_util_serialize_om(env , response_payload);
				add_property_stringl(rmsg, WS_MSG_PAYLOAD_STR, res_text, strlen(res_text), 1); 
				ZVAL_ZVAL(return_value, rmsg, NULL, NULL);
			}
			
		} else {
			zend_throw_exception_ex(zend_exception_get_default(TSRMLS_C), 1 TSRMLS_CC, 
				"soap body is not found");
		}
	}
	return 0;
}

void wsf_util_set_security_opts(HashTable *ht, axis2_env_t *env, axis2_svc_client_t *svc_client TSRMLS_DC)
{
	zval **tmp = NULL;
	axis2_param_t *outflow_param = NULL, *outflow_action = NULL;
	axis2_array_list_t *outflow_vl = NULL, *action_vl = NULL, *param_vl = NULL;

	axis2_param_t *inflow_param = NULL, *inflow_action = NULL, *inflow_params = NULL;
	axis2_array_list_t *inflow_vl = NULL, *inflow_action_vl = NULL, *inflow_params_vl = NULL;

	int usernametoken	= AXIS2_FALSE;
	int timestamp	= AXIS2_FALSE;
	int encrypt				= AXIS2_FALSE;
	int decrypt				= AXIS2_FALSE;
	int engage_rampart = AXIS2_TRUE;
	char *items_value = NULL;
	axis2_param_t *param = NULL;
	param_vl = axis2_array_list_create(env, 7);

	if(zend_hash_find(ht, "user", sizeof("user"), (void **)&tmp) == SUCCESS && 
		Z_TYPE_PP(tmp) == IS_STRING){
			char *username = NULL;
			username = Z_STRVAL_PP(tmp); 
			param = axis2_param_create(env, "user", username);
			axis2_param_set_param_type(param, env, AXIS2_TEXT_PARAM);
			axis2_array_list_add(param_vl, env, param);
			
			AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, " [wsf ]  user   %s", username);

		if(zend_hash_find(ht, "password", sizeof("password"), (void **)&tmp) == SUCCESS && 
			Z_TYPE_PP(tmp) == IS_STRING){
			char *password = NULL;
			password = Z_STRVAL_PP(tmp);
			param = axis2_param_create(env, "password", password);
			axis2_param_set_param_type(param, env, AXIS2_TEXT_PARAM);
			axis2_array_list_add(param_vl, env, param);
			AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, " [wsf ]  password   %s", password);
			usernametoken = AXIS2_TRUE;
			
			if(zend_hash_find(ht, "digest", sizeof("digest"), (void **)&tmp) == SUCCESS && 
			Z_TYPE_PP(tmp) == IS_BOOL){
				int use_digest = 0;
				char *password_type = NULL;
				use_digest = Z_BVAL_PP(tmp);
					if(use_digest){
						password_type = "passwordDigest";
					param = axis2_param_create(env, "passwordType", AXIS2_STRDUP("passwordDigest", env));
					axis2_array_list_add(param_vl, env, param);
					}
				}else{
				char *password_type = NULL;
				password_type = "passwordText";
				param = axis2_param_create(env, "passwordType", AXIS2_STRDUP("passwordText", env));
				axis2_array_list_add(param_vl, env, param);
				}		
		}
	}
	if(zend_hash_find(ht, "timeToLive", sizeof("timeToLive"), 
		(void **)&tmp) == SUCCESS && Z_TYPE_PP(tmp) == IS_STRING){
				char *timeto_live = NULL;
				timeto_live = Z_STRVAL_PP(tmp);
				if(timeto_live){
					param = axis2_param_create(env, "timeToLive", wsf_util_get_ttl(timeto_live, env)); 
					axis2_array_list_add(param_vl, env, param);
				}
				timestamp = AXIS2_TRUE;
	}	
	
	if(zend_hash_find(ht, "encrypt", sizeof("encrypt"), (void**)&tmp) == SUCCESS &&
			Z_TYPE_PP(tmp) == IS_OBJECT && 
			instanceof_function(Z_OBJCE_PP(tmp), ws_security_token_class_entry TSRMLS_CC)){
				zval **sec_tmp = NULL;
				HashTable *secht = Z_OBJPROP_PP(tmp);
				if(zend_hash_find(secht, "encryption_key", sizeof("encryption_key"), (void**)&sec_tmp) == SUCCESS &&
					Z_TYPE_PP(sec_tmp) == IS_STRING){
						axis2_char_t *key = NULL;
						encrypt = AXIS2_TRUE;
						key = Z_STRVAL_PP(sec_tmp);
						param = axis2_param_create(env, "keyBuffer", key);
						axis2_array_list_add(param_vl, env, param);
				}
				if(encrypt){
					if(zend_hash_find(secht, "encryption_method", sizeof("encryption_method"), 
						(void**)&sec_tmp) == SUCCESS && Z_TYPE_PP(sec_tmp) == IS_LONG){
						int algo_suit = -1;
						char *algorithm_asy = NULL, *algorithm_sym = NULL;
						algo_suit = Z_LVAL_PP(sec_tmp);
						algorithm_asy = wsf_util_get_algorithm(algo_suit, WS_ALGORITHM_ASYMMETRIC);
						param = axis2_param_create(env, "encryptionKeyTransportAlgorithm", algorithm_sym);
						axis2_array_list_add(param_vl, env, param);
						algorithm_sym = wsf_util_get_algorithm(algo_suit, WS_ALGORITHM_SYMMETRIC);
						param = axis2_param_create(env, "encryptionSymAlgorithm", algorithm_sym);
						axis2_array_list_add(param_vl, env, param);
					}
					if(zend_hash_find(secht, "sectoken_ref", sizeof("sectoken_ref"), 
						(void**)&sec_tmp) == SUCCESS && Z_TYPE_PP(sec_tmp) == IS_STRING){
						char *security_token_ref = NULL;
						security_token_ref = Z_STRVAL_PP(sec_tmp);
						param = axis2_param_create(env, "encryptionKeyIdentifier", security_token_ref);
						axis2_array_list_add(param_vl, env, param);								
					}
				}
	}		
	
	if(usernametoken && timestamp && encrypt)
	{	
		items_value = "UsernameToken Timestamp Encrypt";
	}else if(usernametoken && timestamp){
		items_value = "UsernameToken Timestamp";
	}else if(usernametoken && encrypt){
		items_value = "UsernameToken Encrypt";
	}else if(timestamp && encrypt){
		items_value = "Timestamp Encrypt";	
	}else if(usernametoken){
		items_value = "UsernameToken";
		AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, " [wsf ]  UsernameToken   %s", items_value);
	}else if(timestamp){
		items_value = "Timestamp";
	}else if(encrypt){
		items_value = "Encrypt";
	}else {
		engage_rampart = AXIS2_FALSE;
	}
	
	if(items_value){
		param = axis2_param_create(env, "items", AXIS2_STRDUP(items_value, env));
		axis2_array_list_add(param_vl, env, param);
		
		outflow_action = axis2_param_create(env, "action", NULL);
		axis2_param_set_value_list(outflow_action, env, param_vl);

		outflow_vl = axis2_array_list_create(env, 1);
		axis2_array_list_add(outflow_vl, env, outflow_action);
		outflow_param = axis2_param_create(env, "OutflowSecurity", NULL);
		axis2_param_set_value_list(outflow_param, env, outflow_vl);
	}
	if(engage_rampart){
		axis2_svc_ctx_t *svc_ctx = NULL;
		axis2_conf_ctx_t *conf_ctx = NULL;
		axis2_conf_t *conf = NULL;
		axis2_svc_t *svc = NULL;
		axis2_param_container_t *param_containter = NULL;

		svc_ctx = AXIS2_SVC_CLIENT_GET_SVC_CTX(svc_client, env);
		conf_ctx = AXIS2_SVC_CTX_GET_CONF_CTX(svc_ctx, env);
		conf = AXIS2_CONF_CTX_GET_CONF(conf_ctx,env);
		AXIS2_CONF_ADD_PARAM(conf, env, outflow_param);
		AXIS2_SVC_CLIENT_ENGAGE_MODULE(svc_client , env, "rampart");
	}
}

void wsf_client_enable_ssl(HashTable *ht, axis2_env_t *env, axis2_options_t *options,
						   axis2_svc_client_t *svc_client TSRMLS_DC)
{
	axis2_property_t *ssl_server_key_prop = NULL;
	axis2_property_t *ssl_client_key_prop = NULL;
	axis2_property_t *passphrase_prop = NULL;
	zval **tmp = NULL;
	char *ssl_server_key_filename = NULL;
	char *ssl_client_key_filename = NULL;
	char *passphrase = NULL;
	
	if(zend_hash_find(ht, WS_SERVER_CERT, sizeof(WS_SERVER_CERT), (void **)&tmp) == SUCCESS){
		ssl_server_key_filename = Z_STRVAL_PP(tmp);		
	}
	if(zend_hash_find(ht, WS_CLIENT_CERT, sizeof(WS_CLIENT_CERT), (void **)&tmp) == SUCCESS){
		ssl_client_key_filename = Z_STRVAL_PP(tmp);	
	}
	if(zend_hash_find(ht, WS_PASSPHRASE, sizeof(WS_PASSPHRASE), (void **)&tmp) == SUCCESS){
		passphrase = Z_STRVAL_PP(tmp);		
	}

	ssl_server_key_prop = axis2_property_create_with_args(env, 0, AXIS2_TRUE, 0, AXIS2_STRDUP(ssl_server_key_filename, env));
	AXIS2_OPTIONS_SET_PROPERTY(options, env, "SERVER_CERT", ssl_server_key_prop);

	ssl_client_key_prop = axis2_property_create_with_args(env, 0, AXIS2_TRUE, 0, AXIS2_STRDUP(ssl_client_key_filename, env));
	AXIS2_OPTIONS_SET_PROPERTY(options, env, "KEY_FILE", ssl_client_key_prop);

	passphrase_prop = axis2_property_create_with_args(env, 0, AXIS2_TRUE, 0, AXIS2_STRDUP(passphrase, env));
	AXIS2_OPTIONS_SET_PROPERTY(options, env, "SSL_PASSPHRASE", passphrase_prop);

	AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf-client] setting ssh options ");
					
}