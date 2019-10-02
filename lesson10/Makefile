#
#  Makefile
#

## source, header, object and executable files
EXES 	= prog10-1 prog10-2 prog10-3 prog10-4
LIBS 	= heap-check.o queue.o

## commands and options
CC      = gcc
CFLAGS  =
LINKER  = gcc
LNFLAGS =

## make rules
all:    $(LIBS) $(EXES)

clean: 
	rm -f $(EXES) $(LIBS) a.out core *~

## suffix rules
.SUFFIXES: .c
.c.o:
	$(CC) $(CFLAGS) -c $<

%: %.c
	$(LINKER) $(LNFLAGS) $^ -o $@

## dependence of objejt, source and header files
prog10-1:	heap-check.o queue.o
prog10-2:	heap-check.o queue.o
prog10-3:	heap-check.o queue.o
prog10-4:	heap-check.o queue.o
heap-check.o:	heap-common.h heaptree-common.h
queue.o:	queue.h heaptree-common.h
