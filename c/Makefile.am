datadir=$(prefix)
SUBDIRS=axis2c $(SANDESHA_DIR) $(RAMPART_DIR) savanc $(WSCLIENT_DIR)
data_DATA=config/axis2.xml README \
        INSTALL COPYING NEWS 

dist-hook:
	sh dist.sh

samples:
	sh samples.sh $(prefix)


EXTRA_DIST=samples.sh config build.bat clean.bat dist.sh

