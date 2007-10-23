require 'flickr_client'
class FlickrController < ApplicationController
  def search
     if params[:query].nil?
      @result = nil
     else
        client = FlickrClient.new('d55214533d60aa9e18d75fe2409799d3')
        @result = client.query(params[:query])
     end  
  rescue => exception
    @result = exception
  end

  def index
  end
end
