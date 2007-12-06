
require 'wsf'
require 'rexml/document'

def echoFunction(in_msg)
     "<wrapped>" + in_msg + "</wrapped>"
end

def passwordCallBack(username)
	#logic to get password from any source (ex: using mysql database etc)

	return "RaigamaPW"
end 

class RampartController < ApplicationController
  
  	def callback
      	operations = {"echoString" => "echoFunction", "echoInt" => "echoFunction"};
	  	actions = {"http://php.axis2.org/samples/echoString" => "echoString"};
		
	 	policy_content = {"use_username_token" => true}
	  	policy = WSO2::WSF::WSPolicy.new({"security" => policy_content})
													
      	sec_token = WSO2::WSF::WSSecurityToken.new({"password_callback" => "passwordCallBack",
                                       			    "password_type" => "Digest"})

	  	wss = WSO2::WSF::WSService.new({"operations" => operations,
                               		    "actions" => actions,
                              		    "policy" => policy,
                               		    "securityToken" => sec_token})
      

      	res = wss.reply(request, response);

      	render :xml => res
  	end

  	
	def timestamp
        operations = {"echoString" => "echoFunction", "echoInt" => "echoFunction"};
        actions = {"http://php.axis2.org/samples/echoString" => "echoString"};
		
		policy_content = {"include_time_stamp" => true}
        policy = WSO2::WSF::WSPolicy.new({"security" => policy_content})

        sec_token = WSO2::WSF::WSSecurityToken.new({"ttl" => 100})

        wss = WSO2::WSF::WSService.new({"operations" => operations,
                                      "actions" => actions,
                                      "policy" => policy,
                                      "securityToken" => sec_token})

        res = wss.reply(request, response);

        render :xml => res
  	end

	def usernametoken
        operations = {"echoString" => "echoFunction", "echoInt" => "echoFunction"};
        actions = {"http://php.axis2.org/samples/echoString" => "echoString"};
        policy_content = {"use_username_token" => true}
        policy = WSO2::WSF::WSPolicy.new({"security" => policy_content})

        sec_token = WSO2::WSF::WSSecurityToken.new({"user" => "Raigama",
                                            		"password" => "RaigamaPW",
                                            		"password_type" => "Digest"})

        wss = WSO2::WSF::WSService.new({"operations" => operations,
                                      "actions" => actions,
                                      "policy" => policy,
                                      "securityToken" => sec_token})

        res = wss.reply(request, response);

        render :xml => res
	end

	def signing
        cert = WSUtil::ws_get_cert_from_file("../keys/bob_cert.cert");
        pvt_key = WSUtil::ws_get_key_from_file("../keys/bob_key.pem");

        operations = {"echoString" => "echoFunction", "echoInt" => "echoFunction"};
        actions = {"http://php.axis2.org/samples/echoString" => "echoString"};
        
		policy_content = {"sign" => true, 
                    	  "algorithmSuite" => "Basic256Rsa15",
                    	  "securityTokenReference" => "KeyIdentifier"}
        
		policy = WSO2::WSF::WSPolicy.new({"security" => policy_content})

        sec_token = WSO2::WSF::WSSecurityToken.new({"privateKey" => pvt_key,
                                       				"certificate" => cert})

        wss = WSO2::WSF::WSService.new({"operations" => operations,
                                      "actions" => actions,
                                      "policy" => policy,
                                      "securityToken" => sec_token})

        res = wss.reply(request, response);
 		
		:xml => res
	end

	def encryption
    	pub_key = WSUtil::ws_get_cert_from_file("../keys/alice_cert.cert");
		pvt_key = WSUtil::ws_get_key_from_file("../keys/bob_key.pem");
    	operations = {"echoString" => "echoFunction", "echoInt" => "echoFunction"};
        actions = {"http://php.axis2.org/samples/echoString" => "echoString"};

        policy_content = {"encrypt" => true,
                    	  "algorithm_suite" => "Basic256Rsa15",
                    	  "security_token_reference" => "IssuerSerial"}

        policy = WSO2::WSF::WSPolicy.new({"security" => policy_content})

        sec_token = WSO2::WSF::WSSecurityToken.new({"privateKey" => pvt_key,
                                       				"receiver_certificate" =>pub_key})

        wss = WSO2::WSF::WSService.new({"operations" => operations,
                                      "actions" => actions,
                                      "policy" => policy,
                                      "securityToken" => sec_token})

        res = wss.reply(request, response);

        render :xml => res
	end

	def complete
		cert = WSUtil::ws_get_cert_from_file("../keys/bob_cert.cert");
		pvt_key = WSUtil::ws_get_key_from_file("../keys/bob_key.pem");
		pub_key = WSUtil::ws_get_cert_from_file("../keys/alice_cert.cert");
       
		operations = {"echoString" => "echoFunction", "echoInt" => "echoFunction"};
        
		actions = {"http://php.axis2.org/samples/echoString" => "echoString"};
        
		policy_content = {"sign" => true, 
		                     "algorithmSuite" => "Basic256Rsa15", 
		                     "securityTokenReference" => "KeyIdentifier"}
        
		policy = WSO2::WSF::WSPolicy.new({"security" => policy_content})

        sec_token = WSO2::WSF::WSSecurityToken.new({"privateKey" => pvt_key,
                                       "certificate" => cert,
                                       "receiverCertificate" =>pub_key})

        wss = WSO2::WSF::WSService.new({"operations" => operations,
                                      "actions" => actions,
                                      "policy" => policy,
                                      "securityToken" => sec_token})

        res = wss.reply(request, response);

        render :xml => res
	end
end
