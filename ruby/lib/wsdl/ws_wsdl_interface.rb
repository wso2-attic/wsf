require 'rexml/document'
require 'ws_wsdl_constants'

include REXML

class WS_WSDL_Interface
  
  WS_WSDL_INTERFACE_NAME_ATTR_NAME = 'name';
  WS_WSDL_INTERFACE_TYPE_ATTR_NAME = 'type';
  WS_WSDL_INTERFACE_OPERATION_ATTR_NAME = 'operation';
  WS_WSDL_INTERFACE_STYLE_ATTR_NAME = 'style';
  WS_WSDL_INTERFACE_INPUT_ATTR_NAME = 'input';
  WS_WSDL_INTERFACE_OUTPUT_ATTR_NAME = 'output';

  WS_WSDL2_INTERFACE_PROTOCAL_ATTR_NAME = "protocol";
  WS_WSDL2_INTERFACE_INTERFACE_ATTR_NAME = "interface";
  WS_WSDL2_INTERFACE_VERSION_ATTR_NAME = "version";
  WS_WSDL2_INTERFACE_VERSION_ATTR_VAL = "1.2";
  WS_WSDL2_INTERFACE_SOAP_ATTR_NAME = "soap";
  WS_WSDL2_INTERFACE_PATTERN_ATTR_NAME = "pattern";
  WS_WSDL2_INTERFACE_ELEMENT_ATTR_NAME = "element";

  def initialize(service_name, operations)
    @svr_name = service_name
    @operations = operations
  end

  def create_interface(interface_doc, interface_root)
    interface_ele = Element.new WS_WSDL2_INTERFACE_INTERFACE_ATTR_NAME
    interface_ele.add_namespace WS_WSDL_Const::WS_WSDL2_NAMESPACE

    interface_ele.add_attribute(WS_WSDL_INTERFACE_NAME_ATTR_NAME,
                                "#{@svr_name}#{WS_WSDL2_INTERFACE_INTERFACE_ATTR_NAME.capitalize}")
    @operations.each_pair do |name, params|
      op = Element.new WS_WSDL_INTERFACE_OPERATION_ATTR_NAME
      op.add_namespace WS_WSDL_Const::WS_WSDL2_NAMESPACE

      op.add_attribute(WS_WSDL_INTERFACE_NAME_ATTR_NAME, name)
      op.add_attribute(WS_WSDL2_INTERFACE_PATTERN_ATTR_NAME,
                       WS_WSDL_Const::WS_WSDL2_PATTERN_ATTR_VAL)

      [WS_WSDL_INTERFACE_INPUT_ATTR_NAME,
       WS_WSDL_INTERFACE_OUTPUT_ATTR_NAME].each do |type|
        operations_ele = Element.new type
        operations_ele.add_namespace WS_WSDL_Const::WS_WSDL2_NAMESPACE

        if type == WS_WSDL_INTERFACE_INPUT_ATTR_NAME
          operation_ele.add_attribute(WS_WSDL2_INTERFACE_PATTERN_ATTR_NAME, name)
        else
          operation_ele.add_attribute(WS_WSDL2_INTERFACE_PATTERN_ATTR_NAME, "#{name}Response")
        end
        op.add_element operation_ele
      end
      interface_ele.add_element op
    end
    interface_root.add_element interface_ele
  end

end
