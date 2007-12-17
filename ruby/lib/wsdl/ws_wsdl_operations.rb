
class WS_WSDL_Operations

  attr_reader :created_types, :operations, :xsd_types

  WS_OPERATION_INPUT_TAG = 'input';
  WS_OPERATION_OUTPUT_TAG = 'output';
  WS_OPERATION_TYPE_TAG = 'type';
  WS_OPERATION_RET_TAG = 'return';
  WS_OPERATION_NAME_TAG = 'name';

  mapping_table = { 
    "string"         =>  "string",
    "boolean"        =>  "boolean",
    "double"         =>  "float",
    "float"          =>  "float",
    "int"            =>  "int",
    "integer"        =>  "int",
    "byte"           =>  "int",
    "decimal"        =>  "string",
    "base64Binary"   =>  "string",
    "hexBinary"      =>  "string",
    "anyType"        =>  "soap Var Object",
    "any"            =>  "soap Var Object",
    "QName"          =>  "string",
    "dateTime"       =>  "string",
    "date"           =>  "string",
    "time"           =>  "string",
    "unsignedLong"   =>  "int",
    "unsignedInt"    =>  "int",
    "unsignedShort"  =>  "int",
    "unsignedByte"   =>  "int",
    "positiveInteger"=>  "int",
    "negativeInteger"=>  "int",
    "nonNegativeInteger"=>"int",
    "gYearMonth"     =>  "string",
    "gMonthDate"     =>  "string",
    "gYear"          =>  "string",
    "gMonth"         =>  "string",
    "gDay"           =>  "string",
    "duration"       =>  "string",
    "Name"           =>  "string",
    "NCName"         =>  "string",
    "NMTOKEN"        =>  "string",
    "NOTATION"       =>  "string",
    "NMTOKENS"       =>  "string",
    "ENTITY"         =>  "string",
    "ENTITIES"       =>  "string",
    "IDREF"          =>  "string",
    "IDREFS"         =>  "string",
    "anyURI"         =>  "string",
    "language"       =>  "string",
    "normalizedString"=> "string",
    "token"          => "string" }

  def initialize(operations)
    @xsd_map_arry = {}
    @operations = {}
    @xsd_types = {}
    @created_types = {}
    (0...operations.length).each do |i|
      @operation_name = operations[i]
      @xsd_map_arry[@operation_name] = []
      set_operations(@operation_name)
    end
  end

  def set_operations(operation_name)
    @operations[operation_name] = 
      { WS_OPERATION_INPUT_TAG => Array.new, WS_OPERATION_OUTPUT_TAG => Array.new }

    @xsd_types[operation_name] = {}
    @xsd_types[operation_name]["In"] = {}

    match = {}
    $wsf_meta[operation_name.intern][:param_names].each do |param|
       match[2] = param
      match[1] = "anyType"
      @xsd_types[operation_name]["In"][match[2]] = "anyType"
             
      @created_types[match[1]] = 2
      @operations[operation_name][WS_OPERATION_INPUT_TAG] =
        { WS_OPERATION_NAME_TAG => match[2], WS_OPERATION_TYPE_TAG => match[1] }

    end

    @xsd_types[operation_name]["Out"] = {}
    @xsd_types[operation_name]["Out"]["returnVal"] = "anyType"
    
    @created_types[match[1]] = 2
    @operations[operation_name][WS_OPERATION_OUTPUT_TAG] =
      { WS_OPERATION_NAME_TAG => WS_OPERATION_RET_TAG, WS_OPERATION_TYPE_TAG => match[1] }

  end

end
