all: test

CFLAGS = -g -O2

test: test.o myToc.o
	cc -o test test.o myToc.o
clean:
	rm -f  *.o test test.exe
demo: test
	./test
