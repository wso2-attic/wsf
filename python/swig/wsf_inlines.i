%newobject wsf_last_soap_fault_exception;
%newobject wsf_axiom_data_handler_get_content;
/*%newobject wsf_axiom_node_to_str; */




#ifdef SWIGPERL5
%inline %{
	SV *wsf_axiom_data_handler_get_content(axiom_data_handler_t *data_handler,
					       const axutil_env_t *env)
	{
		axis2_char_t *content = NULL;
		int content_length = 0;

		axiom_data_handler_read_from(data_handler, env, &content, &content_length);

		if (content == NULL)
			return NULL;

		return newSVpv(content, content_length);
	}
	%}
#elif SWIGRUBY
%inline %{
	VALUE wsf_axiom_data_handler_get_content(axiom_data_handler_t *data_handler,
						 const axutil_env_t   *env)
	{
		axis2_char_t *content = NULL;
		int content_length = 0;

		axiom_data_handler_read_from (data_handler, env, &content, &content_length);

		if (content == NULL)
			return Qnil;

		return rb_str_new(content, content_length);
	}
	%}
#endif

%inline %{

/*#define AXIS2_MODULE_RAMPART    "rampart"*/

    int
    wsf_client_set_module_param_option(axutil_env_t *env,
                                       axis2_svc_client_t *svc_client,
                                       axis2_char_t *module_name,
                                       axis2_char_t *module_option,
                                       axis2_char_t *module_option_value) {
        axis2_conf_ctx_t *conf_ctx = NULL;
        axis2_svc_ctx_t *svc_ctx = NULL;
        axis2_module_desc_t *module_desc = NULL;
        axis2_conf_t *conf = NULL;
        axutil_qname_t *module_qname = NULL;
        axutil_param_t *param = NULL;

        module_qname = axutil_qname_create (env, module_name, NULL, NULL);

        svc_ctx = axis2_svc_client_get_svc_ctx (svc_client, env);

        conf_ctx = axis2_svc_ctx_get_conf_ctx (svc_ctx, env);

        conf = axis2_conf_ctx_get_conf (conf_ctx, env);

        module_desc = axis2_conf_get_module (conf, env, module_qname);
        if (!module_desc)
            return AXIS2_FAILURE;

        param = axis2_module_desc_get_param (module_desc, env, module_option);
        if (!param)
            return AXIS2_FAILURE;

        axutil_param_set_value (param, env, axutil_strdup (env,
                                                           module_option_value));

        AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                         "[wsf_client] setting %s module param %s to %s ", module_name,
                         module_option, module_option_value);
        axutil_qname_free (module_qname, env);
        return AXIS2_SUCCESS;
    }

    axiom_xml_reader_t *
    axiom_xml_reader_create_for_memory_new(const axutil_env_t * env,
					   axis2_char_t *container,
					   int size,
					   const axis2_char_t * encoding,
					   int type) {
      
        return (axiom_xml_reader_t *) axiom_xml_reader_create_for_memory(env,
									 (void *) container,
									 size,
									 encoding,
									 type);
    }

    axiom_node_t *wsf_axiom_element_get_first_node(axiom_element_t    *element,
                                                   axiom_node_t       *element_node,
                                                   const axutil_env_t *env)
    {
        axiom_node_t *child_node = axiom_node_get_first_child(element_node, env);
        
        while (child_node)
        {
            if (axiom_node_get_node_type(child_node, env) == AXIOM_ELEMENT)
                return child_node;
            else
                child_node = axiom_node_get_next_sibling(child_node, env);
        }
        
        return NULL;
    }

    axiom_node_t *wsf_get_last_soap_fault_base_node(const axis2_svc_client_t *svc_client,
                                                    const axutil_env_t       *env)
    {
        axiom_soap_envelope_t *soap_envelope = NULL;
        axiom_soap_body_t *soap_body = NULL;
        axiom_soap_fault_t *soap_fault = NULL;
  
        soap_envelope = axis2_svc_client_get_last_response_soap_envelope(svc_client, env);
        if (soap_envelope == NULL)
            return NULL;
    
        soap_body = axiom_soap_envelope_get_body(soap_envelope, env);
        if (soap_body == NULL)
            return NULL;
    
        soap_fault = axiom_soap_body_get_fault(soap_body, env);
        if (soap_fault == NULL)
            return NULL;

        return axiom_soap_fault_get_base_node(soap_fault, env);
    }

    void set_ssl_settings(axutil_env_t *env,
                          axis2_char_t *ca_cert,
                          axis2_char_t *client_cert,
                          axis2_char_t *pass_phrase,
                          axis2_options_t *client_options) 
    {
        axutil_property_t *ca_cert_property = NULL;
        axutil_property_t *client_cert_property = NULL;
        axutil_property_t *pass_phrase_property = NULL;

        ca_cert_property = axutil_property_create_with_args(env,
                                                            AXIS2_SCOPE_APPLICATION,
                                                            AXIS2_TRUE,
                                                            0,
                                                            axutil_strdup(env, ca_cert));
        
        client_cert_property = axutil_property_create_with_args(env,
                                                                AXIS2_SCOPE_APPLICATION,
                                                                AXIS2_TRUE,
                                                                0,
                                                                axutil_strdup(env, client_cert));
                
        pass_phrase_property = axutil_property_create_with_args(env,
                                                                AXIS2_SCOPE_APPLICATION,
                                                                AXIS2_TRUE,
                                                                0,
                                                                axutil_strdup(env, pass_phrase));
                
        axis2_options_set_property(client_options,
                                   env,
                                   WSF_PROP_NAME_SERVER_CERT,
                                   ca_cert_property);
                
        axis2_options_set_property(client_options,
                                   env,
                                   WSF_PROP_NAME_KEY_FILE,
                                   client_cert_property);
                
        axis2_options_set_property(client_options,
                                   env,
                                   WSF_PROP_NAME_SSL_PASSPHRASE,
                                   pass_phrase_property);
    }


    typedef struct fault_data 
    {
        axis2_char_t *code;
        axis2_char_t *reason;
        axis2_char_t *role;
        axis2_char_t *detail;
        axis2_char_t *xml;
    } fault_data_t;

    fault_data_t *wsf_last_soap_fault_exception(axis2_svc_client_t *svc_client,
                                                axutil_env_t *env) 
    {
        axiom_node_t *soap_fault_base_node = NULL;
        axiom_element_t *fault_element = NULL;
        axiom_child_element_iterator_t *child_element_ite = NULL;
        axiom_node_t *child_node = NULL;
        axiom_element_t *child_element = NULL;
        axis2_char_t *localname = NULL;
        axiom_node_t *code_node = NULL;
        axis2_char_t *code = NULL;
        axiom_node_t *reason_node = NULL;
        axiom_element_t *reason_element = NULL;
        axiom_element_t *code_element = NULL;
        axis2_char_t *reason = NULL;
        axiom_node_t *detail_node = NULL;
        axis2_char_t *detail = NULL;
        axis2_char_t *role = NULL;
        axis2_char_t *xml = NULL;
        fault_data_t *t = NULL;

        soap_fault_base_node = (axiom_node_t *) wsf_get_last_soap_fault_base_node(svc_client, env);
        
        if (soap_fault_base_node == NULL) {
            return NULL;
        }

        fault_element = axiom_node_get_data_element(soap_fault_base_node, env);
        child_element_ite = axiom_element_get_child_elements(fault_element, env, soap_fault_base_node);

        while (child_element_ite &&
	       axiom_child_element_iterator_has_next(child_element_ite, env)) {
        
            child_node = axiom_child_element_iterator_next(child_element_ite, env);
            if (child_node) {
                child_element = axiom_node_get_data_element(child_node, env);
                if (child_element) {
            
                    localname = axiom_element_get_localname(child_element, env);
                    if (axutil_strcmp(localname, WSF_ELEMENT_LN_SOAP12_FAULT_CODE) == 0) {
                
                        code_node = (axiom_node_t *) wsf_axiom_element_get_first_node(child_element, child_node, env);
                
                        if (code_node != NULL) {
                            code_element = (axiom_element_t *) axiom_node_get_data_element(code_node, env);
                            if (code_element != NULL) {
                                code = axiom_element_get_text(code_element, env, code_node);
                            }
                        }
                    } else if (axutil_strcmp(localname, WSF_ELEMENT_LN_SOAP11_FAULT_CODE) == 0) {
                        code = axiom_element_get_text(child_element, env, child_node);
                    } else if (axutil_strcmp(localname, WSF_ELEMENT_LN_SOAP12_FAULT_REASON) == 0) {
                        reason_node = (axiom_node_t *) wsf_axiom_element_get_first_node(child_element, child_node, env);

                        if (reason_node != NULL) {
                            reason_element = (axiom_element_t *) axiom_node_get_data_element(reason_node, env);
                            if (reason_element != NULL) {
                                reason = axiom_element_get_text(reason_element, env, reason_node);
                            }
                        }
                    } else if (axutil_strcmp(localname, WSF_ELEMENT_LN_SOAP11_FAULT_REASON) == 0) {
                        reason = axiom_element_get_text(child_element, env, child_node);
                    } else if ( (axutil_strcmp(localname, WSF_ELEMENT_LN_SOAP12_FAULT_DETAIL) == 0) ||
                                (axutil_strcmp(localname, WSF_ELEMENT_LN_SOAP11_FAULT_DETAIL) == 0) ) {
                        detail_node = axiom_node_get_first_element(child_node, env);
                        if (detail_node != NULL) {
                            detail = axiom_node_to_string(detail_node, env);
                        }
                    } else if ( (axutil_strcmp(localname, WSF_ELEMENT_LN_SOAP12_FAULT_ROLE) == 0) ||
                                (axutil_strcmp(localname, WSF_ELEMENT_LN_SOAP11_FAULT_ROLE) == 0) ) {
                        role = axiom_element_get_text(child_element, env, child_node);
                    }
                }
            }
        
            child_node = axiom_child_element_iterator_next(child_element_ite, env);
        }

        xml = axiom_node_to_string(soap_fault_base_node, env);
        
        t = malloc(sizeof(fault_data_t));

        t->code = axutil_strdup(env, code);
        t->reason = axutil_strdup(env, reason);
        t->role = axutil_strdup(env, role);
        t->detail = axutil_strdup(env, detail);
        t->xml = axutil_strdup(env, xml);
        
        return t;
    }

    int wsf_set_module_param_value(axutil_env_t       *env,
                                   axis2_svc_client_t *svc_client,
                                   axis2_char_t       *module_name,
                                   axis2_char_t       *param_name,
                                   axis2_char_t       *param_value)
    {
        axis2_svc_ctx_t *svc_ctx = NULL;
        axis2_conf_ctx_t *conf_ctx = NULL;
        axis2_conf_t *conf = NULL;
        axutil_qname_t *module_qname = NULL;
        axis2_module_desc_t *module_desc = NULL;
        axutil_param_t *param = NULL;
  
        svc_ctx = axis2_svc_client_get_svc_ctx(svc_client, env);
        if (svc_ctx == NULL)
            return AXIS2_FAILURE;
    
        conf_ctx = axis2_svc_ctx_get_conf_ctx(svc_ctx, env);
        if (conf_ctx == NULL)
            return AXIS2_FAILURE;
    
        conf = axis2_conf_ctx_get_conf(conf_ctx, env);
        if (conf == NULL)
            return AXIS2_FAILURE;

        module_qname = axutil_qname_create(env, module_name, NULL, NULL);
        if (module_qname == NULL)
            return AXIS2_FAILURE;
    
        module_desc = axis2_conf_get_module(conf, env, module_qname);
        if (module_desc == NULL)
            return AXIS2_FAILURE;
    
        param = axis2_module_desc_get_param(module_desc, env, param_name);
        if (param == NULL)
            return AXIS2_FAILURE;
    
        axutil_param_set_value(param, env, axutil_strdup (env, param_value));
  
        axutil_qname_free(module_qname, env);
  
        return AXIS2_SUCCESS;
    }

    axiom_element_t *wsf_axiom_node_get_data_element(axiom_node_t       *om_node,
                                                     const axutil_env_t *env)
    {
        return (axiom_element_t *)axiom_node_get_data_element(om_node, env);
    }

    axiom_text_t *wsf_axiom_node_get_text_element(axiom_node_t       *om_node,
                                                  const axutil_env_t *env)
    {
        return (axiom_text_t *)axiom_node_get_data_element(om_node, env);
    }

    void wsf_axiom_attach_content(const axutil_env_t *env,
                                  axiom_node_t       *node,
                                  axiom_node_t       *parent_node,
                                  axis2_bool_t        enable_mtom,
                                  axis2_char_t       *content_type,
                                  const char         *content,
                                  int                 content_length)
    {
        void *data_buffer = NULL;
        axiom_data_handler_t *data_handler = NULL;
        axiom_node_t *text_node = NULL;
        axiom_text_t *text = NULL;
  
        data_buffer = AXIS2_MALLOC (env->allocator, sizeof (char) * content_length);
        if (data_buffer == NULL)
            return;

        memcpy (data_buffer, (void*)content, content_length);

        data_handler = axiom_data_handler_create (env, NULL, content_type);
        if (data_handler == NULL)
            return;

        axiom_data_handler_set_binary_data (data_handler, env, (axis2_byte_t *)content, content_length);

        text = axiom_text_create_with_data_handler (env, parent_node, data_handler, &text_node);

        if (enable_mtom == AXIS2_FALSE)
            axiom_text_set_optimize (text, env, AXIS2_FALSE);

        axiom_node_detach (node, env);
    }

    axiom_node_t *wsf_str_to_axiom_node(const axutil_env_t *env,
                                        char               *container,
                                        int                 size)
    {
        axiom_xml_reader_t *xml_reader = NULL;
        axiom_stax_builder_t *stax_builder = NULL;
        axiom_document_t *document = NULL;
        axiom_node_t *axiom_node = NULL;
    
        xml_reader = axiom_xml_reader_create_for_memory(env, container, size, "utf-8", AXIS2_XML_PARSER_TYPE_BUFFER);
        if (xml_reader == NULL)
            return NULL;

        stax_builder = axiom_stax_builder_create(env, xml_reader);
        if (stax_builder == NULL)
            return NULL;

        document = axiom_stax_builder_get_document(stax_builder, env);
        if (document == NULL)
            return NULL;

        axiom_node = axiom_document_get_root_element(document, env);
        if (axiom_node == NULL)
            return NULL;

        axiom_document_build_all(document, env);

        axiom_stax_builder_free_self(stax_builder, env);

        return axiom_node;
    }

    axis2_char_t *wsf_axiom_node_to_str(const axutil_env_t *env,
                                        axiom_node_t       *axiom_node)
    {
        axiom_xml_writer_t *xml_writer = NULL;
        axiom_output_t *axiom_output = NULL;
        axis2_char_t *buffer = NULL;
        unsigned int buffer_length = 0;
        axis2_char_t *new_buffer = NULL;
  
        xml_writer = axiom_xml_writer_create_for_memory(env, NULL, AXIS2_TRUE, 0, AXIS2_XML_PARSER_TYPE_BUFFER);
        if (xml_writer == NULL)
            return NULL;
    
        axiom_output = axiom_output_create(env, xml_writer);
        if (axiom_output == NULL)
            return NULL;
    
        axiom_node_serialize(axiom_node, env, axiom_output);
  
        buffer = (axis2_char_t *) axiom_xml_writer_get_xml (xml_writer, env);
        buffer_length = axutil_strlen (buffer);
  
        new_buffer = AXIS2_MALLOC (env->allocator, sizeof (axis2_char_t) * (buffer_length + 1));
        memcpy (new_buffer, buffer, buffer_length);
        new_buffer[buffer_length] = '\0';
  
        axiom_output_free(axiom_output, env);
  
        return new_buffer;
    }

    axutil_property_t *wsf_axutil_property_create_with_args(const axutil_env_t *env,
                                                            axis2_scope_t       scope,
                                                            axis2_bool_t        own_value,
                                                            axis2_char_t        *value)
    {
        return axutil_property_create_with_args(env, scope, own_value, 0, value);
    }

    axis2_status_t wsf_axutil_property_set_value(axutil_property_t  *property,
                                                 const axutil_env_t *env,
                                                 char               *value)
    {
        return axutil_property_set_value(property, env, (void *)value);
    }

    int wsf_axutil_strcmp(const axis2_char_t *s1,
                          const axis2_char_t *s2)
    {
        return ((axutil_strcmp(s1, s2) == 0) ? AXIS2_TRUE : AXIS2_FALSE);
    }

    axis2_status_t wsf_axis2_options_set_property(axis2_options_t    *options,
                                                  const axutil_env_t *env,
                                                  const axis2_char_t *property_key,
                                                  axutil_property_t  *property)
    {
        return axis2_options_set_property(options, env, property_key, (void *)property);
    }

    char *wsf_axutil_strdup(const axutil_env_t *env,
                            const char         *ptr)
    {
        return (char *)axutil_strdup(env, (void *)ptr);
    }

    void axis2_log_debug(axutil_env_t *env,
                         axis2_char_t *str)
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, str);
    }

    void axis2_log_critical(axutil_env_t *env,
                            axis2_char_t *str)
    {
        AXIS2_LOG_CRITICAL(env->log, AXIS2_LOG_SI, str);
    }

    void axis2_log_error(axutil_env_t *env,
                         axis2_char_t *str)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, str);
    }

    /* axis2_status_t wsf_rampart_context_set_receiver_certificate(rampart_context_t *rampart_context,
                                                                const axutil_env_t *env,
                                                                axis2_char_t *receiver_certificate)
    {
        return rampart_context_set_receiver_certificate(rampart_context, env, (void *)receiver_certificate);
    }

    axis2_status_t wsf_rampart_context_set_prv_key(rampart_context_t *rampart_context,
                                                   const axutil_env_t *env,
                                                   axis2_char_t *prv_key)
    {
        return rampart_context_set_prv_key(rampart_context, env, (void *)prv_key);
    }

    axis2_status_t wsf_rampart_context_set_certificate(rampart_context_t* rampart_context,
                                                       const axutil_env_t *env,
                                                       axis2_char_t *certificate)
    {
        return rampart_context_set_certificate(rampart_context, env, (void *)certificate);
    } */


    void wsf_util_find_xop_content_and_convert_to_base64 (const axutil_env_t * env,
							  axiom_node_t * om_node)
    {
	    axiom_node_t *temp_node = NULL;
	    axiom_node_t *nodes[256];
	    int count = 0;

	    if (!om_node)
	    {
		    return;
	    }

	    nodes[count++] = om_node;

	    do {
		    if (axiom_node_get_node_type(om_node, env) == AXIOM_TEXT) {
			    axiom_text_t *text = NULL;
			    axiom_data_handler_t *data_handler = NULL;
			
			
			    text = (axiom_text_t*)axiom_node_get_data_element(om_node, env);
			    if(text) {
				    data_handler = axiom_text_get_data_handler (text, env);
				    if (data_handler) {
					    axiom_text_set_optimize(text, env, AXIS2_FALSE);
				    }			
			    }
		    }
		    temp_node = axiom_node_get_first_child(om_node, env);
		    if (temp_node)
		    {
			    om_node = temp_node;
			    nodes[count++] = om_node;
		    }
		    else
		    {
			    temp_node = axiom_node_get_next_sibling(om_node, env);
			    if (temp_node)
			    {
				    om_node = temp_node;
				    nodes[count -1] = om_node;
			    }
			    else
			    {
				    while (count > 1 && !temp_node)
				    {
					    count--;
					    om_node = nodes[count -1];
					    temp_node = axiom_node_get_next_sibling(om_node, env);
				    }
               
				    if (temp_node && count > 1)
				    {
					    om_node = temp_node;
					    nodes[count -1] = om_node;
				    }
				    else
				    {
					    count--;
				    }
			    }
		    }
	    } while(count > 0);
    
	    return;
    }


     /*   void wsf_set_security_data_to_rampart_context(axutil_env_t *env,
						  rampart_context_t *rampart_context,
						  axis2_char_t *private_key,
						  axis2_char_t *certificate,
						  axis2_char_t *receiver_certificate,
						  axis2_char_t *user,
						  axis2_char_t *password,
						  axis2_char_t *password_type,
						  int ttl)
    {
	    if (NULL != private_key) {
		    if (rampart_context_set_prv_key(rampart_context, env, (void *) private_key) == AXIS2_SUCCESS)
			     AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting pvt key ");
		    if (rampart_context_set_prv_key_type(rampart_context, env, AXIS2_KEY_TYPE_PEM) == AXIS2_SUCCESS)
			    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting pvt key format ");
	    }

	    if (NULL != certificate) {
		    if (rampart_context_set_certificate(rampart_context, env, (void *)certificate) == AXIS2_SUCCESS)
			    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting pub key");
		    if (rampart_context_set_certificate_type(rampart_context, env, AXIS2_KEY_TYPE_PEM) == AXIS2_SUCCESS)
			    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting pub key type");
	    }

	    if (NULL != receiver_certificate) {
		    if (rampart_context_set_receiver_certificate(rampart_context, env, receiver_certificate) == AXIS2_SUCCESS)
			    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting receiver pub key");
		    if (rampart_context_set_receiver_certificate_type(rampart_context, env, AXIS2_KEY_TYPE_PEM) == AXIS2_SUCCESS)
			    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting receiver pub key format");
	    }

	    if ((NULL != user) && (rampart_context_set_user(rampart_context, env, user) == AXIS2_SUCCESS))
		    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting username ");

	    if ((NULL != password) && (rampart_context_set_password(rampart_context, env, password) == AXIS2_SUCCESS))
		    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting password ");

	    if ((NULL != password_type) && (rampart_context_set_password_type(rampart_context, env, password_type) == AXIS2_SUCCESS))
		    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy] setting password type ");

	    if ((ttl > 0) && (rampart_context_set_ttl(rampart_context, env, ttl) == AXIS2_SUCCESS))
		    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_sec_policy) setting ttl");

    }
	    

    void handle_client_security(axutil_env_t *env, 
				axis2_svc_client_t *svc_client,
				axiom_node_t *incoming_policy_node,
				axis2_char_t *private_key,
				axis2_char_t *certificate,
				axis2_char_t *receiver_certificate,
				axis2_char_t *user,
				axis2_char_t *password,
				axis2_char_t *password_type,
				int ttl)
    {
	    axiom_element_t *root = NULL;
	    neethi_policy_t *neethi_policy = NULL;
	    axis2_svc_t *svc = NULL;
	    axis2_desc_t *desc = NULL;
	    axis2_policy_include_t *policy_include = NULL;
	    axis2_svc_ctx_t *svc_ctx = NULL;
	    axis2_conf_ctx_t *conf_ctx = NULL;
	    axis2_conf_t *conf = NULL;
	    axutil_param_t *security_param = NULL;
	    rampart_context_t *rampart_ctx = NULL;

	    if (NULL != incoming_policy_node) {
		    if (axiom_node_get_node_type(incoming_policy_node, env) == AXIOM_ELEMENT) {
			    root = (axiom_element_t *) axiom_node_get_data_element(incoming_policy_node, env);
			    if (NULL != root) {
				    neethi_policy = neethi_engine_get_policy(env, incoming_policy_node, root);
				    if (NULL != neethi_policy) {
					    svc = axis2_svc_client_get_svc(svc_client, env);
					    if (NULL != svc) {
						    desc = axis2_svc_get_base(svc, env);
						    policy_include = axis2_desc_get_policy_include(desc, env);
						    axis2_policy_include_add_policy_element(policy_include, env, AXIS2_SERVICE_POLICY, neethi_policy);
						    svc_ctx = axis2_svc_client_get_svc_ctx(svc_client, env);
						    if (NULL != svc_ctx) {
							    conf_ctx = axis2_svc_ctx_get_conf_ctx(svc_ctx, env);
							    if (NULL != conf_ctx) {
								    conf = axis2_conf_ctx_get_conf(conf_ctx, env);
								    if (NULL != conf) {
									    rampart_ctx = rampart_context_create(env);
									    wsf_set_security_data_to_rampart_context(env, rampart_ctx, private_key, certificate, receiver_certificate, user, password, password_type, ttl);
									    security_param = axutil_param_create(env, (axis2_char_t *) WSF_RAMPART_CONFIGURATION, rampart_ctx);
									    if (NULL != security_param) 
										    axis2_conf_add_param(conf, env, security_param);
								    }
							    }
						    }
					    }
				    }
			    }
		    }
	    }
	    axis2_svc_client_engage_module(svc_client, env, AXIS2_MODULE_RAMPART);

    }*/


				

%}
