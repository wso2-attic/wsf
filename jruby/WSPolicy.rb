# 
# WSPolicy.rb
# 
# Created on Dec 11, 2007, 10:22:14 AM
# 
# To change this template, choose Tools | Templates
# and open the template in the editor.
 
require 'WSF'


class WSPolicy
  def initialize(options)
        
    if (options.is_a?(String))
      inputStream = StringBufferInputStream.new(options)
      builder = StAXOMBuilder.new(inputStream)
      PolicyEngine.getPolicy(builder.getDocumentElement())
      
    end
        
    
  end
end
