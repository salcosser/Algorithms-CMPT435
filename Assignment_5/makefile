launch: Main.o  GraphManager.o Greedy.o Sort.o
	g++ -std=c++14 Main.o  GraphManager.o Greedy.o Sort.o -o launch

Main.o: Main.cpp GraphManager.h Greedy.h
	g++ -std=c++14  -c Main.cpp

GraphManager.o: GraphManager.cpp Vertex.h
	g++ -std=c++14 -c GraphManager.cpp

Greedy.o: Greedy.cpp Greedy.h Sort.h
	g++ -std=c++14 -c Greedy.cpp

Sort.o: Sort.cpp Sort.h
	g++ -std=c++14 -c Sort.cpp

clean:
	rm *.o launch