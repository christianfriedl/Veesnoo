CC=clang
CFLAGS+=-ggdb -fobjc-arc -DDEBUG
LDFLAGS=-lncurses -framework Foundation
OBJECTS=NVRect.o NVCursesManager.o NVCursesWindow.o NVWidget.o NVCheckbox.o \
		NVColorAttribute.o \
		NVTextfield.o \
		NVButton.o NVLabel.o NVMenuItem.o NVHorizontalMenu.o NVVerticalMenu.o NVPopupMenu.o \
		NVWindow.o NVApp.o \
		NVContainerFocusManager.o NVSingleFocusManager.o\
		NVContainer.o \
		NVDumper.o NVLogger.o

STATICLIB=libnvwm.a

.SUFFIXES: .o .m

testall: all test

all: libnvwm.a

test: all
	cd test/; make test

libnvwm.a: $(OBJECTS)
	ar -rs libnvwm.a $(OBJECTS)

.m.o: $<.m $<.h
	$(CC) $(CFLAGS) -c $<


clean:
	rm -f *.o *.a
