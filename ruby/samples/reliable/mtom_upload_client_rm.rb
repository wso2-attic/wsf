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
<ns1:mtomSample xmlns:ns1="http://ws.apache.org/axis2/c/samples/mtom"><ns1:fileName>test.jpg</ns1:fileName><ns1:image><xop:Include href="cid:myid1" xmlns:xop="http://www.w3.org/2004/08/xop/include"/></ns1:image></ns1:mtomSample>
XML

begin
  LOG_FILE_NAME = "ruby_mtom_upload_client_rm.log"
  END_POINT = "http://127.0.0.1:9090/axis2/services/RMSampleService"
  ACTION = "http://php.axis2.org/samples/mtom"

  content = IO.read("resources/axis2.jpg")

  client = WSClient.new({"to" => END_POINT,
                         "action" => ACTION,
                         "use_mtom" => "TRUE",
                         "use_wsa" => "TRUE",
                         "reliable" => "TRUE"},
                        LOG_FILE_NAME)

  req_message = WSMessage.new(req_payload_string,
                              nil,
                              {"attachments" => {"myid1" => content}});

  puts "Sending OM : " << "\n" << req_payload_string << "\n"

  res_message = client.request(req_message)
  
  if not res_message.nil? then
    puts "Received OM: "<< "\n" << res_message.payload_to_s << "\n\n"
    puts "Client invocation SUCCESSFUL !!!"
  else
    puts "Client invocation FAILED !!!"
  end

  sleep(10)
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
