SUBDIRS=wsf_c src 
datadir=$(prefix)
includedir=$(prefix)/include
include_HEADERS=$(top_builddir)/include/*.h
data_DATA=README.INSTALL.LINUX README.SAMPLES README INSTALL COPYING NEWS NOTICE
samples:
	sh build_samples.sh $(prefix)

dist-hook:
	sh dist_hook.sh

install-data-hook:
	rm -rf $(prefix)/samples/*
	mv $(prefix)/docs $(prefix)/wsf_c
	mkdir $(prefix)/docs
	mv $(prefix)/wsf_c $(prefix)/docs/wsf_c
	mkdir $(prefix)/docs/cpp
	cp -rf docs $(prefix)/docs/cpp        

EXTRA_DIST=README.INSTALL.LINUX README.INSTALL.WINDOWS README.SAMPLES build.bat init.bat clean.bat configure.in docs NOTICE LICENSE

