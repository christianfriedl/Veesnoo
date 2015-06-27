. ./config.sh

redo-ifchange $2.o $LIBOBJS

$CC $LDFLAGS -o $3 $2.o $STATIC_LIBS
