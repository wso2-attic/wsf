require 'test/unit'
require 'config/wsconfig'

class TC_Config < Test::Unit::TestCase

	include WSO2::Config

	def test_key_data_type
		assert_equal WSConfig.read_string(1), ""
	end

	def test_read_int
		val = WSConfig.read_int("INT_VAL")
		assert_kind_of Fixnum, val
	end

	def test_read_float
		val = WSConfig.read_float("FLOAT_VAL")
		assert_kind_of Float, val
	end

	def test_read_bool
		# True
		val = WSConfig.read_bool("BOOL_TRUE_VAL")
		assert_equal val, true

		# False
		val = WSConfig.read_bool("MY_BOOL_VAL")
		assert_equal val, false
	end

	def test_read_dir
		# Empty Entry
		val = WSConfig.read_dir("MY_DIR")
		assert_equal val, "/tmp/"

		# Dir
		val = WSConfig.read_dir("DIR_VAL")
		assert_equal val[val.length - 1], '/'
	end

end
