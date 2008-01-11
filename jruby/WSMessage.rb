require 'WSF'

class WSMessage
    def initialize(str_payload,rexml_payload,options)
        @str_payload = str_payload
        @rexml_payload = rexml_payload
        @options = options
    end

    attr_reader :str_payload, :rexml_payload, :options

def payload_to_s
    @str_payload.to_s    
end

def property(propertyName)
    nm = propertyName
    @options[nm]
end

end
