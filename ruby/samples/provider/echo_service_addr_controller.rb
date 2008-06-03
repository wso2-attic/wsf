#the global function to expose 
def echoFunction(in_msg)
    return in_msg
end

class EchoServiceAddrController < ApplicationController

  require "wsf"
  skip_before_filter :verify_authenticity_token
  
  def echo
      #operation to ruby function map
      operations = {"echoString" => "echoFunction",
	   				"echoInt" => "echoFunction"}

      #action to operation map
      actions = {"http://ruby.wsf.wso2/samples/echoString" => "echoString",
	  			 "http://ruby.wsf.wso2/samples/echoInt" => "echoInt"}

      wss = WSO2::WSF::WSService.new({:operations => operations,
									  :actions => actions});

      res = wss.reply(request, response);

      render :text => res
  end
  
end
