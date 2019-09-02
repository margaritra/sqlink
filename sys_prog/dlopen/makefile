aprog : main.o libN.so
	gcc -o aprog main.o libN.so

main.o : main.c
	gcc -c main.c

libN.so: lib1.o  lib2.o  lib3.o
	gcc -o libN.so -shared lib1.o  lib2.o  lib3.o

lib1.o : lib1.c libN.h
	gcc -c -fPIC lib1.c

lib2.o : lib3.c libN.h
	gcc -c -fPIC lib2.c

lib3.o : lib3.c libN.h
	gcc -c -fPIC lib3.c 
