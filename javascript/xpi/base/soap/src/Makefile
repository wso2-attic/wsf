
DEPTH           = ../../../../..
topsrcdir       = ../../../../..
srcdir          = .
VPATH           = .

axis_topbuilddir= $(AXIS2C_HOME)

include $(DEPTH)/config/autoconf.mk

MODULE          = tungsten
LIBRARY_NAME    = tungstensoap_s
XPIDL_MODULE    = tungsten
LIBXUL_LIBRARY  = 1

REQUIRES        = xpcom \
                  string \
                  dom \
                  js \
                  gfx \
                  layout \
                  content \
                  widget \
                  caps \
                  uconv \
                  necko \
                  xpconnect \
                  htmlparser \
                  windowwatcher \
                  xmlextras \
                  $(NULL)
CPPSRCS =       \
                nsWSRequest.cpp \
                $(NULL)


include $(topsrcdir)/config/config.mk


INCLUDES        += -I$(axis_topbuilddir)/include/axis2-1.0 \
                   $(NULL)

LOCAL_INCLUDES +=  \
                   -I../../util/src \
                    $(NULL)

AXIS2C_LIBS=   \
        -L$(axis_topbuilddir)/lib \
        -laxiom \
        -laxis2_libxml2 \
        -laxis2_engine \
        -laxis2_http_receiver \
        -laxis2_http_sender \
        -laxis2_parser \
        -laxis2_soap \
        -laxutil \
        $(NULL)

EXTRA_LIBS = $(AXIS2C_LIBS) \
             -lxml2 \
             $(NULL)


# we don't want the shared lib, but we want to force the creation of a
# static lib.
FORCE_STATIC_LIB = 1

include $(topsrcdir)/config/rules.mk
