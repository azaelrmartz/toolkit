
SUBDIRS = src po tests

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

lib_LTLIBRARIES =  \
	libparserc.la

libparserc_la_CFLAGS=-fPIC -Wl,-Bsymbolic -I/home/azael/develop/toolkit/common/ -I$(top_srcdir)

libparserc_la_LDFLAGS=-shared -fPIC -Wl,-Bsymbolic

libparserc_la_SOURCES =  \
	parser.tab.c \
	lexer.c 

bin_PROGRAMS =  \
	develop

develop_CFLAGS=-I/home/azael/develop/toolkit/common/

develop_SOURCES = \
	develop.c

develop_LDADD = libparserc.la 

DISTCLEANFILES = intltool-extract \
	intltool-merge \
	intltool-update \
	po/.intltool-merge-cache

uninstall-local:
	-rm -r $(docdir)
