noinst_LTLIBRARIES = libaxis2_description.la

libaxis2_description_la_SOURCES =desc.c \
                                op.c \
                                policy_include.c \
                                svc.c \
                                module_desc.c \
                                svc_grp.c \
                                phase_rule.c \
                                handler_desc.c \
                                flow.c \
                                flow_container.c \
                                transport_in_desc.c \
                                transport_out_desc.c \
                                msg.c 

libaxis2_engine_la_LDFLAGS = -version-info $(VERSION_NO)

INCLUDES = -I$(top_builddir)/include \
            -I$(top_builddir)/src/core/engine \
            -I$(top_builddir)/util/include \
            -I$(top_builddir)/axiom/include \
            -I$(top_builddir)/neethi/include

