. ./redo-config.sh

redo-ifchange $2.o $LIBOBJS
>&2 echo "$CC $LDFLAGS -o $3 $2.o $STATIC_LIBS"
$CC $LDFLAGS -o $3 $2.o $STATIC_LIBS
