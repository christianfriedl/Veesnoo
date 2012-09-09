set(LIB_SOURCES nvCursesManager.c nvCursesWindow.c nvColorManager.c
    nvWidget.c nvFocusManager.c nvLabel.c nvTextbox.c nvCheckbox.c
    nvSubwidgetManager.c nvWindow.c nvCollections.c nvActionLabel.c
    nvHorizontalMenu.c nvVerticalMenu.c)

add_library(nvwm STATIC ${LIB_SOURCES})
link_directories(${CGENERICS_BIN_DIRECTORIES}/nvwm)

INCLUDE (CheckIncludeFiles)

# usage: CHECK_INCLUDE_FILES (<header> <RESULT_VARIABLE> )
# CHECK_INCLUDE_FILES ("stdlib.h" HAVE_STDLIB_H)

# CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/config.h)

