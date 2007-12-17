require 'rexml/document'
require 'ws_wsdl_constants'

include REXML

class WS_WSDL_Message

  attr_reader :simple_types, :fun_mapping, :operations
  
  def initialize(operations, simple_types, ops_to_functions)
    @operations = operations
    @simple_types = simple_types
    @fun_mapping = ops_to_functions
  end

  def create_doclit_message(msg_doc, msg_root)
    [WS_WSDL_Const::WS_WSDL_INPUT_ATTR_NAME,
     WS_WSDL_Const::WS_WSDL_OUTPUT_ATTR_NAME].each do |type|
      
      @operations.each_pair do |name, params|
        el = Element.new WS_WSDL_Const::WS_WSDL_MESSAGE_ATTR_NAME
        el.add_namespace WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE

        @fun_mapping.each_pair do |key, value|
          el.add_attribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, "#{key}#{type.capitalize}") if value == name
        end

        part = Element.new WS_WSDL_Const::WS_WSDL_PART_ATTR_NAME
        part.add_namespace WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE
        part.add_attribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME,
                           WS_WSDL_Const::WS_WSDL_PARAMETERS_ATTR_NAME)
        
        if WS_WSDL_Const::WS_WSDL_INPUT_ATTR_NAME.capitalize == type.capitalize
          @fun_mapping.each_pair do |k, v|
            part.add_attribute(WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME,
                               "#{WS_WSDL_Const::WS_WSDL_DEFAULT_SCHEMA_ATTR_NAME}:#{key}") if v == name
          end
        end

        if WS_WSDL_Const::WS_WSDL_OUTPUT_ATTR_NAME.capitalize == type.capitalize
          @fun_mapping.each_pair do |k, v|
            if v == name
              part.add_attribute(WS_WSDL_Const::WS_WSDL_ELEMENT_ATTR_NAME,
                                 "#{WS_WSDL_Const::WS_WSDL_DEFAULT_SCHEMA_ATTR_NAME}:#{key}#{WS_WSDL_Const::WS_WSDL_RESPONSE_ATTR_NAME}") 
            end
          end
        end

        el.add_element part
        msg_root.add_element el
      end
    end
  end

  def create_rpc_message(msg_doc, msg_root)
    @operations.each_pair do |name1, params|
      params.each_pair do |name2, params3|
        el = Element.new WS_WSDL_Const::WS_WSDL_MESSAGE_ATTR_NAME
        el.add_namespace WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE

        @fun_mapping.each_pair do |key, value|
          el.add_attribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME,
                           "#{k}#{n.capitalize}") if name1 == value
        end

        if name2 == WS_WSDL_Const::WS_WSDL_INPUT_ATTR_NAME
          params3.each_pair do |name3, params4|
            part = Element.new WS_WSDL_Const::WS_WSDL_PART_ATTR_NAME
            part.add_namespace WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE

            params4.each_pair do |name4, params5|
              if name4 == WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME
                part.add_attribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, param5)
              end

              if name4 == WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME
                part.add_attribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME,
                                   "#{WS_WSDL_Const::WS_WSDL_XSD_ATTR_NAME}#{param5}")
              end
              el.add_element part
            end
          end
        end
        
        if name2 == WS_WSDL_Const::WS_WSDL_OUTPUT_ATTR_NAME
          params3.each_pair do |name3, params4|
            part = Element.new WS_WSDL_Const::WS_WSDL_PART_ATTR_NAME
            part.add_namespace WS_WSDL_Const::WS_SCHEMA_WSDL_NAMESPACE

            params4.each_pair do |name4, params5|
              if name4 == WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME
                part.add_attribute(WS_WSDL_Const::WS_WSDL_NAME_ATTR_NAME, param5)
              end

              if name4 == WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME
                part.add_attribute(WS_WSDL_Const::WS_WSDL_TYPE_ATTR_NAME,
                                   "#{WS_WSDL_Const::WS_WSDL_XSD_ATTR_NAME}#{param5}")
              end
              el.add_element part
            end
          end
        end

        msg_root.add_element el
      end
    end
  end

end
