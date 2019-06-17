#
#  Makefile
#

## source, header, object and executable files
EXES 	= prog9-1 prog9-2 prog9-3 prog9-4 prog9-5
LIBS 	= sort-check.o measurement.o

## commands and options
CC      = gcc
CFLAGS  =
LINKER  = gcc
LNFLAGS =

filename = /etc/redhat-release
fileexists = $(shell ls ${filename} | grep ${filename})
ifeq (${fileexists}, ${filename})
libc = $(shell rpm -q glibc)
libc_version = $(shell rpm -q glibc | grep 2.12)
ifeq (${libc}, ${libc_version})
LIBTIME = -lrt
else
LIBTIME =
endif
else
LIBTIME =
endif

## make rules
all:    $(LIBS) $(EXES)

clean: 
	rm -f $(EXES) $(LIBS) a.out core *~

## suffix rules
.SUFFIXES: .c
.c.o:
	$(CC) $(CFLAGS) -c $<

prog9-5: prog9-5.c
	$(LINKER) $(LNFLAGS) $(LIBTIME) $^ -o $@

%: %.c
	$(LINKER) $(LNFLAGS) $^ -o $@

## dependence of objejt, source and header files
prog9-1:	sort-check.o
prog9-2:	sort-check.o
prog9-3:	sort-check.o
prog9-4:	sort-check.o
prog9-5:	sort-check.o measurement.o
sort-check.o:	sort-common.h sort-common4list.h
measurement.o:	measurement.h sort-common.h
