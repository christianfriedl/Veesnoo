#!/bin/bash

. ./redo-config.sh

redo-ifchange $2.cc

$CC $CFLAGS $HAVEDEFINES -o $3 -c $2.cc
