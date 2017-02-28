#!/bin/bash

CC=clang++
CURSESLIB=asdfasfs

./redo-config.local.sh

if [ "$HAVE_DEBUG_SYMBOLS" == "yes" ]; then 
    CFLAGS="-g -Wall -std=c++14"
else
    CFLAGS="-Wall -std=c++14"
fi

CFLAGS="-Wall -std=c++14"

# CC=g++
# CFLAGS="-Wall -std=c++14"
# CFLAGS="-g -Wall -std=c++14 -DNV_NO_PAINTING"
LDFLAGS="$CURSESLIB -std=c++14"
AR=ar
ARFLAGS=rs 

HAVEDEFINES=""
. ./config-defines.sh
