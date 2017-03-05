CC=clang
CFLAGS="-g -Wall"
LDFLAGS="-L/usr/local/lib -I/usr/local/include -lncursesw"

$CC $CFLAGS $LDFLAGS -o $3 $2.c
