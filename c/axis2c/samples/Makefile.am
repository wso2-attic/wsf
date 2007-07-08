SUBDIRS = server client user_guide

dist-hook:
	rm -rf `find $(distdir)/ -type d -name .svn`
	rm -rf `find $(distdir)/ -type d -name .deps`
	rm -rf `find $(distdir)/ -type d -name .libs`

EXTRA_DIST=codegen autogen.sh build.sh
