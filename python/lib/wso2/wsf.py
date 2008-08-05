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
from wso2 import Logger
from wso2.wsdl import WSProxy 

__all__ = ['WSClient', 'WSFault']

WSF_PYTHON_HOME = os.path.dirname(__file__)

class WSFault(Exception):
    
    def __init__(self, code, reason, role='', detail='', xml=''):
        self.code = code
        self.reason = reason
        self.role = role
        self.detail = detail
        self.xml = xml
    
    def __str__(self):
        return '[' + self.code + ']' + self.reason + '|' + self.role + '|' + self.detail
    
class WSMessage:
    
    def __init__(self, str_payload, xml_dom_payload=None, properties=None):
        self.properties = {}
        self.str_payload = ''
        self.dom_payload = None
        
        self.properties = properties.copy()
        
        if str_payload is not None and isinstance(str_payload, str):
            self.str_payload = str_payload
        

class WSClient:
   
    def __init__(self, options, log_file_name=WSFC.WSF_DEFAULT_LOG_FILE_NAME):
        self.service_client = None
        self.options = {}

        # Copy user options into options dictionary of WSClient.
        self.options = options.copy()

        # Get the log directory and log level from user options. 
        # If user has not given these options defaults are used.
        if self.options.has_key(WSFC.WSF_CONF_LOG_DIR):
            log_dir = self.options[WSFC.WSF_CONF_LOG_DIR]
        else:
            log_dir = self.get_default_log_dir()

        if self.options.has_key(WSFC.WSF_CONF_LOG_LEVEL):
            log_level = int(self.options[WSFC.WSF_CONF_LOG_LEVEL])
        else:
            log_level = 4 

        # Create the log file path using user options.
        log_file = os.path.join(log_dir, log_file_name)

        # Create a Logger object to  use in WSClient.
        self.logger = Logger(log_file, log_level)

        # Create the axis2 environment.
        self.env = WSFC.axutil_env_create_all(log_file, log_level)
        if self.env is None:
            self.logger.log_critical("Failed to create WSFC environment....")
            return
        
        if self.options.has_key(WSFC.WSF_CONF_WSFC_HOME):
            wsfc_home = self.options[WSFC.WSF_CONF_WSFC_HOME]
        else: 
            wsfc_home = WSFC.WSF_DEFAULT_WSF_HOME
        
        # Create the service client.
        self.service_client = WSFC.axis2_svc_client_create(self.env, wsfc_home)
        if self.service_client is None:
            WSFC.axis2_log_critical(self.env, "[wsf-python] Failed to create service client.")
            return
        
        
        # Set service client options.
        svc_client_options = WSFC.axis2_svc_client_get_options( \
                self.service_client, self.env)
        if svc_client_options is None:
            svc_client_options = WSFC.axis2_options_create(self.env)
            WSFC.axis2_svc_client_set_options(self.service_client, \
                            self.env, svc_client_options)
        
        self.set_client_options(svc_client_options)
        
        pass
    
    # Set the service client options using options given by
    # user at the WSClient construction time.
    def set_client_options(self, svc_client_options):
        soap_version = None
        http_method = None
        
        # Proxy settings
        if self.options.has_key(WSFC.WSF_CP_PROXY_HOST) and \
            self.options.has_key(WSFC.WSF_CP_PROXY_PORT):
            WSFC.axis2_svc_client_set_proxy(self.service_client, self.env, \
                            self.options[WSFC.WSF_CP_PROXY_HOST], \
                            self.options[WSF_CP_PROXY_PORT])            
        # SOAP Settings
        if self.options.has_key(WSFC.WSF_CP_USE_SOAP):
            use_soap = self.options[WSFC.WSF_CP_USE_SOAP].upper()
        else:
            use_soap = 'TRUE'
        
        if use_soap == 'FALSE':
            WSFC.axis2_options_set_enable_rest(svc_client_options, self.env, \
                            WSFC.AXIS2_TRUE)
        elif use_soap == '1.1':
            soap_version = WSFC.AXIOM_SOAP11
        else:
            soap_version = WSFC.AXIOM_SOAP12
        
        if soap_version is not None:
            WSFC.axis2_options_set_soap_version(svc_client_options, self.env, \
                            soap_version)
            
        # Set HTTP Method if specified
        if self.options.has_key(WSFC.WSF_CP_HTTP_METHOD):
            http_method = self.options[WSFC.WSF_CP_HTTP_METHOD]
        else:
            http_method = 'POST'
        
        if http_method == 'GET':
            WSFC.axis2_options_set_http_method(svc_client_options, self.env, \
                            WSFC.AXIS2_HTTP_GET)      
        
        pass
    
    def request(self, message):
        to = None
        use_soap = None
        last_fault_e = None
        
        if self.service_client is None:
            WSFC.axis2_log_error(self.env, "[wsf-python] Service client is null.")
            return None
        
        client_options = WSFC.axis2_svc_client_get_options(self.service_client, \
                            self.env)
        
        # Get the end point address from client options.
        if self.options.has_key(WSFC.WSF_MP_TO):
             to = self.options[WSFC.WSF_MP_TO]
        
        if to is None:
            WSFC.axis2_log_error(self.env, "[wsf-python] End point not specified.")
            return None
        
        to_epr = WSFC.axis2_endpoint_ref_create(self.env, to)
        WSFC.axis2_options_set_to(client_options, self.env, to_epr)
        
        request_axiom = self.message_to_axiom(message)
        if request_axiom is None:
            WSFC.axis2_log_error(self.env, "[wsf-python] Failed to create AXIOM")
            return None
        
        WSFC.axis2_options_set_xml_parser_reset(client_options, self.env, WSFC.AXIS2_FALSE)
        
        if self.options.has_key(WSFC.WSF_CP_USE_SOAP):
            use_soap = self.options[WSFC.WSF_CP_USE_SOAP].upper()
        else:
            use_soap = 'TRUE'
        
        if use_soap != 'FALSE':
            if self.options.has_key(WSFC.WSF_MP_ACTION):
                action = self.options[WSFC.WSF_MP_ACTION]
                soap_action  = WSFC.axutil_string_create(self.env, action)
                WSFC.axis2_options_set_soap_action(client_options, self.env,\
                                soap_action)
                
        response_axiom = WSFC.axis2_svc_client_send_receive(self.service_client,\
                                self.env, request_axiom)
        
        if WSFC.axis2_svc_client_get_last_response_has_fault(self.service_client,\
                                self.env) == WSFC.AXIS2_TRUE:
            last_fault_e = self.last_fault_exception() 
            if last_fault_e is None:
                raise WSFault("SOAP-FAULT-ERROR", "Malformatted SOAP fault message")
            else:
                raise last_fault_e
        else:
            if response_axiom is None:
                raise WSFault("NULL-REPLY", "No response from the server")
            else:
                return self.axiom_to_str(response_axiom)         
        pass

    def get_proxy(self, service_name=None, port_name=None):
        if self.options is None:
            WSFC.axis2_log_error(self.env, "[wsf-python] Options to client cannot be NULL.")
            return None

        if self.options.has_key(WSFC.WSF_CP_WSDL):
            wsdl = self.options[WSFC.WSF_CP_WSDL]
            proxy = WSProxy(self.env, self.service_client, self.options, str(wsdl), service_name, port_name) 
            return proxy
        else:
            WSFC.axis2_log_error(self.env, "[wsf-python] WSDL is not specified.")
            return None


    def message_to_axiom(self, message):
        str_to_om = None
        if isinstance(message, str):
            str_to_om = message
        else:
            WSFC.axis2_log_error(self.env, "[wsf-python] Payload is not a string.")
            return None
        
        return WSFC.wsf_str_to_axiom_node(self.env, str_to_om, len(str_to_om))
    
    def axiom_to_str(self, axiom):
        str = WSFC.axiom_node_to_string(axiom, self.env)
        
        if str is None:
            WSFC.axis2_log_error(self.env, "[wsf-python] Error converting axion to string.")
            return None
        else:
            return str
        
        pass
    
    # This method is used to create a WSFault object when a SOAP fault occurs
    # It is required to throw a WSFault instance when a SOAP fault happens while
    # sending or requesting
    def last_fault_exception(self):
        fault = WSFC.wsf_last_soap_fault_exception(self.service_client, self.env)
        return WSFault(fault.code, fault.reason, fault.role, fault.detail, fault.xml)
    
        
        



