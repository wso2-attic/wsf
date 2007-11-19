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

require 'logger'

module WSO2

  module Logger

    class WSLogger
      
	  @@file_logger = nil

	  # Create logger
	  def WSLogger.init(file_name, log_level = 0)
		return unless file_name.kind_of? String
		return if (log_level < 0) or (log_level > 4)

		@@file_logger = ::Logger.new(file_name)
		@@file_logger.level = log_level
	  end

	  # Check if WSLogger is initialized
	  def WSLogger.init?
        return !@@file_logger.nil?
	  end

	  def WSLogger.finalize
        @@file_logger.close unless @@file_logger.nil?
	  end

	  # Debug
      def WSLogger.log_debug(message)
	    @@file_logger.debug(message) unless @@file_logger.nil?
	  end

	  # Info
      def WSLogger.log_info(message)
	    @@file_logger.info(message) unless @@file_logger.nil?
	  end

	  # Warning
      def WSLogger.log_warning(message)
	    @@file_logger.warn(message) unless @@file_logger.nil?
	  end

	  # Error
      def WSLogger.log_error(message)
	    @@file_logger.error(message) unless @@file_logger.nil?
	  end

	  # Fatal
      def WSLogger.log_critical(message)
	    @@file_logger.fatal(message) unless @@file_logger.nil?
	  end

    end

  end

end
