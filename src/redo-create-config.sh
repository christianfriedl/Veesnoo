#!/bin/bash

## defaults
CC=clang++
CURSESLIB=lncurses
CFLAGS="-Wall -std=c++14"
HAVEDEFINES=""

## source files to create vars
. ./redo-config.local.sh
. ./libnvwm-objects.sh
. ./config-defines.sh

if [ "$HAVE_DEBUG_SYMBOLS" == "yes" ]; then 
    CFLAGS="-g -Wall -std=c++14"
else
    CFLAGS="-Wall -std=c++14"
fi


# CC=g++
# CFLAGS="-Wall -std=c++14"
# CFLAGS="-g -Wall -std=c++14 -DNV_NO_PAINTING"
LDFLAGS="$CURSESLIB -std=c++14"
AR=ar
ARFLAGS=rs 


cat << EOF
CC=$CC
CURSESLIB=$CURSESLIB
CFLAGS="$CFLAGS"
LDFLAGS="$LDFLAGS"
AR="$AR"
ARFLAGS="$ARFLAGS"
HAVEDEFINES="$HAVEDEFINES"
LIBOBJECTS="$LIBOBJECTS"
EOF
