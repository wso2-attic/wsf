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

require 'WSFC'

class WSUtil

  def WSUtil.file_put_base64_content(file_name, base64_content, content_type = "application/octet-stream")

    return false unless file_name.kind_of? String and
                        base64_content.kind_of? String and
                        content_type.kind_of? String

    return false if file_name.empty? or
                    base64_content.empty? or
                    content_type.empty?

    file_name_with_ext = file_name
    file_name_with_ext + ".jpg" if content_type == "image/jpeg"

    return WSFC::ruby_file_put_base64_content(file_name_with_ext, base64_content) ? true : false

  end

  def WSUtil.ws_get_cert_from_file(file_name)
    return extract_content_from_file(file_name, "-----BEGIN CERTIFICATE-----", "-----END CERTIFICATE-----") 
  end

  def WSUtil.ws_get_key_from_file(file_name)
    return extract_content_from_file(file_name, "-----BEGIN RSA PRIVATE KEY-----", "-----END RSA PRIVATE KEY-----") 
  end

  def WSUtil.extract_content_from_file(filename, prefix, suffix)
    input = File.new(filename)
    str = input.read
   
    prefix_index = str.index(prefix)
    suffix_index = str.index(suffix)
   
    return nil if prefix_index.nil?
    return nil if suffix_index.nil?

    content = str[prefix_index + prefix.length + 1, suffix_index - prefix_index - prefix.length - 2]
    return content 
  end
end


