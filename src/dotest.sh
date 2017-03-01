#!/bin/sh
# REDOFLAGS=-xv
rm -f test.log;
redo $REDOFLAGS && (test/$1 ; reset; less test.log)
