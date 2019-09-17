
SUBDIRS = src po

AM_CPPFLAGS = -I$(top_builddir)

bin_PROGRAMS =  \
	developing

developing_SOURCES =  \
	develop.c

parser.tab.c parser.tab.h : parser.y
	bison -o $@ $<

lexer.c : lexer.l
	flex -o $@ $<

dist_doc_DATA = \
	README \
	COPYING \
	AUTHORS \
	ChangeLog \
	INSTALL \
	NEWS


parser.tab.c parser.tab.h : parser.y
	bison -d -o $@ $<

lexer.c : lexer.l
	flex -o $@ $<

INTLTOOL_FILES = intltool-extract.in \
	intltool-merge.in \
	intltool-update.in

EXTRA_DIST = \
	$(INTLTOOL_FILES)

bin_PROGRAMS =  \
	developing

developing_SOURCES =  \
	develop.c

developing_LDADD = libparserc.la 

lib_LTLIBRARIES =  \
	libparserc.la


libparserc_la_CFLAGS=-fPIC -Wl,-Bsymbolic -I/home/azael/develop/toolkit-c++/common/ $(top_builddir)
libparserc_la_LDFLAGS=-shared -fPIC -Wl,-Bsymbolic

libparserc_la_SOURCES =  \
	parser.tab.c \
	lexer.c 


DISTCLEANFILES = intltool-extract \
	intltool-merge \
	intltool-update \
	po/.intltool-merge-cache


# Remove doc directory on uninstall
uninstall-local:
	-rm -r $(docdir)
