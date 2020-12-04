#pragma once
#include "Destination.hpp"
#include <vector>

class VectorMyJosephus{
private:
	int _m;
	int _n;
	int _currPos;
	std::vector<Destination> _v;

public:
	VectorMyJosephus(int m, int n);
	~VectorMyJosephus();
	void clear();
	int currentSize();
	bool isEmpty();
	Destination eliminateDestination();
	void printAllDestinations();
	void addDestination(const Destination &d);
	int getN();
	int getM();
};