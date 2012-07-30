include_directories(../src)

set(LIBS ncurses cgenerics nvwm)

add_executable(0100_nvCursesManager 0100_nvCursesManager.c debug.c)
target_link_libraries(0100_nvCursesManager ${LIBS})

add_executable(0200_nvCursesWindow 0200_nvCursesWindow.c debug.c)
target_link_libraries(0200_nvCursesWindow ${LIBS})

add_executable(0300_nvColorManager 0300_nvColorManager.c debug.c)
target_link_libraries(0300_nvColorManager ${LIBS})

add_executable(0350_nvLabel 0350_nvLabel.c debug.c)
target_link_libraries(0350_nvLabel ${LIBS})

add_executable(0360_nvTextbox 0360_nvTextbox.c debug.c)
target_link_libraries(0360_nvTextbox ${LIBS})

add_executable(0370_nvCheckbox 0370_nvCheckbox.c debug.c)
target_link_libraries(0370_nvCheckbox ${LIBS})

add_executable(0400_nvFocusManager 0400_nvFocusManager.c debug.c)
target_link_libraries(0400_nvFocusManager ${LIBS})

add_executable(0410_nvSubwidgetManager 0410_nvSubwidgetManager.c debug.c)
target_link_libraries(0410_nvSubwidgetManager ${LIBS})
