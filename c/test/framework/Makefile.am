SUBDIRS = src samples
datadir=$(prefix)

EXTRA_DIST = build.sh autogen.sh CREDITS LICENSE build.sh wsfc_unit.mk README INSTALL CREDITS COPYING NEWS wsfc_unit.mk
dist-hook:
	rm -rf `find $(distdir)/ -type d -name .svn`
	rm -rf `find $(distdir)/ -type d -name .deps`
	rm -rf `find $(distdir)/ -type d -name .libs`

