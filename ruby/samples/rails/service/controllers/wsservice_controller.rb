#the global function to expose 
def echoFunction(in_msg)
    return in_msg
end

#the class to expose
class WSFApi
    def echoStringFunc in_msg
        return in_msg
    end

    def echoIntFunc in_msg
        return in_msg
    end
end

def downloadFunction(in_msg)
  res_payload_string = "<ns1:download xmlns:ns1='http://php.axis2.org/samples/mtom'><ns1:fileName>test.jpg</ns1:fileName><ns1:image xmlmime:contentType='image/jpeg' xmlns:xmlmime='http://www.w3.org/2004/06/xmlmime'><xop:Include xmlns:xop='http://www.w3.org/2004/08/xop/include' href='cid:myid1'></xop:Include></ns1:image></ns1:download>"
  
  content = IO.read("resources/axis2.jpg")

  msg = WSO2::WSF::WSMessage.new(res_payload_string,
							     nil,
								 {"attachments" => {"myid1" => content}})
 
  return msg
end

def uploadFunction(in_msg)
	attachments = in_msg.property "attachments"
	cid_2_content_type = in_msg.property "cid_2_content_type"

	if attachments and cid_2_content_type then
	
		cid_2_content_type.each_pair {|cid, content_type|
			content = attachments[cid]
			if content then
			
				file_name = cid
				file_name = file_name + ".jpg" if content_type == "image/jpeg"

				f = File.new(file_name, "w")
				f.write(content)
				f.close

			end
		}

	end

	res_payload_string = "<ns1:response xmlns:ns1='http://ws.apache.org/axis2/c/samples'>Image Saved</ns1:response>"

    return res_payload_string
end

class WsserviceController < ApplicationController

  require "wsf"
  
  def echo
      #operation to ruby function map
      operations = {"echoString" => "echoFunction",
                    "echoInt" => "echoFunction"}

      wss = WSO2::WSF::WSService.new({:operations => operations});

      res = wss.reply(request, response);

      render :text => res
  end
  
  def echo_addr
      #operation to ruby function map
      operations = {"echoString" => "echoFunction",
                    "echoInt" => "echoFunction"}

      #action to operation map
      actions = {"http://ruby.axis2.org/samples/echoString" => "echoString",
                "http://ruby.axis2.org/samples/echoInt" => "echoInt"}

      wss = WSO2::WSF::WSService.new({:operations => operations,
									  :actions => actions});

      res = wss.reply(request, response);

      render :text => res
  end
  
  def mtom
      #operation to ruby function map
      operations = {"download" => "downloadFunction",
	                "upload" => "uploadFunction"}

      wss = WSO2::WSF::WSService.new({:operations => operations,
	  								  :use_mtom => true,
	  								  :request_xop => true});

      res = wss.reply(request, response);

      render :text => res
  end

  def echo_reliable
      #operation to ruby function map
      operations = {"echoString" => "echoFunction",
                    "echoInt" => "echoFunction"}

      #action to operation map
      actions = {"http://ruby.axis2.org/samples/echoString" => "echoString",
                "http://ruby.axis2.org/samples/echoInt" => "echoInt"}

      wss = WSO2::WSF::WSService.new({:operations => operations,
									  :actions => actions,
	  								  :reliable => true});

      res = wss.reply(request, response);

      render :text => res
  end

  def echo_classmap
	  #operation to ruby function map
      class_operation_map = {"echoString" => "echoStringFunc",
                    		 "echoInt" => "echoIntFunc"}
      
	  #action to operation map
      actions = {"http://ruby.axis2.org/samples/echoString" => "echoString",
                "http://ruby.axis2.org/samples/echoInt" => "echoInt"}

      wss = WSO2::WSF::WSService.new({:classes => [:WSFApi => class_operation_map],
									  :actions => actions});

      res = wss.reply(request, response);

      render :text => res
  end
end
