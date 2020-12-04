#include "VectorMyJosephus.hpp"

VectorMyJosephus::VectorMyJosephus(int m, int n){
	this->_m = m;
	this->_n = n;
	this->_currPos = 0;
}

VectorMyJosephus::~VectorMyJosephus(){
	delete &_v;
}

void VectorMyJosephus::clear(){
	_v.clear();
}

int VectorMyJosephus::currentSize(){
	return _v.size();
}

bool VectorMyJosephus::isEmpty(){
	return _v.empty();
}

Destination VectorMyJosephus::eliminateDestination(){
	// Checking if there's only one element in the vector
	Destination popped;
	if(_v.size() == 1){
		popped = _v[0];
	 	_v.erase(_v.begin());
	 	return popped;
	}

	// Iterating through the loop M times
	for(int i = 0; i < this->_m; ++i){
		if(this->_currPos == _v.size())    // if currPos is at the end, set it equal to the front
			this->_currPos = 0;   		   // so the vector is traversed like a loop
		else
			++this->_currPos;
	}

	// if currPos is at the end, move it back to the front 
	if(this->_currPos == _v.size())    
		this->_currPos = 0;     

	//Deleting desired element
	popped = (_v[this->_currPos]);
	_v.erase(_v.begin() + this->_currPos);

	return popped; // Returning deleted element
}

void VectorMyJosephus::printAllDestinations(){
	for(auto &it : _v){
		it.printPosition();
		std::cout << " "; 
		it.printDestinationName();
		std::cout << std::endl;
	}
}

void VectorMyJosephus::addDestination(const Destination &d){
	_v.push_back(d);
}

int VectorMyJosephus::getN(){
	return this->_n;
}

int VectorMyJosephus::getM(){
	return this->_m;
}