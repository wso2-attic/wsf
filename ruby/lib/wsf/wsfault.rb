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

    class WSFault < StandardError
      
      def initialize (code, reason, role = "", detail = "", xml = "")
	    @code = code.to_s
	    @reason = reason.to_s
	    @role = role.to_s
	    @detail = detail.to_s
	    @xml = xml.to_s
      end

      def to_s
	    return "[" + @code + "]" + @reason + "|" + @role + "|" + @detail
      end

      attr_reader :code, :reason, :role, :detail, :xml

    end

  end

end
