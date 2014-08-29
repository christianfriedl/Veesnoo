CXX=g++
CC=g++
CXXFLAGS+=-ggdb -I../
LDFLAGS+=-lncursesw  -L../ 

testWidget: testWidget.o
	g++ $(LDFLAGS) -o testWidget testWidget.o -lnvwm



# g++ $(LDFLAGS) -o testWidget -lnvwm ../Rect.o ../CursesManager.o ../CursesWindow.o ../Widget.o testWidget.o -lnvwm

testWidget.o: testWidget.cc
