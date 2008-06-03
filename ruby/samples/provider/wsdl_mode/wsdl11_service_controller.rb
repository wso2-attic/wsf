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

def QueryPurchaseOrderFunction(orderInfo)

  return_value = {"shipTo" => {"name" => "Jane Smith",
			       "street" => "YorkStreet",
			       "city" => "colombo",
                               "state" => "Sri Lanka",
                               "zip" => 32343 },
	
                  "billTo" => {"name" => "John Smith", 
                               "street" => "Maple Street", 
                               "city" => "LA", "state" => "USA", 
                               "zip" => 55432},
	
                   "product" => {"productId" => 2344, 
                                 "shippingDate" => "20080101", 
                                 "status" => "true"}};
                                                 
	return {"orderDetails" => return_value};
end

class Wsdl11ServiceController < ApplicationController
  
  skip_before_filter :verify_authenticity_token
  
  def index
    begin
      operations = {"QueryPurchaseOrder" => "QueryPurchaseOrderFunction"}
    
      wss = WSO2::WSF::WSService.new({"operations" => operations,
                                      "wsdl" => "sample_wsdl_11.wsdl"})

      res = wss.reply(request, response);

      render :xml => res
    end
  end
end
