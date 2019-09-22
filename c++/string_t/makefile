CFLAGS = -g 

aprog : string_t.o main.o
	g++ -o aprog  string_t.o main.o

string_t.o : string_t.cpp head.h
	g++ -c $(CFLAGS)  string_t.cpp

main.o : main.cpp head.h
	g++ -c $(CFLAGS) main.cpp