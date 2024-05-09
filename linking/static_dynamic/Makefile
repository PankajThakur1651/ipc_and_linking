CC=gcc
CFLAGS=-Wall -g
BINS=static_lib_test shared_lib_test mycode.o mycode.so mystaticcode.a shared_lib_test_a
all: $(BINS)

mycode.o: mycode.c mycode.h
	$(CC) $(CFLAGS) -c mycode.c

mycode.so: mycode.c mycode.h
	$(CC) $(CFLAGS) -fPIC -shared -o  $@ mycode.c -lc

mystaticcode.a: mycode.o
	ar rcs mystaticcode.a mycode.o

static_lib_test: Test.c mycode.o
	$(CC) $(CFLAGS) -o $@ $^

shared_lib_test: Test.c mycode.so
	$(CC) $(CFLAGS) -o $@ $^ 

shared_lib_test_a: Test.c
	$(CC) $(CFLAGS) -o $@ $^ -L. -l:mystaticcode.a

clean:
	rm  $(BINS)
