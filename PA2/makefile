PA2: main.o Destination.o ListMyJosephus.o TestListMyJosephus.o VectorMyJosephus.o TestVectorMyJosephus.o
	g++ -g -Wall -std=c++11 main.o Destination.o ListMyJosephus.o TestListMyJosephus.o VectorMyJosephus.o TestVectorMyJosephus.o -o PA2

main.o: main.cpp 
	g++ -c main.cpp

Destination.o: Destination.cpp Destination.hpp
	g++ -c Destination.cpp

ListMyJosephus.o: ListMyJosephus.cpp ListMyJosephus.hpp 
	g++ -c ListMyJosephus.cpp

TestListMyJosephus.o: TestListMyJosephus.cpp TestListMyJosephus.hpp
	g++ -c TestListMyJosephus.cpp

VectorMyJosephus.o: VectorMyJosephus.cpp VectorMyJosephus.hpp 
	g++ -c VectorMyJosephus.cpp

TestVectorMyJosephus.o: TestVectorMyJosephus.cpp TestVectorMyJosephus.hpp
	g++ -c TestVectorMyJosephus.cpp

clean:
	-rm *.o

run:
	@./PA2