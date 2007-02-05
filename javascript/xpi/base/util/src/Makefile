
DEPTH           = ../../../../..
topsrcdir       = ../../../../..
srcdir          = .
VPATH           = .

include $(DEPTH)/config/autoconf.mk

MODULE          = tungsten
LIBRARY_NAME    = tungstenutil_s
XPIDL_MODULE    = tungsten
LIBXUL_LIBRARY  = 1

REQUIRES        = xpcom \
                  string \
                  dom \
                  js \
                  content \
                  widget \
                  xpconnect \
                  $(NULL)
CPPSRCS =       \
                nsWSRequestException.cpp \
                $(NULL)

include $(topsrcdir)/config/config.mk

# we don't want the shared lib, but we want to force the creation of a
# static lib.
FORCE_STATIC_LIB = 1

include $(topsrcdir)/config/rules.mk
