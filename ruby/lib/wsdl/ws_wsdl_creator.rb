require 'rexml/document'
require 'ws_wsdl_constants'
require 'ws_wsdl_operations'
require 'ws_wsdl_types'
require 'ws_wsdl_message'
require 'ws_wsdl_port'
require 'ws_wsdl_binding'
require 'ws_wsdl_service'
require 'ws_wsdl_interface'

include REXML

class WS_WSDL_Creator

  def initialize(obj_name, service, endpoints, binding_style, ns, wsdl_ver, op_arry)
    if not ns.empty?
      @namespace = endpoints
    else
      @namespace = ns
    end

    @endpoint = endpoints
    @f_name = obj_name
    @service_name = service
    @binding_style = binding_style
    
    @wsdl_version = "wsdl1" if wsdl_ver == "wsdl1.1"
    @wsdl_version = "wsdl2" if wsdl_ver == "wsdl2.0"

    @ops_to_functions = op_arry
  end

  def build_wsdl_dom
    wsdl_dom = Document.new
    wsdl_dom << XMLDecl.new
    wsdl_dom.xml_decl.encoding = WS_WSDL_Const::WS_DOM_DOCUMENT_ENCODING

    wsdl_root_ele = Element.new WS_WSDL_Const::WS_WSDL_DEFINITION
    wsdl_root_ele.add_namespace WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE

    wsdl_root_ele.add_attributes({ WS_WSDL_Const::WS_WSDL_DEF_XSD_QN => WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                   WS_WSDL_Const::WS_WSDL_DEF_TNS_QN => @namespace,
                                   WS_WSDL_Const::WS_WSDL_DEF_SOAP_ENV_QN => WS_WSDL_Const::WS_SCHEMA_SOAP_NAMESPACE,
                                   WS_WSDL_Const::WS_WSDL_DEF_WSDL_QN => WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE,
                                   WS_WSDL_Const::WS_WSDL_DEF_SOAP_ENC_QN => WS_WSDL_Const::WS_SOAP_SCHEMA_ENCODING_NAMESPACE,
                                   WS_WSDL_Const::WS_WSDL_DEF_HTTP_QN => WS_WSDL_Const::WS_WSDL_HTTP12_NAMESPACE,
                                   WS_WSDL_Const::WS_WSDL_DEF_SCHEMA_PREFIX => "#{@namespace}/xsd",
                                   WS_WSDL_Const::WS_WSDL_DEF_TARGET_NS => @namespace })

    oper_obj = WS_WSDL_Operations.new(@f_name)
    created_type_arry = oper_obj.created_types
    operations_arry = oper_obj.operations
    xsd_arry = oper_obj.xsd_types

    if @binding_style == "doclit"
      type_obj = WS_WSDL_Type.new(@namespace, created_type_arry, xsd_arry, @ops_to_functions)
      type_obj.create_doclit_type(wsdl_dom, wsdl_root_ele)
      simple_array = type_obj.simple_types

      msg_obj = WS_WSDL_Message.new(operations_arry, simple_array, @ops_to_functions)
      msg_obj.create_doclit_message(wsdl_dom, wsdl_root_ele)
    end

    if @binding_style == "rpc"
      type_obj = WS_WSDL_Type.new(@namespace, created_type_arry, operations_arry, @ops_to_functions)
      type_obj.created_rpc_type(wsdl_dom, wsdl_root_ele)
      simple_array = type_obj.simple_types

      msg_obj = WS_WSDL_Message.new(operations_arry, simple_array, @ops_to_functions)
      msg_obj.create_rpc_message(wsdl_dom, wsdl_root_ele)
    end

    port_obj = WS_WSDL_Port.new(@service_name, operations_arry, @ops_to_functions)
    port_obj.create_port_type(wsdl_dom, wsdl_root_ele)

    if @binding_style == "doclit"
      bind_obj = WS_WSDL_Binding.new(@service_name, @endpoint, operations_arry, @ops_to_functions)
      bind_obj.create_rpc_binding(wsdl_dom, wsdl_root_ele)
    end
    
    if @binding_style == "rpc"
      bind_obj = WS_WSDL_Binding.new(@service_name, @endpoint, operations_arry, @ops_to_functions)
      bind_obj.create_rpc_binding(wsdl_dom, wsdl_root_ele)
    end

    svr_obj = WS_WSDL_Service.new(@service_name, @endpoint)
    svr_obj.create_service(wsdl_dom, wsdl_root_ele)

    wsdl_dom.add_element wsdl_root_ele
    wsdl_dom.to_s
  end

  def build_wsdl2_dom

    wsdl_dom = Document.new
    wsdl_dom << XMLDecl.new
    wsdl_dom.xml_decl.encoding = WS_WSDL_Const::WS_DOM_DOCUMENT_ENCODING

    wsdl_root_ele = Element.new WS_WSDL_Const::WS_WSDL2_DESCRIPTION
    wsdl_root_ele.add_namespace WS_WSDL_Const::WS_WSDL2_NAMESPACE

    wsdl_root_ele.add_attribute(WS_WSDL_Const::WS_WSDL2_WSDLX_ATTR_NAME,
                                WS_WSDL_Const::WS_WSDL2_WSDLX_ATTR_VAL)

    wsdl_root_ele.add_attribute(WS_WSDL_Const::WS_WSDL_DEF_TNS_QN,
                                @namespace)
    
    wsdl_root_ele.add_attribute(WS_WSDL_Const::WS_WSDL2_WSOAP_ATTR_NAME,
                                WS_WSDL_Const::WS_WSDL2_WSOAP_ATTR_VAL)

    wsdl_root_ele.add_attribute(WS_WSDL_Const::WS_WSDL2_WHTTP_ATTR_NAME,
                                WS_WSDL_Const::WS_WSDL2_WHTTP_ATTR_VAL)

    wsdl_root_ele.add_attribute(WS_WSDL_Const::WS_WSDL_DEF_SOAP_ENC_QN,
                                WS_WSDL_Const::WS_WSDL2_SOAP_ATTR_VAL)
    
    wsdl_root_ele.add_attribute(WS_WSDL_Const::WS_WSDL_DEF_TARGET_NS,
                                @namespace)
    
    wsdl_doc_ele = Element.new WS_WSDL_Const::WS_WSDL2_DOCUMENTATION
    wsdl_doc_ele.add_text "A simple #{@service_name} service"
    wsdl_root_ele.add_element wsdl_doc_ele
  
    oper_obj = WS_WSDL_Operations.new(@f_name)
    created_type_arry = oper_obj.created_types
    operations_arry = oper_obj.operations
    xsd_arry = oper_obj.xsd_types

    type_obj = WS_WSDL_Type.new(@namespace, created_type_arry, xsd_arry, @ops_to_functions)

    type_obj.create_wsdl2_type(wsdl_dom, wsdl_root_ele)
    
    interface_obj = WS_WSDL_Interface(@service_name, operations_arry)

    interface_obj.create_wsdl2_binding(wsdl_dom, wsdl_root_ele)

    bind_obj = WS_WSDL_Binding(@service_name, @endpoint, nil, @ops_to_functions)

    bind_obj.create_wsdl2_binding(wsdl_dom, wsdl_root_ele)
    
    svr_obj = WS_WSDL_Service.new(@service_name, @endpoint)

    svr_obj.create_wsdl2_service(wsdl_dom, wsdl_root_ele)

    wsdl_dom.add_element wsdl_root_ele
    wsdl_dom.to_s
  end

  def ws_wsdl_out
    if @wsdl_version == "wsdl1"
      build_wsdl_dom
    else
      build_wsdl2_dom
    end
  end

end
