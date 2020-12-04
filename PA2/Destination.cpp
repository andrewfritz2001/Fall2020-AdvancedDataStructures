#include "Destination.hpp"

// Default Contructor
Destination::Destination(){
	pos = 0;
	name = " ";
}
// Overloaded Constructor
Destination::Destination(int p, std::string n){
	pos = p;
	name = n;
}
// Copy Constructor
Destination::Destination(const Destination &d1){
	pos = d1.pos;
	name = d1.name;
}
// Destructor
Destination::~Destination(){
}

// Print Functions
void Destination::printPosition(){
	std::cout << pos; 
}
void Destination::printDestinationName(){
	std::cout << name;
}