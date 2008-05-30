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
<ns1:echoString xmlns:ns1="http://tempuri.org/">
    <ns1:Text>Hello World !!!</ns1:Text>
</ns1:echoString>
XML

begin
  LOG_FILE_NAME = "ruby_ping_client_rm_multiple_messages.log"
  END_POINT = "http://127.0.0.1:3000/echo_service_rm/echo"
  
  client = WSClient.new({"use_wsa" => "TRUE",
                         "reliable" => "TRUE",
                         "will_continue_sequence" => "TRUE"},
                        LOG_FILE_NAME)

  message1 = WSMessage.new(req_payload_string,
                           nil,
                           {"to" => END_POINT})

  message2 = WSMessage.new(req_payload_string,
                           nil,
                           {"to" => END_POINT})

  message3 = WSMessage.new(req_payload_string,
                           nil,
                           {"to" => END_POINT,
                            "last_message" => "TRUE"})

  puts "Sending OM 1 : " << "\n" << req_payload_string << "\n" 
  client.send(message1)

  puts "Sending OM 2 : " << "\n" << req_payload_string << "\n" 
  client.send(message2)

  puts "Sending OM 3 : " << "\n" << req_payload_string << "\n" 
  client.send(message3)

  sleep(40)
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
