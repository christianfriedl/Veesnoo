CC=clang
CFLAGS+=-ggdb 
LDFLAGS=-lncurses -framework Foundation
OBJECTS=NVRect.o NVCursesManager.o NVCursesWindow.o NVWidget.o NVCheckbox.o $(TESTOBJ)
TESTOBJ=testNVCursesWindow.o

.SUFFIXES: .o .m

.m.o:
	$(CC) $(CFLAGS) -c $<

testnvwm: $(OBJECTS)
	clang -o testnvwm $(OBJECTS) $(LDFLAGS)

NVCursesManager.o: NVCursesManager.m NVCursesManager.h
NVCursesWindow.o: NVCursesWindow.m NVCursesWindow.h

clean:
	rm *.o
