OBJECTS="CursesException.o CursesManager.o CursesWindow.o Rect.o Widget.o "
OBJECTS="$OBJECTS Logger.o"

redo-ifchange $OBJECTS

. ./config.sh

$AR $ARFLAGS $3 $OBJECTS
