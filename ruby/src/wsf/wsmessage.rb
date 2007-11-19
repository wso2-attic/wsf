# Copyright 2005,2006,2007 WSO2, Inc. http://wso2.com
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

require 'rexml/document'

module WSO2

  module WSF

    class WSMessage
     
	  WSF_MSG_PROP_ATTACHMENTS = "attachments"
	  WSF_MSG_PROP_CID_2_CONTENT_TYPE = "cid_2_content_type"

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

	    attachments = property(WSF_MSG_PROP_ATTACHMENTS)
	    if attachments.nil? then
	  
	      attachments = Hash.new
	      @properties.store(WSF_MSG_PROP_ATTACHMENTS, attachments)

	    end

	    attachments.store(cid, content)
      end


      def add_content_type(cid, content_type)
	    return unless cid.kind_of? String
	    return unless content_type.kind_of? String

	    cid_2_content_type = property(WSF_MSG_PROP_CID_2_CONTENT_TYPE)
	    if cid_2_content_type.nil? then
	  
	      cid_2_content_type = Hash.new
	      @properties.store(WSF_MSG_PROP_CID_2_CONTENT_TYPE, cid_2_content_type)

	    end

	    cid_2_content_type.store(cid, content_type)
      end

    end
 
  end

end
