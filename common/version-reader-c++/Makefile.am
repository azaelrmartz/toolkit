
SUBDIRS = po

# bin_PROGRAMS = vrcpp
# vrcpp_SOURCES =  parser.yy lexer.ll lexer.cc parser.cc 

parser.tab.cc parser.tab.hh : parser.yy
	bison -o $@ $<

lexer.cc : lexer.l
	flex -o $@ $<

#parser.o lexer.o driver.o : parser.cc lexer.cc driver.cpp
#	$(CXX) $(CXXFLAGS) -I. -I../ -c $^

#libparsercpp.a: parser.o lexer.o driver.o 
#	ar rcs libparsercpp.a parser.o lexer.o driver.o


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
	libparser.la

libparser_la_SOURCES =  \
	parser.tab.cc \
	lexer.cc \
	driver.cpp


libparser_la_LDFLAGS = -module \
	-avoid-version 


DISTCLEANFILES = intltool-extract \
	intltool-merge \
	intltool-update \
	po/.intltool-merge-cache

# Remove doc directory on uninstall
uninstall-local:
	-rm -r $(docdir)
