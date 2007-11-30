require 'flickr_client'
class FlickrController < ApplicationController
  def search
     if params[:query].nil?
      	@result = nil
     else
        key = ""
		log_file = "ruby_rails_flicker_client.log"
        client = FlickrClient.new(key, log_file)
        @result = client.query(params[:query])
     end  
  rescue => exception
    @result = exception
  end

  def index
  end
end
