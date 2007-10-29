require 'rexml/document'

class WSMessage
  
  def initialize (str_payload, rexml_payload = nil, properties = nil)
    @str_payload = ""
    @rexml_payload = nil
    @properties = Hash.new
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

  
  def add_attachment_content(cid, content)
    return unless cid.kind_of? String
    return unless content.kind_of? String

    attachments = property("attachments")
    if attachments.nil? then
      
      attachments = Hash.new
      @properties.store("attachments", attachments)

    end

    attachments.store(cid, content)
  end


  def add_content_type(cid, content_type)
    return unless cid.kind_of? String
    return unless content_type.kind_of? String

    cid_2_content_type = property("cid_2_content_type")
    if cid_2_content_type.nil? then
      
      cid_2_content_type = Hash.new
      @properties.store("cid_2_content_type", cid_2_content_type)

    end

    cid_2_content_type.store(cid, content_type)
  end

end
