# Filters added to this controller apply to all controllers in the application.
# Likewise, all the methods added will be available for all controllers.

class ApplicationController < ActionController::Base
  # Pick a unique cookie name to distinguish our session data from others'
  session :session_key => '_blog_session_id'
  ENV["AXIS2C_HOME"] = "/home/janapriya/deploy/axis2c"
end
