require 'rexml/document'

include REXML

module WSO2

  module WSDL
  
    class WSProxy  

      def initialize(environment, service_client, client_options, wsdl)
        @env = environment
        @svc_client = service_client
        @options = client_options
        @wsdl = wsdl
      end
      
      def method_missing(name, *args)
        #super unless name.to_s =~ /^w+_ismyname$/
        #puts "Why, hello #{name}!" 
        puts "Method Missing Found"
      end

    end
  
  end

end
