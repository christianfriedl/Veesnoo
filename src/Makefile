CC=clang
CFLAGS+=-ggdb 
LDFLAGS=-lncurses -framework Foundation
OBJECTS=NVRect.o NVCursesManager.o NVCursesWindow.o NVWidget.o NVCheckbox.o \
		NVButton.o NVLabel.o NVMenuItem.o NVHorizontalMenu.o NVVerticalMenu.o \
		NVSimpleFocusManager.o \
		$(TESTOBJ)

# TESTOBJ=testNVCursesWindow.o
TESTOBJ=testFocus.o

.SUFFIXES: .o .m

test: testnvwm

clean-test: clean test

testnvwm: $(OBJECTS)
	clang -o testnvwm $(OBJECTS) $(LDFLAGS)

.m.o: $<.m $<.h
	$(CC) $(CFLAGS) -c $<


clean:
	rm -f *.o testnvwm
