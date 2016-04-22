CC=clang++
CFLAGS="-g -I../ -Wall -std=c++14"
LDFLAGS="-lncursesw  -L../ -std=c++14"
STATIC_LIBS=-lnvwm
LIBOBJS=../libnvwm.a
BINARIES="testWidget testLabel "
# BINARIES="$BINARIES testButton testCheckbox testHorizontalMenu testVerticalMenu"
# BINARIES="$BINARIES testWindow testTextBox testPopupMenu"

OBJECTS="testWidget.o testLabel.o "
# OBJECTS="$OBJECTS testButton.o testCheckbox.o testHorizontalMenu.o testVerticalMenu.o"
# OBJECTS="$OBJECTS testWindow.o testTextBox.o testPopupMenu.o"
