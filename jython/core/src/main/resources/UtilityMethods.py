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

from java.util import HashMap

def dictToJavaMap(dict):
     javaMap = HashMap()
     for i in dict.items():
          javaMap[i[0]]=i[1]
     #print 'type conversion method invoked!'
     #for i in javaMap:
     #     print javaMap[i[0]], ' == ' , javaMap[i[0]]
     return javaMap

def echo():
    print "echo method invoked"