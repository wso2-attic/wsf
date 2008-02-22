SUBDIRS = platforms/unix @ZLIBBUILD@ stomp
lib_LTLIBRARIES = libaxutil.la
libaxutil_la_SOURCES = hash.c \
                        allocator.c \
                        env.c \
                        error.c \
                        stream.c \
                        log.c \
                        string.c \
                        string_util.c \
                        qname.c \
                        array_list.c \
                        linked_list.c \
                        utils.c \
                        dir_handler.c \
                        file_handler.c \
                        class_loader.c\
                        network_handler.c \
                        file.c\
                        uuid_gen.c\
                        thread_pool.c \
                        property.c \
                        types.c \
                        param.c \
                        param_container.c \
                        dll_desc.c\
                        url.c\
                        stack.c \
                        generic_obj.c \
                        base64.c \
                        uri.c \
                        date_time.c \
                        base64_binary.c \
                        properties.c \
						http_chunked_stream.c \
			rand.c \
			date_time_util.c \
			version.c \
			duration.c\
			stomp/frame.c \
			stomp/stomp.c \
			md5.c \
			digest_calc.c


                        
libaxutil_la_LIBADD =	$(top_builddir)/src/platforms/unix/libaxis2_unix.la \
						@ZLIBLIBS@


libaxutil_la_LDFLAGS = -version-info $(VERSION_NO)

INCLUDES = -I$(top_builddir)/include\
	   -Istomp

EXTRA_DIST=platforms/windows string_util.c
