OBJECTS="CursesException.o CursesManager.o CursesWindow.o Rect.o Widget.o Label.o"
OBJECTS="$OBJECTS FocusManaging.o SingleFocusManager.o ContainerFocusManager.o ContainerFocusManaging.o FocusableWidget.o FocusableContainer.o "
OBJECTS="$OBJECTS Button.o"
OBJECTS="$OBJECTS Checkbox.o TextBox.o Container.o "
OBJECTS="$OBJECTS MenuItem.o HorizontalMenu.o VerticalMenu.o"
OBJECTS="$OBJECTS Logger.o"

redo-ifchange $OBJECTS

. ./config.sh

$AR $ARFLAGS $3 $OBJECTS
