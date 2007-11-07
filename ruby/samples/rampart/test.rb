#!/usr/bin/env ruby
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
require 'rexml/document'

include REXML

req_payload = <<XML
<ns1:echo xmlns:ns1="http://php.axis2.org/samples"><text>Hello World!</text></ns1:echo>
XML

def load_policy_from_file(filename)
   #returns REXML::Element
   input = File.new(filename)
   return input.read
end

begin
   str = "-----BEGIN CERTIFICATE---------END CERTIFICATE-----"
#load_policy_from_file("keys/alice_cert.cert")
   begin_string = "-----BEGIN CERTIFICATE-----"
   end_string = "-----END CERTIFICATE-----"
   begin_index = str.index(begin_string)
   end_index = str.index(end_string)

   return nil if begin_index.nil?
   return nil if end_index.nil? 
 
   puts "begin_index" << begin_index.to_s
   puts "end_index" << end_index.to_s

   puts str 
   certificate = str[begin_index + begin_string.length + 1, end_index - begin_index - begin_string.length - 2]
    certificate
rescue => exception
   puts "Client invocation FAILED !!!\n"
   puts "Exception : " << exception
end
