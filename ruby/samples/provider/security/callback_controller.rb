
require 'wsf'
require 'rexml/document'
require 'rexml/element'

def echoFunction(in_msg)
     "<wrapped>" + in_msg.payload_to_s + "</wrapped>"
end

def passwordCallBack(username)
	#logic to get password from any source (ex: using mysql database etc)

	return "RaigamaPW"
end
 

class CallbackController < ApplicationController
   
   skip_before_filter :verify_authenticity_token
   
   def callback
      	begin
			operations = {"echoString" => "echoFunction"}
    		actions = {"http://php.axis2.org/samples/echoString" => "echoString"}
		
			policy_content = {"use_username_token" => true}
			policy = WSO2::WSF::WSPolicy.new({"security" => policy_content})
														
			sec_token = WSO2::WSF::WSSecurityToken.new({"password_callback" => "passwordCallBack",
													  "password_type" => "Digest"})

			wss = WSO2::WSF::WSService.new({"operations" => operations,
											"actions" => actions,
											"policy" => policy,
											"security_token" => sec_token})
		  

			res = wss.reply(request, response);

			render :xml => res
		end
  	end
 
end
