## Process this file with automake to produce Makefile.in
## Created by Anjuta


CPPFLAGS = -I$(top_srcdir)/version-reader-c++ -I$(top_builddir)/version-reader-c++ 

SUBDIRS = version-reader-c++ po



dist_doc_DATA = \
	README \
	COPYING \
	AUTHORS \
	ChangeLog \
	INSTALL \
	NEWS


INTLTOOL_FILES = intltool-extract.in \
	intltool-merge.in \
	intltool-update.in

EXTRA_DIST = \
	$(INTLTOOL_FILES)

bin_PROGRAMS =  \
	test

test_SOURCES =  \
	main.cpp

test_LDADD = libversion-reader-cpp.a


lib_LIBRARIES =  \
	libversion-reader-cpp.a


libversion_reader_cpp_LDADD = version-reader-c++/libparser.la

libversion_reader_cpp_a_SOURCES =  \
	Version.cpp \
	common.cpp \
	Error.cpp \
	Message.cpp \
	Object.cpp \
	Version-parser.cpp


DISTCLEANFILES = intltool-extract \
	intltool-merge \
	intltool-update \
	po/.intltool-merge-cache


# Remove doc directory on uninstall
uninstall-local:
	-rm -r $(docdir)
