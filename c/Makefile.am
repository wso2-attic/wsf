datadir=$(prefix)
docsdir=$(prefix)/docs
SUBDIRS=axis2c $(SANDESHA_DIR) $(RAMPART_DIR) savanc $(WSCLIENT_DIR) 
docs_DATA=docs/*
data_DATA=config/axis2.xml README \
        INSTALL COPYING NEWS CREDITS NOTICE

dist-hook:
	sh dist.sh

samples: build_samples.sh
	touch build_samples.sh
	sh build_samples.sh $(prefix)


EXTRA_DIST=build_samples.sh config build.bat clean.bat dist.sh docs CREDITS NOTICE

