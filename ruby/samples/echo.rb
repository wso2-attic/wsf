#!/usr/bin/env ruby

require 'wsf'

req_payload_string = <<XML
<ns1:echoString xmlns:ns1="http://ws.apache.org/axis2/services/echo">
    <text>Hello World!</text>
</ns1:echoString>
XML

begin
  client = WSClient.new(Hash[:to => "http://localhost:9090/axis2/services/echo"])

  puts "Using endpoint : http://localhost:9090/axis2/services/echo"
  puts "Sending OM : " << "\n" << req_payload_string << "\n" 

  res_message = client.request(req_payload_string)

  if not res_message.nil? then
    puts "Received OM: "<< "\n" << res_message.payload_to_s << "\n\n"
    puts "echo client invoke SUCCESSFUL!"
  else
    puts "echo client invoke FAILED!"
  end

rescue WSFault => wsfault
  puts "echo client invoke FAILED!\n"
  puts "WSFault : "
  puts wsfault.xml
  puts "----------"
  puts wsfault.code
  puts "----------"
  puts wsfault.reason
  puts "----------"
  puts wsfault.role
  puts "----------"
  puts wsfault.detail
  puts "----------"
rescue => exception
  puts "echo client invoke FAILED!\n"
  puts "Exception : " << exception
end

