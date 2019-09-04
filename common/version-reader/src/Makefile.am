## Process this file with automake to produce Makefile.in

## Created by Anjuta

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\"

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = version_reader_cpp

version_reader_cpp_SOURCES = \
	main.cc

version_reader_cpp_LDFLAGS = 

version_reader_cpp_LDADD = 


if NATIVE_WIN32
version_reader_cpp_LDFLAGS += -mwindows
endif
