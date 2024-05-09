CC=g++
CPPFLAGS=-Wall -g
BINS=plus_1.so test_executable
all: $(BINS)


plus_1.so: plus_1.cpp
	$(CC) $(CPPFLAGS) -fPIC -shared -o  $@ $^

test_executable: Test.cpp
	$(CC) $(CPPFLAGS)  -o  $@ $^

clean:
	rm  $(BINS)
