SRCDIR=src
LIBDIR=lib
BINDIR=bin
INCLUDEDIR=include
CC = gcc
AR = ar
CFLAGS=-Wall -pedantic -g
LDFLAGS=-lcunit
EXEC=benchTri

all :  $(BINDIR)/$(EXEC) $(BINDIR)/testTas $(BINDIR)/testTriParTas

$(BINDIR)/$(EXEC) : $(SRCDIR)/main.o $(LIBDIR)/libtris.a $(LIBDIR)/libechanger.a
	$(CC)  -o $@ $< -ltris -lechanger -Llib $(LDFLAGS)

$(BINDIR)/testTas : $(SRCDIR)/testTas.o $(LIBDIR)/libtris.a $(LIBDIR)/libechanger.a
	$(CC)  -o $@ $< -ltris -lechanger -Llib $(LDFLAGS)

$(BINDIR)/testTriParTas : $(SRCDIR)/testTriParTas.o $(LIBDIR)/libtris.a $(LIBDIR)/libechanger.a
	$(CC)  -o $@ $< -ltris -lechanger -Llib $(LDFLAGS)

$(LIBDIR)/libtris.a : $(SRCDIR)/triParMinSuccessif.o  $(SRCDIR)/triParInsertion.o $(SRCDIR)/triRapide.o $(SRCDIR)/triFusion.o $(SRCDIR)/triParTas.o $(SRCDIR)/tas.o
	$(AR)  -q $@  $^

$(LIBDIR)/lib%.a : $(SRCDIR)/%.o
	$(AR)  -q $@  $^

$(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDEDIR)  


clean :
	rm -rf $(BINDIR)/*
	rm -rf $(LIBDIR)/*
	rm -rf $(SRCDIR)/*.o
