CC=clang
CFLAGS+=-ggdb
LDFLAGS=-lncursesw 
OBJECTS=CursesManager.o

all: $(OBJECTS)

.cc.o: $<.m $<.h
	$(CC) $(CFLAGS) -c $<

