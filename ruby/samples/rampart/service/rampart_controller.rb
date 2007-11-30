
require 'wsf'
require 'rexml/document'
require 'rexml/element'

def echoFunction(in_msg)
     "<wrapped>" + in_msg + "</wrapped>"
end

def passwordCallBack(username)
	#logic to get password from any source (ex: using mysql database etc)

	return "RaigamaPW"
end

def load_policy_from_file(filename)
   return nil unless filename.kind_of? String
   input = File.new(filename)
   unless input.nil?
     doc = REXML::Document.new(input)
     unless doc.nil?
       root_element = doc.root
       return root_element
     end
   end
   return nil
end
 

class RampartController < ApplicationController
 
  	def callback
      	begin
			operations = {"echoString" => "echoFunction", "echoInt" => "echoFunction"}
    		actions = {"http://php.axis2.org/samples/echoString" => "echoString"}
		
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
  	end
  	
	def timestamp
		begin
			operations = {"echoString" => "echoFunction", "echoInt" => "echoFunction"}
            actions = {"http://php.axis2.org/samples/echoString" => "echoString"}

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
  	end

    def timestamp_file
        begin
            operations = {"echoString" => "echoFunction", "echoInt" => "echoFunction"}
            actions = {"http://php.axis2.org/samples/echoString" => "echoString"}

            policy_content = load_policy_from_file("./app/controllers/policies/policy_timestamp.xml")

            policy = WSO2::WSF::WSPolicy.new(policy_content)

            sec_token = WSO2::WSF::WSSecurityToken.new({"ttl" => 100})

            wss = WSO2::WSF::WSService.new({"operations" => operations,
                                          "actions" => actions,
                                          "policy" => policy,
                                          "securityToken" => sec_token})

            res = wss.reply(request, response);

            render :xml => res
        end
    end

	def usernametoken
        begin
            operations = {"echoString" => "echoFunction", "echoInt" => "echoFunction"}
            actions = {"http://php.axis2.org/samples/echoString" => "echoString"}

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
	end

    def usernametoken_file
        begin
            operations = {"echoString" => "echoFunction", "echoInt" => "echoFunction"}
            actions = {"http://php.axis2.org/samples/echoString" => "echoString"}

            policy_content = load_policy_from_file("./app/controllers/policies/policy_usernametoken.xml")

            policy = WSO2::WSF::WSPolicy.new(policy_content)

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
    end

	def signing
		begin
            operations = {"echoString" => "echoFunction", "echoInt" => "echoFunction"}
            actions = {"http://php.axis2.org/samples/echoString" => "echoString"}

			cert = WSO2::Util::WSUtil::ws_get_cert_from_file("./app/controllers/keys/bob_cert.cert");
			pvt_key = WSO2::Util::WSUtil::ws_get_key_from_file("./app/controllers/keys/bob_key.pem");

			policy_content = {"sign" => true, 
							  "algorithm_suite" => "Basic256Rsa15",
							  "security_token_reference" => "KeyIdentifier"}
			
			policy = WSO2::WSF::WSPolicy.new({"security" => policy_content})

			sec_token = WSO2::WSF::WSSecurityToken.new({"private_key" => pvt_key,
														"certificate" => cert})

			wss = WSO2::WSF::WSService.new({"operations" => operations,
										  "actions" => actions,
										  "policy" => policy,
										  "securityToken" => sec_token})

			res = wss.reply(request, response);
			
			render :xml => res
		end
	end

    def signing_file
        begin
            operations = {"echoString" => "echoFunction", "echoInt" => "echoFunction"}
            actions = {"http://php.axis2.org/samples/echoString" => "echoString"}

            cert = WSO2::Util::WSUtil::ws_get_cert_from_file("./app/controllers/keys/bob_cert.cert");
            pvt_key = WSO2::Util::WSUtil::ws_get_key_from_file("./app/controllers/keys/bob_key.pem");

            policy_content = load_policy_from_file("./app/controllers/policies/policy_signing.xml")

            policy = WSO2::WSF::WSPolicy.new(policy_content)

            sec_token = WSO2::WSF::WSSecurityToken.new({"private_key" => pvt_key,
            policy = WSO2::WSF::WSPolicy.new({"security" => policy_content})
                                                        "certificate" => cert})

            wss = WSO2::WSF::WSService.new({"operations" => operations,
                                          "actions" => actions,
                                          "policy" => policy,
                                          "securityToken" => sec_token})

            res = wss.reply(request, response);

            render :xml => res
        end
    end

	def encryption
		begin
            operations = {"echoString" => "echoFunction", "echoInt" => "echoFunction"}
            actions = {"http://php.axis2.org/samples/echoString" => "echoString"}

			pub_key = WSO2::Util::WSUtil::ws_get_cert_from_file("./app/controllers/keys/alice_cert.cert");
			pvt_key = WSO2::Util::WSUtil::ws_get_key_from_file("./app/controllers/keys/bob_key.pem");

			policy_content = {"encrypt" => true,
							  "algorithm_suite" => "Basic256Rsa15",
							  "security_token_reference" => "IssuerSerial"}

			policy = WSO2::WSF::WSPolicy.new({"security" => policy_content})

			sec_token = WSO2::WSF::WSSecurityToken.new({"private_key" => pvt_key,
														"receiver_certificate" =>pub_key})

			wss = WSO2::WSF::WSService.new({"operations" => operations,
										  "actions" => actions,
										  "policy" => policy,
										  "securityToken" => sec_token})

			res = wss.reply(request, response);

			render :xml => res
		end
	end

    def encryption_file
        begin
            operations = {"echoString" => "echoFunction", "echoInt" => "echoFunction"}
            actions = {"http://php.axis2.org/samples/echoString" => "echoString"}

            pub_key = WSO2::Util::WSUtil::ws_get_cert_from_file("./app/controllers/keys/alice_cert.cert");
            pvt_key = WSO2::Util::WSUtil::ws_get_key_from_file("./app/controllers/keys/bob_key.pem");

            policy_content = load_policy_from_file("./app/controllers/policies/policy_encryption.xml")

            policy = WSO2::WSF::WSPolicy.new(policy_content)

            sec_token = WSO2::WSF::WSSecurityToken.new({"private_key" => pvt_key,
                                                        "receiver_certificate" =>pub_key})

            wss = WSO2::WSF::WSService.new({"operations" => operations,
                                          "actions" => actions,
                                          "policy" => policy,
                                          "securityToken" => sec_token})

            res = wss.reply(request, response);

            render :xml => res
        end
    end


	def complete
		begin
            operations = {"echoString" => "echoFunction", "echoInt" => "echoFunction"}
            actions = {"http://php.axis2.org/samples/echoString" => "echoString"}

			cert = WSO2::Util::WSUtil::ws_get_cert_from_file("./app/controllers/keys/bob_cert.cert");
			pvt_key = WSO2::Util::WSUtil::ws_get_key_from_file("./app/controllers/keys/bob_key.pem");
			pub_key = WSO2::Util::WSUtil::ws_get_cert_from_file("./app/controllers/keys/alice_cert.cert");
		  	
			policy_content = load_policy_from_file("./app/controllers/policies/policy_complete.xml")
			
			policy = WSO2::WSF::WSPolicy.new(policy_content)

			sec_token = WSO2::WSF::WSSecurityToken.new({"private_key" => pvt_key,
										   "certificate" => cert,
										   "receiver_certificate" =>pub_key})

			wss = WSO2::WSF::WSService.new({"operations" => operations,
										  "actions" => actions,
										  "policy" => policy,
										  "securityToken" => sec_token})

			res = wss.reply(request, response);

			render :xml => res
		end
	end
end
