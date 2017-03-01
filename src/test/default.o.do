#!/bin/bash

. ./redo-config.sh

redo-ifchange $2.cc

>&2 echo "$CC $CFLAGS $HAVEDEFINES -o $3 -c $2.cc"
$CC $CFLAGS $HAVEDEFINES -o $3 -c $2.cc
