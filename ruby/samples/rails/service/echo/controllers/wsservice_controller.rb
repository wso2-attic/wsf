# The function which defines the logic of the service operation
def echoFunction(in_msg)
    return in_msg
end

class WsserviceController < ApplicationController

  def echo
      require "wsf"

      # The map to operation name => function defines the buisness logic
      operations = {"echoString" => "echoFunction",
                    "echoInt" => "echoFunction"}

      wss = WSO2::WSF::WSService.new({:operations => operations});

      res = wss.reply(request, response);

      render :xml => res
  end

  def echo_addr
      require "wsf"

      # The map to service operation name => function defines the buisness logic
      operations = {"echoString" => "echoFunction",
                    "echoInt" => "echoFunction"}
      
      # The map to wsa action => service operation name
      actions = {"http://ruby.axis2.org/samples/echoString" => "echoString",
                "http://ruby.axis2.org/samples/echoInt" => "echoInt"}

      wss = WSO2::WSF::WSService.new({:operations => operations, :actions => actions});

      res = wss.reply(request, response);

      render :xml => res
  end
end
