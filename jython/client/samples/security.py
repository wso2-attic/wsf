#
# Copyright 2008 WSO2, Inc. http://www.wso2.org
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
#

from org.wso2.wsf.jython.client import WSClient
from org.wso2.wsf.jython.client import WSFault
from org.wso2.wsf.jython.client import WSMessage

LOG_FILE_NAME = "/home/heshan/IdeaProjects/MRclient/src/python_client.log"
POLICY_FILE_NAME = "/home/heshan/workspace/RampartCheckout/rampart/modules/rampart-samples/policy/sample01/policy.xml"
END_POINT = "http://localhost:8070/axis2/services/annotationScript/deduct"

req_payload_string = "<deduct><var1>1.8</var1><var2>4.87594</var2></deduct>"
content1 = "first attachment"
content2 = "second attachment"

try:
    client = WSClient({}, LOG_FILE_NAME)
    req_message = WSMessage(req_payload_string, {"to" : END_POINT,
                                                 "policy" : POLICY_FILE_NAME})
    print " Sending OM      : " , req_payload_string
    res_message = client.request(req_message)
    print " Response Message: " , res_message

except WSFault, e:
    e.printStackTrace();
