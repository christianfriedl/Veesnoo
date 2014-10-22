OBJECTS="CursesException.o CursesManager.o CursesWindow.o Rect.o Widget.o Label.o Button.o FocusableWidget.o "
OBJECTS="$OBJECTS SingleFocusManager.o SingleFocusManager.o FocusManaging.o Checkbox.o Container.o FocusableContainer.o"
OBJECTS="$OBJECTS HorizontalMenu.o VerticalMenu.o MenuItem.o ContainerFocusManager.o ContainerFocusManaging.o"

redo-ifchange $OBJECTS

. ./config.sh

$AR $ARFLAGS $3 $OBJECTS