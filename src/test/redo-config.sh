CC=clang++
CFLAGS="-g -I../ -Wall -std=c++14"
LDFLAGS="-lncursesw  -L../ -std=c++14"
STATIC_LIBS=-lnvwm
LIBOBJS=../libnvwm.a
BINARIES="testWidget testLabel "
BINARIES="$BINARIES testButton testTextBox "
# BINARIES="$BINARIES testButton testCheckbox testHorizontalMenu testVerticalMenu"
# BINARIES="$BINARIES testWindow testTextBox testPopupMenu"

TESTOBJECTS="testWidget.o testLabel.o "
TESTOBJECTS="$TESTOBJECTS testButton.o testTextBox.o "
# LIBOBJECTS="$TESTOBJECTS testButton.o testCheckbox.o testHorizontalMenu.o testVerticalMenu.o"
# LIBOBJECTS="$TESTOBJECTS testWindow.o testTextBox.o testPopupMenu.o"
