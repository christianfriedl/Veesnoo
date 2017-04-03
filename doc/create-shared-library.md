gcc -shared -Wl,-soname,your_soname \
    -o library_name file_list library_list

gcc -fPIC -g -c -Wall a.c
gcc -fPIC -g -c -Wall b.c
gcc -shared -Wl,-soname,libmystuff.so.1 \
    -o libmystuff.so.1.0.1 a.o b.o -lc

 -Wl,-rpath,$(DEFAULT_LIB_INSTALL_PATH) ---- set ld path locally
