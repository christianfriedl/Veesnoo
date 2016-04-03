CC=clang++
CFLAGS="-g -I../ -Wall -std=c++14"
LDFLAGS="-lncursesw  -L../ -std=c++14"
STATIC_LIBS=-lnvwm-debug
LIBOBJS=../libnvwm-debug.a
BINARIES="testWidget testLabel testButton testCheckbox testHorizontalMenu testVerticalMenu"
BINARIES="testWindow testTextBox testPopupMenu"
OBJECTS="testWidget.o testLabel.o testButton.o testCheckbox.o testHorizontalMenu.o testVerticalMenu.o"
OBJECTS="$OBJECTS testWindow.o testTextBox.o testPopupMenu.o"

#### debugging
BINARIES="testWidget testLabel testButton testCheckbox testTextBox"
OBJECTS="testWidget.o testLabel.o testCheckbox.o"
OBJECTS="$OBJECTS testButton.o testTextBox.o"
