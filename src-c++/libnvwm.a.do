OBJECTS="CursesException.o CursesManager.o CursesWindow.o Rect.o Widget.o Label.o Button.o FocusableWidget.o SingleFocusManager.o SingleFocusManager.o FocusManaging.o Checkbox.o"

redo-ifchange $OBJECTS

. ./config.sh

$AR $ARFLAGS $3 $OBJECTS
