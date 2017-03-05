#!/bin/sh
# REDOFLAGS=-xv

TESTFILE=$1
echo $TESTFILE
[ -f test/$TESTFILE ] || TESTFILE=`basename -s .cc $TESTFILE`
echo $TESTFILE
[ -f test/$TESTFILE ] || TESTFILE=`basename -s .h $TESTFILE`
echo $TESTFILE
[ -f test/$TESTFILE ] || TESTFILE="test$TESTFILE"
echo $TESTFILE

rm -f test.log;
redo test/$TESTFILE && (test/$1 ; reset; less test.log)
