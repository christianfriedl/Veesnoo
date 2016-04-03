rm -f test.log && redo -x debug && $1 && cat test.log
