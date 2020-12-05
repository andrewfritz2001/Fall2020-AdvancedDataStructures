PA3: main.o CancerData.o
	g++ -g -Wall -std=c++11 main.o CancerData.o -o PA3 

main.o: main.cpp AVLTree.h AVLNode.h
	g++ -c main.cpp


CancerData.o: CancerData.h CancerData.cpp
	g++ -c CancerData.cpp

clean:
	-rm *.o

run:
	@./PA3