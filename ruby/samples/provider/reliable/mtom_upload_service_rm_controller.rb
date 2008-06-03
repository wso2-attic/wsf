#the global function to expose 
def uploadFunction(in_msg)
	attachments = in_msg.property "attachments"
	cid_2_content_type = in_msg.property "cid_2_content_type"

	if attachments and cid_2_content_type then
	
		cid_2_content_type.each_pair {|cid, content_type|
			content = attachments[cid]
			if content then
			
				file_name = cid
				file_name = file_name + ".jpg" if content_type == "image/jpeg"

				f = File.new(file_name, "wb")
				f.write(content)
				f.close

			end
		}

	end

	res_payload_string = "<ns1:response xmlns:ns1='http://ws.apache.org/axis2/c/samples'>Image Saved</ns1:response>"

    return res_payload_string
end

class MtomUploadServiceRmController < ApplicationController

  require "wsf"
  skip_before_filter :verify_authenticity_token
  
  def upload
      #operation to ruby function map
      operations = {"upload" => "uploadFunction"}

      wss = WSO2::WSF::WSService.new({:operations => operations,
	  								  :request_xop => true,
	  								  :reliable => true});

      res = wss.reply(request, response);

      render :text => res
  end

end
