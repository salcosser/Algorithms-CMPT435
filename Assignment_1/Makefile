output: Element.o Stack.o Main.o
	g++ Element.o Stack.o Main.o -o output

Main.o: Main.cpp
	g++ -c Main.cpp

Element.o: Element.cpp Element.h
	g++ -c Element.cpp

Stack.o: Stack.cpp
	g++ -c Stack.cpp

clean: 
	rm *.o output