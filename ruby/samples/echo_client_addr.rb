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
<ns1:echoString xmlns:ns1="http://ws.apache.org/axis2/services/echo">
    <text>Hello World!</text>
</ns1:echoString>
XML

begin
  AXIS2C_HOME = "/home/danushka/wsf/axis2c"
  LOG_FILE_NAME = "/tmp/ruby_echo_client_addr.log"
  END_POINT = "http://localhost:9090/axis2/services/echo"
  ACTION = "http://ws.apache.org/axis2/c/samples/echoString"

  client = WSClient.new({"use_wsa" => "TRUE"},
                        AXIS2C_HOME,
                        LOG_FILE_NAME)

  req_message = WSMessage.new(req_payload_string,
                              nil,
                              {"to" => END_POINT,
                               "action" => ACTION})

  puts "Sending OM : " << "\n" << req_payload_string << "\n" 

  res_message = client.request(req_message)

  if not res_message.nil? then
    puts "Received OM: "<< "\n" << res_message.payload_to_s << "\n\n"
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
