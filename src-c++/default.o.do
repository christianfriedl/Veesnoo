redo-ifchange $2.cc
. ./config.sh

$CC $CFLAGS -MD -MF $2.d -c -o $3 $2.cc
read DEPS <$2.d

redo-ifchange ${DEPS#*:}

