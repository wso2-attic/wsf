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
  req_message = WSMessage.new(req_payload_string, nil, {"to" => "http://localhost:9090/axis2/services/echo",
                                                        "action" => "http://ws.apache.org/axis2/c/samples/echoString"})

  client = WSClient.new({"axis2c_home" => "/home/danushka/wsf/axis2c",
                         "use_wsa" => "TRUE"})

  puts "Using endpoint : http://localhost:9090/axis2/services/echo"
  puts "Sending OM : " << "\n" << req_payload_string << "\n" 

  res_message = client.request(req_message)

  if not res_message.nil? then
    puts "Received OM: "<< "\n" << res_message.payload_to_s << "\n\n"
    puts "echo client invoke SUCCESSFUL!"
  else
    puts "echo client invoke FAILED!"
  end
rescue WSFault => wsfault
  puts "echo client invoke FAILED!\n"
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
  puts "echo client invoke FAILED!\n"
  puts "Exception : " << exception
end
