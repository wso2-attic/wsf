#the global function to expose 
def downloadFunction(in_msg)
  res_payload_string = "<ns1:download xmlns:ns1='http://php.axis2.org/samples/mtom'><ns1:fileName>test.jpg</ns1:fileName><ns1:image xmlmime:contentType='image/jpeg' xmlns:xmlmime='http://www.w3.org/2004/06/xmlmime'><xop:Include xmlns:xop='http://www.w3.org/2004/08/xop/include' href='cid:myid1'></xop:Include></ns1:image></ns1:download>"
  
  resource = File.new("resources/axis2.jpg", "rb")
  
  content = resource.read


  msg = WSO2::WSF::WSMessage.new(res_payload_string,
							     nil,
								 {"attachments" => {"myid1" => content}})
 
  return msg
end

class MtomDownloadServiceController < ApplicationController

  require "wsf"
  skip_before_filter :verify_authenticity_token
  
  def download
      #operation to ruby function map
      operations = {"download" => "downloadFunction"}

      wss = WSO2::WSF::WSService.new({:operations => operations,
	  								  :use_mtom => true});

      res = wss.reply(request, response);

      render :text => res
  end

end
