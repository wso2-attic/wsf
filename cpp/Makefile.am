SUBDIRS=wsf_c src 
datadir=$(prefix)
data_DATA=README.INSTALL.LINUX README.SAMPLES README INSTALL COPYING NEWS NOTICE
samples:
	sh build_samples.sh $(prefix)

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

EXTRA_DIST=README.INSTALL.LINUX README.INSTALL.WINDOWS README.SAMPLES build.bat clean.bat configure.in docs NOTICE LICENSE 

