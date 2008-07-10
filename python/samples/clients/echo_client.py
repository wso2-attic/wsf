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

import wso2.wsf

LOG_DIR = '/tmp/'
LOG_LEVEL = 4
WSFC_HOME = '/home/milinda/wso2/wsfc/deploy'
END_POINT = 'http://localhost:9090/axis2/services/echo'

if __name__ == '__main__':
    message = """
    <ns1:echoString xmlns:ns1="http://ws.apache.org/axis2/services/echo">
        <text>Hello World!</text>
    </ns1:echoString>
    """
    try:
        client = wso2.wsf.WSClient({
            "to":END_POINT,
            "WSF_LOG_DIR":LOG_DIR,
            "WSF_LOG_LEVEL":LOG_LEVEL,
            "WSFC_HOME":WSFC_HOME
            })

        print 'Sending: ' + message

        response = client.request(message)

        print 'Respose: ' + response + '\n'
    except wso2.wsf.WSFault, e:
        print 'Exception occurred:'
        print e

