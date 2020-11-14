launch: Main.o BinTree.o GraphManager.o Queue.o
	g++ -std=c++14 Main.o BinTree.o  GraphManager.o Queue.o -o launch

Main.o: Main.cpp BinTree.h BinNode.h
	g++ -std=c++14  -c Main.cpp

BinTree.o: BinTree.cpp BinTree.h BinNode.h
	g++ -std=c++14 -c BinTree.cpp
GraphManager.o: GraphManager.cpp Vertex.h Queue.cpp Queue.h Node.h
	g++ -std=c++14 -c GraphManager.cpp
Queue.o: Queue.cpp Queue.h Node.h
	g++ -std=c++14 -c Queue.cpp
clean:
	rm *.o launch