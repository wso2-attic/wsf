require 'WSFC'
require 'wsf/wsmessage'
require 'wsf/wsfault'
require 'rexml/document'

class WSClient

  # Create a new WSClient object.
  # All the instance level initialization is done here
  
  def initialize(options)
    # Create Environment
    log_file_name = options.has_key?(:log_file_name) ? options[:log_file_name] : "wsf_ruby_client.log"
    @env = WSFC::axutil_env_create_all(log_file_name, WSFC::AXIS2_LOG_LEVEL_TRACE)
    if @env.nil? then
      WSFC::axis2_log_critical(@env, "[wsf-ruby] Failed to create WSF/C environment" )
      return
    end

    # Check if AXIS2C_HOME is set
    axis2c_home = ENV["AXIS2C_HOME"].to_s
    if axis2c_home.empty? then
      WSFC::axis2_log_critical(@env, "[wsf-ruby] Environment variable AXIS2C_HOME is not set")
      return
    end

    # Create service client
    @svc_client = WSFC::axis2_svc_client_create(@env, axis2c_home)
    if @svc_client.nil? then
      WSFC::axis2_log_critical(@env, "[wsf-ruby] Failed to create service client")
      return
    end
    
    @client_options = WSFC::axis2_svc_client_get_options(@svc_client, @env)
    
    @options = Hash.new
    options.each_pair {|k,v| @options.store(k,v)} if options.kind_of? Hash

    # Set proxy settings
    WSFC::axis2_svc_client_set_proxy(@svc_client,
                                     @env,
                                     @options[:proxy_host].to_s,
                                     @options[:proxy_port].to_s) if @options.has_key?(:proxy_host) and @options.has_key?(:proxy_port)

    # Set SOAP settings
    use_soap = @options.has_key?(:use_soap) ? @options[:use_soap].to_s.upcase : "TRUE"

    if use_soap.eql? "FALSE" then # REST style
      WSFC::axis2_options_set_enable_rest(@client_options, @env, WSFC::AXIS2_TRUE)
    else # SOAP style
      soap_version = use_soap.eql?("1.1") ? WSFC::AXIOM_SOAP11 : WSFC::AXIOM_SOAP12
      WSFC::axis2_options_set_soap_version(@client_options, @env, soap_version)
    end

    # HTTP method
    http_method = @options.has_key?(:http_method) ? @options[:http_method].to_s.upcase : "POST"

    if http_method.eql? "GET" then
      WSFC::axis2_options_set_http_method(@client_options, @env, WSFC::AXIS2_HTTP_GET)
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
   
    # Create request payload 
    request_axiom_payload = message_to_axiom_node(message)
    if request_axiom_payload.nil? then
      WSFC::axis2_log_error(@env, "[wsf-ruby] Failed to create a valid AXIOM payload for request")
      return nil
    end
   
    # Set end point 
    to = message_property(:to, message).to_s
    if to.empty? then
      WSFC::axis2_log_error(@env, "[wsf-ruby] Can not find end point for request")
      return nil
    end
    
    to_end_point_ref = WSFC::axis2_endpoint_ref_create(@env, to)
    WSFC::axis2_options_set_to(@client_options, @env, to_end_point_ref)
    
    # Set SOAP action
    action = message_property(:action, message).to_s
    begin
      soap_action_str = WSFC::axutil_string_create(@env, action)
      WSFC::axis2_options_set_soap_action(@client_options, @env, soap_action_str)
    end unless action.empty?

    # Handle Addressing options
    handle_addressing(message)

    # Handle outgoing attachments
    handle_outgoing_attachments(message, request_axiom_payload)
 
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
   
    # Create request payload 
    request_axiom_payload = message_to_axiom_node(message)
    if request_axiom_payload.nil? then
      WSFC::axis2_log_error(@env, "[wsf-ruby] Failed to create a valid AXIOM node for request")
      return
    end
   
    # Set end point 
    to = message_property(:to, message).to_s
    if to.empty? then
      WSFC::axis2_log_error(@env, "[wsf-ruby] Can not find end point for request")
      return
    end
    
    to_end_point_ref = WSFC::axis2_endpoint_ref_create(@env, to)
    WSFC::axis2_options_set_to(@client_options, @env, to_end_point_ref)
    
    # Set SOAP action
    action = message_property(:action, message).to_s
    begin
      soap_action_str = WSFC::axutil_string_create(@env, action)
      WSFC::axis2_options_set_soap_action(@client_options, @env, soap_action_str)
    end unless action.empty?

    # Hadle Addressing options
    handle_addressing(message)

    # Handle outgoing attachments
    handle_outgoing_attachments(message, request_axiom_payload)

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

    # Create XML reader
    xml_reader = WSFC::axiom_xml_reader_create_for_memory_new(@env,
                                                              str_payload,
                                                              str_payload.length,
                                                              "utf-8",
                                                              WSFC::AXIS2_XML_PARSER_TYPE_BUFFER)
    if xml_reader.nil? then
      WSFC::axis2_log_error(@env, "[wsf-ruby] Failed to create AXIOM XML reader")
      return nil
    end
   
    # Create StAX builder
    stax_builder = WSFC::axiom_stax_builder_create(@env, xml_reader)
    if stax_builder.nil? then
      WSFC::axis2_log_error(@env, "[wsf-ruby] Failed to create StAX builder")
      return nil
    end

    # Create document
    document = WSFC::axiom_stax_builder_get_document(stax_builder, @env)
    if document.nil? then
      WSFC::axis2_log_error(@env, "[wsf-ruby] Failed to create StAX builder document")
      return nil
    end

    # Create AXIOM node
    axiom_node = WSFC::axiom_document_get_root_element(document, @env)
    WSFC::axiom_document_build_all(document, @env) unless axiom_node.nil?

    WSFC::axiom_xml_reader_free(xml_reader, @env)
    WSFC::axis2_options_set_xml_parser_reset(@client_options, @env, WSFC::AXIS2_TRUE)
    
    return axiom_node
  end

  # This method is used to create a WSMessage with respect to a given AXIOM node
  # This is used to create the response message in a request call
  
  def axiom_node_to_message(axiom_node)
    # Create XML writer
    xml_writer = WSFC::axiom_xml_writer_create_for_memory(@env,
                                                          "utf-8",
                                                          WSFC::AXIS2_TRUE,
                                                          0,
                                                          WSFC::AXIS2_XML_PARSER_TYPE_BUFFER)
    return nil if xml_writer.nil?
    
    axiom_output = WSFC::axiom_output_create(@env, xml_writer)
    return nil if axiom_output.nil?

    WSFC::axiom_node_serialize(axiom_node, @env, axiom_output)
 
    str_payload = WSFC::axiom_xml_writer_get_xml_new(xml_writer, @env)

    message = WSMessage.new(str_payload)
    
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

  # This method is used to engage WS-Addressing specifications
  # All addressing specific manipulations have to be done inside this method
  
  def handle_addressing(message)
    return unless message.kind_of? WSMessage    

    use_wsa = client_property(:use_wsa).to_s.upcase
    action = message_property(:action, message).to_s

    if (use_wsa.eql? "1.0" or use_wsa.eql? "SUBMISSION" or use_wsa.eql? "TRUE") and (!action.empty?) then
      # Action
      WSFC::axis2_options_set_action(@client_options, @env, action)
      
      # From
      from = message_property(:from, message).to_s
      begin
        from_end_point_ref = WSFC::axis2_endpoint_ref_create(@env, from)
        WSFC::axis2_options_set_from(@client_options, @env, from_end_point_ref)
      end unless from.empty?
     
      # Reply_to
      reply_to = message_property(:reply_to, message).to_s
      begin
        reply_to_end_point_ref = WSFC::axis2_endpoint_ref_create(@env, reply_to)
        WSFC::axis2_options_set_reply_to(@client_options, @env, reply_to_end_point_ref)
      end unless reply_to.empty?
      
      # Fault_to
      fault_to = message_property(:fault_to, message).to_s
      begin
        fault_to_end_point_ref = WSFC::axis2_endpoint_ref_create(@env, fault_to)
        WSFC::axis2_options_set_fault_to(@client_options, @env, fault_to_end_point_ref)
      end unless fault_to.empty?
      
      WSFC::axis2_svc_client_engage_module(@svc_client, @env, WSFC::AXIS2_MODULE_ADDRESSING)

      if use_wsa.eql? "SUBMISSION" then
        property = WSFC::axutil_property_create_with_args(@env,
                                                          0,
                                                          WSFC::AXIS2_TRUE,
                                                          0,
                                                          WSFC::axutil_strdup(@env, WSFC::AXIS2_WSA_NAMESPACE_SUBMISSION))
        WSFC::axis2_options_set_property(@client_options,
                                         @env,
                                         WSFC::AXIS2_WSA_VERSION,
                                         property)
      end
    end
  end

  # This method is used to handle attachments sent with a message
  # All MTOM/XOP specific manipulations have to be done inside this method

  def handle_outgoing_attachments(message, axiom_payload)
    return unless message.kind_of? WSMessage

    attachments = message_property(:attachments)
    return if attachments.nil?
    return unless attachments.kind_of? Hash
    
    enable_mtom = client_property(:use_mtom).to_s.upcase.eql?("FALSE") ? WSFC::AXIS2_FALSE : WSFC::AXIS2_TRUE
    
    default_content_type_ref = message_property(:default_attachment_content_type, message)
    default_content_type = default_content_type_ref.nil? ? "application/octet-stream" : default_content_type_ref.to_s

    WSFC::axis2_options_set_enable_mtom(@client_options, @env, enable_mtom)

    pack_attachments(axiom_payload, attachments, enable_mtom, default_content_type)  
  end  

  # This method is used to pack attachments specified using the ":attachments" property
  # in the outgoing payload according to cid information specified in "Include" tags

  def pack_attachments(payload_node, attachments, enable_mtom, default_content_type)
    if WSFC::axiom_node_get_node_type(payload_node, @env) == WSFC::AXIOM_ELEMENT then
      
    end
  end

  # This method is used to handle attachments received with a message
  # All MTOM/XOP specific manipulations have to be done inside this method

  def handle_incoming_attachments(message)
    
  end  

  private :message_to_axiom_node
  private :axiom_node_to_message
  private :client_property
  private :message_property
  private :last_soap_fault_exception
  private :handle_addressing
  private :handle_outgoing_attachments
  private :pack_attachments
  private :handle_incoming_attachments

end
