
SHELL = /bin/bash

INSTALL = cp
INSTALL_PROGRAM = $(INSTALL)
INSTALL_DATA    = $(INSTALL)

#########################################################
# Compiler and options
#########################################################

CC = gcc
CPP = gcc -E

INCDIR = -I.

CPPFLAGS = $(INCDIR)
#CPPFLAGS = $(INCDIR) -DHAVE_CONFIG
#CPPFLAGS = $(INCDIR) -D_XOPEN_SOURCE=500 -DHAVE_CONFIG
#CPPFLAGS = $(INCDIR) -D_XOPEN_SOURCE=500 -DNDEBUG

# -fPIC pour que les .o générés puissent être utilisés sur diverses
# architectures
CFLAGS = -g -Wall -Wextra -pedantic -std=c99 -fPIC
#CFLAGS = -O -Wall -Wextra -pedantic -std=c99 -fPIC


#LIBS = -ljpeg -lXaw -lm
LIBS = 

#LDFLAGS = -L/usr/local/X11R6/lib -L../jpeg $(LIBS)
LDFLAGS = $(LIBS)



#########################################################
# Common prefix for installation directories.
#########################################################

#prefix = /usr/local
prefix = .
exec_prefix = ${prefix}

bindir  = ${exec_prefix}/bin
sbindir = ${exec_prefix}/sbin
libexecdir = ${exec_prefix}/libexec

libdir = ${exec_prefix}/lib
infodir = ${prefix}/info
includedir = ${prefix}/include
mandir = ${prefix}/man

srcdir  = .


#########################################################
# bin, sources, ...
#########################################################

BIN1 = 1_2_exercice
SRC1 = 1_2_exercice.c
OBJ1 = $(subst .c,.o,$(SRC1))
DFILES1 = $(subst .c,.d,$(SRC1))

BIN2 = 1_3_exercice
SRC2 = 1_3_exercice.c
OBJ2 = $(subst .c,.o,$(SRC2))
DFILES2 = $(subst .c,.d,$(SRC2))

BIN = $(BIN1) $(BIN2)
SRC = $(SRC1) $(SRC2)
OBJ = $(OBJ1) $(OBJ2)
DFILES = $(DFILES1) $(DFILES2)


#########################################################
# explicite rules
#########################################################

all: $(BIN)

$(BIN1): $(OBJ1)
	@echo "creating" $@
	@$(CC) $(CFLAGS) -o $@ $(OBJ1) $(LDFLAGS)
#	@echo "end creating" $@ "======================================="

$(BIN2): $(OBJ2)
	@echo "creating" $@
	@$(CC) $(CFLAGS) -o $@ $(OBJ2) $(LDFLAGS)
#	@echo "end creating" $@ "======================================="



#########################################################
# generic rules
#########################################################
install:
	@echo install to do

uninstall:
	@echo uninstall to do

clean:
	@echo "deleting" $(OBJ) $(DFILES)
	@$(RM) $(OBJ) $(DFILES)

distclean: clean
	@echo "deleting" $(BIN)
	@$(RM) $(BIN)

mostlyclean:
	@echo mostlyclean to do

maintainer-clean:
	@echo maintainer-clean to do

TAGS:
	@echo TAGS to do

info:
	@echo info to do


#########################################################
# Implicite rules
#########################################################

#.SILENT:

.SUFFIXES : .c .o .d

%.o : %.c
	@echo 'compiling' $< ;\
	$(CC) $(CFLAGS) -c $(CPPFLAGS) $< -o $@ ;

%.d : %.c
	@$(SHELL) -ec '$(CC) -MM $(CPPFLAGS) $< \
	   | sed '\''s/\($*\.o\)[ :]*/\1 $@ : /g'\'' > $@' ;

# include dependance files
-include $(DFILES)
