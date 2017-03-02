#!/bin/bash

redo-ifchange redo-config.sh

./create_ctags.sh
. ./redo-config.sh

redo-ifchange $LIBOBJECTS

>&2 echo "$AR $ARFLAGS $3 $LIBOBJECTS"
$AR $ARFLAGS $3 $LIBOBJECTS
