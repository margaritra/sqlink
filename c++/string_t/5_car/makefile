CFLAGS = -g 

aprog : functions.o main.o
	g++ -o aprog  functions.o main.o

functions.o : functions.cpp car_t_head.h
	g++ -c $(CFLAGS)  functions.cpp

main.o : main.cpp car_t_head.h
	g++ -c $(CFLAGS) main.cpp