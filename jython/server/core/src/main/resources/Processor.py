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

from types import *
from java.util import HashMap
#import inspect

#count = 1
result = ''

def dictToJavaMap(dict):
     javaMap = HashMap()
     for i in dict.items():
          javaMap[i[0]]=i[1]
     #for i in javaMap:
     #     print javaMap[i[0]], ' == ' , javaMap[i[0]]
     return javaMap


def echo():
    print 'echo() invoked'


def getDictionary(str1):
    #print 'str1 == ' , str1
    string5 = str(str1)
    li2 = string5.split(" ")
    #print li2[3]
    string5 = li2[3].replace('>','')    
    string5 = string5.replace('\'','')
    #print 'string5 ' , string5
    ##strFile = '/home/heshan/workspace/IdeaProjects/PYtest/src/pythonScripts/annotationScript.py'
    ##print 'strFile ', strFile
    ##strFile = '/home/heshan/repo/scripts/annotationScript.py'
    ##fh = open(strFile,"r")
    fh = open(string5,"r")

    igot = fh.readlines()
    Dictionary = {}
    for line in igot:
        if line.find("@annotate") > -1:
                string1 = line[line.find("("):]
                string2 = string1[2:len(string1)-2]
                data = string2
                q = data.split(",")
                m = []
                t = ""
                con = False
                for k in range(len(q)):
                    s = q[k].strip()
                    #print 's ==' , s
                    if '(' in s:
                        con = True
                    if con == True and ')' not in s:
                        t += s + ','
                    if ')' in s:
                        t += s + ','
                        m.append(t)
                        t = ""
                        con = False
                    elif con == False:
                        m.append(s)
                string3 = ""
                for w in m:
                    #print 'value of w is == ', w
                    S = w
                    where = S.find('=')         # Search and find the first position
                    #print where
                    S = S[:where] + '-' + S[(where+1):]
                    #print 'value of s is'
                    #print S
                    #string3 = string3 + w + "$"
                    string3 = string3 + S + "$"
                string3 = string3.replace(",","~")
                #print 'string3 ==' , string3
                li = string3.split("$")
                key = li[1]
                #print li
                Dictionary[key] = li
    #print
    #print 'Dictionary'
    #print Dictionary
    return Dictionary

    
def analyze_func(obj, method=False):
   str1 = ''
   global result

   print '%s' % obj.__name__
   print 'object passed to func() is ' , obj

   if method:
       # testing --- object for the class
       sentence = '%s' % obj
       words = sentence.split()
       #print 'words ',words
       classObj = words.pop(2)
       classObj = classObj.replace(">","")
       print 'Method: ' , classObj
       #print 'Method: %s' % classObj_
       strme = classObj
       str1=strme
   else:
       print 'Function: %s' % obj.__name__
       strme = '%s' % obj.__name__
       #print 'strme value is' ,strme
       str1=strme

   # A tuple of four things is returned: (args, varargs, varkw, defaults)
   arginfo = inspect.getargspec(obj)
   # serach the inspect documentation for a method to get the method name
   args = arginfo[0]
   argsvar = arginfo[1]

   print 'result is ' , str1
   result = result + str1
   result = result + '@'

   if args:
       if args[0] == 'self':
           print '\t%s is an instance method' % obj.__name__
           args.pop(0)
       print '\tMethod Arguments: %s' % ' '.join(args)
       if arginfo[3]:
           dl = len(arginfo[3])
           al = len(args)
           defargs = args[al-dl:al]
           print 'Default arguments:',zip(defargs, arginfo[3])

   if arginfo[1]:
       print '\t Positional Args Param: %s' % arginfo[1]
   if arginfo[2]:
       print '\t Keyword Args Param: %s' % arginfo[2]


def analyze_klass(obj):
   #print 'Class: %s' % obj.__name__
   for name in obj.__dict__:
       item = getattr(obj, name)
       if type(item) is MethodType:
           analyze_func(item, True)


def classify(module):
   #print 'Module: %s' % module.__name__
   for name in dir(module):
       obj = getattr(module, name)
       if type(obj) in (ClassType, TypeType):
           analyze_klass(obj)
       elif type(obj) is FunctionType:
           analyze_func(obj)
   #print ' The final result is === ' , result
   return result


# defines how to annotate a python script
def annotate(returns, operationName, **params):
    def decorate(func):
        params['returns'] = returns
        params['operationName'] = operationName
        func.__annotations__ = params
        return func
    return decorate


if __name__ == "__main__":   
   import test
   #val=classify(test)
   Dict = {}
   Dict = getDictionary("test")
   print Dict

