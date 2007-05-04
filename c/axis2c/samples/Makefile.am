samplesdir=$(prefix)/samples
samples_DATA=AUTHORS autogen.sh ChangeLog configure.ac Makefile.am NEWS README configure Makefile.in config.h.in INSTALL COPYING ../install-sh ../config.guess ../ltmain.sh ../depcomp ../missing ../config.sub
SUBDIRS = server client user_guide
install-data-hook:
	chmod 755 $(samplesdir)/configure $(samplesdir)/autogen.sh

dist-hook:
	rm -rf `find $(distdir)/ -type d -name .svn`
	rm -rf `find $(distdir)/ -type d -name .deps`
	rm -rf `find $(distdir)/ -type d -name .libs`

EXTRA_DIST=codegen autogen.sh build.sh
