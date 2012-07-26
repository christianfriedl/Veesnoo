include_directories(../src)

set(LIBS ncurses cgenerics nvwm)

add_executable(0100_nvCursesManager 0100_nvCursesManager.c)
target_link_libraries(0100_nvCursesManager ${LIBS})

add_executable(0200_nvCursesWindow 0200_nvCursesWindow.c)
target_link_libraries(0200_nvCursesWindow ${LIBS})
