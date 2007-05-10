datadir=$(prefix)/modules/sandesha2
includedir=$(prefix)/include/sandesha2-0.90
docsdir=$(prefix)/docs
prgbindir=$(prefix)/bin
SUBDIRS = src
docs_DATA=INSTALL README
include_HEADERS= \
			include/sandesha2_client_constants.h \
			include/sandesha2_constants.h \
			include/sandesha2_client.h \
			include/sandesha2_seq_report.h \
			include/sandesha2_report.h
data_DATA = config/module.xml
prgbin_DATA = config/mysql_schema.sh config/init_mysql.sh config/sqlite_schema.sh
EXTRA_DIST=config include autogen.sh build.sh LICENSE

