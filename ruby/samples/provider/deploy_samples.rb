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

if RUBY_PLATFORM =~ /mswin32/
	system("cmd /C rails -d mysql " + rails_app_name)
else
	system("rails -d mysql " + rails_app_name)
end

#system("rails " + rails_app_name)

destination = rails_app_name + "/app/controllers/"
if FileTest.directory?(destination)
    FileUtils.copy_file("echo_classmap_service_controller.rb", destination + "/echo_classmap_service_controller.rb");
    FileUtils.copy_file("echo_service_addr_controller.rb", destination + "/echo_service_addr_controller.rb");
    FileUtils.copy_file("echo_service_controller.rb", destination + "/echo_service_controller.rb");
    
    FileUtils.copy_file("mtom/mtom_base64_upload_service_controller.rb", destination + "/mtom_base64_upload_service_controller.rb");
    FileUtils.copy_file("mtom/mtom_download_service_controller.rb", destination + "/mtom_download_service_controller.rb");
    FileUtils.copy_file("mtom/mtom_upload_service_controller.rb", destination + "/mtom_upload_service_controller.rb");
    FileUtils.cp_r("mtom/resources", rails_app_name);

    FileUtils.copy_file("security/callback_controller.rb", destination + "/callback_controller.rb");
    FileUtils.copy_file("security/complete_controller.rb", destination + "/complete_controller.rb");
    FileUtils.copy_file("security/encryption_controller.rb", destination + "/encryption_controller.rb");
    FileUtils.copy_file("security/signing_controller.rb", destination + "/signing_controller.rb");
    FileUtils.copy_file("security/timestamp_controller.rb", destination + "/timestamp_controller.rb");
    FileUtils.copy_file("security/username_token_controller.rb", destination + "/username_token_controller.rb");
    FileUtils.cp_r("security/policies", destination);
    FileUtils.cp_r("security/keys", destination);

    FileUtils.copy_file("reliable/echo_service_rm_controller.rb", destination + "/echo_service_rm_controller.rb");
    FileUtils.copy_file("reliable/mtom_upload_service_rm_controller.rb", destination + "/mtom_upload_service_rm_controller.rb");
    
    FileUtils.copy_file("wsdl_mode/wsdl11_service_controller.rb", destination + "/wsdl11_service_controller.rb");
    FileUtils.copy_file("wsdl_mode/wsdl20_service_controller.rb", destination + "/wsdl20_service_controller.rb");
    FileUtils.copy_file("wsdl_mode/sample_wsdl_11.wsdl", rails_app_name + "/sample_wsdl_11.wsdl");
    FileUtils.copy_file("wsdl_mode/sample_wsdl_20.wsdl", rails_app_name + "/sample_wsdl_20.wsdl");
end
