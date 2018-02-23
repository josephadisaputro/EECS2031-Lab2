CC = gcc
CFLAGS = -g -Wall -ansi -pedantic
OBJS = identifier_tester.o identifiers.o 
INCL = identifiers.h g_identifiers.h

identifier_tester:	$(OBJS) 
	$(CC)  -o $@ $^ -L. -lglib

%.o:	 %.c $(INCL)
	$(CC) $(CFLAGS) -c -o $@ $< 

glib.a:	g_identifiers.o
	ar rcs libglib.a g_identifiers.o

clean:
	rm $(OBJS) identifier_tester
