#!/usr/bin/env ruby

require "rbconfig"

puts ::Config::CONFIG["WSFC_HOME"].to_s
