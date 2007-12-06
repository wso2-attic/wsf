
class WS_WSDL_Operations

  WS_OPERATION_INPUT_TAG = 'input';
  WS_OPERATION_OUTPUT_TAG = 'output';
  WS_OPERATION_TYPE_TAG = 'type';
  WS_OPERATION_RET_TAG = 'return';
  WS_OPERATION_NAME_TAG = 'name';

  mappingTable = [ "string"         =>  "string",
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
                   "token"          => "string" ]

  def initialize(operations)
    operations.each_pair do |i, value|
      @operation_name = operations[i]
      @xsd_map_arry[@operation_name] = []
      set_operations(@operation_name)
    end
  end

  def set_operations(operation_name)
    @operations[@operation_name][WS_OPERATION_INPUT_TAG] = []
    @operations[@operation_name][WS_OPERATION_OUTPUT_TAG] = []

    # get doc comments here, figure out a way to get a la doc commenting thing

    # ideally this logic executes when there's no doc comments
    # going ahead and executing them since we don't have them, yet.

    xsd_types[operation_name]["In"] = []
    operation.
  end

end
