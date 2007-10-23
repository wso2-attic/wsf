require 'rexml/document'

class WSMessage
  
  def initialize (str_payload, rexml_payload = nil, properties = nil)
    @str_payload = ""
    @rexml_payload = nil
    @properties = Hash.new
    #@attachments = Hash.new
    @cid_2_content_type = Hash.new
    @soap_headers = Array.new

    @str_payload = str_payload if str_payload.kind_of? String
    @rexml_payload = rexml_payload if rexml_payload.kind_of? REXML::Document
    properties.each_pair {|k,v| @properties.store(k,v)} if properties.kind_of? Hash
  end

  
  def payload_to_s
    return @str_payload unless @str_payload.empty?
    return @rexml_payload.to_s unless @rexml_payload.nil?
    return ""
  end
  
  
  def property(property_name)
    return @properties.has_key?(property_name) ? @properties[property_name] : nil
  end

end
