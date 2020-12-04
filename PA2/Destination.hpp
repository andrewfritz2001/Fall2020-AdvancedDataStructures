#pragma once
#include <iostream>

class Destination{
private:
	int pos;
	std::string name;

public:
	// Default Constructor
	Destination();
	// Overloaded Constructor
	Destination(int p, std::string n);
	// Copy Constructor
	Destination(const Destination &d1);
	// Destructor
	~Destination();

	// Functions
	void printPosition();
	void printDestinationName();
};