## Process this file with automake to produce Makefile.in

## Created by Anjuta

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(TOOLKIT_COMMON_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = toolkit_common

toolkit_common_SOURCES = \
	main.cc

toolkit_common_LDFLAGS = 

toolkit_common_LDADD = $(TOOLKIT_COMMON_LIBS)


if NATIVE_WIN32
toolkit_common_LDFLAGS += -mwindows
endif
