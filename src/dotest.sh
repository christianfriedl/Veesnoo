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
if [ ! -f test/$TESTFILE ]; then echo "Testfile $TESTFILE not found."; exit; fi

rm -f test.log || true
redo test/$TESTFILE && (test/$TESTFILE ; reset; less test.log)
