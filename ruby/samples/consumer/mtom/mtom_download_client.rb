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

include WSO2::WSF

req_payload_string = <<XML
<download/>
XML

begin
  LOG_FILE_NAME = "ruby_mtom_download_client.log"
  END_POINT = "http://localhost:3000/mtom_download_service/download"

  client = WSClient.new({"to" => END_POINT,
                         "response_xop" => "TRUE"},
                        LOG_FILE_NAME)

  puts "Sending OM : " << "\n" << req_payload_string << "\n"

  req_message = WSMessage.new(req_payload_string)

  res_message = client.request(req_message)

  if not res_message.nil? then
    puts "Received OM : " << "\n" << res_message.payload_to_s << "\n\n"
    
    # Save image/jpeg files
    attachments = res_message.property "attachments"
    cid_2_content_type = res_message.property "cid_2_content_type"
  
    if attachments and cid_2_content_type then

      cid_2_content_type.each_pair {|cid, content_type|
        content = attachments[cid]
        if content then

		  file_name = cid
		  file_name = file_name + ".jpg" if content_type == "image/jpeg"
		  
		  f = File.new(file_name, "wb")
		  f.write(content)
		  f.close

          puts "Downloaded file : " << file_name << "\n\n"

        end
      }

    else
      puts "Attachments not found !!!"
    end
    
    puts "Client invocation SUCCESSFUL !!!"
  else
    puts "Client invocation FAILED !!!"
  end
rescue WSFault => wsfault
  puts "Client invocation FAILED !!!\n"
  puts "WSFault : "
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
rescue => exception
  puts "Client invocation FAILED !!!\n"
  puts "Exception : " << exception
end
