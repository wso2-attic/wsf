# Copyright 2005,2008 WSO2, Inc. http://wso2.com
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
#
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

require 'wsf'

def GetPriceFunction(requestInfo)

  return_value = {"Price" => 234.431};
                                                 
	return {"GetPriceResponse" => return_value};
end

class Wsdl20ServiceController < ApplicationController

  skip_before_filter :verify_authenticity_token

  def index
    begin
      operations = {"GetPrice" => "GetPriceFunction"}
    
      wss = WSO2::WSF::WSService.new({"operations" => operations,
				      "wsdl" => "sample_wsdl_20.wsdl"})

      res = wss.reply(request, response);

      render :xml => res
    end
  end
end
