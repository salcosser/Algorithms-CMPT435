launch: Stack.o Main.o Queue.o
	g++ -std=c++11 Stack.o Main.o Queue.o -o launch

Main.o: Main.cpp Stack.h
	g++ -std=c++11 -c Main.cpp

Stack.o: Stack.cpp Node.h Stack.h
	g++ -std=c++11 -c Stack.cpp

Queue.o: Queue.cpp Queue.h Node.h
	g++ -std=c++11 -c Queue.cpp

clean: 
	rm *.o launch
