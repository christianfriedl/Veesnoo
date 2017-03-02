#!/bin/bash

redo-ifchange $2.cc

. ./redo-config.sh

>&2 echo "$CXX $CFLAGS $CXXFLAGS -MD -MF $2.d -c -o $3 $2.cc"
$CXX $CFLAGS $CXXFLAGS -MD -MF $2.d -c -o $3 $2.cc

read DEPS <$2.d

DEPS="$DEPS redo-config.sh"

redo-ifchange ${DEPS#*:}

