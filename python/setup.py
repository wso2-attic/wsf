#!/usr/bin/env python

# Setup script for the WSFC Python Extension
#
# Targets build install

import sys, os, string, platform

from distutils.core import setup, Extension
from distutils import sysconfig

AXIS2C_INCLUDES = 'include/axis2-1.5.0'
RAMPARTC_INCLUDES = 'include/rampart-1.2.0'
AXIS2C_LIBS = 'lib'
RAMPARTC_LIBS = 'modules/rampart'

# Special command-line arguments
WSFC_HOME = None

# Check the command is install.
INSTALL_OP = False

# Holders for include directories, lib directories and libraries
wsfc_incdirs = None
wsfc_libdirs = None
wsfc_libs = None

# String used to hold the include path(e.g. -I../include -I/home/wsfc/include).
INCLUDE_STR = None

args = sys.argv[:]

for arg in args:
	print arg
	if string.find(arg, '--with-wsfc=') == 0:
		WSFC_HOME = string.split(arg, '=')[1]
		sys.argv.remove(arg)
	elif string.find(arg, 'install') == 0:
		INSTALL_OP = True

def get_wsfc_prefix():
	if WSFC_HOME:
		return WSFC_HOME
	else:
		return

# Handle other cases like user have installed
# WSFC Development version from .deb package,
# yum, or through aptitude.

if sys.platform.startswith('linux'):
	wsfc_libs = ['axis2_axiom']
elif sys.platform == 'win32':
	wsfc_libs = ['axiom']

python_version = platform.python_version()[0:3]
removals = ['-Wstrict-prototypes']

if python_version == '2.5':
	cv_opt = sysconfig.get_config_vars()["CFLAGS"]
	for removal in removals:
		cv_opt = cv_opt.replace(removal, " ")
	sysconfig.get_config_vars()["CFLAGS"] = ' '.join(cv_opt.split())
else:
	cv_opt = sysconfig.get_config_vars()["OPT"]
	for removal in removals:
		cv_opt = cv_opt.replace(removal, " ")
	sysconfig.get_config_vars()["OPT"] = ' '.join(cv_opt.split())

wsfc_prefix = get_wsfc_prefix()

print wsfc_prefix
print sysconfig.get_config_vars()["CFLAGS"]
print os.path.join(wsfc_prefix, AXIS2C_INCLUDES)

current_wd = os.getcwd()
wsdlc_includes = os.path.join(current_wd, 'wsdlc/include')

if wsfc_prefix:
	wsfc_incdirs = [
		os.path.join(wsfc_prefix, AXIS2C_INCLUDES), wsdlc_includes, os.path.join(wsfc_prefix, RAMPARTC_INCLUDES), ] 
		#os.path.join(wsfc_prefix, RAMPARTC_INCLUDES)]
	wsfc_libdirs = [
		os.path.join(wsfc_prefix, AXIS2C_LIBS),] 
		#os.path.join(wsfc_prefix, RAMPARTC_LIBS)]
	wsfc_libs.extend([
		'axutil',
		'axis2_parser',
		'axis2_engine',
		'axis2_http_common',
		'axis2_http_sender',
		'axis2_http_receiver',
		'neethi',
		'neethi_util',
        'wsdlc',
		])
else:
	print 'WSFC_HOME not found. Please specify the WSFC_HOME using --with-wsfc=$path_to_wsfc'

extra_l_args = '--rpath ' + os.path.join(wsfc_prefix, AXIS2C_LIBS)

# Creating file which contains location of the WSFC libraries.
# This file will copy into /etc/ld.so.conf.d directory 
wsfc_ld_conf = None
if wsfc_prefix:
	wsfc_ld_conf = open('wsfc.conf', 'w')
	wsfc_ld_conf.write(os.path.join(wsfc_prefix, AXIS2C_LIBS))
	wsfc_ld_conf.close()


setup(name='WSFC',
	  version='0.1',
	  ext_modules=[Extension(
			  			'_WSFC',
						sources=['WSFC.i'],
						swig_opts=['-I./swig/'],
						include_dirs=wsfc_incdirs,
						library_dirs=wsfc_libdirs,
						libraries=wsfc_libs,
						extra_compile_args=['-Wno-strict-prototypes', '-fno-strict-aliasing', ],
						extra_link_args=[extra_l_args,],
						)],
      py_modules=['WSFC'],
	  data_files=[('/etc/ld.so.conf.d', ['wsfc.conf']),],
	  description='Python binding for WSFC',
      packages=['wso2',],
      package_dir={'wso2': 'lib/wso2'},
      package_data={'wso2': ['wsdlc/conf/*.xml', 'wsdlc/xslt/*.*'], }
      )

# If the operation is install, we have to run 'ldconfig' to add WSFC libraries
# to system (Work only for Linux).
if INSTALL_OP:
	if sys.platform.startswith('linux'):
		print 'running ldconfig'
		cmd = 'ldconfig'
		os.system(cmd)


