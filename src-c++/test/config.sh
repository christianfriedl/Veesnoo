CC=g++
CFLAGS="-ggdb -I../ -Wall"
LDFLAGS="-lncursesw  -L../"
STATIC_LIBS=-lnvwm
LIBOBJS=../libnvwm.a
BINARIES="testWidget testLabel testButton"
OBJECTS="testWidget.o testLabel.o testButton.o"
