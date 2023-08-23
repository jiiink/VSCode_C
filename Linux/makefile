CC = gcc
CFLAGS = -Wall -g -o $@ 
OBJS = register.o print.o search.o delete.o sort.o
LIB = -L. -lshared

all : prog

%.o : %.c
	$(CC) $(CFLAGS) -c -fPIC $<

libhw8.so : $(OBJS)
	$(CC) $(CFLAGS) -shared $^

prog : hw8Main.o libhw8.so
	$(CC) $(CFLAGS) $^ $(LIB) -I.

clean :
	rm -f $(OBJS) hw8Main.o prog libhw8.so
