require 'rexml/document'
require 'ws_wsdl_constants'

include REXML

class WS_WSDL_Service
  
  def initialize(ser_name, ep)
    if not ser_name.empty?
      @s_name = ser_name
    else
      @s_name = "ws_default_service"
    end

    @endpoint = ep
  end

  def create_service(svr_dom, svr_root)
    svr_ele = Element.new WS_WSDL_Const::WS_WSDL_SERVICE_ATTR_NAME
    svr_ele.add_namespace WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE

    svr_ele.add_attribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, @s_name)
    
    svr_port = Element.new WS_WSDL_Const::WS_WSDL_PORT_ATTR_NAME
    svr_port.add_namespace WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE

    svr_port.add_attribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, @s_name)
    svr_port.add_attribute(WS_WSDL_Const::WS_WSDL_BINDING_ATTR_NAME,
                           "#{WS_WSDL_Const::WS_WSDL_TNS_ATTR_NAME}:#{@s_name}")

    svr_addr = Element.new WS_WSDL_Const::WS_WSDL_ADDRESS_ATTR_NAME
    svr_addr.add_namespace WS_WSDL_Const::WS_SCHEMA_SOAP_NAMESPACE

    svr_addr.add_attribute(WS_WSDL_Const::WS_WSDL_LOCATION_ATTR_NAME,
                           "#{WS_WSDL_Const::WS_WSDL_HTTP_ATTR_NAME}#{@endpoint}")
    svr_port.add_element svr_addr
    svr_ele.add_element svr_port
    svr_root.add_element svr_ele
  end

  def create_wsdl2_service(svr_dom, svr_root)
    svr_ele = Element.new WS_WSDL_Const::WS_WSDL_SERVICE_ATTR_NAME
    svr_ele.add_namespace WS_WSDL_Const::WS_WSDL2_NAMESPACE

    svr_ele.add_attribute(WS_WSDL_Const::WS_WSDL_SERVICE_ATTR_NAME, @s_name)
    svr_ele.add_attribute(WS_WSDL_Const::WS_WSDL_INTERFACE_ATTR_NAME,
                          "#{s_name}#{WS_WSDL_Const::WS_WSDL_INTERFACE_ATTR_NAME.capitalize}")
    
    svr_port = Element.new WS_WSDL_Const::WS_WSDL_ENDPOINT_ATTR_NAME
    svr_port.add_namespace WS_WSDL_Const::WS_WSDL2_NAMESPACE

    svr_port.add_attribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, @s_name)
    svr_port.add_attribute(WS_WSDL_Const::WS_WSDL_BINDING_ATTR_NAME, "tns#{s_name}")
    svr_port.add_attribute(WS_WSDL_Const::WS_WSDL_ADDRESS_ATTR_NAME, @endpoint)

    svr_ele.add_element svr_port
    svr_root.add_element svr_ele
  end

end
