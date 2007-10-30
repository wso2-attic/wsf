#!/usr/bin/env ruby

# Copyright 2005,2006 WSO2, Inc. http://wso2.com
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
#
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

require 'wsf'

req_payload_string = <<XML
<download/>
XML

client = WSClient.new({"axis2c_home" => "/home/danushka/wsf/axis2c",
                       "to" => "http://localhost:9090/samples/mtom/mtom_download_service.php",
                       "use_mtom" => "TRUE",
                       "response_xop" => "TRUE"})

req_message = WSMessage.new(req_payload_string)

begin
  res_message = client.request(req_message)
  return if res_message.nil?  

  puts res_message.payload_to_s

  # Save image/jpeg files
  attachments = res_message.property "attachments"
  cid_2_content_type = res_message.property "cid_2_content_type"
  
  if attachments and cid_2_content_type then

    cid_2_content_type.each_pair {|cid, content_type|
      
      content = attachments[cid]
      if content then

        if WSUtil.file_put_base64_content(cid, content, content_type) then
          puts "File saved SUCCESSFULLY !!!"
        else
          puts "Failed to save file !!!"
        end

      end
    }    

  else
    puts "Attachments not found !!!"
  end
rescue WSFault => wsfault
  puts "WSFault error..."
  puts wsfault.xml
  puts "----------"
  puts wsfault.code
  puts "----------"
  puts wsfault.reason
  puts "----------"
  puts wsfault.role
  puts "----------"
  puts wsfault.detail
  puts "----------"
end

