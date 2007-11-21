#the global function to expose 
def echoFunction(in_msg)
    return in_msg
end

#the class to expose
class WSFApi
    def echoStringFunc in_msg
        return in_msg
    end

    def echoIntFunc in_msg
        return in_msg
    end
end

class WsserviceController < ApplicationController

  
  def echo
      require "wsf"
      #operation to ruby function map
      operations = {"echoString" => "echoFunction",
                    "echoInt" => "echoFunction"}

      wss = WSO2::WSF::WSService.new({:operations => operations});

      res = wss.reply(request, response);

      render :xml => res
  end

  def echo_addr
      require "wsf"
      #operation to ruby function map
      operations = {"echoString" => "echoFunction",
                    "echoInt" => "echoFunction"}

      #action to operation map
      actions = {"http://ruby.axis2.org/samples/echoString" => "echoString",
                "http://ruby.axis2.org/samples/echoInt" => "echoInt"}

      wss = WSO2::WSF::WSService.new({:operations => operations, :actions => actions});

      res = wss.reply(request, response);

      render :xml => res
  end

  def echo_classmap
      require "wsf"
      #operation to ruby function map
      class_operation_map = {"echoString" => "echoStringFunc",
                    "echoInt" => "echoIntFunc"}
      #action to operation map
      actions = {"http://ruby.axis2.org/samples/echoString" => "echoString",
                "http://ruby.axis2.org/samples/echoInt" => "echoInt"}

      wss = WSO2::WSF::WSService.new({:classes => [:WSFApi => class_operation_map], :actions => actions});

      res = wss.reply(request, response);

      render :xml => res
  end
end
