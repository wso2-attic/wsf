# 
# ***** BEGIN LICENSE BLOCK *****
# Version: MPL 1.1/GPL 2.0/LGPL 2.1
#
# The contents of this file are subject to the Mozilla Public License Version
# 1.1 (the "License"); you may not use this file except in compliance with
# the License. You may obtain a copy of the License at
# http://www.mozilla.org/MPL/
#
# Software distributed under the License is distributed on an "AS IS" basis,
# WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
# for the specific language governing rights and limitations under the
# License.
#
# Alternatively, the contents of this file may be used under the terms of
# either the GNU General Public License Version 2 or later (the "GPL"), or
# the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
# in which case the provisions of the GPL or the LGPL are applicable instead
# of those above. If you wish to allow use of your version of this file only
# under the terms of either the GPL or the LGPL, and not to allow others to
# use your version of this file under the terms of the MPL, indicate your
# decision by deleting the provisions above and replace them with the notice
# and other provisions required by the GPL or the LGPL. If you do not delete
# the provisions above, a recipient may use your version of this file under
# the terms of any one of the MPL, the GPL or the LGPL.
#
# ***** END LICENSE BLOCK *****

DEPTH           = ../../../../..
topsrcdir       = ../../../../..
srcdir          = .
VPATH           = .

include $(DEPTH)/config/autoconf.mk

MODULE		= tungsten
XPIDL_MODULE	= tungsten
LIBRARY_NAME	= tungsten_stub
EXPORT_LIBRARY  = 1
ifneq ($(OS_ARCH),WINNT)
SHORT_LIBNAME	= tungsten_stub
endif
IS_COMPONENT	= 1
MODULE_NAME	= nsTungstenModule
GRE_MODULE	= 1
LIBXUL_LIBRARY	= 1
axis_top_srcdir = $(AXIS2C_HOME)/..
axis_top_builddir= $(AXIS2C_HOME)

PACKAGE_FILE = tungsten_stub.pkg

REQUIRES	= xpcom \
		  string \
		  $(NULL)

CPPSRCS		= nsTungstenModuleStub.cpp

FORCE_SHARED_LIB = 1

include $(topsrcdir)/config/config.mk

EXTRA_DSO_LDOPTS += \
                $(DIST)/lib/$(LIB_PREFIX)xpcomglue_s.$(LIB_SUFFIX) \
	        $(XPCOM_FROZEN_LDOPTS) \
                $(NSPR_LIBS) \
		$(NULL)


include $(topsrcdir)/config/rules.mk

DEFINES += -DMOZ_DLL_PREFIX_TOK=$#(DLL_PREFIX)
EXTRA_DSO_LDOPTS += $(MOZ_COMPONENT_LIBS)

install:: $(TARGETS)
