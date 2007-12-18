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

module WSO2

  module Util

    class WSUtil

      WSF_UTIL_BEGIN_CERTIFICATE = "-----BEGIN CERTIFICATE-----"
      WSF_UTIL_END_CERTIFICATE = "-----END CERTIFICATE-----"
      WSF_UTIL_BEGIN_RSA_PVT_KEY = "-----BEGIN RSA PRIVATE KEY-----" 
      WSF_UTIL_END_RSA_PVT_KEY = "-----END RSA PRIVATE KEY-----"
  
      def WSUtil.ws_get_cert_from_file(file_name)
        return nil unless file_name.kind_of? String
    
        return extract_content_from_file(file_name, WSF_UTIL_BEGIN_CERTIFICATE, WSF_UTIL_END_CERTIFICATE) 
      end

      def WSUtil.ws_get_key_from_file(file_name)
        return nil unless file_name.kind_of? String

        return extract_content_from_file(file_name, WSF_UTIL_BEGIN_RSA_PVT_KEY, WSF_UTIL_END_RSA_PVT_KEY) 
      end

      def WSUtil.extract_content_from_file(filename, prefix, suffix)
        input = File.new(filename)
        str = input.read
   
        prefix_index = str.index(prefix)
        suffix_index = str.index(suffix)
   
        return nil if prefix_index.nil? or suffix_index.nil?

        content = str[prefix_index + prefix.length + 1, suffix_index - prefix_index - prefix.length - 2]
        return content 
      end
    end

  end

end
