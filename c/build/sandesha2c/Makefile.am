datadir=$(prefix)/modules/sandesha2
includedir=$(prefix)/include/wsfc-2.0.0
docsdir=$(prefix)/docs/sandesha2c
sysconfdir=$(prefix)
samplesdir=$(prefix)/samples/src/sandesha2c
scriptsdir=$(prefix)/samples/bin/sandesha2c

SUBDIRS = src
samples_DATA=
include_HEADERS= include/*.h

data_DATA = LICENSE config/module.xml

docs_DATA=

sysconf_DATA=config/axis2.xml

EXTRA_DIST=LICENSE config xdocs build ides

scripts_DATA=config/*.bat config/*.sh

install-data-hook:
	mkdir -p $(samplesdir)
	cp -rf samples/* $(samplesdir)


