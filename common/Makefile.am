
AM_CPPFLAGS = -I$(top_srcdir)/version-reader  -I$(top_builddir)/version-reader 

SUBDIRS = version-reader


dist_doc_DATA = \
	README \
	COPYING \
	AUTHORS \
	ChangeLog \
	INSTALL \
	NEWS

bin_PROGRAMS =  \
	test

test_LDADD =  version-reader/libparser.la

test_SOURCES =  \
	main.cpp


lib_LIBRARIES =  \
	libtoolkit_common_cpp.a

libtoolkit_common_cpp_LDADD =  version-reader/libparser.la

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
	intltool-update 


# Remove doc directory on uninstall
uninstall-local:
	-rm -r $(docdir)
