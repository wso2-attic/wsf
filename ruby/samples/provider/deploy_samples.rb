#!/usr/bin/env ruby

require 'fileutils'

#filling the app name from the first argument
if ARGV[0] 
    rails_app_name=ARGV[0]
else
    rails_app_name="my_rails_app"
end

if FileTest.directory?(rails_app_name)
    puts "You already have a directory called: " + rails_app_name +", Please delete and rerun this script"
    exit(-1)
end

#creating the rails application
puts "Creating rails application '" + rails_app_name + "' "

system("rails " + rails_app_name)

destination = rails_app_name + "/app/controllers/"
if FileTest.directory?(destination)
    FileUtils.copy_file("echo_classmap_service_controller.rb", destination + "/echo_classmap_service_controller.rb");
    FileUtils.copy_file("echo_service_addr_controller.rb", destination + "/echo_service_addr_controller.rb");
    FileUtils.copy_file("echo_service_controller.rb", destination + "/echo_service_controller.rb");
    
    FileUtils.copy_file("mtom/mtom_base64_upload_service_controller.rb", destination + "/mtom_base64_upload_service_controller.rb");
    FileUtils.copy_file("mtom/mtom_download_service_controller.rb", destination + "/mtom_download_service_controller.rb");
    FileUtils.copy_file("mtom/mtom_upload_service_controller.rb", destination + "/mtom_upload_service_controller.rb");
    FileUtils.cp_r("mtom/resources", rails_app_name);

    FileUtils.copy_file("security/security_controller.rb", destination + "/security_controller.rb");
    FileUtils.cp_r("security/policies", destination);
    FileUtils.cp_r("security/keys", destination);

    FileUtils.copy_file("reliable/echo_service_rm_controller.rb", destination + "/echo_service_rm_controller.rb");
    FileUtils.copy_file("reliable/mtom_upload_service_rm_controller.rb", destination + "/mtom_upload_service_rm_controller.rb");

end
