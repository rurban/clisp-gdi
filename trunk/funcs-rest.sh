awk -f func.awk <funcs-rest.h >funcs-rest.c
sed "s/popSTACK()/BEFORE(args_end_pointer)/" <funcs-rest.c >funcs-rest.c1
mv funcs-rest.c1 funcs-rest.c
