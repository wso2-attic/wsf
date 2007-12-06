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
<ns1:ping xmlns:ns1="http://tempuri.org">
    <text>Ping !!!</text>
</ns1:ping>
XML

begin
  LOG_FILE_NAME = "ruby_ping_client_rm.log"
  END_POINT = "http://127.0.0.1:9090/axis2/services/RMSampleService"
  ACTION = "urn:wsrm:ping"

  client = WSClient.new({"use_wsa" => "TRUE",
                         "reliable" => "TRUE"},
                        LOG_FILE_NAME)

  message = WSMessage.new(req_payload_string,
                          nil,
                          {"to" => END_POINT,
                           "action" => ACTION})

  puts "Sending OM : " << "\n" << req_payload_string << "\n" 

  client.send(message)

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
