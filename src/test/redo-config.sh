# CC=clang++
CC=g++
CFLAGS="-g -I../ -Wall -std=c++14"
# CFLAGS="-I../ -Wall -std=c++14"
LDFLAGS="-lncurses  -L../ -std=c++14"
STATIC_LIBS=-lnvwm
LIBOBJS=../libnvwm.a
BINARIES="testOneWidget testWidget testLabel "
BINARIES="$BINARIES testButton testTextBox testCheckbox "
BINARIES="$BINARIES testHorizontalMenu testContainer"
# BINARIES="$BINARIES testButton testCheckbox testHorizontalMenu testVerticalMenu"
# BINARIES="$BINARIES testWindow testTextBox testPopupMenu"

TESTOBJECTS="testOneWidget.o testWidget.o testLabel.o "
TESTOBJECTS="$TESTOBJECTS testButton.o testTextBox.o testCheckbox.o "
TESTOBJECTS="$TESTOBJECTS testHorizontalMenu.o testContainer.o"
# LIBOBJECTS="$TESTOBJECTS testButton.o testCheckbox.o testHorizontalMenu.o testVerticalMenu.o"
# LIBOBJECTS="$TESTOBJECTS testWindow.o testTextBox.o testPopupMenu.o"
