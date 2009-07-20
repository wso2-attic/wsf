SUBDIRS=src
datadir=$(prefix)
includedir=$(prefix)/include
include_HEADERS=$(top_builddir)/include/*.h
data_DATA=README.INSTALL.LINUX README.SAMPLES README INSTALL COPYING NEWS NOTICE
samples:
	sh build_samples.sh $(prefix)
#	rm -rf $(prefix)/bin/samples/resources  
#	rm -rf $(prefix)/bin/samples/sandesha2  
#	rm -rf $(prefix)/bin/samples/savan  
#	rm -rf $(prefix)/bin/samples/wsclient
#	rm -rf $(prefix)/bin/samples/c
#	rm -rf $(prefix)/samples
#	rm -rf $(prefix)/bin/samples/echo_blocking
#	rm -rf $(prefix)/bin/samples/echo_blocking_dual
#	rm -rf $(prefix)/bin/samples/echo_non_blocking
#	rm -rf $(prefix)/bin/samples/echo_rest  
#	rm -rf $(prefix)/bin/samples/math  
#	rm -rf $(prefix)/bin/samples/notify
#	rm -rf $(prefix)/bin/samples/echo
#	rm -rf $(prefix)/bin/samples/echo_blocking_addr
#	rm -rf $(prefix)/bin/samples/echo_blocking_soap11  
#	rm -rf $(prefix)/bin/samples/echo_non_blocking_dual  
#	rm -rf $(prefix)/bin/samples/google     
#	rm -rf $(prefix)/bin/samples/mtom  
#	rm -rf $(prefix)/bin/samples/yahoosearch
#
dist-hook:
	sh dist_hook.sh

install-data-hook:
	cp -rf $(prefix)/docs $(prefix)/docs_temp
	rm -rf $(prefix)/docs
	mkdir $(prefix)/docs
	mkdir $(prefix)/docs/wsf_c
	mv -f $(prefix)/docs_temp $(prefix)/docs/wsf_c/docs
	mv -f $(prefix)/docs/wsf_c/docs/wsclient $(prefix)/docs/wsf_c/wsclient
	mkdir $(prefix)/docs/wsf_c/wsclient/docs
	mv $(prefix)/docs/wsf_c/wsclient/index.html $(prefix)/docs/wsf_c/wsclient/docs/
	rm -rf $(prefix)/docs/wsf_c/docs/rampartc
	rm -rf $(prefix)/docs/wsf_c/docs/sandesha2c
	rm -rf $(prefix)/docs/wsf_c/docs/axis2c
	cp -rf docs $(prefix)/docs/cpp
	cp -rf tools/codegen $(prefix)/bin/tools/

EXTRA_DIST=README.INSTALL.LINUX README.INSTALL.WINDOWS README.SAMPLES build.bat build_codegen.bat copy_codegen.bat init.bat clean.bat configure.in docs NOTICE LICENSE tools

