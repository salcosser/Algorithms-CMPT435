launch: Stack.o Main.o
	g++  Stack.o Main.o -o launch

Main.o: Main.cpp LinkedLists.h
	g++ -c Main.cpp

Stack.o: Stack.cpp LinkedLists.h
	g++ -c Stack.cpp

clean: 
	rm *.o launch