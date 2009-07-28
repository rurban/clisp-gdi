make clisp-module INCLUDES='-I.. -I'"$absolute_linkkitdir"
NEW_FILES='gdi-preload.lisp gdi.o'
# on mingw/w32api we need to add -lmsimg32 
NEW_LIBS='gdi.o -lgdi32 -lmsimg32'
NEW_MODULES='GDI'
TO_LOAD='gdi'
TO_PRELOAD='gdi-preload.lisp'
