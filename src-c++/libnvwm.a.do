OBJECTS="CursesException.o CursesManager.o CursesWindow.o Rect.o Widget.o Label.o"

redo-ifchange $OBJECTS

. ./config.sh

$AR $ARFLAGS $3 $OBJECTS
