datadir=$(prefix)
docsdir=$(prefix)/docs
SUBDIRS=axis2c $(SANDESHA_DIR) $(RAMPART_DIR) $(SAVAN_DIR) $(WSCLIENT_DIR) 
docs_DATA=
data_DATA=config/axis2.xml README \
        INSTALL COPYING NEWS CREDITS NOTICE

dist-hook:
	sh dist.sh

samples:
	sh build_samples.sh $(prefix)

install-data-hook:
	cp -rf docs/* $(docsdir)


EXTRA_DIST=build_samples.sh config build.bat clean.bat dist.sh docs CREDITS NOTICE examples LICENSE

