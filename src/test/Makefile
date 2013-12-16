CC=clang
CFLAGS+=-ggdb -I../
LDFLAGS=-lncurses -fobjc-arc -framework Foundation $(STATICLIB)
OBJECTS=testFocus.o testTextfield.o
STATICLIB=../libnvwm.a
TESTBINARIES=testFocus testTextfield

.SUFFIXES: .o .m

test: clean $(TESTBINARIES)

testFocus: $(OBJECTS)
	clang $(LDFLAGS) testFocus.o -o testFocus

testTextfield: $(OBJECTS)
	clang $(LDFLAGS) testTextfield.o -o testTextfield

.m.o: $<.m $<.h
	$(CC) $(CFLAGS) -c $<


clean:
	rm -f $(TESTBINARIES)
