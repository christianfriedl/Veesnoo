CC=gcc
CFLAGS+=-ggdb
LDFLAGS=-lncursesw 
OBJECTS=CursesManager.o CursesWindow.o CursesException.o Widget.o

all: $(OBJECTS)

.cc.o: $<.m $<.h
	$(CC) $(CFLAGS) -c $<

