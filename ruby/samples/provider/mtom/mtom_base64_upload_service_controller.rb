#the global function to expose 
def uploadFunction(in_msg)

	require "rexml/document"

	doc = REXML::Document.new in_msg.payload_to_s
	image_node = XPath.first(doc, "//ns1:image")
	
	res_payload_string = ""

	if !image_node.nil? then
	  puts "Base64 content = " + image_node.text

	  file_name = "base64imagecontent.txt"

	  f = File.new(file_name, "w")
	  f.write(image_node.text)
	  f.close
	  
	  res_payload_string = "<ns1:response xmlns:ns1='http://ws.apache.org/axis2/c/samples'>Image Saved</ns1:response>"
	else
		res_payload_string = "<ns1:response xmlns:ns1='http://ws.apache.org/axis2/c/samples'>Image Content not Found</ns1:response>"
	end

    return res_payload_string
end

class MtomBase64UploadServiceController < ApplicationController

  require "wsf"
  skip_before_filter :verify_authenticity_token
  
  def upload
      #operation to ruby function map
      operations = {"upload" => "uploadFunction"}

      wss = WSO2::WSF::WSService.new({:operations => operations});

      res = wss.reply(request, response);

      render :text => res
  end

end
