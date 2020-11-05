launch: Main.o BinTree.o 
	g++ -std=c++11 Main.o BinTree.o  -o launch

Main.o: Main.cpp BinTree.h BinNode.h
	g++ -std=c++11  -c Main.cpp

BinTree.o: BinTree.cpp BinTree.h BinNode.h
	g++ -std=c++11 -c BinTree.cpp



clean:
	rm *.o launch