TESTS =
datadir=$(prefix)/bin/samples/rampart/secpolicy
SUBDIRS = callback client server keys authn_provider credential_provider data
data_DATA=

install-data-hook:
	cp -rf secpolicy/* $(datadir)
	cp -rf README $(datadir)/../

EXTRA_DIST=secpolicy omxmlsec data


