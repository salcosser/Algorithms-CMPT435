launch: Main.o PooledTesting.o
	g++ -std=c++14 Main.o PooledTesting.o -o launch 

Main.o: Main.cpp PooledTesting.h
	g++ -std=c++14  -c Main.cpp


clean:
	rm *.o launch