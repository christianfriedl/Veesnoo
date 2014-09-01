CC=clang
CFLAGS+=-ggdb -I../../
LDFLAGS=-lncurses -fobjc-arc -framework Foundation $(STATICLIB)
OBJECTS=rects.o
STATICLIB=../../libnvwm.a
TESTBINARIES=rects

.SUFFIXES: .o .m

test: clean $(TESTBINARIES)

rects: $(OBJECTS)
	clang $(LDFLAGS) rects.o -o rects


.m.o: $<.m
	$(CC) $(CFLAGS) -c $<


clean:
	rm -f $(TESTBINARIES)
