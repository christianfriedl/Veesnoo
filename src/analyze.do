. ./libnvwm-objects.sh
. ./redo-config.sh

for cfile in $LIBSOURCES; do
    >&2 echo "analyzing $cfile" 
    $CC -std=c++14 --analyze -Xanalyzer -analyzer-output=text $cfile
done
