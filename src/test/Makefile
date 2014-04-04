CC=clang
CFLAGS+=-ggdb -I../
LDFLAGS=-lncurses -fobjc-arc -framework Foundation $(STATICLIB)
OBJECTS=testFocus.o testTextfield.o testHorizVertMenus.o testPopupMenu.o testWidget.o
STATICLIB=../libnvwm.a
TESTBINARIES=testWidget testHorizVertMenus testTextfield testPopupMenu

.SUFFIXES: .o .m

test: clean $(TESTBINARIES)

testWidget: $(OBJECTS)
	clang $(LDFLAGS) testWidget.o -o testWidget


testHorizVertMenus: $(OBJECTS)
	clang $(LDFLAGS) testHorizVertMenus.o -o testHorizVertMenus

testTextfield: $(OBJECTS)
	clang $(LDFLAGS) testTextfield.o -o testTextfield

testPopupMenu: $(OBJECTS)
	clang $(LDFLAGS) testPopupMenu.o -o testPopupMenu

.m.o: $<.m $<.h
	$(CC) $(CFLAGS) -c $<


clean:
	rm -f $(TESTBINARIES)
