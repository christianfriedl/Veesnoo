CFLAGS+=-ggdb
CC=clang++

all: objs
	$(CC) -ggdb -o app Widget.o Manager.o main.o
	
objs: Widget.o Manager.o main.o

clean:
	rm -f *.o foobar

analyze: Widget.cc Manager.cc main.cc
	$(CC) -std=c++14 --analyze -Xanalyzer -analyzer-output=text $<
