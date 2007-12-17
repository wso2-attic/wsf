require 'rexml/document'
require 'ws_wsdl_constants'

include REXML

class WS_WSDL_Type
  
  attr_reader :ns, :created_types, :fun_mapping, :simple_types, :cmplx_types, :schema_types

  def initialize(ns, array1, array2, mapping_array)
    @cmplx_types = {}
    @ns = ns
    @simple_types = WS_WSDL_Const::DEFAULT_TYPES
    @created_types = array1
    @schema_types = array2
    create_ruby_types
    @fun_mapping = mapping_array
  end

  def find_types(wsdl_type)
  end

  def build_complex_type(class_name)
    @cmplx_types[class_name] = []
    @created_types[class_name] = 
      { WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME => class_name,
      WS_WSDL_Const::WS_WSDL_NAMESPACE_ATTR_NAME => @ns }

    # foreach attribute get doc comments and do stuff
  end

  def create_ruby_types
    @cmplx_types['mixed'] = 
      [ { WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME => 'varString',
          'type' => 'string' },
        { WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME => 'varInt',
          'type' => 'int' },
        { WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME => 'varFloat',
          'type' => 'float' },
        { WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME => 'varArray',
          'type' => 'anyType' }
      ]
    @simple_types['mixed'] = 
      { WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME => 'mixed',
      WS_WSDL_Const::WS_WSDL_NAMESPACE_ATTR_NAME => @ns }

    @simple_types['array'] =
      { WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME => 'array',
      WS_WSDL_Const::WS_WSDL_NAMESPACE_ATTR_NAME => @ns }
  end

  def create_doclit_type(type_doc, type_root)
    types = Element.new WS_WSDL_Const::WS_WSDL_TYPES_ATTR_NAME
    types.add_namespace WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE
    type_root.add_element types

    el = Element.new WS_WSDL_Const::WS_WSDL_SCHEMA_ATTR_NAME
    el.add_namespace WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE
    el.add_attribute(WS_WSDL_Const::WS_WSDL_DEF_TARGET_NS, "#{@ns}/xsd")

    types.add_element el

    @schema_types.each_pair do |function_name, params|
      params.each_pair do |request_type, params2|
        ct = Element.new WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME
        ct.add_namespace WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE

        if request_type == WS_WSDL_Const::WS_WSDL_IN_ATTR_NAME
          @fun_mapping.each_pair do |key, value|
            ct.add_attribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, key) if value == function_name
          end # @fun_mapping
          el.add_element ct

          com_type = Element.new WS_WSDL_Const::WS_WSDL_COMPLXTYPE_ATTR_NAME
          com_type.add_namespace WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE
          ct.add_element com_type
          
          seq = Element.new WS_WSDL_Const::WS_WSDL_SEQUENCE_ATTR_NAME
          seq.add_namespace WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE
          com_type.add_element seq

          params2.each_pair do |param_name, xs_type|
            ele = Element.new WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME
            ele.add_namespace WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE

            ele.add_attribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, param_name)
            ele.add_attribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME, 
                              "#{WS_WSDL_Const::WS_WSDL_XSD_ATTR_NAME}#{xs_type}")
            seq.add_element ele
          end
        end
        
        if request_type == WS_WSDL_Const::WS_WSDL_OUT_ATTR_NAME
          @fun_mapping.each_pair do |key, value|
            ct.add_attribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME,
                             "#{key}#{WS_WSDL_Const::WS_WSDL_RESPONSE_ATTR_NAME}") if value == function_name
          end
          el.add_element ct
          
          com_type = Element.new WS_WSDL_Const::WS_WSDL_COMPLXTYPE_ATTR_NAME
          com_type.add_namespace WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE
          ct.add_element com_type

          seq = Element.new WS_WSDL_Const::WS_WSDL_SEQUENCE_ATTR_NAME
          seq.add_namespace WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE
          com_type.add_element seq

          params2.each_pair do |param_name, xs_type|
            ele = Element.new WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME
            ele.add_namespace WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE
            ele.add_attribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, param_name)
            ele.add_attribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME, 
                              "#{WS_WSDL_Const::WS_WSDL_XSD_ATTR_NAME}#{xs_type}")
            seq.add_element ele
          end
        end
      end
    end
  end

  def create_rpc_type(type_doc, type_root)
    types = Element.new WS_WSDL_Const::WS_WSDL_TYPES_ATTR_NAME
    types.add_namespace WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE
    
    type_root.add_attribute types

    el = Element.new WS_WSDL_Const::WS_WSDL_SCHEMA_ATTR_NAME
    el.add_namespace WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE

    el.add_attribute(WS_WSDL_Const::WS_WSDL_DEF_TARGET_NS, "#{@ns}/xsd")
    types.add_attribute el

    @cmplx_types.each_pair do |name, data|
      ct = Element.new WS_WSDL_Const::WS_WSDL_COMPLXTYPE_ATTR_NAME
      ct.add_namespace WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE
      ct.add_attribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, name)
      
      all = Element.new WS_WSDL_Const::WS_WSDL_ALL_ATTR_NAME
      all.add_namespace WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE

      data.each do |prop|
        p = Element.new WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME
        p.add_namespace WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE
        
        p.add_attribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME,
                        prop[WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME])
        p.add_attribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME,
                        prop[WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME])
        prefix = type_root.attributes.get_attribute(prop[WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME][WS_WSDL_Const::WS_WSDL_NAMESPACE_ATTR_NAME]).prefix
        p.add_attribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME, 
                        "#{prefix}:#{@simple_types[prop[WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME]][WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME]}")
        all.add_element p
      end
      ct.add_element all
      el.add_element ct
    end
  end

  def create_wsdl2_type(type_doc, type_root)
    types = Element.new WS_WSDL_Const::WS_WSDL_TYPES_ATTR_NAME
    types.add_namespace WS_WSDL_Const::WS_WSDL2_NAMESPACE

    type_root.add_element types
    el = Element.new WS_WSDL_Const::WS_WSDL_SCHEMA_ATTR_NAME
    el.add_namespace WS_WSDL_Const::WS_SOAP_XML_SCHEMA_NAMESPACE

    el.add_attribute(WS_WSDL_Const::WS_WSDL_ELEMENTFROMDEFAULT_ATTR_NAME,
                     WS_WSDL_Const::WS_WSDL_QUALIFIED_ATTR_NAME)

    types.add_element el
    
    @schema_types.each_pair do |function_name, params|
      params.each_pair do |request_type, params2|
        ct = Element.new WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME
        ct.add_namespace WS_WSDL_Const::WS_WSDL2_NAMESPACE

        if request_type == WS_WSDL_Const::WS_WSDL_IN_ATTR_NAME
          ct.add_attribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, function_name)
          el.add_element ct

          com_type = Element.new WS_WSDL_Const::WS_WSDL_COMPLXTYPE_ATTR_NAME
          com_type.add_namespace WS_WSDL_Const::WS_WSDL2_NAMESPACE
          
          ct.add_element com_type

          seq = Element.new WS_WSDL_Const::WS_WSDL_SEQUENCE_ATTR_NAME
          seq.add_namespace WS_WSDL_Const::WS_WSDL2_NAMESPACE

          com_type.add_element seq

          params2.each_pair do |param_name, xs_type|
            ele = Element.new WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME
            ele.add_namespace WS_WSDL_Const::WS_WSDL2_NAMESPACE

            ele.add_attribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, param_name)
            ele.add_attribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME, 
                              "#{WS_WSDL_Const::WS_WSDL_XSD_ATTR_NAME}#{xs_type}")
            seq.add_element ele
          end
        end

        if request_type == WS_WSDL_Const::WS_WSDL_OUT_ATTR_NAME
          ct.add_attribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME,
                           "#{function_name}#{WS_WSDL_Const::WS_WSDL_RESPONSE_ATTR_NAME}")
          el.add_attribute ct
          
          com_type = Element.new WS_WSDL_Const::WS_WSDL_COMPLXTYPE_ATTR_NAME
          com_type.add_namespace WS_WSDL_Const::WS_WSDL2_NAMESPACE

          ct.add_element com_type
          com_type.add_element seq

          params2.each_pair do |param_name, xs_type|
            ele = Element.new WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME
            ele.add_namespace WS_WSDL_Const::WS_WSDL2_NAMESPACE
            ele.add_attribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, param_name)
            ele.add_attribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME, 
                              "#{WS_WSDL_Const::WS_WSDL_XSD_ATTR_NAME}#{xs_type}")
            seq.add_element ele
          end
        end
      end
    end
  end

end
