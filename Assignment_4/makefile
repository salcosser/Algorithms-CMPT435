launch: Main.o BinTree.o GraphManager.o
	g++ -std=c++11 Main.o BinTree.o  GraphManager.o -o launch

Main.o: Main.cpp BinTree.h BinNode.h
	g++ -std=c++11  -c Main.cpp

BinTree.o: BinTree.cpp BinTree.h BinNode.h
	g++ -std=c++11 -c BinTree.cpp
GraphManager.o: GraphManager.cpp Vertex.h
	g++ -std=c++11 -c GraphManager.cpp


clean:
	rm *.o launch