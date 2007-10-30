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
<ns1:mtomSample xmlns:ns1="http://ws.apache.org/axis2/c/samples/mtom"><ns1:fileName>test.jpg</ns1:fileName><ns1:image><xop:Include href="cid:myid1" xmlns:xop="http://www.w3.org/2004/08/xop/include"/></ns1:image></ns1:mtomSample>
XML

content = IO.read("resources/axis2.jpg")

req_message = WSMessage.new(req_payload_string, nil, {"attachments" => {"myid1" => content}});

client = WSClient.new({"axis2c_home" => "/home/danushka/wsf/axis2c",
                       "to" => "http://localhost:9090/axis2/services/mtom",
                       "action" => "http://ws.apache.org/axis2/c/samples/mtomSample",
                       "use_mtom" => "FALSE",
                       "use_wsa" => "TRUE"})

begin
  res_message = client.request(req_message)
  
  puts res_message.payload_to_s
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
