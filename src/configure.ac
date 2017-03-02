AC_INIT([nvwm], [0.1a], [cf@christian-friedl.info])
AC_PREREQ([2.69])

AC_LANG([C++])
AC_PROG_CXX([clang++ g++])

AC_CHECK_LIB(ncursesw, [initscr], [AC_SUBST(LIB_CURSES, [-lncursesw])], [AC_MSG_ERROR([initscr was not found in libncursesw])])
AC_CHECK_LIB(ncursesw, [raw], [], [AC_MSG_ERROR([function raw was not found in libncursesw])])
AC_CHECK_LIB(ncursesw, [cbreak], [], [AC_MSG_ERROR([function cbreak was not found in libncursesw])])
AC_CHECK_LIB(ncursesw, [noecho], [], [AC_MSG_ERROR([function noecho was not found in libncursesw])])
AC_CHECK_LIB(ncursesw, [keypad], [], [AC_MSG_ERROR([function keypad was not found in libncursesw])])
AC_CHECK_LIB(ncursesw, [set_escdelay], [], [AC_MSG_ERROR([function set_escdelay was not found in libncursesw])])
AC_CHECK_LIB(ncursesw, [has_colors], [], [AC_MSG_ERROR([function has_colors was not found in libncursesw])])
AC_CHECK_LIB(ncursesw, [endwin], [], [AC_MSG_ERROR([function endwin was not found in libncursesw])])
AC_CHECK_LIB(ncursesw, [newwin], [], [AC_MSG_ERROR([function newwin was not found in libncursesw])])
AC_CHECK_LIB(ncursesw, [delwin], [], [AC_MSG_ERROR([function delwin was not found in libncursesw])])
AC_CHECK_LIB(ncursesw, [refresh], [], [AC_MSG_ERROR([function refresh was not found in libncursesw])])
AC_CHECK_LIB(ncursesw, [has_colors], [], [AC_MSG_ERROR([function has_colors was not found in libncursesw])])
AC_CHECK_LIB(ncursesw, [init_pair], [], [AC_MSG_ERROR([function initpair was not found in libncursesw])])
AC_CHECK_LIB(ncursesw, [getch], [], [AC_MSG_ERROR([function getch was not found in libncursesw])])
dnl getmaxyx is a macro AC_CHECK_LIB(ncursesw, [getmaxyx], [], [AC_MSG_ERROR([function getmaxyx was not found in libncursesw])])

AC_CHECK_HEADERS([ncursesw/ncurses.h], [], [AC_MSG_ERROR([no ncurses header found])])
AC_CHECK_HEADERS([ncurses.h], [], [])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([redo-config.sh.dotmp])
AC_OUTPUT
