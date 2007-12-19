#!/usr/bin/env ruby
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

require 'wsf'

include WSO2::WSF

req_payload = <<XML
<ns1:echo xmlns:ns1="http://php.axis2.org/samples"><text>Hello World!</text></ns1:echo>
XML

begin
   LOG_FILE = "security_sample.log"
   ACTION = "http://php.axis2.org/samples/echoString"
   END_POINT = "http://localhost:3000/username_token/usernametoken"

   message_properties = {"to" => END_POINT,
                         "action" => ACTION}

   payload = WSMessage.new(req_payload, 
                           nil, 
                           message_properties)

   policy_content = {"use_username_token" => true}

   policy = WSPolicy.new({"security" => policy_content})

   security_options = {"user" => "Raigama",
                       "password" => "RaigamaPW",
                       "password_type" => "Digest"}
 
   security_token = WSSecurityToken.new(security_options)

   options = {"use_wsa" => true,
              "policy" => policy,
              "security_token" => security_token}
   
   
   client = WSClient.new(options, LOG_FILE)

   res_message = client.request(payload)

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
