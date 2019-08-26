CFLAGS  = -g 

aprog : hash_table.o hash_table_test.o
	gcc -o aprog hash_table.o hash_table_test.o

hash_table.o : hash_table.c hash_table.h
	gcc -c $(CFLAGS) hash_table.c

hash_table_test.o : hash_table_test.c hash_table.h
	gcc -c $(CFLAGS) hash_table_test.c
