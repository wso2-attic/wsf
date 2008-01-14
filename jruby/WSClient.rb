include Java

require 'WSF'


@@axis_home = String.new('')

#declaring the necessary java classes that are used to handle MTOM attachments
DataHandler = javax.activation.DataHandler
FileDataSource = javax.activation.FileDataSource
ArrayList = java.util.ArrayList

class WSClient 
	
def initialize(options,axis_home)
 begin    
    #creating a hash of options
    tempOptions = Hash.new
    options.each_pair {|k,v| tempOptions.store(k,v)} if options.kind_of? Hash  
    
    @@axis_home = axis_home 
 
    #instantiating ServiceClient and Options
    @client = ServiceClient.new()
    @options = Options.new
    
    # setting the End Point Reference
    @options.setTo(EndpointReference.new(tempOptions['to']))
    
    # setting the SOAP action
    if(tempOptions.has_key?('action'))
           @options.setAction(tempOptions['action'])
    end
  
    #Checkig whether to use SOAP or REST
    if tempOptions.has_key?('use_soap')
          if tempOptions['use_soap'].to_s.upcase.eql?('FALSE')
              #enable REST
              @options.setProperty(Constants::Configuration::ENABLE_REST, Boolean::TRUE)
          end
        
          # Decides whether to use 'Get' or 'Post'
          httpMethod = tempOptions.has_key?('http_method')? tempOptions['http_method'].to_s.upcase: nil;
          
          if httpMethod.eql?('GET')
            #use 'Get' method
            @options.setProperty(Constants::Configuration::HTTP_METHOD, Constants::Configuration::HTTP_METHOD_GET)
          else
            if httpMethod.eql?('POST')
              #use 'Post' method
              @options.setProperty(Constants::Configuration::HTTP_METHOD, Constants::Configuration::HTTP_METHOD_POST)
            end
          end
    end

    # Checking whether the MTOM is used
    use_mtom = tempOptions.has_key?('use_mtom')? tempOptions['use_mtom'].to_s.upcase : nil ;
    
    if use_mtom.eql?('TRUE')
            @options.set(Constants::Configuration::ENABLE_MTOM, Constants::VALUE_TRUE)
    else
       if use_mtom.eql?('FALSE')
          @options.setProperty(Constants::Configuration::FORCE_MIME, Constants::VALUE_TRUE)
       end
    end

    #Setting up the proxy properties, if provided
    proxy = HttpTransportProperties::ProxyProperties.new()

    #if the proxy host is specified
    if tempOptions.has_key?('proxy_host')
      proxy.setProxyName(tempOptions['proxy_host'])
    end

    #if the proxy port is specified
    if tempOptions.has_key?('proxy_port')
      proxy.setProxyPort(tempOptions['proxy_port'])
      
      @options.setProperty(HTTPConstants::PROXY, proxy)
    end

  # engaging addressing module.
        if tempOptions['use_wsa'].eql?(true)
               begin
                    @client.engageModule("addressing")

               rescue Exception => ex
                   puts ex
               end
               
        end
       

    rescue Exception => wsfault
       WSFault.new(wsfault.to_s)
    end
end



=begin
this sendReceive method of the ServiceClient is called within this method. This method accepts either a string of 
payload or a WSMessage as the parameter
=end
def request(opt)

    #if the parameter is a String of Payload
    if opt.is_a?(String)
        @req_payload_string = Java_String.new(opt)
    end                                               
    

    if opt.is_a?(REXML::Document)
       @req_payload_string = opt.to_s
    end

    # if th eparameter is a WSMessage
    if opt.is_a?(WSMessage)
        
        #assigns the contents of a WSMessage to the local variables
	if(opt.rexml_payload == nil)
          @req_payload_string = opt.str_payload
        else
          @req_payload_string = opt.rexml_payload.to_s
        end
        tempOptions = opt.options

        if(tempOptions != nil)
        # setting the EPR if it is sent with the WSMessage
        if(tempOptions.has_key?('to'))
           @options.setTo(EndpointReference.new(tempOptions['to']))
        end
        
        #setting the SOAP action
        if(tempOptions.has_key?('action'))
           @options.setAction(tempOptions['action'])
        end
        
        # Codes related to sending attachments
        if(tempOptions.has_key?('attachments'))
           @has_attachments = true
           mtom_attachments = Hash.new();
           mtom_attachments = tempOptions['attachments'];
           # taking the list of attahments to an arraylist
           @mtom_attachments_list = ArrayList.new
           mtom_attachments.each_value{|value|@mtom_attachments_list.add(value)}

        end
        
       #WSAddressing related codes goes here. These are optional
        
        if(tempOptions.has_key?('action'))
          @options.setAction(tempOptions['action'])
        end
        
        if(tempOptions.has_key?('from'))
          @options.setFrom(tempOptions['from'])
        end
        
        if(tempOptions.has_key?('reply_to'))
          @options.setReplyTo(tempOptions['reply_to'])
        end
        
        if(tempOptions.has_key?('fault_to'))
          @options.setFaultTo(tempOptions['fault_to'])
        end
        
	end
    end
    
    #setting options to the ServiceClient
    @client.setOptions(@options)
    
    #building the OMElement out of the request string
    req_stream = StringBufferInputStream.new(@req_payload_string)
    omBuilder = StAXOMBuilder.new(req_stream)
    omElement = OMElement.new
    omElement = omBuilder.getDocumentElement

    # if attachments are available, add them to the OMElement 
    if(@has_attachments)
    size = @mtom_attachments_list.size();
    index = 0
     while (index < size )
            fileDataSource = FileDataSource.new(String(@mtom_attachments_list.get(index)));
            expectedDH = DataHandler.new(fileDataSource);
            fac = OMAbstractFactory.getOMFactory();
	    expectedTextData = OMTextImpl.new(expectedDH, true, fac);
	    tmpEle = fac.createOMElement(QName.new("wrapperElement"));
	    omElement.addChild(tmpEle);            
	    tmpEle.addChild(expectedTextData);
            index +=1
     end
    end

    begin
        # invoke the sendReceive method and return the output as a WSMessage
        res = @client.sendReceive(omElement)
	res_message = WSMessage.new(res.to_string, nil, nil)
        res_message

    rescue Exception => wsfault
       WSFault.new(wsfault.to_s)
    end

end

#sendRobust method is invoked on serviceClient within this method
def send(opt)
    # Checking the type of the input parameter
    if opt.is_a?(String)
       @req_payload_string = Java_String.new(opt)
    end

    if opt.is_a?(WSMessage)
        @req_payload_string = opt.str_payload
        rexml_message = opt.rexml_payload
        tempOptions = opt.options

         if(tempOptions.has_key?('to'))
            @options.setTo(EndpointReference.new(tempOptions['to']))
         end

         if(tempOptions.has_key?('action'))
            @options.setAction(tempOptions['action'])
         end

     end
     
     # Setting options to the serviceClient
     @client.setOptions(@options)
     req_stream = StringBufferInputStream.new(@req_payload_string)
     omBuilder = StAXOMBuilder.new(req_stream)
     omElement = OMElement.new
     omElement = omBuilder.getDocumentElement

    begin
        #invoking the sendRobust method
        res = @client.sendRobust(omElement);
        res_message = WSMessage.new(res.to_string, nil, nil)
        res_message

    rescue Exception => wsfault
       WSFault.new(wsfault.to_s)
    end


end

end



