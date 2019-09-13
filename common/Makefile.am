## Process this file with automake to produce Makefile.in
## Created by Anjuta

#AM_CPPFLAGS = -I$(top_srcdir)/version-reader  -I$(top_builddir)/version-reader 

SUBDIRS = version-reader src po

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

AM_CPPFLAGS = $(cunit_CFLAGS) 


lib_LTLIBRARIES = \
	libtoolkit-common-cpp.la


libtoolkit_common_cpp_la_LIBADD = version-reader/libparsercpp.la
#libtoolkit_common_cpp_la_CPPFLAGS=-fPIC -Wl,-Bsymbolic 
libtoolkit_common_cpp_la_CXXFLAGS= -DENABLED_AUTOT -fPIC -Wl,-Bsymbolic -I$(top_srcdir)/version-reader  -I$(top_builddir)/version-reader 
libtoolkit_common_cpp_la_LDFLAGS= -shared -fPIC -Wl,-Bsymbolic -version-info `$(top_srcdir)/versionInfo.sh toolkit-common-c++ --dd`

libtoolkit_common_cpp_la_SOURCES =  \
	common.cpp \
	Error.cpp \
	Message.cpp \
	Object.cpp \
	Version.cpp\
	Version-parser.cpp   

bin_PROGRAMS =  \
	developing \
	testing-v5
developing_CXXFLAGS = -DENABLED_AUTOT
developing_LDADD =  libtoolkit-common-cpp.la 

developing_SOURCES =  \
	main.cpp


	
testing_v5_CXXFLAGS = -DENABLED_AUTOT 
testing_v5_LDADD = libtoolkit-common-cpp.la \
	$(cunit_LIBS) 

testing_v5_SOURCES =  \
	tests/v5.cc

DISTCLEANFILES = intltool-extract \
	intltool-merge \
	intltool-update \
	po/.intltool-merge-cache


# Remove doc directory on uninstall
uninstall-local:
	-rm -r $(docdir)
