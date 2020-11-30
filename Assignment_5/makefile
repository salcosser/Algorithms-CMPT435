launch: Main.o  GraphManager.o 
	g++ -std=c++14 Main.o  GraphManager.o  -o launch

Main.o: Main.cpp GraphManager.h
	g++ -std=c++14  -c Main.cpp

GraphManager.o: GraphManager.cpp Vertex.h 
	g++ -std=c++14 -c GraphManager.cpp

clean:
	rm *.o launch