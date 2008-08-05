# Copyright 2005,2006,2007,2008 WSO2, Inc. http://wso2.com
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

# This is a top level interface file that would expose
# all the WSF/Ruby classes that are available


import logging

__author__ = "Milinda Pathirage <milinda@wso2.com>"
__status__ = "alpha"
__version__ = "o.1.0.0"
__date__ = "7 July 2008"


__all__ = ['Logger', 'wsf']

class Logger:

    logger_ = None

    def __init__(self, log_file, log_level):
        mapped_log_level = self.map_log_levels(log_level)
        logging.basicConfig(level=mapped_log_level,
                            format='%(asctime)s %(levelname)-8s %(message)s',
                            datefmt='[%a %b %d %H:%M:%S %Y]',
                            filename=log_file,
                            filemode='w')
        self.logger_ = logging.getLogger('')
        
    def map_log_levels(self, log_level):
        if log_level == 0:
            return logging.CRITICAL
        elif log_level == 1:
            return logging.ERROR
        elif log_level == 2:
            return logging.WARNING
        elif log_level == 3:
            return logging.INFO
        elif log_level == 4:
            return logging.DEBUG
        elif log_level == 5 or log_level == 6:
            return logging.NOTSET

    def shutdown(self):
        self.logger_.shutdown()
        
    def log_debug(self, msg):
        self.logger_.debug(msg)

    def log_info(self, msg):
        self.logger_.info(msg)

    def log_warn(self, msg):
        self.logger_.warn(msg)

    def log_error(self, msg):
        self.logger_.error(msg);

    def log_critical(self, msg):
        self.logger_.critical(msg)



