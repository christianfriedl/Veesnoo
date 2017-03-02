CC=clang++
CURSESLIB=-lncursesw
CFLAGS="-g -Wall -std=c++14"
LDFLAGS="-lncursesw -std=c++14"
AR="ar"
ARFLAGS="rs"
HAVEDEFINES="-DHAVE_USR_INCLUDE_NCURSESW_NCURSES_H "
LIBOBJECTS=" Logger.o  CursesException.o CursesManager.o CursesWindow.o Rect.o Widget.o Label.o  Button.o FocusableWidget.o  TextBox.o Checkbox.o MenuItem.o  Container.o  HorizontalMenu.o VerticalMenu.o FocusableContainer.o ContainerFocusManaging.o ContainerFocusManager.o  Window.o PopupMenu.o  MainLoop.o "
