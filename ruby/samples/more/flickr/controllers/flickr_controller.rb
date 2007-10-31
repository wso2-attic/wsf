require 'flickr_client'
class FlickrController < ApplicationController
  def search
     if params[:query].nil?
      @result = nil
     else
        key = ""
        client = FlickrClient.new(key)
        @result = client.query(params[:query])
     end  
  rescue => exception
    @result = exception
  end

  def index
  end
end
