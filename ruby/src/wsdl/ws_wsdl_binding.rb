require 'ws_wsdl_constants'
require 'rexml/document'

include REXML

class WS_WSDL_Binding

  WS_WSDL2_BINDING_VERSION_ATTR_VAL = "1.2"

  def initialize(service_name, wsdl_ep, operations, ops_to_functions)
    @svr_name = service_name
    @operations = operations
    @wsdl_location = wsdl_ep
    @fun_mapping = ops_to_functions
  end
  
  def create_doclit_binding(binding_doc, binding_root)
    binding_ele = Element.new WS_WSDL_Const::WS_WSDL_BINDING_ATTR_NAME
    binding_ele.add_namespace WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE
    binding_ele.add_attribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME,
                              @svr_name)
    binding_ele.add_attribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME,
                              "#{WS_WSDL_Const::WS_WSDL_TNS_ATTR_NAME}:#{@svr_name}")
    s_binding = Element.new WS_WSDL_Const::WS_WSDL_BINDING_ATTR_NAME
    s_binding.add_namespace WS_WSDL_Const::WS_SCHEMA_SOAP_NAMESPACE
    s_binding.add_attribute(WS_WSDL_Const::WS_WSDL_TRANSPORT_ATTR_NAME, 
                            WS_WSDL_Const::WS_SCHEMA_SOAP_HTTP_NAMESPACE)
    s_binding.add_attribute(WS_WSDL_Const::WS_WSDL_STYLE_ATTR_NAME,
                            WS_WSDL_Const::WS_WSDL_DOCUMENT_ATTR_NAME)
    binding_ele.add_element s_binding

    @operations.each_pair do |name, params|
      op = Element.new WS_WSDL_Const::WS_WSDL_OPERATION_ATTR_NAME
      op.add_namespace WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE

      @fun_mapping.each_pair do |key, value|
        op.add_attribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, key)
      end

      action_ele = Element.new WS_WSDL_Const::WS_WSDL_OPERATION_ATTR_NAME
      action_ele.add_namespace WS_WSDL_Const::WS_SCHEMA_SOAP_NAMESPACE
      action_ele.add_attribute(WS_WSDL_Const::WS_WSDL_SOAP_ACTION_ATTR_NAME,
                               "#{WS_WSDL_Const::WS_WSDL_HTTP_ATTR_NAME}#{@wsdl_location}/#{name}")
      action_ele.add_attribute(WS_WSDL_Const::WS_WSDL_STYLE_ATTR_NAME,
                               WS_WSDL_Const::WS_WSDL_DOCUMENT_ATTR_NAME)
      op.add_element action_ele

      [WS_WSDL_Const::WS_WSDL_INPUT_ATTR_NAME, WS_WSDL_Const::WS_WSDL_OUTPUT_ATTR_NAME].each do |type|
        sbinding_ele = Element.new type
        sbinding_ele.add_namespace WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE
        s_body = Element.new  WS_WSDL_Const::WS_WSDL_BODY_ATTR_NAME
        s_body.add_namespace WS_WSDL_Const::WS_SCHEMA_SOAP_NAMESPACE,
        s_body.add_attribute(WS_WSDL_Const::WS_WSDL_USE_ATTR_NAME,
                             WS_WSDL_Const::WS_WSDL_LITERAL_ATTR_NAME)
        sbinding_ele.add_element s_body
        op.add_element sbinding_ele
      end

      binding_ele.add_element op
    end
    
    binding_root.add_element binding_ele
  end

  def create_rpc_binding(binding_doc, binding_root)
    binding_ele = Element.new WS_WSDL_Const::WS_WSDL_BINDING_ATTR_NAME
    binding_ele.add_namespace WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE
    binding_ele.add_attribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, @svr_name)
    binding_ele.add_attribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME,
                              "#{WS_WSDL_Const::WS_WSDL_TNS_ATTR_NAME}:#{@svr_name}")
    s_binding = Element.new WS_WSDL_Const::WS_WSDL_BINDING_ATTR_NAME
    s_binding.add_namespace WS_WSDL_Const::WS_SCHEMA_SOAP_NAMESPACE
    s_binding.add_attribute(WS_WSDL_Const::WS_WSDL_STYLE_ATTR_NAME,
                            WS_WSDL_Const::WS_WSDL_RPC_ATTR_NAME)
    s_binding.add_attribute(WS_WSDL_Const::WS_WSDL_TRANSPORT_ATTR_NAME,
                            WS_WSDL_Const::WS_SCHEMA_SOAP_HTTP_NAMESPACE)
    binding_ele.add_element s_binding

    @operations.each_pair do |name, params|
      op = Element.new WS_WSDL_Const::WS_WSDL_OPERATION_ATTR_NAME
      op.add_namespace WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE

      @fun_mapping.each_pair do |key, value|
        op.add_addtribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, $key) if value == name
      end
        
      [WS_WSDL_Const::WS_WSDL_INPUT_ATTR_NAME,
       WS_WSDL_Const::WS_WSDL_OUTPUT_ATTR_NAME].each do |type|

        sbinding_ele = Element.new type
        sbinding_ele.add_namespace WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE
        s_body = Element.new WS_WSDL_Const::WS_WSDL_BODY_ATTR_NAME
        s_body.add_namespace WS_WSDL_Const::WS_SCHEMA_SOAP_NAMESPACE
        s_body.add_attribute(WS_WSDL_Const::WS_WSDL_USE_ATTR_NAME,
                             WS_WSDL_Const::WS_WSDL_ENCODED_ATTR_NAME)
        s_body.add_attribute(WS_WSDL_Const::WS_WSDL_ENCOD_STYLE_ATTR_NAME,
                             WS_WSDL_Const::WS_SOAP_SCHEMA_ENCODING_NAMESPACE)
        sbinding_ele.add_element s_body
        op.add_element sbinding_ele
      end
      binding_ele.add_element op
    end
    binding_root.add_element binding_ele
  end


  def create_wsdl2_binding(binding_doc, binding_root)
    binding_ele = Element.new WS_WSDL_Const::WS_WSDL_BINDING_ATTR_NAME
    binding_ele.add_namespace WS_WSDL_Const::WS_WSDL2_NAMESPACE

    binding_ele.add_attribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME,
                              "#{@svr_name}#{WS_WSDL_Const::WS_WSDL_SOAP_ATTR_NAME.upcase}#{WS_WSDL_Const::WS_WSDL_BINDING_ATTR_NAME.capitalize}")
    binding_ele.add_attribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME,
                              WS_WSDL_Const:: WS_WSDL2_WSOAP_ATTR_VAL)
    binding_ele.add_attribute(WS_WSDL_Const::WS_WSDL_INTERFACE_ATTR_NAME,
                              "#{@svr_name}#{WS_WSDL_Const::WS_WSDL_INTERFACE_ATTR_NAME.capitalize}")
    binding_ele.add_attribute(WS_WSDL_Const::WS_WSDL_VERSION_ATTR_NAME,
                              WS_WSDL2_BINDING_VERSION_ATTR_VAL)
    binding_ele.add_attribute(WS_WSDL_Const::WS_WSDL_PROTOCAL_ATTR_NAME,
                              WS_WSDL_Const::WS_WSDL2_BINDING_ATTR_VAL)
    binding_root.add_element binding_ele
  end

end
