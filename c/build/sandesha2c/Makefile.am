datadir=$(prefix)/modules/sandesha2
samplesdir=$(prefix)/samples/sandesha2c
includedir=$(prefix)/include/sandesha2-0.91
docsdir=$(prefix)/docs/sandesha2c
sysconfdir=$(prefix)
samplesdir=$(prefix)/samples/sandesha2
scriptsdir=$(prefix)/bin/sandesha2

SUBDIRS = src
samples_DATA=
include_HEADERS= include/*.h

data_DATA = LICENSE config/module.xml

docs_DATA=

sysconf_DATA=config/axis2.xml

EXTRA_DIST=LICENSE config xdocs build ides

scripts_DATA=config/*.bat config/*.sh config/*.txt

install-data-hook:
	cp -rf samples/* $(samplesdir)


