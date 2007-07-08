TESTS = test_c14n
noinst_PROGRAMS = test_c14n

#AM_CFLAGS = -g -O2 -pthread

test_c14n_SOURCES =  test.c

INCLUDES = -I$(top_builddir)/include \
		   @OPENSSLINC@ \
		    @AXIS2INC@ \
		    @UTILINC@ \
		    @AXIOMINC@ 

test_c14n_LDADD  = ${AXIS2C_HOME}/lib/libaxutil.la \
		    	   ${AXIS2C_HOME}/lib/libaxis2_axiom.la \
		    	   ${AXIS2C_HOME}/lib/libaxis2_libxml2.la \
				   $(top_builddir)/src/omxmlsec/c14n/liboxsc14n.la \
				@OPENSSLLIB@
