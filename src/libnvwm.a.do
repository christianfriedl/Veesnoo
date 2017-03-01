#!/bin/bash

./create_ctags.sh
. ./libnvwm-objects.sh

redo-ifchange $LIBOBJECTS

. ./redo-config.sh

>&2 echo "$AR $ARFLAGS $3 $LIBOBJECTS"
$AR $ARFLAGS $3 $LIBOBJECTS
