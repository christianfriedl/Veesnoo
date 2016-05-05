. ./redo-config.sh

for cfile in *.cc; do
    echo "analyzing $cfile"
    $CC $CFLAGS --analyze -Xanalyzer -analyzer-output=text $cfile
done
