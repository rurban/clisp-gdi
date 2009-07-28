# Makefile for the CLISP module GDI

# Programs used by "make":
CC = gcc

CFLAGS =  -W -Wswitch -Wcomment -Wpointer-arith -Wimplicit -Wreturn-type  -Wno-sign-compare -g -DSAFETY=1 -DUNICODE -DDYNAMIC_FFI -DNO_SIGSEGV -I. -I.. -falign-functions=4

INCLUDES=-I. -I..
CPP = gcc -O -E -w -DUNICODE -DDYNAMIC_FFI
CLFLAGS = 

MODPREP = ../modprep

CLISP = clisp -q -norc -E 1:1

LN = ln

MAKE = make

SHELL = /bin/sh

DISTRIBFILES = *
distribdir =

all : gdi.o gdi.fas

gdi.fas : gdi.lisp
	$(CLISP) -c gdi.lisp

gdi.c : gdi.m local.c funcs-ok.c funcs-rest.c funcs-prob.c funcs-count.c funcs-out.c
	cat gdi.m local.c funcs-ok.c funcs-rest.c funcs-prob.c  funcs-count.c funcs-out.c >gdi.mm
	$(CLISP) $(MODPREP) gdi.mm gdi.c

#grep -v "\#line" gdi.mmm > gdi.c
#rm gdi.mmm

gdi.o : gdi.c
	$(CC) $(CFLAGS) $(INCLUDES) -I.. -c gdi.c

# Make a module
clisp-module : all

clean :
	rm gdi.o gdi.c gdi.mm gdi.fas gdi.lib
# Make a module distribution into $(distribdir)
clisp-module-distrib : clisp-module force
	$(LN) $(DISTRIBFILES) $(distribdir)

tgz : clean
	cd ..; tar -zcvf gdi.tar.gz gdi

force :

