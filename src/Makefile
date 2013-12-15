CC=clang
CFLAGS+=-ggdb 
LDFLAGS=-lncurses -framework Foundation
OBJECTS=NVRect.o NVCursesManager.o NVCursesWindow.o NVWidget.o NVCheckbox.o \
		NVButton.o NVLabel.o NVMenuItem.o NVHorizontalMenu.o NVVerticalMenu.o \
		NVSimpleFocusManager.o \
		NVContainer.o
STATICLIB=libnvwm.a

.SUFFIXES: .o .m

all: libnvwm.a

test: all
	cd test/; make test

libnvwm.a: $(OBJECTS)
	ar -rs libnvwm.a $(OBJECTS)

.m.o: $<.m $<.h
	$(CC) $(CFLAGS) -c $<


clean:
	rm -f *.o
