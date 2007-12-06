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

    wsdl_root_ele = Element.new WS_WSDL_const::WS_WSDL_DEFINITION
    wsdl_root_ele.add_namespace WS_WSDL_const::WS_SCHEMA_WSDL_NAMESPACE

    wsdl_root_ele.add_attributes({ WS_WSDL_const::WS_WSDL_DEF_XSD_QN => WS_WSDL_const::WS_SOAP_XML_SCHEMA_NAMESPACE,
                                   WS_WSDL_const::WS_WSDL_DEF_TNS_QN => @namespace,
                                   WS_WSDL_const::WS_WSDL_DEF_SOAP_ENV_QN => WS_WSDL_const::WS_SCHEMA_SOAP_NAMESPACE,
                                   WS_WSDL_const::WS_WSDL_DEF_WSDL_QN => WS_WSDL_const::WS_SCHEMA_WSDL_NAMESPACE,
                                   WS_WSDL_const::WS_WSDL_DEF_SOAP_ENC_QN => WS_WSDL_const::WS_SOAP_SCHEMA_ENCODING_NAMESPACE,
                                   WS_WSDL_const::WS_WSDL_DEF_HTTP_QN => WS_WSDL_const::WS_WSDL_HTTP12_NAMESPACE,
                                   WS_WSDL_const::WS_WSDL_DEF_SCHEMA_PREFIX => "#{@namespace}/xsd",
                                   WS_WSDL_const::WS_WSDL_DEF_TARGET_NS => @namespace })

    oper_obj = WS_WSDL_Operations.new(@f_name)
    created_type_arry = oper_obj.created_types
    operations_arry = oper_obj.operations
    xsd_arry = oper_obj.xsd_types
  end

end
