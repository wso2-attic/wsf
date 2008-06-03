#the class to expose
class WSFApi
    def initialize prefix, postfix
        @prefix = prefix
        @postfix = postfix
    end

    def echoStringFunc in_msg
        return @prefix + in_msg.payload_to_s + @postfix
    end

    def echoIntFunc in_msg
        return @prefix + in_msg.payload_to_s + @postfix
    end
end

class EchoClassmapServiceController < ApplicationController

  require "wsf"
  skip_before_filter :verify_authenticity_token
  
  def echo
	  #operation to ruby function map
      class_operation_map = {"echoString" => "echoStringFunc",
                    		 "echoInt" => "echoIntFunc"}
      
	  #action to operation map
      actions = {"http://ruby.wsf.wso2/samples/echoString" => "echoString",
                 "http://ruby.wsf.wso2/samples/echoInt" => "echoInt"}

      wss = WSO2::WSF::WSService.new({"classes" => ["WSFApi" => {"operations" => class_operation_map, 
                                                                 "args" => ["<wrapped>", "</wrapped>"]}],
									  "actions" => actions});

      res = wss.reply(request, response);

      render :text => res
  end
end
