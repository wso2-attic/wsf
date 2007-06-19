datadir=$(prefix)/modules/sandesha2
includedir=$(prefix)/include/sandesha2-0.90
docsdir=$(prefix)/docs/sandesha2c

SUBDIRS = src

docs_DATA=

include_HEADERS= include/*.h

data_DATA = LICENSE config/module.xml

install-data-hook: 
	cp -rf xdocs/* $(docsdir)

EXTRA_DIST=LICENSE config xdocs
