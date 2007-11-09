# Copyright 2005,2006,2007 WSO2, Inc. http://wso2.com
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

require 'WSFC'
require 'wsf/wsmessage'
require 'wsf/wsfault'
require 'rexml/document'

class WSClient

  # Create a new WSClient instance.
  # All instance level initialization is done here.
  
  def initialize(options, axis2c_home = "/opt/wso2/wsf", log_file_name = "/tmp/wsf_ruby_client.log")
    # Create Environment
    @env = WSFC::axutil_env_create_all(log_file_name, WSFC::AXIS2_LOG_LEVEL_TRACE)
    if @env.nil? then
      puts "[critical][wsf-ruby] Failed to create WSF/C environment..."
      return
    end

    # Check if axis2c_home is valid
    if !axis2c_home.kind_of?(String) or axis2c_home.empty? then
      WSFC::axis2_log_critical(@env, "[wsf-ruby] 'axis2c_home' is invalid")
      return
    end

    # Create service client
    @svc_client = WSFC::axis2_svc_client_create(@env, axis2c_home)
    if @svc_client.nil? then
      WSFC::axis2_log_critical(@env, "[wsf-ruby] Failed to create service client")
      return
    end
    
    @options = Hash.new
    options.each_pair {|k,v| @options.store(k,v)} if options.kind_of? Hash

	# Set client level options
	client_options = WSFC::axis2_svc_client_get_options(@svc_client, @env)
	set_client_options(client_options)
  end
  
  # This method is used to set client level settings according to 
  # the options specified when the client is created.
  
  def set_client_options(client_options)
	# Proxy settings
    WSFC::axis2_svc_client_set_proxy(@svc_client,
                                     @env,
                                     @options["proxy_host"].to_s,
                                     @options["proxy_port"].to_s) if @options.has_key?("proxy_host") and @options.has_key?("proxy_port")

    # SOAP settings
    use_soap = @options.has_key?("use_soap") ? @options["use_soap"].to_s.upcase : "TRUE"

    if use_soap.eql? "FALSE" then # REST style
      WSFC::axis2_options_set_enable_rest(client_options, @env, WSFC::AXIS2_TRUE)
    else # SOAP style
      soap_version = use_soap.eql?("1.1") ? WSFC::AXIOM_SOAP11 : WSFC::AXIOM_SOAP12
      WSFC::axis2_options_set_soap_version(client_options, @env, soap_version)
    end
    
    # HTTP method
    http_method = @options.has_key?("http_method") ? @options["http_method"].to_s.upcase : "POST"

    if http_method.eql? "GET" then
      WSFC::axis2_options_set_http_method(client_options, @env, WSFC::AXIS2_HTTP_GET)
    end
    
    # SSL settings
    ca_cert = @options.has_key?("ca_cert") ? @options["ca_cert"].to_s : ""
    client_cert = @options.has_key?("client_cert") ? @options["client_cert"].to_s : ""
    pass_phrase = @options.has_key?("pass_phrase") ? @options["pass_phrase"].to_s : ""

    ca_cert_property = WSFC::ruby_axutil_property_create_with_args(@env,
                                                                   WSFC::ruby_axutil_strdup(@env, ca_cert))
    
    client_cert_property = WSFC::ruby_axutil_property_create_with_args(@env,
                                                                       WSFC::ruby_axutil_strdup(@env, client_cert))
    
    pass_phrase_property = WSFC::ruby_axutil_property_create_with_args(@env,
                                                                       WSFC::ruby_axutil_strdup(@env, pass_phrase))
    
    WSFC::ruby_axis2_options_set_property(client_options,
                                          @env,
                                          "SERVER_CERT",
                                          ca_cert_property)

    WSFC::ruby_axis2_options_set_property(client_options,
                                          @env,
                                          "KEY_FILE",
                                          client_cert_property)

    WSFC::ruby_axis2_options_set_property(client_options,
                                          @env,
                                          "SSL_PASSPHRASE",
                                          pass_phrase_property)
  end

  # This method is used to set transaction level settings.
  # This is called for every request/send call.
  
  def set_transaction_options(message, client_options)
    WSFC::axis2_options_set_xml_parser_reset(client_options, @env, WSFC::AXIS2_FALSE)
	
	# Set SOAP action
    use_soap = @options.has_key?("use_soap") ? @options["use_soap"].to_s.upcase : "TRUE"

    if !use_soap.eql?("FALSE") then # SOAP style
      action = message_property("action", message).to_s
      begin
        soap_action = WSFC::axutil_string_create(@env, action)
        WSFC::axis2_options_set_soap_action(client_options, @env, soap_action)
      end unless action.empty?
    end
  end

  # This method is used to do a blocking request call.
  # message can be an XML string, a REXML object or a WSMessage.
  # A WSFault is thown if an error occurs while a message is being sent.

  def request(message)
    if @svc_client.nil? then
      WSFC::axis2_log_error(@env, "[wsf-ruby] Service client not created")
      return nil
    end
    
    client_options = WSFC::axis2_svc_client_get_options(@svc_client, @env)
    
	# Set end point 
    to = message_property("to", message).to_s
    if to.empty? then
      WSFC::axis2_log_error(@env, "[wsf-ruby] End point not specified")
      return nil
    end
    
    to_end_point_ref = WSFC::axis2_endpoint_ref_create(@env, to)
    WSFC::axis2_options_set_to(client_options, @env, to_end_point_ref)
   
    # Create request payload 
    request_axiom_payload = message_to_axiom_node(message)
    if request_axiom_payload.nil? then
      WSFC::axis2_log_error(@env, "[wsf-ruby] Failed to create a valid AXIOM payload for request")
      return nil
    end
   
    # Set transaction level options
    set_transaction_options(message, client_options)

    # Handle Security
    handle_security

    # Handle Addressing options
    handle_addressing(message, client_options)

    # Handle outgoing attachments
    handle_outgoing_attachments(message, client_options, request_axiom_payload)
 
    response_axiom_payload = WSFC::axis2_svc_client_send_receive(@svc_client, @env, request_axiom_payload)

    if WSFC::axis2_svc_client_get_last_response_has_fault(@svc_client, @env) == WSFC::AXIS2_TRUE then # SOAP fault occurred
      last_soap_fault_e = last_soap_fault_exception
      
      if last_soap_fault_e.nil? then
        raise WSFault.new("SOAP-FAULT-ERROR", "Malformatted SOAP fault message")
      else
        raise last_soap_fault_e
      end
    else
      if response_axiom_payload.nil? then # No response from the server
        raise WSFault.new("NULL-REPLY", "No response from the server")
      else
        return axiom_node_to_message(response_axiom_payload)
      end
    end
  end

  # This method is used to do a send call.
  # message can be an XML string, a REXML object or a WSMessage.
  # A WSFault is thown if an error occurs while a message is being sent.
 
  def send(message)
    if @svc_client.nil? then
      WSFC::axis2_log_error(@env, "[wsf-ruby] Service client not created")
      return
    end
  
	client_options = WSFC::axis2_svc_client_get_options(@svc_client, @env)

    # Set end point 
    to = message_property("to", message).to_s
    if to.empty? then
      WSFC::axis2_log_error(@env, "[wsf-ruby] End point not specified")
      return
    end
    
    to_end_point_ref = WSFC::axis2_endpoint_ref_create(@env, to)
    WSFC::axis2_options_set_to(client_options, @env, to_end_point_ref)
    
    # Create request payload 
    request_axiom_payload = message_to_axiom_node(message)
    if request_axiom_payload.nil? then
      WSFC::axis2_log_error(@env, "[wsf-ruby] Failed to create a valid AXIOM node for request")
      return
    end
   
	# Set transaction level options
    set_transaction_options(message, client_options)

    # Handle Security
    handle_security

    # Handle Addressing options
    handle_addressing(message, client_options)

    # Handle outgoing attachments
    handle_outgoing_attachments(message, client_options, request_axiom_payload)

    status = WSFC::axis2_svc_client_send_robust(@svc_client, @env, request_axiom_payload)

    if WSFC::axis2_svc_client_get_last_response_has_fault(@svc_client, @env) == WSFC::AXIS2_TRUE then # SOAP fault occurred
      last_soap_fault_e = last_soap_fault_exception
      
      if last_soap_fault_e.nil? then
        raise WSFault.new("SOAP-FAULT-ERROR", "Malformatted SOAP fault message")
      else
        raise last_soap_fault_e
      end
    else
      if status == WSFC::AXIS2_FALSE then
        raise WSFault.new("SEND-ERROR", "Error occurred while sending message")
      end
    end
  end

  # This method is used to create an AXIOM node with respect to a message.
  # message can be an XML string, a REXML object or a WSMessage.
  
  def message_to_axiom_node(message)
    str_payload = ""
    
    if message.kind_of? String then
      str_payload = message
    elsif message.kind_of? REXML::Document then
      str_payload = message.to_s
    elsif message.kind_of? WSMessage then
      str_payload = message.payload_to_s
    end

    if str_payload.empty? then
      WSFC::axis2_log_error(@env, "[wsf-ruby] Payload not found")
      return nil
    end

    return WSFC::ruby_str_to_axiom_node(@env, str_payload, str_payload.length)
  end

  # This method is used to create a WSMessage with respect to a given AXIOM node
  # This is used to create the response message in a request call
  
  def axiom_node_to_message(axiom_node)
    str_payload = WSFC::ruby_axiom_node_to_str(@env, axiom_node)
	
	if str_payload.empty? then
      WSFC::axis2_log_error(@env, "[wsf-ruby] Failed to generate payload string from axiom node")
	  return nil
	end
    
    message = WSMessage.new(str_payload)

    handle_incoming_attachments(message, axiom_node)

    return message
  end

  # This method is used to get the value of the property with the given name
  # which is spcified when the client is created

  def client_property(property_name)
    return @options.has_key?(property_name) ? @options[property_name] : nil
  end

  # This method is used to get the value of property with the given name.
  # The given property can be something spcified when the client is created
  # If the message is of type WSMessage, the propery may be specified in the message
  # and in which case, that value gets the priority

  def message_property(property_name, message)
    if message.kind_of? WSMessage then
      msg_property = message.property(property_name)
      return msg_property unless msg_property.nil?
    end
    
    return @options.has_key?(property_name) ? @options[property_name] : nil
  end

  # This method is used to create a WSFault object when a SOAP fault occurs
  # It is required to throw a WSFault instance when a SOAP fault happens while
  # sending or requesting
 
  def last_soap_fault_exception
    soap_envelope = WSFC::axis2_svc_client_get_last_response_soap_envelope(@svc_client, @env)
    return nil if soap_envelope.nil?

    soap_body = WSFC::axiom_soap_envelope_get_body(soap_envelope, @env)
    return nil if soap_body.nil?

    soap_fault = WSFC::axiom_soap_body_get_fault(soap_body, @env)
    return nil if soap_fault.nil?
    
    # code
    soap_fault_code = WSFC::axiom_soap_fault_get_code(soap_fault, @env)
    soap_fault_code_value = soap_fault_code.nil? ? nil : WSFC::axiom_soap_fault_code_get_value(soap_fault_code, @env)
    code = soap_fault_code_value.nil? ? "" : WSFC::axiom_soap_fault_value_get_text(soap_fault_code_value, @env)

    # reason
    soap_fault_reason = WSFC::axiom_soap_fault_get_reason(soap_fault, @env)
    first_soap_fault_text = soap_fault_reason.nil? ? nil : WSFC::axiom_soap_fault_reason_get_first_soap_fault_text(soap_fault_reason, @env)
    reason = first_soap_fault_text.nil? ? "" : WSFC::axiom_soap_fault_text_get_text(first_soap_fault_text, @env)

    # role
    soap_fault_role = WSFC::axiom_soap_fault_get_role(soap_fault, @env)
    role = soap_fault_role.nil? ? "" : WSFC::axiom_soap_fault_role_get_role_value(soap_fault_role, @env)

    # detail
    soap_fault_detail = WSFC::axiom_soap_fault_get_detail(soap_fault, @env)
    fault_detail_ite = soap_fault_detail.nil? ? nil : WSFC::axiom_soap_fault_detail_get_all_detail_entries(soap_fault_detail, @env)
    
    detail = ""
    begin
      next_detail_node = WSFC::axiom_children_iterator_next(fault_detail_ite, @env)
      while !next_detail_node.nil?
        detail << WSFC::axiom_node_to_string(next_detail_node, @env)
        
        next_detail_node = WSFC::axiom_children_iterator_next(fault_detail_ite, @env)
      end
    end unless fault_detail_ite.nil?

    # xml
    soap_fault_base_node = WSFC::axiom_soap_fault_get_base_node(soap_fault, @env)
    xml = soap_fault_base_node.nil? ? "" : WSFC::axiom_node_to_string(soap_fault_base_node, @env)
    
    return WSFault.new(code, reason, role, detail, xml)
  end

  # This method is used to handle security
  
  def handle_security
     policy = client_property("policy")
     sec_token = client_property("security_token")

     return unless !policy.nil? # and !sec_token.nil?
     
     incoming_policy_node = policy.get_policy_as_axiom_node(@env)

     if not incoming_policy_node.nil?
        if WSFC::axiom_node_get_node_type(incoming_policy_node, @env) == WSFC::AXIOM_ELEMENT then
     	   root = WSFC::ruby_axiom_node_get_data_element(incoming_policy_node, @env)
           if not root.nil?
              neethi_policy = WSFC::neethi_engine_get_policy(@env, incoming_policy_node, root)
              svc = WSFC::axis2_svc_client_get_svc(@svc_client, @env)
              desc = WSFC::axis2_svc_get_base(svc, @env)
              policy_include = WSFC::axis2_desc_get_policy_include(desc, @env)
              WSFC::axis2_policy_include_add_policy_element(policy_include, @env, WSFC::AXIS2_SERVICE_POLICY, neethi_policy)
              svc_ctx = WSFC::axis2_svc_client_get_svc_ctx(@svc_client, @env)
              conf_ctx = WSFC::axis2_svc_ctx_get_conf_ctx(svc_ctx, @env)
              conf = WSFC::axis2_conf_ctx_get_conf(conf_ctx, @env)
              rampart_ctx = WSFC::rampart_context_create(@env)
              set_security_token_data_to_rampart_context(rampart_ctx, sec_token)
     	      security_param = WSFC::ruby_axutil_security_param_create(@env, WSFC::WS_RAMPART_CONFIGURATION, rampart_ctx)
 	      WSFC::axis2_conf_add_param(conf, @env, security_param)
     	   end
     	end
     end
     
     WSFC::axis2_svc_client_engage_module(@svc_client, @env, "rampart")
  rescue => exception
     puts "Exception : #{exception}"
  end

  def set_security_token_data_to_rampart_context(rampart_context, sec_token)
    return if sec_token.nil?
    
    option = sec_token.option("private_key") 
    if not option.nil?
       if (WSFC::ruby_rampart_context_set_prv_key(rampart_context, @env, option) == WSFC::AXIS2_SUCCESS) then
          WSFC::axis2_log_debug(@env, "[wsf_sec_policy] setting pvt key  ")
       end
       if (WSFC::rampart_context_set_prv_key_type(rampart_context, @env, WSFC::AXIS2_KEY_TYPE_PEM) == WSFC::AXIS2_SUCCESS) then 
          WSFC::axis2_log_debug(@env, "[wsf_sec_policy] setting pvt key format ")
       end
    end
   
    option = sec_token.option("certificate")
    if not option.nil?
       if (WSFC::ruby_rampart_context_set_certificate(rampart_context, @env, option) == WSFC::AXIS2_SUCCESS) then
          WSFC::axis2_log_debug(@env, "[wsf_sec_policy] setting pub key  ")
       end
       if (WSFC::rampart_context_set_certificate_type(rampart_context, @env, WSFC::AXIS2_KEY_TYPE_PEM) == WSFC::AXIS2_SUCCESS) then
          WSFC::axis2_log_debug(@env, "[wsf_sec_policy] setting pub key type ")
       end
    end

    option = sec_token.option("receiver_certificate")
    if not option.nil?
       if (WSFC::ruby_rampart_context_set_receiver_certificate(rampart_context, @env, option) == WSFC::AXIS2_SUCCESS) then
          WSFC::axis2_log_debug(@env, "[wsf_sec_policy] setting receiver pub key")
       end 
       if (WSFC::rampart_context_set_receiver_certificate_type(rampart_context, @env, WSFC::AXIS2_KEY_TYPE_PEM) == WSFC::AXIS2_SUCCESS) then
          WSFC::axis2_log_debug(@env, "[wsf_sec_policy] setting receiver pub key format")
       end
    end

    option = sec_token.option("user")
    if not option.nil?
       if (WSFC::rampart_context_set_user(rampart_context, @env, option) == WSFC::AXIS2_SUCCESS) then
          WSFC::axis2_log_debug(@env, "[wsf_sec_policy] setting username ")
       end 
    end

    option = sec_token.option("password")
    if not option.nil?
       if (WSFC::rampart_context_set_password(rampart_context, @env, option) == WSFC::AXIS2_SUCCESS) then
          WSFC::axis2_log_debug(@env, "[wsf_sec_policy] setting password ")
       end
    end

    option = sec_token.option("password_type")
    if not option.nil?
       if (WSFC::rampart_context_set_password_type(rampart_context, @env, option) == WSFC::AXIS2_SUCCESS) then
          WSFC::axis2_log_debug(@env, "[wsf_sec_policy] setting password type ")
       end
    end

    option = sec_token.option("ttl")
    if not option.nil?
       if (WSFC::rampart_context_set_ttl(rampart_context, @env, option) == WSFC::AXIS2_SUCCESS) then
          WSFC::axis2_log_debug(@env, "[wsf_sec_policy) setting ttl")
       end
    end

    #option = sec_token.option("password_callback")
    #if not option.nil?
    #   if (WSFC::ruby_rampart_context_set_pwcb_function(rampart_context, @env, nil, option) == WSFC::AXIS2_SUCCESS) then
    #      WSFC::axis2_log_debug(@env, "[wsf_sec_policy] setting callback function")
    #   end
    #end
  end  

  # This method is used to engage WS-Addressing specifications
  # All addressing specific manipulations have to be done inside this method
  
  def handle_addressing(message, client_options)
    return unless message.kind_of? WSMessage    

    use_wsa = client_property("use_wsa").to_s.upcase
    action = message_property("action", message).to_s

    if (use_wsa.eql? "1.0" or use_wsa.eql? "SUBMISSION" or use_wsa.eql? "TRUE") and (!action.empty?) then
      # Action
      WSFC::axis2_options_set_action(client_options, @env, action)
      
      # From
      from = message_property("from", message).to_s
      begin
        from_end_point_ref = WSFC::axis2_endpoint_ref_create(@env, from)
        WSFC::axis2_options_set_from(client_options, @env, from_end_point_ref)
      end unless from.empty?
     
      # Reply_to
      reply_to = message_property("reply_to", message).to_s
      begin
        reply_to_end_point_ref = WSFC::axis2_endpoint_ref_create(@env, reply_to)
        WSFC::axis2_options_set_reply_to(client_options, @env, reply_to_end_point_ref)
      end unless reply_to.empty?
      
      # Fault_to
      fault_to = message_property("fault_to", message).to_s
      begin
        fault_to_end_point_ref = WSFC::axis2_endpoint_ref_create(@env, fault_to)
        WSFC::axis2_options_set_fault_to(client_options, @env, fault_to_end_point_ref)
      end unless fault_to.empty?
      
      WSFC::axis2_svc_client_engage_module(@svc_client, @env, WSFC::AXIS2_MODULE_ADDRESSING)

      if use_wsa.eql? "SUBMISSION" then
        property = WSFC::ruby_axutil_property_create_with_args(@env,
                                                               WSFC::ruby_axutil_strdup(@env, WSFC::AXIS2_WSA_NAMESPACE_SUBMISSION))
        WSFC::ruby_axis2_options_set_property(client_options,
                                              @env,
                                              WSFC::AXIS2_WSA_VERSION,
                                              property)
      end
    end
  end

  # This method is used to handle attachments sent with a message
  # All MTOM/XOP specific manipulations have to be done inside this method

  def handle_outgoing_attachments(message, client_options, axiom_payload)
    return unless message.kind_of? WSMessage

    attachments = message_property("attachments", message)
    return if attachments.nil?
    return unless attachments.kind_of? Hash
    
    enable_mtom = client_property("use_mtom").to_s.upcase.eql?("FALSE") ? WSFC::AXIS2_FALSE : WSFC::AXIS2_TRUE
    
    default_content_type_ref = message_property("default_attachment_content_type", message)
    default_content_type = default_content_type_ref.nil? ? "application/octet-stream" : default_content_type_ref.to_s

    WSFC::axis2_options_set_enable_mtom(client_options, @env, enable_mtom)

    pack_attachments(axiom_payload, attachments, enable_mtom, default_content_type)  
  end  

  # This method is used to pack attachments specified using the "attachments" property
  # in the outgoing payload according to cid information specified in "Include" tags

  def pack_attachments(node, attachments, enable_mtom, default_content_type)
    return if node.nil?

    if WSFC::axiom_node_get_node_type(node, @env) == WSFC::AXIOM_ELEMENT then
      
      node_element = WSFC::ruby_axiom_node_get_data_element(node, @env)
      if !node_element.nil? then

        child_element_ite = WSFC::axiom_element_get_child_elements(node_element, @env, node)
        if !child_element_ite.nil? then

          child_node = WSFC::axiom_child_element_iterator_next(child_element_ite, @env)
          attachment_done = false

          while !child_node.nil? and !attachment_done do
            child_element = WSFC::ruby_axiom_node_get_data_element(child_node, @env)

            element_localname = WSFC::axiom_element_get_localname(child_element, @env)
            if !element_localname.nil? and  WSFC::ruby_axutil_strcmp(element_localname, "Include") == WSFC::AXIS2_TRUE then
        
              element_namespace = WSFC::axiom_element_get_namespace(child_element, @env, child_node)
              if !element_namespace.nil? then
          
                namespace_uri = WSFC::axiom_namespace_get_uri(element_namespace, @env)
                if !namespace_uri.nil? and WSFC::ruby_axutil_strcmp(namespace_uri, "http://www.w3.org/2004/08/xop/include") == WSFC::AXIS2_TRUE then
            
                  cnt_type = WSFC::axiom_element_get_attribute_value_by_name(node_element, @env, "xmlmime:contentType")
                  content_type = cnt_type.nil? ? default_content_type : cnt_type

                  href = WSFC::axiom_element_get_attribute_value_by_name(child_element, @env, "href")
                  href.lstrip!
                  href.rstrip!

                  if href.length > 4 then
            
                    cid = href[4..href.length - 1]

                    content = attachments[cid]
                    if !content.nil? then
                
                      WSFC::ruby_axiom_attach_content(@env,
                                                      child_node,
                                                      node,
                                                      enable_mtom,
                                                      content_type,
                                                      content,
                                                      content.length)

                      attachment_done = true
                
                    end

                  end

                end

              end

            end

            child_node = WSFC::axiom_child_element_iterator_next(child_element_ite, @env)
          end

        end

      end
      
    end

    # Process child nodes
    child_node = WSFC::axiom_node_get_first_child(node, @env)
    while !child_node.nil? do
      pack_attachments(child_node, attachments, enable_mtom, default_content_type)

      child_node = WSFC::axiom_node_get_next_sibling(child_node, @env)
    end

  end

  # This method is used to handle attachments received with a message
  # All MTOM/XOP specific manipulations have to be done inside this method

  def handle_incoming_attachments(message, axiom_payload)
    return unless message.kind_of? WSMessage
    
    response_xop = client_property("response_xop").to_s.upcase.eql?("TRUE") ? WSFC::AXIS2_TRUE : WSFC::AXIS2_FALSE
    
    unpack_attachments(axiom_payload, message) if response_xop == WSFC::AXIS2_TRUE 
  end

  # This method is used to unpack attachments received with the payload
  # The received attachments are saved as strings against the content id's
  # The content type is saved against the content id as well

  def unpack_attachments(node, message)
    return if node.nil?

    # Process current node
    if WSFC::axiom_node_get_node_type(node, @env) == WSFC::AXIOM_TEXT then
     
      text_element = WSFC::ruby_axiom_node_get_text_element(node, @env)
      if !text_element.nil? then
        
        data_handler = WSFC::axiom_text_get_data_handler(text_element, @env)
        if !data_handler.nil? then
          
          base64_content = WSFC::ruby_axiom_data_handler_get_base64_content(data_handler, @env)
          content_type = WSFC::axiom_data_handler_get_content_type(data_handler, @env)
          cid = WSFC::axiom_text_get_content_id(text_element, @env)

	      message.add_attachment_content(cid, base64_content)
          message.add_content_type(cid, content_type)

        end
        
      end
      
    end
    
    # Process child nodes
    child_node = WSFC::axiom_node_get_first_child(node, @env)
    while !child_node.nil? do
      unpack_attachments(child_node, message)

      child_node = WSFC::axiom_node_get_next_sibling(child_node, @env)
    end
  end

  private :set_client_options
  private :set_transaction_options
  private :message_to_axiom_node
  private :axiom_node_to_message
  private :client_property
  private :message_property
  private :last_soap_fault_exception
  private :handle_addressing
  private :handle_outgoing_attachments
  private :pack_attachments
  private :handle_incoming_attachments
  private :unpack_attachments

end
