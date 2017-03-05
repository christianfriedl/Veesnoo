* The canonical order of screen updates has to be:
** ::refresh (CursesManager::refresh())
** Container::refresh();
** (sub-)Widget::refresh();
** ::wmove (CursesWindow:setCursorPosition());
