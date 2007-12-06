#the class to expose
class WSFApi
    def echoStringFunc in_msg
        return in_msg
    end

    def echoIntFunc in_msg
        return in_msg
    end
end

class EchoClassmapServiceController < ApplicationController

  require "wsf"
  
  def echo_classmap
	  #operation to ruby function map
      class_operation_map = {"echoString" => "echoStringFunc",
                    		 "echoInt" => "echoIntFunc"}
      
	  #action to operation map
      actions = {"wso2:wsf:ruby:echo_string" => "echoString",
                 "wso2:wsf:ruby:echo_int" => "echoInt"}

      wss = WSO2::WSF::WSService.new({:classes => [:WSFApi => class_operation_map],
									  :actions => actions});

      res = wss.reply(request, response);

      render :text => res
  end
end
