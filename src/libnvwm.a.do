#!/bin/bash

./create_ctags.sh
. ./libnvwm-objects.sh

redo-ifchange $LIBOBJECTS

. ./redo-config.sh

$AR $ARFLAGS $3 $LIBOBJECTS
