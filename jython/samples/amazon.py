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

req_payload_string = "<ItemSearch><Service>AWSECommerceService</Service> <SearchIndex>Books</SearchIndex><AWSAccessKeyId>XXXXXXXXXXXXXXXXXXX</AWSAccessKeyId><Operation>ItemSearch</Operation><Keywords>sri lanka travel books</Keywords></ItemSearch>"
LOG_FILE_NAME = "/home/heshan/IdeaProjects/MRclient/src/python_amazon.log"
END_POINT = "http://webservices.amazon.com/onca/xml"

try:
    client = WSClient({  "http_method" : "GET",
                         "use_soap" : "false"},
                      LOG_FILE_NAME)
    req_message = WSMessage(req_payload_string, {"to" :END_POINT})
    print " Sending OM      : " , req_payload_string
    res_message = client.request(req_message)
    print " Response Message: " , res_message

except WSFault, e:
    e.printStackTrace();


