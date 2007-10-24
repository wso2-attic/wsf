class WSFault < StandardError
  
  def initialize (code, reason, role = "", detail = "", xml = "")
    @code = code
    @reason = reason
    @role = role
    @detail = detail
    @xml = xml
  end

  def to_s
    return "[" + @code + "]" + @reason + "|" + @role + "|" + @detail
  end

  attr_reader :code, :reason, :role, :detail, :xml

end
