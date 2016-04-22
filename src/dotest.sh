#!/bin/sh

rm -f test.log;
redo && $1 && cat test.log
