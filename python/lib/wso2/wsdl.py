#!/usr/bin/env python

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

import os
import sys

import WSFC
from wso2.wsf import WSFMethodMissingMixin


class WSProxy(WSFMethodMissingMixin):
    
    def __init__(self, env, svc_client, client_options, wsdl, service_name, port_name):
        self.env = env
        self.svc_client = svc_client
        self.client_options = client_options
        self.wsdl = wsdl
        self.service_name = service_name
        self.port_name = port_name
    
    def method_missing(self, method, *args, **kwargs):
        if len(args) == 1:
            arg = args[0]
            if isinstance(arg, dict):
                result = WSFC.wsf_wsdl_request_function(
                        self.env,
                        self.svc_client,
                        self.client_options,
                        self.wsdl,
                        str(method),
                        arg,
                        self.service_name,
                        self.port_name,
                        wso2.wsf.WSF_PYTHON_HOME)
                return result
            else:
                print "Argument to Web Service operation must be a dictionary."
        else:
            print "Dynamic function only support one argument."
        
