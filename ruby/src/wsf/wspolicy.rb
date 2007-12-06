#Copyright 2005,2006,2007 WSO2, Inc. http://wso2.com
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

require 'WSFC'
require 'rexml/document'
require 'rexml/element'

include REXML

module WSO2

  module WSF

    class WSPolicy
       
       # Constructs a new WSPolicy Object.
       # Policy can be a XML string, a REXML::Element or a Hash of options. 
       # Hash options should be specified as below
       # Hash.new("security" => a hash of security options)
       
       def initialize(policy)
	     @policy = policy
       end
	
       
       def get_policy_as_axiom_node(env)
	     if @policy.kind_of? String
	       return create_policy_from_string(@policy, env) 
	     elsif @policy.kind_of? REXML::Element
	       return create_policy_from_string(@policy.to_s, env)
	     elsif @policy.kind_of? Hash
	       return create_policy_from_hash(@policy, env) 
	     end

	     return nil
       end

	   # this method will return policy as a string, if policy is created using a string or
	   # a REXML::Element. 
	   # used by wsservice

	   def get_policy()
		 if @policy.kind_of? String
           return @policy
         elsif @policy.kind_of? REXML::Element
           return @policy.to_s
		 end

         return nil
	   end
	   
	   # this method will return policy options if policy is defined from a hash
	   # used by wsservice
	   
	   def option(policy_option)
		  return nil if @policy.kind_of? String
		  return nil if @policy.kind_of? REXML::Element
		
          options = @policy.has_key?("security")? @policy["security"]: nil

          return nil if options.nil?

		  opt = options.has_key?(policy_option)? options[policy_option].to_s : nil
		  
		  return opt
	   end
	
	
       def create_policy_from_hash(policy, env)
	     return nil if policy.nil?
	     return nil unless policy.kind_of? Hash
	  
	     options = policy.has_key?("security")? policy["security"]: nil

	     return nil if options.nil?

	     neethi_options = WSFC::neethi_options_create(env)
	 
	     if not neethi_options.nil?
	       option = options.has_key?("include_time_stamp")? options["include_time_stamp"] : nil
	       if (!option.nil? and option == true)
	         WSFC::neethi_options_set_include_timestamp(neethi_options, env, WSFC::AXIS2_TRUE)
	       end
	  
	       option = options.has_key?("use_username_token")? options["use_username_token"] : nil
	       if (!option.nil? and option == true)
	         WSFC::neethi_options_set_is_username_token(neethi_options, env, WSFC::AXIS2_TRUE)
	       end

	       option = options.has_key?("encrypt")? options["encrypt"] : nil
	       if not option.nil?
	         if option.kind_of? String
		       WSFC::neethi_options_set_encrypt_body(neethi_options, env, option)
	         elsif option
		       WSFC::neethi_options_set_encrypt_body(neethi_options, env, WSFC::AXIS2_TRUE)
	         end
	       end

	       option = options.has_key?("algorithm_suite")? options["algorithm_suite"] : nil
	       if !option.nil? and option.kind_of? String
	         WSFC::neethi_options_set_algorithmsuite(neethi_options, env, option)
	       end

	       option = options.has_key?("sign")? options["sign"] : nil
	       if not option.nil?
	         if option.kind_of? String
		       WSFC::neethi_options_set_sign_body(neethi_options, env, option)
	         elsif option
		       WSFC::neethi_options_set_sign_body(neethi_options, env, WSFC::AXIS2_TRUE)
	         end
	       end

	       option = options.has_key?("security_token_reference")? options["security_token_reference"] : nil
	       if not option.nil?
	         if option.kind_of? String
		       token_ref = get_rampart_token_value(option)

		       WSFC::neethi_options_set_keyidentifier(neethi_options, env, token_ref) unless token_ref.nil?
	         end
	       end
     
	       option = options.has_key?("encrypt_signature")? options["encrypt_signature"] : nil
	       if (!option.nil? and option == true)
	         WSFC::neethi_options_set_signature_protection(neethi_options, env, WSFC::AXIS2_TRUE)
	       end

	       option = options.has_key?("protection_order")? options["protection_order"] : nil
	       if not option.nil?
	         if option.kind_of? String
		       if option == "EncryptBeforeSigning"
		         WSFC::neethi_options_set_encrypt_before_sign(neethi_options, env, WSFC::AXIS2_TRUE)
		       elsif option == "SignBeforeEncrypt"
		         WSFC::neethi_options_set_encrypt_before_sign(neethi_options, env, WSFC::AXIS2_FALSE)
		       end
	         end
	       end
	   
		   return WSFC::neethi_options_get_root_node(neethi_options, env)
	     end
	     
		 return nil
      end  


      def create_policy_from_string(policy, env)
	    return nil if policy.nil?
	    return nil unless policy.kind_of? String
	 
	    return WSFC::wsf_str_to_axiom_node(env, policy, policy.length)   
      end  


      def get_rampart_token_value(option)
	    if option == "IssuerSerial" then 
	      return WSFC::RP_REQUIRE_ISSUER_SERIAL_REFERENCE
	    elsif option == "KeyIdentifier" then
	      return WSFC::RP_REQUIRE_KEY_IDENTIFIRE_REFERENCE
	    elsif option == "EmbeddedToken" then
	      return WSFC:: RP_REQUIRE_EMBEDDED_TOKEN_REFERENCE
	    elsif option == "Thumbprint" then
	      return WSFC::RP_REQUIRE_THUMBPRINT_REFERENCE
	    else
	      return nil
	    end
      end

	  public  :get_policy
    end 

  end   

end
