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
require 'config/wsconfig'
require 'logger/wslogger'
require 'wsdl/ws_wsdl_proxy'
require 'rexml/document'

module WSO2

  module WSF

    class WSClient
      
      include WSO2::Config
      include WSO2::Logger

      # Create a new WSClient instance.
      # All instance level initialization is done here.
      
      def initialize(options, log_file_name = WSFC::WSF_DEFAULT_LOG_FILE_NAME)
        @svc_client = nil
        @options = nil

        
        # Init WSLogger
        log_path = WSConfig.read_dir(WSFC::WSF_CONF_LOG_DIR)
        log_file = log_path + log_file_name
        log_level = WSConfig.read_int(WSFC::WSF_CONF_LOG_LEVEL)
        
        WSLogger.init(log_file, log_level)
        
        # Create Environment
        @env = WSFC::axutil_env_create_all(log_file, log_level)
        if @env.nil? then
          WSLogger.log_critical("Failed to create WSF/C environment...")
          return
        end
        
        WSLogger.finalize
        
        # Check if WSFC_HOME is configured
        wsfc_home = WSConfig.read_dir(WSFC::WSF_CONF_WSFC_HOME)
        wsfc_home = WSFC::WSF_DEFAULT_WSF_HOME if wsfc_home.empty?
        
        # Create service client
        @svc_client = WSFC::axis2_svc_client_create(@env, wsfc_home)
        if @svc_client.nil? then
          WSFC::axis2_log_critical(@env, "[wsf-ruby] Failed to create service client")
          return
        end
        
        @options = Hash.new
        options.each_pair {|k,v| @options.store(k,v)} if options.kind_of? Hash
        
        # Set client level options
        client_options = WSFC::axis2_svc_client_get_options(@svc_client, @env)
        
        if client_options.nil? then
          client_options = WSFC::axis2_options_create(@env)
          WSFC::axis2_svc_client_set_options(@svc_client, @env, client_options)
        end
        
        set_client_options(client_options)
      end
      
      # This method is used to set client level settings according to 
      # the options specified when the client is created.
      
      def set_client_options(client_options)
        # Proxy settings
        WSFC::axis2_svc_client_set_proxy(@svc_client,
                                         @env,
                                         @options[WSFC::WSF_CP_PROXY_HOST].to_s,
                                         @options[WSFC::WSF_CP_PROXY_PORT].to_s) if @options.has_key?(WSFC::WSF_CP_PROXY_HOST) and 
          @options.has_key?(WSFC::WSF_CP_PROXY_PORT)
        
        # SOAP settings
        use_soap = @options.has_key?(WSFC::WSF_CP_USE_SOAP) ? @options[WSFC::WSF_CP_USE_SOAP].to_s.upcase : "TRUE"
        
        if use_soap.eql? "FALSE" then # REST style
          WSFC::axis2_options_set_enable_rest(client_options, @env, WSFC::AXIS2_TRUE)
        else # SOAP style
          soap_version = use_soap.eql?("1.1") ? WSFC::AXIOM_SOAP11 : WSFC::AXIOM_SOAP12
          WSFC::axis2_options_set_soap_version(client_options, @env, soap_version)
        end
	
        # HTTP method
        http_method = @options.has_key?(WSFC::WSF_CP_HTTP_METHOD) ? @options[WSFC::WSF_CP_HTTP_METHOD].to_s.upcase : "POST"
        
        if http_method.eql? "GET" then
          WSFC::axis2_options_set_http_method(client_options, @env, WSFC::AXIS2_HTTP_GET)
        end
	
        # SSL settings
        ca_cert = @options.has_key?(WSFC::WSF_CP_CA_CERT) ? @options[WSFC::WSF_CP_CA_CERT].to_s : ""
        client_cert = @options.has_key?(WSFC::WSF_CP_CLIENT_CERT) ? @options[WSFC::WSF_CP_CLIENT_CERT].to_s : ""
        pass_phrase = @options.has_key?(WSFC::WSF_CP_PASS_PHRASE) ? @options[WSFC::WSF_CP_PASS_PHRASE].to_s : ""
        
        WSFC::set_ssl_settings(@env, ca_cert, client_cert, pass_phrase, client_options)
      end
      
      # This method is used to set transaction level settings.
      # This is called for every request/send call.
      
      def set_transaction_options(message, client_options)
        WSFC::axis2_options_set_xml_parser_reset(client_options, @env, WSFC::AXIS2_FALSE)
        
        # SOAP settings
        use_soap = @options.has_key?(WSFC::WSF_CP_USE_SOAP) ? @options[WSFC::WSF_CP_USE_SOAP].to_s.upcase : "TRUE"
        
        if !use_soap.eql?("FALSE") then # SOAP style
          action = message_property(WSFC::WSF_MP_ACTION, message).to_s
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
        to = message_property(WSFC::WSF_MP_TO, message).to_s
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
        addressing_engaged = handle_addressing(message, client_options)

        # Handle RM options
        handle_reliable_messaging(message, client_options, addressing_engaged, false)
        
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
	    to = message_property(WSFC::WSF_MP_TO, message).to_s
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

	    # Hadle Addressing options
	    addressing_engaged = handle_addressing(message, client_options)

	    # Handle RM options
	    handle_reliable_messaging(message, client_options, addressing_engaged, true)

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

	    return WSFC::wsf_str_to_axiom_node(@env, str_payload, str_payload.length)
      end

      # This method is used to create a WSMessage with respect to a given AXIOM node
      # This is used to create the response message in a request call
      
      def axiom_node_to_message(axiom_node)
	    str_payload = WSFC::wsf_axiom_node_to_str(@env, axiom_node)
	    
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
        t = WSFC::wsf_last_soap_fault_exception(@svc_client, @env);	
        return WSFault.new(t.code, t.reason, t.role, t.detail, t.xml)
      end

      # This method is used to handle security
      
      def handle_security
        policy = client_property(WSFC::WSF_CP_POLICY)
        sec_token = client_property(WSFC::WSF_CP_SEC_TOKEN)
        
        return if policy.nil? 
        
        incoming_policy_node = policy.get_policy_as_axiom_node(@env)
        
        if WSFC::wsf_handle_client_security_for_ruby(@env, 
                                                     @svc_client, 
                                                     incoming_policy_node, 
                                                     sec_token) == WSFC::AXIS2_TRUE then

          WSFC::axis2_svc_client_engage_module(@svc_client, @env, WSFC::AXIS2_MODULE_RAMPART)
        end
      end

      # This method is used to engage WS-Addressing specifications
      # All addressing specific manipulations have to be done inside this method
      
      def handle_addressing(message, client_options)
        return false unless message.kind_of? WSMessage
        
        use_wsa = client_property(WSFC::WSF_CP_USE_WSA).to_s.upcase
        action = message_property(WSFC::WSF_MP_ACTION, message).to_s
        
        status = false
        
        if (use_wsa.eql? "1.0" or use_wsa.eql? "SUBMISSION" or use_wsa.eql? "TRUE") and (!action.empty?) then
          # Action
          WSFC::axis2_options_set_action(client_options, @env, action)
	  
          # From
          from = message_property(WSFC::WSF_MP_FROM, message).to_s
          begin
            from_end_point_ref = WSFC::axis2_endpoint_ref_create(@env, from)
            WSFC::axis2_options_set_from(client_options, @env, from_end_point_ref)
          end unless from.empty?
          
          # Reply_to
          reply_to = message_property(WSFC::WSF_MP_REPLY_TO, message).to_s
          begin
            reply_to_end_point_ref = WSFC::axis2_endpoint_ref_create(@env, reply_to)
            WSFC::axis2_options_set_reply_to(client_options, @env, reply_to_end_point_ref)
          end unless reply_to.empty?
	  
          # Fault_to
          fault_to = message_property(WSFC::WSF_MP_FAULT_TO, message).to_s
          begin
            fault_to_end_point_ref = WSFC::axis2_endpoint_ref_create(@env, fault_to)
            WSFC::axis2_options_set_fault_to(client_options, @env, fault_to_end_point_ref)
          end unless fault_to.empty?
	  
          WSFC::axis2_svc_client_engage_module(@svc_client, @env, WSFC::AXIS2_MODULE_ADDRESSING)
          
          if use_wsa.eql? "SUBMISSION" then
            property = WSFC::wsf_axutil_property_create_with_args(@env,
                                                                  WSFC::AXIS2_SCOPE_REQUEST,
                                                                  WSFC::AXIS2_TRUE,
                                                                  WSFC::wsf_axutil_strdup(@env, WSFC::AXIS2_WSA_NAMESPACE_SUBMISSION))
            WSFC::wsf_axis2_options_set_property(client_options,
                                                 @env,
                                                 WSFC::AXIS2_WSA_VERSION,
                                                 property)
          end
          
          status = true
        end
        
        return status
      end

      # This method is used to handle attachments sent with a message
      # All MTOM/XOP specific manipulations have to be done inside this method

      def handle_outgoing_attachments(message, client_options, axiom_payload)
        return unless message.kind_of? WSMessage
        
        attachments = message_property(WSFC::WSF_MP_ATTACHMENTS, message)
        return if attachments.nil?
        return unless attachments.kind_of? Hash
	
        enable_mtom = client_property(WSFC::WSF_CP_USE_MTOM).to_s.upcase.eql?("FALSE") ? WSFC::AXIS2_FALSE : WSFC::AXIS2_TRUE
	
        default_content_type_ref = message_property(WSFC::WSF_MP_DEF_ATT_CON_TYPE, message)
        default_content_type = default_content_type_ref.nil? ? WSFC::WSF_DEFAULT_CONTENT_TYPE : default_content_type_ref.to_s
        
        WSFC::axis2_options_set_enable_mtom(client_options, @env, enable_mtom)
        
        pack_attachments(axiom_payload, attachments, enable_mtom, default_content_type)  
      end  

      # This method is used to pack attachments specified using the "attachments" property
      # in the outgoing payload according to cid information specified in "Include" tags

      def pack_attachments(node, attachments, enable_mtom, default_content_type)
        return if node.nil?
        
        if WSFC::axiom_node_get_node_type(node, @env) == WSFC::AXIOM_ELEMENT then
	  
          node_element = WSFC::wsf_axiom_node_get_data_element(node, @env)
          if !node_element.nil? then
            
            child_element_ite = WSFC::axiom_element_get_child_elements(node_element, @env, node)
            if !child_element_ite.nil? then
              
              child_node = WSFC::axiom_child_element_iterator_next(child_element_ite, @env)
              attachment_done = false
              
              while !child_node.nil? and !attachment_done do
                child_element = WSFC::wsf_axiom_node_get_data_element(child_node, @env)
                
                element_localname = WSFC::axiom_element_get_localname(child_element, @env)
                if !element_localname.nil? and  WSFC::wsf_axutil_strcmp(element_localname, WSFC::AXIS2_ELEMENT_LN_INCLUDE) == WSFC::AXIS2_TRUE then
                  
                  element_namespace = WSFC::axiom_element_get_namespace(child_element, @env, child_node)
                  if !element_namespace.nil? then
                    
                    namespace_uri = WSFC::axiom_namespace_get_uri(element_namespace, @env)
                    if !namespace_uri.nil? and WSFC::wsf_axutil_strcmp(namespace_uri, WSFC::AXIS2_NAMESPACE_URI_INCLUDE) == WSFC::AXIS2_TRUE then
                      
                      cnt_type = WSFC::axiom_element_get_attribute_value_by_name(node_element, @env, WSFC::AXIS2_ELEMENT_ATTR_NAME_CONTENT_TYPE)
                      content_type = cnt_type.nil? ? default_content_type : cnt_type
                      
                      href = WSFC::axiom_element_get_attribute_value_by_name(child_element, @env, WSFC::AXIS2_ELEMENT_ATTR_NAME_HREF)
                      href.lstrip!
                      href.rstrip!
                      
                      if href.length > 4 then
                        
                        cid = href[4..href.length - 1]
                        
                        content = attachments[cid]
                        if !content.nil? then
                          
                          WSFC::wsf_axiom_attach_content(@env,
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
	
        response_xop = client_property(WSFC::WSF_CP_RES_XOP).to_s.upcase.eql?("TRUE") ? WSFC::AXIS2_TRUE : WSFC::AXIS2_FALSE
	
        unpack_attachments(axiom_payload, message) if response_xop == WSFC::AXIS2_TRUE 
      end

      # This method is used to unpack attachments received with the payload
      # The received attachments are saved as strings against the content id's
      # The content type is saved against the content id as well

      def unpack_attachments(node, message)
        return if node.nil?
        
        # Process current node
        if WSFC::axiom_node_get_node_type(node, @env) == WSFC::AXIOM_TEXT then
          
          text_element = WSFC::wsf_axiom_node_get_text_element(node, @env)
          if !text_element.nil? then
	    
            data_handler = WSFC::axiom_text_get_data_handler(text_element, @env)
            if !data_handler.nil? then
	      
              content = WSFC::wsf_axiom_data_handler_get_content(data_handler, @env)
              content_type = WSFC::axiom_data_handler_get_content_type(data_handler, @env)
              cid = WSFC::axiom_text_get_content_id(text_element, @env)
              
              message.add_attachment_content(cid, content)
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

      # This method is used to engage WS-ReliableMessaging specifications
      # All RM specific manipulations have to be done inside this method
      
      def handle_reliable_messaging(message, client_options, addressing_engaged, one_way)
        reliable = client_property(WSFC::WSF_CP_RELIABLE).to_s.upcase
        
        if reliable.eql?("TRUE") or reliable.eql?("1.0") or reliable.eql?("1.1") then
          
          # Set RM version
          rm_version = reliable.eql?("1.1") ? WSFC::WSF_RM_VERSION_1_1 : WSFC::WSF_RM_VERSION_1_0
          rm_version_str = reliable.eql?("1.1") ? WSFC::WSF_RM_VERSION_1_1_STR : WSFC::WSF_RM_VERSION_1_0_STR
          
          rm_property = WSFC::wsf_axutil_property_create_with_args(@env,
                                                                   WSFC::AXIS2_SCOPE_REQUEST,
                                                                   WSFC::AXIS2_FALSE,
                                                                   WSFC::wsf_axutil_strdup(@env, rm_version_str))
          
          WSFC::wsf_axis2_options_set_property(client_options,
                                               @env,
                                               WSFC::WSF_SANDESHA2_CLIENT_RM_SPEC_VERSION,
                                               rm_property)
          
          # Engage Addressing if not engaged already
          action = message_property(WSFC::WSF_MP_ACTION, message).to_s
          need_to_engage_addressing = (!addressing_engaged) and (!action.empty?)
          
          WSFC::axis2_svc_client_engage_module(@svc_client, @env, WSFC::AXIS2_MODULE_ADDRESSING) if need_to_engage_addressing
          
          # Engage Sandesha2
          WSFC::axis2_svc_client_engage_module(@svc_client, @env, WSFC::AXIS2_MODULE_SANDESHA2)
          
          # Set Sequence Expiry Time
          sequence_expiry_time = client_property(WSFC::WSF_CP_SEQ_EXP_TIME).to_s
          WSFC::wsf_set_module_param_value(@env,
                                           @svc_client,
                                           WSFC::AXIS2_MODULE_SANDESHA2,
                                           WSFC::WSF_SANDESHA2_CLIENT_INACT_TIMEOUT,
                                           sequence_expiry_time) unless sequence_expiry_time.empty?
          
          # Set Sequence Key
          sequence_key = client_property(WSFC::WSF_CP_SEQ_KEY).to_s
          sequence_key_property = WSFC::wsf_axutil_property_create_with_args(@env,
                                                                             WSFC::AXIS2_SCOPE_REQUEST,
                                                                             WSFC::AXIS2_TRUE,
                                                                             WSFC::wsf_axutil_strdup(@env, sequence_key))
          
          WSFC::wsf_axis2_options_set_property(client_options,
                                               @env,
                                               WSFC::WSF_SANDESHA2_CLIENT_SEQ_KEY,
                                               sequence_key_property)
          
          # Mark last message
          last_msg = true
          will_continue_sequence = client_property(WSFC::WSF_CP_WILL_CON_SEQ).to_s.upcase
          
          if will_continue_sequence.eql?("TRUE") and message.kind_of?(WSMessage) then
            
            last_message = message_property(WSFC::WSF_MP_LAST_MSG, message).to_s.upcase
            last_msg = false unless last_message.eql? "TRUE"
            
          end
          
          if (last_msg) and (rm_version == 1) then
            
            last_msg_property =  WSFC::wsf_axutil_property_create_with_args(@env,
                                                                            WSFC::AXIS2_SCOPE_REQUEST,
                                                                            WSFC::AXIS2_FALSE,
                                                                            WSFC::wsf_axutil_strdup(@env, WSFC::AXIS2_VALUE_TRUE))
            
            WSFC::wsf_axis2_options_set_property(client_options,
                                                 @env,
                                                 WSFC::WSF_SANDESHA2_CLIENT_LAST_MESSAGE,
                                                 last_msg_property)
            
          end
          
          if (!one_way) then
            
            # Set offered sequence id
            offered_sequence_id = WSFC::axutil_uuid_gen(@env)
            
            sequence_property = WSFC::axutil_property_create(@env)
            WSFC::wsf_axutil_property_set_value(sequence_property,
                                                @env,
                                                WSFC::wsf_axutil_strdup(@env, offered_sequence_id))
            
            WSFC::wsf_axis2_options_set_property(client_options,
                                                 @env,
                                                 WSFC::WSF_SANDESHA2_CLIENT_OFFERED_SEQ_ID,
                                                 sequence_property)
            
            # Set time out
            response_time_out = client_property(WSFC::WSF_CP_RES_TIME_OUT).to_s
            time_out = response_time_out.empty? ? WSFC::WSF_SANDESHA2_CLIENT_DEFAULT_TIME_OUT : response_time_out
            
            time_out_property = WSFC::wsf_axutil_property_create_with_args(@env,
                                                                           WSFC::AXIS2_SCOPE_REQUEST,
                                                                           WSFC::AXIS2_FALSE,
                                                                           WSFC::wsf_axutil_strdup(@env, time_out))
            
            WSFC::wsf_axis2_options_set_property(client_options,
                                                 @env,
                                                 WSFC::WSF_SANDESHA2_CLIENT_TIME_OUT,
                                                 time_out_property)
            
          end
          
        end
        
      end

      def get_proxy(service_name = nil, port_name = nil)
        if @options.nil? 
          WSFC::axis2_log_error(@env, "[wsf-ruby] options is null, this is unexpected..")
          return nil
        end
        wsdl = client_property(WSFC::WSF_CP_WSDL)
        
        unless wsdl.nil?
          proxy = WSO2::WSDL::WSProxy.new(@env, @svc_client, @options, wsdl.to_s, service_name, port_name)
          return proxy
        else
          WSFC::axis2_log_error(@env, "[wsf-ruby] wsdl is not set")
        end

        return nil
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
      private :handle_reliable_messaging
      private :handle_security

    end

  end

end
