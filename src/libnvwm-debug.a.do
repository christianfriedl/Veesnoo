OBJECTS="CursesException.o CursesManager.o CursesWindow.o Rect.o Widget.o Label.o"
OBJECTS="$OBJECTS FocusManaging.o SingleFocusManager.o FocusableWidget.o Button.o"
OBJECTS="$OBJECTS Checkbox.o TextBox.o"
OBJECTS="$OBJECTS Logger.o"

redo-ifchange $OBJECTS

. ./config.sh

$AR $ARFLAGS $3 $OBJECTS
