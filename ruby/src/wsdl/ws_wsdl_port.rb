require 'rexml/document'
require 'ws_wsdl_constants'

include REXML

class WS_WSDL_Port

  def initialize(service, ops, ops_to_functions)
    @service_name = service
    @operations = ops
    @fun_mapping = ops_to_functions
  end

  def create_port_type(port_doc, port_root)
    port_el = Element.new WS_WSDL_Const::WS_WSDL_PORTTYPE_ATTR_NAME
    port_el.add_namespace WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE
    port_el.add_attribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, @service_name)

    @operations.each_pair do |name, params|
      operation = Element.new WS_WSDL_Const::WS_WSDL_OPERATION_ATTR_NAME
      operation.add_namespace WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE

      @fun_mapping.each_pair do |key, value|
        operation.add_attribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, key) if value == name
      end

      [WS_WSDL_Const::WS_WSDL_INPUT_ATTR_NAME, 
       WS_WSDL_Const::WS_WSDL_OUTPUT_ATTR_NAME].each do |type|
        sel = Element.new type
        sel.add_namespace WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE

        @fun_mapping.each_pair do |key, value|
          sel.add_attribute(WS_WSDL_Const::WS_WSDL_MESSAGE_ATTR_NAME,
                            "#{WS_WSDL_Const::WS_WSDL_TNS_ATTR_NAME}:#{key}#{type.capitalize}")
        end
        operation.add_element sel
      end
      port_el.add_element operation
    end
    port_root.add_element port_el
  end

end
