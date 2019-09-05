## Process this file with automake to produce Makefile.in
## Created by Anjuta

SUBDIRS = src po

AM_CPPFLAGS = -I$(top_builddir)

parser.tab.cc parser.tab.hh : parser.yy
	bison -o $@ $<

lexer.cc : lexer.ll
	flex -o $@ $<

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
	libparsercpp.la

#libparsercpp_la_CPPFLAGS=-fPIC -Wl,-Bsymbolic 
libparsercpp_la_CXXFLAGS=-fPIC -Wl,-Bsymbolic
libparsercpp_la_LDFLAGS= -shared -fPIC -Wl,-Bsymbolic

libparsercpp_la_SOURCES =  \
	parser.tab.cc \
	lexer.cc \
	driver.cpp 

DISTCLEANFILES = intltool-extract \
	intltool-merge \
	intltool-update \
	po/.intltool-merge-cache


# Remove doc directory on uninstall
uninstall-local:
	-rm -r $(docdir)
