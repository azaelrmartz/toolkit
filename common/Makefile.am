
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

lib_LTLIBRARIES =  \
	libtoolkit-common-cpp.la


libtoolkit_common_cpp_la_LIBADD = version-reader/libparserc.la

libtoolkit_common_cpp_la_CPPFLAGS= -DENABLED_AUTOT -fPIC -Wl,-Bsymbolic -I$(top_srcdir)/version-reader  -I$(top_builddir)/version-reader
 
libtoolkit_common_cpp_la_LDFLAGS= -shared -fPIC -Wl,-Bsymbolic -version-info `$(top_srcdir)/versionInfo.sh toolkit-common-c++ --dd`

libtoolkit_common_cpp_la_SOURCES =  \
	common.cpp \
	Error.cpp \
	Message.cpp \
	Object.cpp \
	Version.cpp \
	Version-parser.cpp \
	Licence.cpp

DISTCLEANFILES = intltool-extract \
	intltool-merge \
	intltool-update \
	po/.intltool-merge-cache


# Remove doc directory on uninstall
uninstall-local:
	-rm -r $(docdir)


SUBDIRS = version-reader src po
