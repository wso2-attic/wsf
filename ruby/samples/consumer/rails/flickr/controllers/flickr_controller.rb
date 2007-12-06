require 'flickr_client'
class FlickrController < ApplicationController
  def search
     if params[:query].nil?
      	@result = nil
     else
        @query = params[:query]
        key = ""
		log_file = "ruby_rails_flicker_client.log"
        client = FlickrClient.new(key, log_file)
        @result = client.query(@query)
     end  
  rescue => exception
    @result = exception
  end

  def index
  end
end
