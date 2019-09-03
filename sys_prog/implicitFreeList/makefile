CFLAGS = -g

aprog : impl_Test.o implicitfunc.o
	gcc -o aprog impl_Test.o implicitfunc.o

impl_Test.o : impl_Test.c implicit_head.h
	gcc -c $(CFLAGS) impl_Test.c

implicitfunc.o : implicitfunc.c implicit_head.h
	gcc -c $(CFLAGS) implicitfunc.c