launch: Main.o Sort.o Queue.o Search.o HashTable.o
	g++ -std=c++11 Main.o Sort.o Queue.o Search.o HashTable.o -o launch

Main.o: Main.cpp Sort.h HashTable.h Search.h
	g++ -std=c++11  -c Main.cpp

Sort.o: Sort.cpp Sort.h
	g++ -std=c++11 -c Sort.cpp


Queue.o: Queue.cpp Queue.h Node.h
	g++ -std=c++11 -c Queue.cpp

Search.o: Search.cpp Search.h
	g++ -std=c++11 -c Search.cpp

HashTable.o: HashTable.cpp HashTable.h
	g++ -std=c++11 -c HashTable.cpp

clean:
	rm *.o launch
	