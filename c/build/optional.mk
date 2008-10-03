AUTOCONF = ..\configure.in
!include $(AUTOCONF)

!if "$(ENABLE_RAMPARTC)" == "1"
OPFLAGS = "yes" 
!else
OPFLAGS = "no" 
!endif

!if "$(ENABLE_SANDESHA2C)" == "1"
OPFLAGS = $(OPFLAGS) "yes" 
!else
OPFLAGS = $(OPFLAGS) "no" 
!endif

!if "$(ENABLE_SAVANC)" == "1"
OPFLAGS = $(OPFLAGS) "yes" 
!else
OPFLAGS = $(OPFLAGS) "no" 
!endif

!if "$(WITH_UDP)" == "1"
OPFLAGS = $(OPFLAGS) "yes" 
!else
OPFLAGS = $(OPFLAGS) "no" 
!endif


dist :
	build_optional.bat $(OPFLAGS)
