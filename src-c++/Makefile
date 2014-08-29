CC=gcc
CFLAGS+=-ggdb
LDFLAGS=-lncursesw 
OBJECTS=CursesManager.o CursesWindow.o CursesException.o Widget.o Rect.o

all: $(OBJECTS)
	ar rs libnvwm.a $(OBJECTS)

.cc.o: $<.m $<.h
	$(CC) $(CFLAGS) -c $<

