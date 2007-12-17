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

require 'rbconfig'

module WSO2

  module Config

    class WSConfig

	  WSF_CONF_TRUE = ["TRUE", "T", "Y", "YES"]
	  WSF_CONF_DIR = "/tmp/"

	  # Read String
      def WSConfig.read_string(key)
	    return "" unless key.kind_of? String

		value = ::Config::CONFIG[key].to_s
		value.lstrip
		value.rstrip

        return value
	  end
      
	  # Read Integer
	  def WSConfig.read_int(key)
	    return read_string(key).to_i
	  end
      
	  # Read Float
	  def WSConfig.read_float(key)
        return read_string(key).to_f
	  end
      
	  # Read Bool
	  def WSConfig.read_bool(key)
	    value = read_string(key).upcase

		return WSF_CONF_TRUE.include?(value)
	  end

	  # Read Directory
	  def WSConfig.read_dir(key)
        value = read_string(key)
        value = WSF_CONF_DIR if value.empty?

		value << '/' unless value[value.length - 1] == '/'

		return value
	  end

    end

  end

end
