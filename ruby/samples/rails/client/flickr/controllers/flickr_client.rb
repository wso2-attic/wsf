#!/usr/bin/env ruby         

# Copyright 2005,2006,2007 WSO2, Inc. http://wso2.com
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

require 'wsf'
require 'rexml/document'

include REXML
include WSO2::WSF

class FlickrClient
   def initialize(key, log_file)
      @key = key
      @client = WSClient.new({"to" => "http://api.flickr.com/services/soap"},
                             log_file)
   end

   def query(text)
      payload = compile_query(text)
      res_message = @client.request(payload)
      
      return generate_html(res_message.payload_to_s)    
   
   rescue => exception
      return "Exception : #{exception}"
   end

private
   def compile_query(text)
     # check for text nil and empty, key nil and empty 
     # throw exception
     payload = <<XML
     <x:FlickrRequest xmlns:x="urn:flickr">
       <method>flickr.photos.search</method>
       <api_key>#{@key}</api_key>
       <text>#{text}</text>
     </x:FlickrRequest>
XML
     return payload
   end

   def generate_html(result)
     doc = Document.new(result) 
     photos = doc.elements['/x:FlickrResponse']
  
     doc = Document.new(photos.text)
     photos = doc.elements['photos'] 
    
     current_page = photos.attributes['page']
     number_of_pages = photos.attributes['pages']
     photos_per_page = photos.attributes['perpage']
     photos_total = photos.attributes['total']
  
     return_array = Array.new
  
     #puts "current page : #{current_page}, number of pages : #{number_of_pages}, photos_per_page : #{photos_per_page}, photos_total : #{photos_total}"
     #puts "return_array created"
     photos.each_element do |photo|
       if photo.has_attributes?
         id = photo.attributes['id']
         farm = photo.attributes['farm']
         title = photo.attributes['title']
         server = photo.attributes['server']
         secret = photo.attributes['secret']
  
         #puts "attributes : #{id}, #{farm}, #{title}, #{secret}"

	     h = Hash.new
         h[:title] = title
         h[:url_o_jpg] = "http://farm#{farm}.static.flickr.com/#{server}/#{id}_#{secret}_o.jpg";
         h[:url_o_gif] = "http://farm#{farm}.static.flickr.com/#{server}/#{id}_#{secret}_o.gif";
         h[:url_o_png] = "http://farm#{farm}.static.flickr.com/#{server}/#{id}_#{secret}_o.png";
         h[:url_big_size] = "http://farm#{farm}.static.flickr.com/#{server}/#{id}_#{secret}_b.jpg";
         h[:url_small_size] = "http://farm#{farm}.static.flickr.com/#{server}/#{id}_#{secret}_s.jpg";
         h[:url_medium_size] = "http://farm#{farm}.static.flickr.com/#{server}/#{id}_#{secret}_m.jpg";
         h[:url_thumbnail_size] = "http://farm#{farm}.static.flickr.com/#{server}/#{id}_#{secret}_t.jpg";
  
         return_array << h
      #else
         #puts "no attributes"
      end
    end
  
    #return_array.each do |x|
    #  puts "#{x}\n"
    #end
    
    return return_array
    #return result
rescue => exception
    puts exception

   end
end
