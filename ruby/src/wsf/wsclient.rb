require 'WSFC'
require 'wsf/wsmessage'
require 'wsf/wsfault'
require 'rexml/document'

class WSClient

  def initialize (options)
    return unless options.kind_of? Hash

    # Create Environment
    log_file_name = options.has_key?(:log_file_name) ? options[:log_file_name] : "wsf_ruby_client.log"
    @env = WSFC::axutil_env_create_all(log_file_name, WSFC::AXIS2_LOG_LEVEL_TRACE)
    if @env.nil? then
      WSFC::axis2_log_critical(@env, "[wsf-ruby] Failed to create WSF/C environment" )
      return
    end

    # Check if AXIS2C_HOME is set
    axis2c_home = ENV["AXIS2C_HOME"]
    if axis2c_home.nil? then
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
                                     @options[:proxy_host],
                                     @options[:proxy_port]) if @options.has_key?(:proxy_host) and @options.has_key?(:proxy_port)

    # Set SOAP settings
    use_soap = @options.has_key?(:use_soap) ? @options[:use_soap].to_s.upcase : "TRUE"

    puts use_soap   
 
    if use_soap.eql? "FALSE" then # REST style
      #rest_property = WSFC::axutil_property_create(@env)
      #WSFC::axutil_property_set_value(rest_property,
      #                                @env,
      #                                WSFC::AXIS2_VALUE_TRUE)
      #WSFC::axis2_options_set_property(@client_options,
      #                                 @env,
      #                                 WSFC::AXIS2_ENABLE_REST,
      #                                 rest_property)
      puts "REST Style"
      WSFC::axis2_options_set_enable_rest(@client_options, @env, WSFC::AXIS2_TRUE)
    else # SOAP style
      soap_version = use_soap.eql?("1.1") ? WSFC::AXIOM_SOAP11 : WSFC::AXIOM_SOAP12
      WSFC::axis2_options_set_soap_version(@client_options, @env, soap_version)
    end

    # HTTP method
    http_method = @options.has_key?(:http_method) ? @options[:http_method].to_s.upcase : "POST"

    if http_method.eql? "GET" then
      #http_get_property = WSFC::axutil_property_create(@env)
      #WSFC::axutil_property_set_value(http_get_property,
      #                                @env,
      #                                WSFC::AXIS2_HTTP_GET)
      #WSFC::axis2_options_set_property(@client_options,
      #                                 @env,
      #                                 WSFC::AXIS2_HTTP_METHOD,
      #                                 http_get_property)
      
      WSFC::axis2_options_set_http_method(@client_options, @env, WSFC::AXIS2_HTTP_GET)
      
    end
  end


  def request (message)
    if @svc_client.nil? then
      WSFC::axis2_log_error(@env, "[wsf-ruby] Service client not created")
      return nil
    end
    
    request_axiom_node = message_to_axiom_node(message)
    if request_axiom_node.nil? then
      WSFC::axis2_log_error(@env, "[wsf-ruby] Failed to create a valid AXIOM node for request")
      return nil
    end
   
    # Set end point 
    to = message_property(:to, message)
    if to.empty? then
      WSFC::axis2_log_error(@env, "[wsf-ruby] Can not find end point for request")
      return nil
    end
    
    to_end_point_ref = WSFC::axis2_endpoint_ref_create(@env, to)
    WSFC::axis2_options_set_to(@client_options, @env, to_end_point_ref)
    
    # Set SOAP action
    soap_action = message_property(:action, message)
    begin
      soap_action_str = WSFC::axutil_string_create(@env, soap_action)
      WSFC::axis2_options_set_soap_action(@client_options, @env, soap_action_str)
    end unless soap_action.empty?

    # Set Addressing options
    use_wsa = message_property(:use_wsa, message)
    if use_wsa.eql? "1.0" or use_wsa.eql? "submission" or use_wsa.eql? "TRUE" then
      WSFC::axis2_options_set_action(@client_options, @env, soap_action)
      
      from = message_property(:from, message)
      begin
        from_end_point_ref = WSFC::axis2_endpoint_ref_create(@env, from)
        WSFC::axis2_options_set_from(@client_options, @env, from_end_point_ref)
      end unless from.empty?
      
      reply_to = message_property(:reply_to, message)
      begin
        reply_to_end_point_ref = WSFC::axis2_endpoint_ref_create(@env, reply_to)
        WSFC::axis2_options_set_reply_to(@client_options, @env, reply_to_end_point_ref)
      end unless reply_to.empty?
      
      fault_to = message_property(:fault_to, message)
      begin
        fault_to_end_point_ref = WSFC::axis2_endpoint_ref_create(@env, fault_to)
        WSFC::axis2_options_set_fault_to(@client_options, @env, fault_to_end_point_ref)
      end unless fault_to.empty?
      
      WSFC::axis2_svc_client_engage_module(@svc_client, @env, "addressing")

      if use_wsa.eql? "submission" then
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

    response_axiom_node = WSFC::axis2_svc_client_send_receive(@svc_client, @env, request_axiom_node)

    if WSFC::axis2_svc_client_get_last_response_has_fault(@svc_client, @env) == WSFC::AXIS2_TRUE then # SOAP fault occurred
      last_soap_fault_instance = last_soap_fault
      
      if last_soap_fault_instance.nil? then
        raise StandardError, "Malformatted SOAP fault message"
      else
        raise last_soap_fault_instance
      end
    else
      response_message = axiom_node_to_message(response_axiom_node)
      return response_message
    end
  end

 
  def send (message)
    
  end

  
  def message_to_axiom_node (message)
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


  def message_property(property_name, message)
    if message.kind_of? WSMessage then
      msg_property = message.property(property_name)
      return msg_property unless msg_property.empty?
    end
    
    return @options.has_key?(property_name) ? @options[property_name] : ""
  end

  
  def axiom_node_to_message (axiom_node)
    # Create XML writer
    xml_writer = WSFC::axiom_xml_writer_create_for_memory(@env,
                                                          "utf-8",
                                                          WSFC::AXIS2_TRUE,
                                                          0,
                                                          WSFC::AXIS2_XML_PARSER_TYPE_BUFFER)

    if xml_writer.nil? then
      WSFC::axis2_log_error(@env, "[wsf-ruby] Failed to create AXIOM XML writer")
      return nil
    end
    
    axiom_output = WSFC::axiom_output_create(@env, xml_writer)

    WSFC::axiom_node_serialize(axiom_node, @env, axiom_output)
 
    str_payload = WSFC::axiom_xml_writer_get_xml_new(xml_writer, @env)

    message = WSMessage.new(str_payload)
    
    return message
  end

 
  def last_soap_fault
    soap_envelope = WSFC::axis2_svc_client_get_last_response_soap_envelope(@svc_client, @env)
    if soap_envelope.nil? then
      return nil
    end

    soap_body = WSFC::axiom_soap_envelope_get_body(soap_envelope, @env)
    if soap_body.nil? then
      return nil
    end

    soap_fault = WSFC::axiom_soap_body_get_fault(soap_body, @env)
    if soap_fault.nil? then
      return nil
    end
    
    # code
    soap_fault_code = WSFC::axiom_soap_fault_get_code(soap_fault, @env)
    soap_fault_code_value = WSFC::axiom_soap_fault_code_get_value(soap_fault_code, @env) unless soap_fault_code.nil?
    code = soap_fault_code_value.nil? ? "" : WSFC::axiom_soap_fault_value_get_text(soap_fault_code_value, @env)

    # reason
    soap_fault_reason = WSFC::axiom_soap_fault_get_reason(soap_fault, @env)
    first_soap_fault_text = WSFC::axiom_soap_fault_reason_get_first_soap_fault_text(soap_fault_reason, @env) unless soap_fault_reason.nil?
    reason = first_soap_fault_text.nil? ? "" : WSFC::axiom_soap_fault_text_get_text(first_soap_fault_text, @env)

    # role
    soap_fault_role = WSFC::axiom_soap_fault_get_role(soap_fault, @env)
    role = soap_fault_role.nil? ? "" : WSFC::axiom_soap_fault_role_get_role_value(soap_fault_role, @env)

    # detail
    soap_fault_detail = WSFC::axiom_soap_fault_get_detail(soap_fault, @env)
    detail = ""

    # xml
    soap_fault_base_node = WSFC::axiom_soap_fault_get_base_node(soap_fault, @env)
    xml = soap_fault_base_node.nil? ? "" : WSFC::axiom_node_to_string(soap_fault_base_node, @env)
    
    return WSFault.new(code, reason, role, detail, xml)
  end

  private :message_to_axiom_node
  private :message_property
  private :axiom_node_to_message
  private :last_soap_fault

end
