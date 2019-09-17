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

bin_PROGRAMS = toolkit_common \
	testing-v6

toolkit_common_SOURCES = \
	main.cc

toolkit_common_LDFLAGS = 

toolkit_common_LDADD = $(TOOLKIT_COMMON_LIBS)




testing_v6_SOURCES = \
	v6.cc

testing_v6_LDFLAGS = 

testing_v6_LDADD = $(TOOLKIT_COMMON_LIBS) ../libtoolkit-common-cpp.la



if NATIVE_WIN32
toolkit_common_LDFLAGS += -mwindows
endif
