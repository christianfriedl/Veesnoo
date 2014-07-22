CC=clang
CFLAGS+=-ggdb -I../
LDFLAGS=-lncurses -fobjc-arc -framework Foundation $(STATICLIB)
OBJECTS=testTextfield.o testHorizVertMenus.o testPopupMenu.o testWidget.o testApp.o testSelectbox.o
STATICLIB=../libnvwm.a
TESTBINARIES=testWidget testHorizVertMenus testTextfield testPopupMenu testApp testSelectbox

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

testApp: $(OBJECTS)
	clang $(LDFLAGS) testApp.o -o testApp

testSelectbox: $(OBJECTS)
	clang $(LDFLAGS) testSelectbox.o -o testSelectbox

.m.o: $<.m
	$(CC) $(CFLAGS) -c $<


clean:
	rm -f $(TESTBINARIES)
