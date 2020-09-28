launch: Sort.o Main.o
	g++ -std=c++11 Sort.o Main.o -o launch

Main.o: Main.cpp Sort.h
	g++ -std=c++11 -c Main.cpp

Sort.o: Sort.cpp Sort.h 
	g++ -std=c++11 -c Sort.cpp

clean: 
	rm *.o launch