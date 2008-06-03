#the global function to expose 
def echoFunction(in_msg)
    return in_msg
end

class EchoServiceRmController < ApplicationController

  require "wsf"
  skip_before_filter :verify_authenticity_token

  def echo
      #operation to ruby function map
      operations = {"echoString" => "echoFunction"}

      wss = WSO2::WSF::WSService.new({:operations => operations,
	  								  :reliable => true});

      res = wss.reply(request, response);

      render :text => res
  end

end
