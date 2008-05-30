require 'rexml/document'
require 'rbconfig'

include REXML

module WSO2

  module WSDL
  
    class WSProxy  

      def initialize(environment, service_client, client_options, wsdl, service_name, port_name)
        @env = environment
        @svc_client = service_client
        @options = client_options
        @wsdl = wsdl
        @ruby_home = ::Config::CONFIG["WSF_RUBY_HOME"].to_s
        @service_name = service_name
        @port_name = port_name
      end
      
      def method_missing(name, *args)
        if args.length == 1 then 
          arg = args[0]
          if arg.kind_of? Hash then
            result = WSFC::wsf_wsdl_request_function(@env, 
                                                                      @svc_client, 
                                                                      @options, 
                                                                      @wsdl, 
                                                                      name.to_s, arg,
                                                                      @service_name,
                                                                      @port_name,
                                                                      @ruby_home)
            return result
          else
            puts "only Hash is supported"
          end
        else
          puts "dynamic function only support one argument"
        end
        return nil
      end      
    end
  
  end

end





























      #~ def method_missing(name, *args)
        #~ if args.length == 1 then #only 1 argument supported.
          #~ arg = args[0]
          #~ if arg.kind_of? Hash then
            #~ #TODO: if there is no "/" or "\" in the wsdl path, this is a relative path. Add the current location of the script. 	handle paths with ".." too.
            #~ result = WSFC::wsf_wsdl_request_function(@env, 
                                                                      #~ @svc_client, 
                                                                      #~ @options, 
                                                                      #~ @wsdl, 
                                                                      #~ name.to_s, arg,
                                                                      #~ @type_map,
                                                                      #~ @xslt_location)
            #~ return result
          #~ else
            #~ puts "only Hash is supported"
          #~ end
        #~ else
          #~ puts "dynamic function only support one argument"
        #~ end
        #~ return nil
      #~ end    
