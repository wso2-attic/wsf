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

require 'WSFC'
require 'rexml/document'
require 'rexml/element'

include REXML

class WSSecurityToken
   
   # Constructs a new WSPolicy Object.
   # Policy can be a XML string, a REXML::Element or a Hash of options. 
   # Hash options should be specified as below
   # Hash.new(:security => a hash of security options)
   
   def initialize(policy)
      if policy.kind_of? String
         @policy = create_hash_from_string(policy)      
      elsif policy.kind_of? Hash
         @policy = policy  
      elsif policy.kind_of? Element
         @policy = create_hash_from_element(policy)
      else
	 # raise exception
      end
   end
   
   def option(option_name)
      return @policy.has_key?(option_name) ? @policy[option_name] : nil
   end 
      
   private
   def create_hash_from_string(policy)
      return nil 
   end

   def create_hash_from_element(policy)
      return nil
   end
end    
