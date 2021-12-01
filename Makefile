CC=gcc --std=c99 -g

all: test_dynarray

test_dynarray: test_dynarray.c dynarray.o
	$(CC) test_dynarray.c dynarray.o -o test_dynarray

dynarray.o: dynarray.c dynarray.h
	$(CC) -c dynarray.c

clean:
	rm -f dynarray.o test_dynarray
