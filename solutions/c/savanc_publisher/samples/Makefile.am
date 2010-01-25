SUBDIRS = server client

dist-hook:
	rm -rf `find $(distdir)/ -type d -name .svn`
	rm -rf `find $(distdir)/ -type d -name .deps`
	rm -rf `find $(distdir)/ -type d -name .libs`
	rm -rf `find $(distdir)/ -type d -name .o`
	rm -rf `find $(distdir)/ -type d -name .la`
	rm -rf `find $(distdir)/ -type d -name .lo`
	rm -rf `find $(distdir)/ -type d -name .loT`
	rm -rf `find $(distdir)/ -type d -name Makefile`
	rm -rf `find $(distdir)/ -type d -name autom4te.cache`


EXTRA_DIST=autogen.sh build.sh
