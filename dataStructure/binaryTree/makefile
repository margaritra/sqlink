CFLAGS = -g 

aprog : bst_test.o bst.o
	gcc -o aprog bst_test.o bst.o

bst_test.o : bst_test.c bst.h
	gcc -c $(CFLAGS) bst_test.c

bst.o : bst.c bst.h
	gcc -c $(CFLAGS) bst.c
