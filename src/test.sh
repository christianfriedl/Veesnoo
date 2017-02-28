#!/bin/bash
HAVEDEFINES=""
if [[ -f /usr/include/ncurses.h ]]; then
    HAVEDEFINES="-DHAVE_USR_INCLUDE_NCURSES_H $HAVEDEFINES"
elif [[ -f /usr/include/ncursesw/ncurses.h ]]; then
    HAVEDEFINES="-DHAVE_USR_INCLUDE_NCURSESW_NCURSES_H $HAVEDEFINES"
fi

echo $HAVEDEFINES
