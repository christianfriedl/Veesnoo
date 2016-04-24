. ./redo-config.sh

redo-ifchange $2.cc

$CC $CFLAGS -o $3 -c $2.cc
