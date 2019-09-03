
AM_CPPFLAGS = -I$(top_srcdir)/version-reader-cpp  -I$(top_builddir)/version-reader-cpp 

SUBDIRS = version-reader-cpp


dist_doc_DATA = \
	README \
	COPYING \
	AUTHORS \
	ChangeLog \
	INSTALL \
	NEWS

bin_PROGRAMS =  \
	test

test_LDADD =  version-reader-cpp/libparser.la

test_SOURCES =  \
	main.cpp


lib_LIBRARIES =  \
	libtoolkit_common_cpp.a

libtoolkit_common_cpp_LDADD =  version-reader-cpp/libparser.la

libtoolkit_common_cpp_a_SOURCES =  \
	Version-parser.cpp \
	Version.cpp \
	common.cpp \
	Error.cpp \
	Message.cpp \
	Object.cpp

INTLTOOL_FILES = intltool-extract.in \
	intltool-merge.in \
	intltool-update.in

EXTRA_DIST = \
	$(INTLTOOL_FILES)

DISTCLEANFILES = intltool-extract \
	intltool-merge \
	intltool-update \
	po/.intltool-merge-cache


# Remove doc directory on uninstall
uninstall-local:
	-rm -r $(docdir)
