launch: Stack.o Main.o Queue.o
	g++  Stack.o Main.o Queue.o -o launch

Main.o: Main.cpp Stack.h
	g++ -c Main.cpp

Stack.o: Stack.cpp Node.h Stack.h
	g++ -c Stack.cpp

Queue.o: Queue.cpp Queue.h Node.h
	g++ -c Queue.cpp
clean: 
	rm *.o launch