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

module WSO2

  module WSF

    class WSSecurityToken

       def initialize(policy)
	     return unless policy.kind_of? Hash
	     @policy = policy
       end

       
       def option(option_name)
		  return @policy.has_key?(option_name) ? @policy[option_name] : nil
       end 

    end   

  end

end 
