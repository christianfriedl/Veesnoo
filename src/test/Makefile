CC=clang
CFLAGS+=-ggdb -I../
LDFLAGS=-lncurses -framework Foundation $(STATICLIB)
OBJECTS=testFocus.o
STATICLIB=../libnvwm.a
TESTBINARIES=testFocus

.SUFFIXES: .o .m

test: $(TESTBINARIES)

testFocus: $(OBJECTS)
	clang $(LDFLAGS) testFocus.o -o testFocus

.m.o: $<.m $<.h
	$(CC) $(CFLAGS) -c $<


clean:
	rm -f *.o
