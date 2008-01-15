SUBDIRS=src samples wsf_c
datadir=$(prefix)
data_DATA=README.INSTALL.LINUX README.SAMPLES README INSTALL COPYING NEWS NOTICE
examples:
	sh build_samples.sh $(prefix)
	rm -rf $(prefix)/bin/samples/resources  
	rm -rf $(prefix)/bin/samples/sandesha2  
	rm -rf $(prefix)/bin/samples/savan  
	rm -rf $(prefix)/bin/samples/wsclient
	rm -rf $(prefix)/bin/samples/c
	rm -rf $(prefix)/samples
	rm -rf $(prefix)/bin/samples/echo_blocking
	rm -rf $(prefix)/bin/samples/echo_blocking_dual
	rm -rf $(prefix)/bin/samples/echo_non_blocking
	rm -rf $(prefix)/bin/samples/echo_rest  
	rm -rf $(prefix)/bin/samples/math  
	rm -rf $(prefix)/bin/samples/notify
	rm -rf $(prefix)/bin/samples/echo
	rm -rf $(prefix)/bin/samples/echo_blocking_addr
	rm -rf $(prefix)/bin/samples/echo_blocking_soap11  
	rm -rf $(prefix)/bin/samples/echo_non_blocking_dual  
	rm -rf $(prefix)/bin/samples/google     
	rm -rf $(prefix)/bin/samples/mtom  
	rm -rf $(prefix)/bin/samples/yahoosearch

EXTRA_DIST=README.INSTALL.LINUX README.INSTALL.WINDOWS README.SAMPLES build.bat clean.bat configure.in docs

