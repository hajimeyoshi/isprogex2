#	
#  Makefile
#

## source, header, object and executable files
EXES 	= prog15-1 prog15-2 prog15-3
LIBS 	= graph-check.o queue.o stack.o

## commands and options
CC      = gcc
CFLAGS  =
LINKER  = gcc
LNFLAGS =

## make rules
all:	$(LIBS) $(EXES)

clean: 
	rm -f $(EXES) $(LIBS) a.out core *~

## suffix rules
.SUFFIXES: .c
.c.o:
	$(CC) $(CFLAGS) -c $<

%: %.c
	$(LINKER) $(LNFLAGS) $^ -o $@

## dependence of objejt, source and header files
prog15-1:	graph-check.o 
prog15-2:	graph-check.o stack.o
prog15-3:	graph-check.o queue.o
graph-check.o:	graph-common.h
queue.o:	queue.h
stack.o:	stack.h
