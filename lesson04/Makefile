#
#  Makefile
#

## source, header, object and executable files
EXES 	= prog4-1 prog4-2 prog4-3 prog4-4 prog4-5

## commands and options
CC      = gcc
CFLAGS  =
        
## make rules
all:	$(EXES)

clean: 
	rm -f $(EXES) a.out core *~

## suffix rules
.SUFFIXES: .c
.c.o:
	$(CC) $(CFLAGS) $<

## dependence of objejt, source and header files
