CFLAGS = -g 

aprog : multFileDetc_test.o multFileDetc_func.o hash_table.o walk.o
	gcc -o finddup multFileDetc_test.o multFileDetc_func.o hash_table.o walk.o -lssl -lcrypto 

multFileDetc_test.o : multFileDetc_test.c multFileDetc.h
	gcc -c $(CFLAGS)  multFileDetc_test.c

multFileDetc_func.o : multFileDetc_func.c multFileDetc.h
	gcc -c $(CFLAGS) multFileDetc_func.c

hash_table.o : hash_table.c hash_table.h
	gcc -c $(CFLAGS) hash_table.c

walk.o : walk.c walk.h
	gcc -c $(CFLAGS) walk.c