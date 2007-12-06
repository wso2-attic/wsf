#the global function to expose 
def echoFunction(in_msg)
    return in_msg
end

class EchoServiceAddrController < ApplicationController

  require "wsf"
  
  def echo_addr
      #operation to ruby function map
      operations = {"echoString" => "echoFunction",
	   				"echoInt" => "echoFunction"}

      #action to operation map
      actions = {"wso2:wsf:ruby:echo_string" => "echoString",
	  			 "wso2:wsf:ruby:echo_int" => "echoInt"}

      wss = WSO2::WSF::WSService.new({:operations => operations,
									  :actions => actions});

      res = wss.reply(request, response);

      render :text => res
  end
  
end
