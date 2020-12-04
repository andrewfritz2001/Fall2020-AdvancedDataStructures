#pragma once
#include "Destination.hpp"
#include <list>

class ListMyJosephus{
private:
	int _m;
	int _n;
	std::list<Destination>::iterator _itc;
	std::list<Destination> _l;

public:
	ListMyJosephus(int m, int n);
	~ListMyJosephus();
	void clear();
	int currentSize();
	bool isEmpty();
	Destination eliminateDestination();
	void printAllDestinations();
	void addDestination(const Destination &d);
	int getN();
	int getM();
};